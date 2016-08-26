#!/bin/bash

if [ "$1" == "-s" ] || [ "$1" == "--server" ]; then
	sudo modprobe usbip-core
	sudo modprobe usbip-host

	if [ -z "$2" ]; then
		usbip list -l
	elif [ "$2" == "--netstat" ]; then
		netstat -alpt
	elif [ "$2" == "-u" ] || [ "$2" == "--unbind" ]; then
		sudo usbip unbind -b $3
	else
		sudo usbipd -D &
		sudo usbip bind -b $2
	fi
elif [ "$1" == "-c" ] || [ "$1" == "--client" ]; then
	sudo modprobe vhci-hcd

	if [ -z "$3" ]; then
		usbip list -r $2
	elif [ "$2" == "-a" ] || [ "$2" == "--attach" ]; then
		sudo usbip attach -r $3 -b $4
	fi 
fi

