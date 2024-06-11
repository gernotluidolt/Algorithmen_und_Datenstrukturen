# Define the compiler to use
CXX = g++

# Define compiler flags
CXXFLAGS = -Wall -g

# Define the target executable
TARGET = main

# Define the source files
SRCS = main.cpp HashTable.cpp

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to build the object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean up the build directory
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: clean
