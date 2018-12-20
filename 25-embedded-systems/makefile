# Example makefile compiling the FLTK course code :)

# Let FLTK return the compiler
CXX = $(shell fltk-config --cxx)

# Save lib path in variable
LIB=../lib

# Let FLTK set the system specific compiler flags
CXXFLAGS = $(shell fltk-config --cxxflags) -g -std=c++14 -I $(LIB)

# Set app name
FNAME=drill

# Set dependencies needed to compile
HEADERS = $(LIB)/Matrix.h $(LIB)/MatrixIO.h
# DEPS =


app:
	$(CXX) $(CXXFLAGS) $(FNAME).cpp -o $(FNAME)
