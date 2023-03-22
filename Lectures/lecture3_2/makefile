## style guide: https://style-guides.readthedocs.io/en/latest/makefile.html
#

cc = g++  # use g++ compiler

# Make a compiler variable for C++ 17 standard flag named flags
flags = -std=c++17
# Append the "all warnings" flag to variable
flags += -Wall
# Include GDB debugger info
flags += -g
# Use optimization level 3
flags += -O3

# Create link variable to compile, assemble, link, and name
link = $(cc) $(flags) -o

# Create variable compile to compile, assemble, but not link
compile = $(cc) $(flags) -c

intro : intro.cc
	$(link) $@ $^

separate : separate.o
	$(link) $@ $^

separate.o : separate.cc separate.h
	$(compile) $<  # notice the new placeholder 

pass_by_ref : pass_by_ref.o
	$(link) $@ $^

pass_by_ref.o : pass_by_ref.cc pass_by_ref.h
	$(compile) $<

overload : overload.o
	$(link) $@ $^

overload.o : overload.cc overload.h
	$(compile) $<

default : default.o
	$(link) $@ $^

default.o : default.cc default.h
	$(compile) $<

all : intro separate pass_by_ref overload default

clean:
	@rm -f intro separate pass_by_ref overload default *.o 
