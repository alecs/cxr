
OBJS= CXR.o CmdLine.o Stream.o Tokenizer.o
BIN=./bin

cxr: setup $(OBJS)
	$(CXX) -o $(BIN)/$@ $(OBJS)

setup:
	mkdir -p $(BIN)

clean:
	rm *.o
