#Variables at the top
FILES=main.cpp foo.cpp 
OBJECTS=main.o foo.o 
VERSION=c++17

# Commands go here
# `all` tells the makefile what to do when you run an empty `make` command
all: build

# Link the files together to an executable called cmd
# This can only run when the files named in OBJECTS exist, so it'll
# autmatically trigger the next rule below
build: $(OBJECTS) 
	g++ $(OBJECTS) -o cmd
	echo ""

# Build each individual .cpp file into a .o file 
%.o: %.cpp
	g++ -c -std=$(VERSION) $^ -o $@

clean:
	rm -rf *.o
	rm -rf *.gch
	rm cmd
