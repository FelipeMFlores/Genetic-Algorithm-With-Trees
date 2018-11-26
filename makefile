SRC_DIR = ./src
BIN_DIR = ./bin
INCLUDE_DIR = ./include

all: compile

compile: $(SRC_DIR)/main.cpp $(SRC_DIR)/graph.cpp $(SRC_DIR)/tree.cpp
	g++ -o $(BIN_DIR)/main  $^  -std=c++11 -Wall



clean:
	rm -rf bin/main 