EXE=reverse
CC=g++
CFLAGS=
LIBS=

SDIR=..
ODIR=obj

SRCS:=$(wildcard $(SDIR)/*.cpp)
OBJS:=$(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(SRCS))


all: $(EXE)

$(ODIR)/%.o: $(SDIR)/%.cpp | build
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
