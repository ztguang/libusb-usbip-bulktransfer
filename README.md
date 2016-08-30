## Links and Libraries

libraries needed: libusb-1.0-0-dev

NOTE: write error may occur if you have already written to the device. Try remove and re-inserting usb to fix.
usbip is required; can be found in the package manager

http://www.dreamincode.net/forums/topic/148707-introduction-to-using-libusb-10/

https://wiki.openwrt.org/doc/howto/usb.iptunnel (DON'T FORGET THE SUDO's!!!)

## Todo
1. Fix detach (only reqires port)
2. Make fake usb

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

(c) Sam & Shyan - Developed in Agile style
