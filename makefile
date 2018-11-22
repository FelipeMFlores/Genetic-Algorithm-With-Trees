compile: main.cpp graph.cpp tree.cpp
	g++ -o main tree.cpp graph.cpp main.cpp  -std=c++11 -Wall

clean:
	rm -rf main 