CC=g++
CFLAGS=-Wall -Wpedantic -O2 -std=c++11
SOURCES=$(wildcard tp1/lib/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=tp
TEST=test

all: $(SOURCES) $(EXECUTABLE) $(TEST)

rebuild: clean all

$(TEST): tp1/tests.cpp $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) tp1/tests.cpp -o $@

$(EXECUTABLE): tp1/main.cpp $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) tp1/main.cpp -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJECTS)
	rm $(EXECUTABLE)
	rm $(TEST)
