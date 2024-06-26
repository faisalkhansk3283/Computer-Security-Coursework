#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// changed method name bar to my last name khan and buffer size 736 to my nearest UMBC Id which is multiple of 16
int khan(char *str) {
  char bx[736];
  int n = 2;

  strcpy(bx, str);
// printing my last name
  puts("khan");
  return n;
}

// changed method name foo to my first name faisal and buffer size 736 to my nearest UMBC Id which is multiple of 16
int faisal(char *str) {
  char fx[736];
  int n = 1;

  khan(str);
  strcpy(fx, str);
// printing my first name
  puts("faisal");
  return n;
}

int main() {
  char x[128] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  FILE *fd;
  int n;

  //fd = fopen("badfile", "r");
  //fread(x, sizeof(char), 128, fd);

//calling with my first name method which was earlier foo()
  n = faisal(x);

  if (n == 1) {
    printf("Returned properly\n");

  } else {
    printf("Improper return \n");
  }

  return 0;
}