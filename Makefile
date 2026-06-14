CC = gcc
CFLAGS = -Wall -Wextra -O2
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
TARGET = img
SRC = img.c
all: $(TARGET)
$(TARGET): $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(LIBS) -o $(TARGET)
clean:
	rm -f $(TARGET)
