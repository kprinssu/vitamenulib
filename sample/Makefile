TARGET = touchvitalibsample
OBJS   = main.o 
VITA_MENU_LIB = ../libvitamenu/*.cc

LIBS = -lvita2d -lm -lc_stub -lSceKernel_stub -lSceDisplay_stub -lSceGxm_stub	\
	-lSceCtrl_stub -lSceTouch_stub

PREFIX  = $(DEVKITARM)/bin/arm-none-eabi
CC      = $(PREFIX)-gcc
CFLAGS  = -Wall -specs=psp2.specs
CXXFLAGS = $(CFLAGS) -I$(PSP2SDK)/include/c++ -fno-exceptions
CXX      = $(PREFIX)-g++
ASFLAGS = $(CFLAGS)

all: $(TARGET)_fixup.elf

%_fixup.elf: %.elf
	psp2-fixup -q -S $< $@

$(TARGET).elf: $(OBJS) $(VITA_MENU_LIB)
	$(CC) $(CXXFLAGS) $^ $(LIBS) -o $@

clean:
	@rm -rf $(TARGET)_fixup.elf $(TARGET).elf $(OBJS)