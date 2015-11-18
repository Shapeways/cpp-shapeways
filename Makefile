# Compiler information 
CC = g++
CFLAGS = -g -Wall

# Target information
TARGET = cpp-shapeways

# Generic information
RM = rm

all: $(TARGET)

$(TARGET): main.cpp
	$(CC) $(CLFAGS) -o bin/$(TARGET) main.cpp 

clean:
	$(RM) $(TARGET) 
