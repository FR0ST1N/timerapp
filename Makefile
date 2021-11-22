CC = gcc
C_STD = -std=c17
CFLAGS = -Wall -Wextra
SOURCE_DIR = src
FILE_TYPE = *.c
BUILD_DIR = build
TARGET = $(BUILD_DIR)/timerapp
INSTALL_DIR = /usr/local/bin/timerapp

.PHONY: all lint open run clean

all:
	mkdir -p $(BUILD_DIR)
	$(CC) $(C_STD) $(CFLAGS) -o $(TARGET) $(SOURCE_DIR)/$(FILE_TYPE)

lint:
	clang-format -i -style=file $(SOURCE_DIR)/$(FILE_TYPE)

open:
	@./$(TARGET)

run: all open

install: all
	cp $(TARGET) $(INSTALL_DIR)

uninstall:
	rm $(INSTALL_DIR)

clean:
	rm -f $(TARGET)
