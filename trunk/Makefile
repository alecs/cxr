
BIN=./bin
SRC=./src
OBJS= $(SRC)/CXR.o $(SRC)/CmdLine.o $(SRC)/Stream.o $(SRC)/Tokenizer.o

cxr: setup $(OBJS)
	$(CXX) -o $(BIN)/$@ $(OBJS)

setup:
	mkdir -p $(BIN)

clean:
	rm $(SRC)/*.o
