
BIN=./bin
SRC=./src
TEST=./test
CXR=$(BIN)/cxr
OBJS= $(SRC)/CXR.o $(SRC)/CmdLine.o $(SRC)/Stream.o $(SRC)/Tokenizer.o
TEST_OBJS= $(TEST)/Test.o $(TEST)/strings.o

cxr: setup $(OBJS)
	$(CXX) -o $(BIN)/$@ $(OBJS)

setup:
	mkdir -p $(BIN)

clean:
	rm $(SRC)/*.o $(TEST)/*.o

test: cxr test-setup $(TEST_OBJS)
	$(CXX) -o $(BIN)/$@ $(TEST_OBJS)

test-setup:
	cp $(SRC)/cxr_inc.h $(TEST)

$(TEST)/strings.o: $(TEST)/strings.cxr
	$(CXR) -i $(TEST)/strings.cxr -o $(TEST)/strings.cpp
	$(CXX) -c $(TEST)/strings.cpp -o $(TEST)/strings.o

