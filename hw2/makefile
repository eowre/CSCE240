## style guide: https://style-guides.readthedocs.io/en/latest/makefile.html
#

cc = g++  # use g++ compiler

# Make a compiler variable for C++ 17 standard flag named flags
flags = -std=c++17
# Append the "all warnings" flag to variable
flags += -Wall
# Include GDB debugger info
flags += -g
# Include PWD on compiler include path
flags += -I .

# Create link variable to compile, assemble, link, and name
link = $(cc) $(flags) -o

# Create variable compile to compile, assemble, but not link
compile = $(cc) $(flags) -c


test-all: test-comp-geo
	@./test-comp-geo 0
	@./test-comp-geo 1
	@./test-comp-geo 2
	@./test-comp-geo 3
	@./test-comp-geo 4
	@./test-comp-geo 5
	@./test-comp-geo 6

test-comp-geo-style: comp_geo.cc comp_geo.h
	cpplint --root=. $^

test-comp-geo: comp-geo.o test-comp-geo.o
	$(link) $@ $^
test-comp-geo.o : test_comp_geo.cc comp-geo.o
	$(compile) $< -o $@

comp-geo.o : comp_geo.cc comp_geo.h
	$(compile) $< -o $@

clean:
	@rm -f test-comp-geo *.o
