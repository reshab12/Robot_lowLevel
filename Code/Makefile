default: build

build: main.c
	@echo "Building main"
	@avr-gcc main.c -mmcu=atmega328p -o main

flash: build
	@avr-objcopy -O ihex -R .eeprom main main.hex
	avrdude -F -V -c arduino -p m328p -P /dev/ttyACM0 -b 115200 -U flash:w:main.hex

clean:
	@rm main *.o *.hex
