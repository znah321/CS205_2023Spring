CXX = g++
TARGET = main
OBJ = $(TMP).o
TMP = exp03

$(TARGET): $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)

$(TMP).o: $(TMP).cpp
	$(CXX) -c $(TMP).cpp

.PHONY: clean
clean:
	rm -f *.o $(TARGET)