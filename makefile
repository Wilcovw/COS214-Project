main: *.o
	g++ -o main *.o

*.o: *.cpp
	g++ -c *.cpp

run: main
	./main

clean:
	rm *.o main