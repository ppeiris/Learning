#############################################################
#
# This program will compile the program that pass to it and
# copy the data file from ../data/ to bin/ directory
# How To use this make file: make -e PROG="program_name"
#
#############################################################

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFALGS = -Wall $(DEBUG)
BIN = bin
DATADIR = ../data
DATA_FILE = IntegerArray.txt

# Check for PROG to compile
ifndef PROG
$(info How to use this make command)
$(info make -e PROG="program_name")
# $(error PROG is not set)
endif

# make the bin/ if doesn't exists
$(info ************  building $(PROG) ************)
$(info + making $(BIN) directory)
$(shell mkdir -p $(BIN))

# copy the data file in to bin/ if it is not there
# ifeq ($(wildcard $(BIN)/$(DATA_FILE)),)
# $(info + copying data file to $(BIN))
# $(shell cp $(DATADIR)/$(DATA_FILE) $(BIN)/)
# endif


# compiling
all: $(PROG)

$(PROG): $(PROG).o
	$(CC) $(PROG).o -o $(BIN)/$(PROG)

$(PROG).o: $(PROG).C
	$(CC) $(CFLAGS) $(PROG).C

clean:
	\rm -rf bin *.o

