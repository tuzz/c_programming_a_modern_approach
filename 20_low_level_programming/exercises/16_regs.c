#include <stdio.h>

typedef unsigned int DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

static union {
  struct {
    DWORD eax, ebx, ecx, edx;
  } dword;
  struct {
    WORD ax, bx, cx, dx;
  } word;
  struct {
    BYTE al, ah, bl, bh, cl, ch, dl, dh;
  } byte;
} regs;

int main(void) {
  printf("DWORD size: %lu\n", sizeof(DWORD));
  printf("WORD size: %lu\n", sizeof(WORD));
  printf("BYTE size: %lu\n\n", sizeof(BYTE));

  regs.byte.ah = 0x12;
  regs.byte.al = 0x34;
  printf("AX: %hx\n", regs.word.ax);
  printf("EAX: %x\n", regs.dword.eax);

  return 0;
}
