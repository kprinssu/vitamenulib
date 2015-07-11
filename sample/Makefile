TARGET = touchvitalibsample
OBJS   = main.o ../libvitamenu/*.cc

LIBS = -lvita2d -lm -lc_stub -lSceKernel_stub -lSceDisplay_stub -lSceGxm_stub	\
	-lSceCtrl_stub -lSceTouch_stub

PREFIX  = $(DEVKITARM)/bin/arm-none-eabi
CC      = $(PREFIX)-g++
CFLAGS  = -Wall -specs=psp2.specs
CXXFLAGS = $(CFLAGS) -I$(PSP2SDK)/include/c++ -fno-exceptions
CXX      = $(PREFIX)-g++
ASFLAGS = $(CFLAGS)

all: $(TARGET)_fixup.elf

%_fixup.elf: %.elf
	psp2-fixup -q -S $< $@

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

clean:
	@rm -rf $(TARGET)_fixup.elf $(TARGET).elf $(OBJS)