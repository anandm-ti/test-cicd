INCLUDE_DIR = ../inc
OUTPUT_DIR = ../out
SRC_DIR = ../src
CC = gcc

# Command to link 
$(OUTPUT_DIR)/chess: main.o bmp.o
	$(CC) -Wincompatible-pointer-types -o $(OUTPUT_DIR)/chess main.o bmp.o
# Command to generate main.o object file
main.o: $(SRC_DIR)/main.c $(INCLUDE_DIR)/bmp.h
	$(CC) -Wincompatible-pointer-types -c -I $(INCLUDE_DIR) $(SRC_DIR)/main.c
# Command to generate bmp.o object file
bmp.o: $(SRC_DIR)/bmp.c $(INCLUDE_DIR)/bmp.h
	$(CC) -Wincompatible-pointer-types -I $(INCLUDE_DIR) -c $(SRC_DIR)/bmp.c
# Command to clean the obj and executable
clean:
	rm -f *.o $(OUTPUT_DIR)/chess.exe $(OUTPUT_DIR)/chess

