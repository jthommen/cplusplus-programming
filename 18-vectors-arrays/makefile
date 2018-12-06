# Example makefile compiling the FLTK course code :)

# Let FLTK return the compiler
CXX = $(shell fltk-config --cxx)

# Save lib path in variable
LIB=../lib

# Let FLTK set the system specific compiler flags
CXXFLAGS = $(shell fltk-config --cxxflags) -g -std=c++11 -I $(LIB)

# Set app name
FNAME=drill02

# Set dependencies needed to compile
HEADERS = $(LIB)/Graph.h $(LIB)/GUI.h $(LIB)/Simple_window.h $(LIB)/std_lib_facilities.h $(LIB)/Window.h
DEPS = $(LIB)/Graph.cpp $(LIB)/Window.cpp $(LIB)/GUI.cpp $(LIB)/Simple_window.cpp


app:
	$(CXX) $(CXXFLAGS) $(FNAME).cpp -o $(FNAME)
