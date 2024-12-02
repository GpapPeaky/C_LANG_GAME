SRCP = src/
BINP = bin/

SRC =\
$(SRCP)PM_Main.cpp\
$(SRCP)PM_Move.cpp

all:
	g++ $(SRC) -o $(BINP)PeakyMove