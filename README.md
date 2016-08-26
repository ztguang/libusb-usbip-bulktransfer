libraries needed: libusb-1.0-0-dev

for libusbip-dev: libusb-1.0-0-dev, libtpl-dev

http://www.dreamincode.net/forums/topic/148707-introduction-to-using-libusb-10/

http://libusb.sourceforge.net/api-1.0/group__syncio.html

https://github.com/forensix/libusbip

:(( https://www.raspberrypi.org/forums/viewtopic.php?f=63&t=35341

NOTE: write error may occur if you have already written to the device. Try remove and re-inserting usb to fix.
usbip is required; can be found in the package manager

-----------------------------------------------------------------------------------------------------------
## Usage

```
Usage: ./usbip.sh [options]

Options:

  Server:
    -s, --server                            Lists usb devices on the server
    -s, --server device_id                  Binds usb device to server
    --netstat                               Displays Netstat info
    --u, --unbind                           Unbinds usb device
  
  Client:
    -c, --client server_ip                  Lists usb devices bound to the server
    -a, --attatch server_ip device_id       Attatches usb device on server to client

```

-----------------------------------------------------------------------------------------------------------

http://usbip.sourceforge.net/

https://wiki.openwrt.org/doc/howto/usb.iptunnel (DON'T FORGET THE SUDO's!!!)

http://askubuntu.com/questions/612355/share-usb-drive-over-network

https://www.howtoforge.com/how-to-set-up-a-usb-over-ip-server-and-client-with-ubuntu-10.04

(c) Sam & Shyan - Developed in Agile style
