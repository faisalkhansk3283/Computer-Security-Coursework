#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int khan(char *str) {
  char bx[736];
  int n = 2;

  // Compute the stack address of bx
  unsigned long bx_addr = (unsigned long)&bx;

  // Compute the stack address of the return address of bar
  unsigned long ret_addr = (unsigned long)__builtin_return_address(0);

  // Corrupt the stack by overwriting the return address of bar
  *(unsigned long*)(bx_addr + sizeof(bx) + 8) = ret_addr;

  puts("khan");
  return n;
}

int faisal(char *str) {
  char fx[736];
  int n = 1;

  // Compute the stack address of fx
  unsigned long fx_addr = (unsigned long)&fx;

  // Compute the stack address of the return address of foo
  unsigned long ret_addr = (unsigned long)__builtin_return_address(0);

  // Corrupt the stack by overwriting the return address of foo
  *(unsigned long*)(fx_addr + sizeof(fx) + 8) = ret_addr;

  // Corrupt the stack by overwriting the local variable of foo
  strcpy((char*)(fx_addr - sizeof(fx)), "Stack Smashed!");

  puts("faisal");
  return n;
}

int main() {
  char x[128] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int n;

  n = faisal(x);

  if (n == 1) {
    printf("Improper return\n");
  } else {
    printf("Returned properly\n");
  }

  return 0;
}