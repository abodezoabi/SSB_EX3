CXX = g++
 CXXFLAGS = -std=c++11 -Wall
TARGET = catan
TEST_TARGET = test
OBJS = Demo.o catan.o Board.o Player.o Vertex.o Edge.o card.o
TEST_OBJS = test.o catan.o Board.o Player.o Vertex.o Edge.o card.o

# Default target that builds the game and runs it
catan: $(TARGET)
	./$(TARGET)

# Compile and link the catan game target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile and link the test target
test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

# Compile individual source files
Demo.o: Demo.cpp
	$(CXX) $(CXXFLAGS) -c Demo.cpp

test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp

catan.o: catan.cpp catan.hpp
	$(CXX) $(CXXFLAGS) -c catan.cpp

Board.o: Board.cpp Board.hpp
	$(CXX) $(CXXFLAGS) -c Board.cpp

Player.o: Player.cpp Player.hpp
	$(CXX) $(CXXFLAGS) -c Player.cpp

Vertex.o: Vertex.cpp Vertex.hpp
	$(CXX) $(CXXFLAGS) -c Vertex.cpp

Edge.o: Edge.cpp Edge.hpp
	$(CXX) $(CXXFLAGS) -c Edge.cpp

card.o: card.cpp card.hpp
	$(CXX) $(CXXFLAGS) -c card.cpp

# Clean target to remove compiled files
clean:
	rm -f *.o $(TARGET) $(TEST_TARGET)
