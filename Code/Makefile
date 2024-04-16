CFLAGS = -mmcu=atmega328p
OUTPUT =  -o main

final: main.c
		@echo "Building main"
		@avr-gcc main.c $(CFLAGS) $(OUTPUT)

clean:
		@rm main
