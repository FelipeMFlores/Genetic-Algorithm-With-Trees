SRC_DIR = ./src
BIN_DIR = ./bin
INCLUDE_DIR = ./include

all: compile

compile: $(SRC_DIR)/main.cpp $(SRC_DIR)/graph.cpp $(SRC_DIR)/tree.cpp $(SRC_DIR)/GeneticAlgorithm.cpp
	g++ -O2 -o $(BIN_DIR)/main  $^  -std=c++11 -Wall



clean:
	rm -rf bin/main 