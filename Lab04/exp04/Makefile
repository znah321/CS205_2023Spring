main: main.o fib.o
	g++ -o main main.o fib.o

main.o: main.cpp
	g++ main.cpp -c

fib.o: fib.cpp
	g++ fib.cpp -c

.PHONY: clean
clean:
	rm -f *.o main