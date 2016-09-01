## Installation
### Ubuntu
```
sudo apt-get install usbip
sudo apt-get install libusb-1.0-0-dev
```
### Fedora
```
sudo dnf install usbip
sudo dnf install libusb-devel
```

## Usage

```
Usage: ./usbip_server.sh [options]
       ./usbip_client.sh [options]

Options:

  Server:
    -l, --list                            Lists usb devices on the server
    -b, --bind device_id                  Binds usb device to server
    -u, --unbind device_id                Unbinds usb device
    -n, --netstat                         Displays Netstat info
  
  Client:
    -l, --list server_ip                  Lists usb devices bound to the server
    -a, --attatch server_ip device_id     Attatches usb device specified
    -d, --detach server_ip device_id      Detaches usb device specified

```
-----------------------------------------------------------------------------------------------------------

## Libraries and References

libraries needed: libusb-1.0-0-dev, usbip

NOTE: write error may occur if you have already written to the device. Try remove and re-inserting usb to fix.
usbip is required; can be found in the package manager

http://www.dreamincode.net/forums/topic/148707-introduction-to-using-libusb-10/

https://wiki.openwrt.org/doc/howto/usb.iptunnel (DON'T FORGET THE SUDO's!!!)

https://github.com/texane/stlink

http://www.hertaville.com/stm32f0discovery-part-1-linux.html

https://my.st.com/public/STe2ecommunities/mcu/Lists/STM32F4DISCOVERY/Flat.aspx?RootFolder=%2Fpublic%2FSTe2ecommunities%2Fmcu%2FLists%2FSTM32F4DISCOVERY%2FHelp%20transfering%20data%20to%20PC&FolderCTID=0x01200200770978C69A1141439FE559EB459D7580002E3D0FFCC5A9AA4A9C29C3EECB7CCDBF&currentviews=2377#{3258930D-6DF8-407A-B305-CACF8301C78D

(c) Sam & Shyan - Developed in  <a href="https://en.wikipedia.org/wiki/Agile_software_development">Agile style</a>
