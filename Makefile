# Compiler information
CC = g++
CFLAGS = -Wall -std=c++11

# Target information
TARGET = cpp-shapeways

# Generic information
RM = rm
MKDIR = mkdir -p

all: MAKEDIR $(TARGET)

MAKEDIR:
	$(MKDIR) bin

$(TARGET): main.cpp
	$(CC) $(CFLAGS) -o bin/$(TARGET) main.cpp swApiClient.cpp -lcurl

clean:
	$(RM) $(TARGET)
