SRCS = $(wildcard *.c) $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)
PFILES = $(SRCS:.c=.P)
MODULE = run

CC     = g++
EXE    = $(MODULE).x

## Build with maximum gcc warning level
CFLAGS = -Wall -Wno-deprecated -Wno-return-type -Wno-char-subscripts $(DEBUG) $(OPT) $(EXTRACFLAGS)

.PHONY: clean 

#$(EXE): $(OBJS) $(SYSTEMC)/lib-$(TARGET_ARCH)/libsystemc.a 
#	$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) -o $@ $(OBJS) $(LIBS) 2>&1 | c++filt

$(EXE): $(OBJS) 
	$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) -o $@ $(OBJS) $(LIBS) 2>&1 | c++filt

%.o : %.c
	$(CC) $(CFLAGS) $(INCDIR) -c -MMD -o $@ $<
	@cp $*.d $*.P; \
	sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $*.d >> $*.P; \
	rm -f $*.d

clean:
	-rm -f $(OBJS) $(PFILES) *~ $(EXE) *.vcd *.wif *.isdb *.dmp *.P *.log

tidy:
	-rm -f $(OBJS) $(PFILES) *~ *.vcd *.wif *.isdb *.dmp *.P *.log