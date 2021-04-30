EXE=threading
CC=gcc
CFLAGS=
LIBS=

SDIR=..
ODIR=obj

SRCS:=$(wildcard $(SDIR)/*.c)
OBJS:=$(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))


all: $(EXE)

$(ODIR)/%.o: $(SDIR)/%.c | build
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

build:
	@echo "Building $(EXE)"
	@if [ ! -d $(ODIR) ]; then \
		mkdir $(ODIR); \
	fi

clean:
	@echo "Cleaning"
	@rm -fr $(ODIR) 
	@rm -f $(EXE)

.PHONY: all clean build 
