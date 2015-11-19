# Compiler information 
CC = g++
CFLAGS = -g -Wall

# Target information
TARGET = cpp-shapeways

# Generic information
RM = rm
MKDIR = mkdir -p

all: MAKEDIR $(TARGET)

MAKEDIR: 
	$(MKDIR) bin

$(TARGET): main.cpp
	$(CC) $(CLFAGS) -o bin/$(TARGET) main.cpp swApiClient.cpp -lcurl 

clean:
	$(RM) $(TARGET) 
