compile: main.cpp graph.cpp
	g++ -o main graph.cpp main.cpp  -std=c++11 -Wall

clean:
	rm -rf main 