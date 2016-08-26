#!/bin/bash

sudo modprobe usbip-core
sudo modprobe usbip-host

if ! [ -z "$1" ]; then
	if   [ "$1" == "-l" ] || [ "$1" == "--list"    ]; then
		usbip list -l
	elif [ "$1" == "-n" ] || [ "$1" == "--netstat" ]; then
		netstat -alpt
	fi
	
	if ! [ -z "$2" ]; then
		if   [ "$1" == "-b" ] || [ "$1" == "--bind"    ]; then 
			sudo usbipd -D &
			sudo usbip bind -b $2
		elif [ "$1" == "-u" ] || [ "$1" == "--unbind"  ]; then
			sudo usbip unbind -b $2
		fi
	fi
fi
