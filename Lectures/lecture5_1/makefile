CC = g++   # use g++ compiler

FLAGS = -std=c++17  # compile with C++ 17 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -I inc     # compile with inc directory appended to path

LINK = $(CC) $(FLAGS) -o        # compile and link for executable binary
COMPILE = $(CC) $(FLAGS) -c -o  # compile into intermediary binary


# Person library
#
bin/test1 : bin/person.o bin/test_person.o
	$(LINK) $@ $^

bin/test_person.o : src/test_person.cc inc/test_person.h inc/person.h
	cpplint --root=../ $^
	$(COMPILE) $@ $<

bin/person.o : src/person.cc inc/person.h
	cpplint --root=../ $^
	$(COMPILE) $@ $<


# Rational library
#
bin/test2 : bin/rational.o bin/test_rational.o
	$(LINK) $@ $^

bin/test_rational.o : src/test_rational.cc inc/test_rational.h inc/rational.h
	cpplint --root=../ $^
	$(COMPILE) $@ $<

bin/rational.o : src/rational.cc inc/rational.h
	cpplint --root=../ $^
	$(COMPILE) $@ $<


clean:
	@rm -f bin/*
