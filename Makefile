BOARD = arduino:samd:mkrwifi1010
PORT  = /dev/ttyACM0
BUILD = build
 
.PHONY: default all flash

default: all flash

all: 
	arduino-cli compile --fqbn $(BOARD) --output-dir $(BUILD) .

flash: 
	arduino-cli upload --fqbn $(BOARD) -p $(PORT) --input-dir $(BUILD) .
	
clean:
	rm -r $(BUILD)
