# Define the compiler and the flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Define the target executable
TARGET = m

# Define the source and header files
SRCS = m.cpp player.cpp board.cpp hexagon.cpp edge.cpp vertex.cpp 
HDRS = player.hpp board.hpp catan.hpp

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to build the object files
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: clean
