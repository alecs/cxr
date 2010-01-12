
BIN=./bin
SRC=./src
TEST=./test-proj
CXR=$(BIN)/cxr
OBJS= $(SRC)/CXR.o $(SRC)/CmdLine.o $(SRC)/Stream.o $(SRC)/Tokenizer.o
TEST_OBJS= $(TEST)/Test.o $(TEST)/strings.o

cxr: setup $(OBJS)
	$(CXX) -o $(BIN)/$@ $(OBJS)

setup:
	mkdir -p $(BIN)

clean:
	rm $(SRC)/*.o

test: cxr $(TEST_OBJS)
	$(CXX) -o $(BIN)/$@ $(TEST_OBJS)
	
$(TEST)/strings.o: $(TEST)/strings.cxr
	$(CXR) -i $(TEST)/strings.cxr -o $(TEST)/strings.cpp
	$(CXX) -c $(TEST)/strings.cpp -o $(TEST)/strings.o

