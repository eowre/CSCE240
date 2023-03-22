CC = g++  # use g++ compiler

FLAGS = -std=c++17  # compile with C++ 17 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -I .       # compile with inc directory on #include system path
FLAGS += -g

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files

test_sum_finder : bin/test_sum_finder.o bin/sum_finder.o
	$(LINK) $@ $^

test_style : src/sum_finder.cc inc/sum_finder.h
	cpplint --root=. $^

bin/test_sum_finder.o : src/test_sum_finder.cc inc/test_sum_finder.h \
                        inc/sum_finder.h
	$(COMPILE) -o $@ $<

bin/sum_finder.o : src/sum_finder.cc inc/sum_finder.h
	$(COMPILE) -o $@ $<

clean:
	rm -f bin/* test_sum_finder
