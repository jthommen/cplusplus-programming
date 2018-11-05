# Example makefile compiling the FLTK course code :)

# Let FLTK return the compiler
CXX = $(shell fltk-config --cxx)

# Let FLTK set the system specific compiler flags
CXXFLAGS = $(shell fltk-config --cxxflags) -g -std=c++11 -I ../lib

# Set app name
FNAME=drill

# Set dependencies needed to compile
DEPS = ../lib/Graph.cpp ../lib/Window.cpp ../lib/GUI.cpp ../lib/Simple_window.cpp

# FLTK linker configurations
LINKFLTK = $(shell fltk-config --ldstaticflags)
LINKFLTK_GL = $(shell fltk-config --use-gl --ldstaticflags)
LINKFLTK_IMG = $(shell fltk-config --use-images --ldstaticflags)

app: $(FNAME).cpp
	$(CXX) $(CXXFLAGS) $(DEPS) $(FNAME).cpp -o $(FNAME) $(LINKFLTK) $(LINKFLTK_IMG)$
