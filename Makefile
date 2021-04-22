CXX := g++

CPPSTANDARD := c++17

CXXFLAGS := -Wall -Wextra -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wwrite-strings -Wcast-qual -Wunreachable-code

SOURCE_FILES := ./src/main.cpp ./src/polynomial.cpp ./src/polyrand.cpp ./src/generator.cpp ./src/utilsMethod.cpp ./src/grader.cpp ./src/SafeInput.cpp ./src/pSettings.cpp

HEADER_FOLDER := ./header

main: $(SOURCE_FILES)
	$(CXX) $(CXXFLAGS) -std=$(CPPSTANDARD) -o main $(SOURCE_FILES) -I$(HEADER_FOLDER) 