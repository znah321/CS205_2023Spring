CXX = gcc
TARGET = calculator 
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

CXXFLAGS = -c

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *.o $(TARGET)
