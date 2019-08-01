#Q := @
ARCH = arm
CFLAGS = -mcpu=cortex-a17.cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4
CFLAGS += -Wall -g 
CC = arm-hisiv500-linux-g++
LDFLAGS = -mcpu=cortex-a17.cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4

SRCS := $(wildcard *.cxx)
OBJS := $(patsubst %.cxx,%.o,$(SRCS))
TGTS := $(basename $(SRCS))

.PHONY : clean all

all: $(TGTS)

$(TGTS) : %: %.cxx
	$(Q)$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	$(Q)rm -f $(OBJS) $(TGTS) 


