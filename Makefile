CC = gcc
CXX = g++
CFLAGS = -Wall
CXXFLAGS = -Wall

TARGET = testUTF8string_lab5
OBJ = testUTF8string_lab5.o UTF8string.o utf8.o

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
	
clean: 
	-rm -f *.o
	-rm -f $(TARGET)