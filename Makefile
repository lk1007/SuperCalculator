CC=g++
all: main
	./main
listEx1: listEx1.o
	$(CC) $^ -o $@
lists: lists.o
	$(CC) $^ -o $@
main: main.o func.o func.h
	$(CC) $^ -o $@
%.o: %.cpp
	$(CC) $^ -c
clean:
	rm *.hi
	rm *.o
	rm out
	rm lists