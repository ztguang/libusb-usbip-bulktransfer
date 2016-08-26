#!/bin/bash

sudo modprobe vhci-hcd

if ! [ -z "$1" ] && ! [ -z "$2" ]; then
	if [ "$1" == "-l" ] || [ "$1" == "--list" ]; then
		usbip list -r $2
	elif ! [ -z "$3" ]; then
		if   [ "$1" == "-a" ] || [ "$1" == "--attach" ]; then
			sudo usbip attach -r $2 -b $3
		elif [ "$1" == "-d" ] || [ "$1" == "--detach" ]; then
			sudo usbip detach -r $2 -b $3
		fi
	fi
fi 
