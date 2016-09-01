#include <stdio.h>
#include <libusb-1.0/libusb.h>
#include <stdlib.h>

#define VID 0x8644 // vendor ID
#define PID 0x8003 // product ID
#define EP  2      // endpoint address

void printdev(libusb_device *dev) {
  struct libusb_device_descriptor desc;
  int r = libusb_get_device_descriptor(dev, &desc);
  if (r < 0) {
    printf("failed to get device descriptor");
    return;
  }
  printf("Number of possible configurations: %d  ", (int)desc.bNumConfigurations);
  printf("Device Class: %d  ", (int)desc.bDeviceClass);
  printf("VendorID: %04x  ", desc.idVendor);
  printf("ProductID: %04x\n", desc.idProduct);

  struct libusb_config_descriptor *config;
  libusb_get_config_descriptor(dev, 0, &config);
  printf(".Interfaces: %d |||\n", (int)config->bNumInterfaces);

  const struct libusb_interface *inter;
  const struct libusb_interface_descriptor *interdesc;
  const struct libusb_endpoint_descriptor *epdesc;
  for(int i=0; i<(int)config->bNumInterfaces; i++) {
    inter = &config->interface[i];
    printf("..Number of alternate settings: %d\n", inter->num_altsetting);
    for(int j=0; j<inter->num_altsetting; j++) {
      interdesc = &inter->altsetting[j];
      printf("...Interface Number: %d | ", (int)interdesc->bInterfaceNumber);
      printf("Number of endpoints: %d\n", (int)interdesc->bNumEndpoints);
      for(int k=0; k<(int)interdesc->bNumEndpoints; k++) {
        epdesc = &interdesc->endpoint[k];
        printf("....Descriptor Type: %d | ", (int)epdesc->bDescriptorType);
        printf("EP Address: %d\n", (int)epdesc->bEndpointAddress);
      }
    }
  }

  printf("\n");
  libusb_free_config_descriptor(config);
}

int main() {
  // =============================
  // === SETTING UP USB DEVICE ===
  // =============================

  printf("Testing libusb synchronous bulk transfer...\n");

  libusb_device **devs;             // pointer to pointer of device, used to retrieve a list of devices
  libusb_device_handle *dev_handle; // a device handle
  libusb_context *ctx = NULL;       // a libusb session
  int r;                            // return value

  // initialize a library session
  r = libusb_init(&ctx); 
  if (r < 0) {
    printf("<!! Init Error !!>\n");
    return 1;
  }
  libusb_set_debug(ctx, 3); //set verbosity level to 3, as suggested in the documentation

  //get the list of devices
  ssize_t cnt = libusb_get_device_list(ctx, &devs); 
  if (cnt < 0) {
    printf("<!! Get Device Error !!>\n"); //there was an error
    return 1;
  }
  printf(" (%d) devices in list\n", cnt);   //print total number of usb devices
   for(ssize_t i = 0; i < cnt; i++) printdev(devs[i]);

  // open specific device
  dev_handle = libusb_open_device_with_vid_pid(ctx, VID, PID);
  if (dev_handle == NULL)
    printf("<!! Cannot open device !!>\n");
  else
    printf("Device Opened\n");
  libusb_free_device_list(devs, 1); // free the list, unref the devices in it

  if (libusb_kernel_driver_active(dev_handle, 0) == 1) { // find out if kernel driver is attached
    printf("Kernel Driver Active\n");
    if (libusb_detach_kernel_driver(dev_handle, 0) == 0) { // detach it
      printf("Kernel Driver Detached\n");
    }
  }
  r = libusb_claim_interface(dev_handle, 0); //claim interface 0 (the first) of device (mine had jsut 1)
  if (r < 0) {
    printf("<!! Cannot Claim Interface !!>\n");
    return 1;
  }
  printf("Claimed Interface\n");

  // ==================================
  // === SENDING RAW DATA TO DEVICE ===
  // ==================================

  char  data[] = {'a', 'b', 'c', 'd'}; // data to send
  char *buffer = malloc(4);            // buffer to receive
  int actual; //used to find out how many bytes were written

  printf("Writing Data...\n");
  // device's out endpoint was 2, found with trial (using outputs from printdev)
  r = libusb_bulk_transfer(dev_handle, (EP | LIBUSB_ENDPOINT_OUT), data, 4, &actual, 0); 
  //r = libusb_bulk_transfer(dev_handle, (2 | LIBUSB_ENDPOINT_IN), buffer, 4, &actual, 3000); 
  if (r == 0 && actual == 4) {
    printf("Writing Successful\n");
  }
  else {
    printf("<!! Write Error (%d) !!>\n", r);
  }
  printf("Bytes transferred = %d\n", actual);

  // =========================
  // === RELEASE RESOURCES ===
  // =========================

  r = libusb_release_interface(dev_handle, 0); //release the claimed interface
  if (r!=0) {
    printf("<!! Cannot Release Interface !!>\n");
    return 1;
  }
  printf("Released Interface\n");

  libusb_close(dev_handle); //close the device we opened
  libusb_exit(ctx);         //close the session

  return 0;
}
