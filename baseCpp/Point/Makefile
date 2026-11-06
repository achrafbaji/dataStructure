prog: main.o point.o
	g++ main.o point.o -o prog

main.o: main.cpp point.h
	g++ -c main.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

clean:
	rm -f *.o prog