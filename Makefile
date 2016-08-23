install:
	gcc -std=c99 test_libusb.c -lusb-1.0
	sudo ./a.out
