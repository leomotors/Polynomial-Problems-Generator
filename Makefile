CXX := g++

CPPSTANDARD := c++17

CXXFLAGS := -Wall -Wextra -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wwrite-strings -Wcast-qual -Wunreachable-code

SOURCE_FILES := $(wildcard */*.cpp)

HEADER_FOLDER := ./header

main: $(SOURCE_FILES)
	$(CXX) $(CXXFLAGS) -std=$(CPPSTANDARD) -O2 -o main $(SOURCE_FILES) -I$(HEADER_FOLDER)