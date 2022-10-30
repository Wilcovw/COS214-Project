main: *.o
	g++ -std=c++11 -o main *.o

*.o: *.cpp
	g++ -c -std=c++11 -static *.cpp

run: main
	./main
    
clean:
	rm *.o main