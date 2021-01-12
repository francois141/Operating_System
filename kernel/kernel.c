#include "../cpu/idt.h"
#include "../cpu/isr.h"
#include "../drivers/timer.h"
#include "../drivers/screen.h"
#include "../drivers/keyboard.h"
#include "../drivers/ata.h"
#include "../drivers/pci.h"
#include "shell.h"
#include "../system_lib/graphics/libgui.h"
#include "../drivers/pc_speaker.h"



void main()
{
  load_screen_driver();
  isr_install();
  init_keyboard();
  __asm__ __volatile__("sti");

  load_screen_driver();
  init_timer(1000);

  beep(1000);
  enter_shell();

}
