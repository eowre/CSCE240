cc = g++  # use g++ compiler

flags = -std=c++11  # compile with C++ 11 standard
flags += -Wall      # compile with all warnings
flags += -Wunused-const-variable
flags += -I .
flags += -g

link = $(cc) $(flags) -o  # final linked build to binary executable

compile = $(cc) $(flags) -c  # compilation to intermediary .o files

test-all: bin/test-bracket-op bin/test-add-gradebook bin/test-equals \
          bin/test-less-than
	./bin/test-bracket-op
	./bin/test-add-gradebook
	./bin/test-equals
	./bin/test-less-than

test-style : src/gradebook.cc inc/gradebook.h
	cpplint --root=. $^

bin/test-bracket-op : src/test_bracket_op.cc bin/gradebook.o
	$(link) $@ $^

bin/test-add-gradebook : src/test_add_gradebook.cc bin/gradebook.o
	$(link) $@ $^

bin/test-equals : src/test_equals.cc bin/gradebook.o
	$(link) $@ $^

bin/test-less-than : src/test_less_than.cc bin/gradebook.o
	$(link) $@ $^

bin/gradebook.o : src/gradebook.cc inc/gradebook.h
	$(compile) $< -o $@

clean:
	rm -f bin/*
