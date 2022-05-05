BOARD = arduino:samd:mkrwifi1010
PORT  = /dev/ttyACM0
BIN = bin
 
.PHONY: default all flash

default: all flash

all: 
	arduino-cli compile --fqbn $(BOARD) --output-dir $(BIN) .

flash: 
	arduino-cli upload --fqbn $(BOARD) -p $(PORT) --input-dir $(BIN) .
	
clean:
	rm -r $(BIN)
