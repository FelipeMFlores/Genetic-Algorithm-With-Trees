SRC_DIR = ./src
BIN_DIR = ./bin
INCLUDE_DIR = ./include

all: compile

compile: $(SRC_DIR)/main.cpp $(SRC_DIR)/graph.cpp $(SRC_DIR)/tree.cpp $(SRC_DIR)/GeneticAlgorithm.cpp
	g++ -O2 -o $(BIN_DIR)/main  $^  -std=c++11 -Wall

run: admv1 admv2 admv3 admv4 admv5 admv6 admv7 admv8 admv9 admv10 

admv1:
	bin/main result01.txt 50 3 1 7200 < admv/admv01
admv2:
	bin/main result02.txt 50 3 1 7200 < admv/admv02
admv3:
	bin/main result03.txt 50 3 1 7200 < admv/admv03
admv4:
	bin/main result04.txt 50 3 1 7200 < admv/admv04
admv5:
	bin/main result05.txt 50 3 1 7200 < admv/admv05
admv6:
	bin/main result06.txt 50 3 1 7200 < admv/admv06
admv7:
	bin/main result07.txt 50 3 1 7200 < admv/admv07
admv8:
	bin/main result08.txt 50 3 1 7200 < admv/admv08
admv9:
	bin/main result09.txt 50 3 1 7200 < admv/admv09
admv10:
	bin/main result10.txt 50 3 1 7200 < admv/admv10

clean:
	rm -rf bin/main 
