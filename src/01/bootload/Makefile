PREFIX = /usr/local
ARCH = h8300-elf
BINDIR = $(PREFIX)/bin
ADDNAME = $(ARCH)-

AR = $(BINDIR)/$(ADDNAME)ar
AS = $(BINDIR)/$(ADDNAME)as
CC = $(BINDIR)/$(ADDNAME)gcc
LD = $(BINDIR)/$(ADDNAME)ld
NM = $(BINDIR)/$(ADDNAME)nm
OBJCOPY = $(BINDIR)/$(ADDNAME)objcopy
OBJDUMP = $(BINDIR)/$(ADDNAME)objdump
RANLIB = $(BINDIR)/$(ADDNAME)ranlib
STRIP = $(BINDIR)/$(ADDNAME)strip

H8WRITE = ../../tools/h8write/kz_h8write

# FreeBSD-4.x:/dev/cuaaX
H8WRITE_SERDEV = /dev/ttyUSB0

OBJS = vector.o startup.o main.o
OBJS += lib.o serial.o

#生成する実行形式のファイル名
TARGET = kzload

#compile options
CFLAGS = -Wall -mh -nostdinc -nostdlib -fno-builtin
#CFLAGS += -mint32
CFLAGS += -I.
#CFLAGS += -g
CFLAGS += -Os
CFLAGS += -DZKLOAD

LFLAGS = -static -T ld.scr -L. #link option

.SUFFIXES: .c .o
.SUFFIXES: .s .o

all : $(TARGET)

$(TARGET) : $(OBJS)
			$(CC) $(OBJS) -o $(TARGET) $(CFLAGS) $(LFLAGS)
			cp $(TARGET) $(TARGET).elf
			$(STRIP) $(TARGET)

#compile rule for *.c file
.c.o : $<
	   $(CC) -c $(CFLAGS) $<

#assemble rule for *.s file
.s.o : $<
	   $(CC) -c $(CFLAGS) $<

#モトローラSレコード・フォーマットへの変換ルール
$(TARGET).mot : $(TARGET)
				$(OBJCOPY) -O srec $(TARGET) $(TARGET).mot

image : $(TARGET).mot

#transfer to flashROM
write : $(TARGET).mot
		$(H8WRITE) -3069 -f20 $(TARGET).mot $(H8WRITE_SERDEV)

clean :
		rm -f $(OBJS) $(TARGET) $(TARGET).elf $(TARGET).mot
