cc = g++  # use g++ compiler

flags = -std=c++11  # compile with C++ 11 standard
flags += -Wall      # compile with all warnings
flags += -I .
flags += -g

link = $(cc) $(flags) -o  # final linked build to binary executable

compile = $(cc) $(flags) -c  # compilation to intermediary .o files

test-all: bin/test-add-and-get-grade bin/test-add-gradebook bin/test-equals \
          bin/test-get-gpa bin/test-get-max bin/test-less-than
	./bin/test-add-and-get-grade
	./bin/test-get-gpa
	./bin/test-get-max
	./bin/test-add-gradebook
	./bin/test-equals
	./bin/test-less-than

test-style : src/gradebook.cc inc/gradebook.h
	cpplint --root=. $^

bin/test-add-and-get-grade : src/test_add_and_get_grade.cc bin/gradebook.o
	$(link) $@ $^

bin/test-get-gpa : src/test_get_gpa.cc bin/gradebook.o
	$(link) $@ $^

bin/test-get-max : src/test_get_max.cc bin/gradebook.o
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
