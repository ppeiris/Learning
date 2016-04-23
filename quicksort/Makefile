CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFALGS = -Wall $(DEBUG)
BIN = bin

$(shell mkdir -p $(BIN))

DATA_FILE2 = IntegerArray.txt
DATA_FILE1 = points.txt

all: quicksort quicksort_array

quicksort: quicksort.o
	$(CC) quicksort.o -o $(BIN)/quicksort

quicksort.o: quicksort.C
	$(CC) $(CFLAGS) quicksort.C


quicksort_array: quicksort_array.o
	$(CC) quicksort_array.o -o $(BIN)/quicksort_array

quicksort_array.o: quicksort_array.C
	$(CC) $(CFLAGS) quicksort_array.C



$(shell cp $(DATA_FILE2) $(BIN))
$(shell cp $(DATA_FILE1) $(BIN))

clean:
	\rm -rf bin *.o *~quicksort
