ofiles = main.o Citizens.o Status.o Unlisted.o Enlisted.o Stationed.o Fighting.o Dead.o RevolutionCommand.o
main: $(ofiles)
	g++ -o main $(ofiles)

main.o: main.cpp
	g++ -c main.cpp

Citizens.o: Citizens.cpp	
	g++ -c Citizens.cpp

Status.o: Status.cpp
	g++ -c Status.cpp

Unlisted.o: Unlisted.cpp
	g++ -c Unlisted.cpp

Enlisted.o: Enlisted.cpp
	g++ -c Enlisted.cpp

Stationed.o: Stationed.cpp
	g++ -c Stationed.cpp

Fighting.o: Fighting.cpp
	g++ -c Fighting.cpp

Dead.o: Dead.cpp
	g++ -c Dead.cpp

RevolutionCommand.o:RevolutionCommand.cpp Command.h
	g++ -c RevolutionCommand.cpp

run: main
	./main

clean:
	rm *.o main