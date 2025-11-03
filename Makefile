DIR?=blink
FILE?=blink

SRC_DIR = $(DIR)
BLINK_DIR = blink
BUILD_DIR = build

LIB_DIR = /usr/lib/avr/include/

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
ELF = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.efl, $(SRC))
BIN = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.bin, $(SRC))

MMCU=atmega328p

default: all

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c $@ $< -I$(LIB_DIR)

$(BUILD_DIR)/%.elf: $(SRC_DIR)/%.c
	avr-gcc -mmcu=$(MMCU) -Os -o $@ $<

$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf
	avr-objcopy -O binary $< $@ 

install: build $(BUILD_DIR)/$(FILE).bin
	avrdude -p atmega328p -c usbasp -P /dev/ttyACM0 -U flash:w:$(BUILD_DIR)/$(FILE).bin

build: _build $(BIN)

_build:
	mkdir -p $(BUILD_DIR)

clear:
	rm -rf $(BUILD_DIR)

all: build
