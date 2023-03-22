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


test-all: test-problem1 test-problem2 test-problem3 test-problem4 test-problem5
	@echo "All Tests Ran"

# Problem 1
#
test-problem1 : problem1
	@echo "PROBLEM 1"
	@echo "echo \"+ 1.5 2\" | ./problem1"
	@echo "+ 1.5 2" | ./problem1 | awk '/[0,9]*/{print" Expected 3.5, Actual",$$0}'
	@echo "echo \"- 1.5 2\" | ./problem1"
	@echo "- 1.5 2" | ./problem1 | awk '/[0,9]*/{print" Expected -0.5, Actual",$$0}'
	@echo "echo \"x 1.5 2\" | ./problem1"
	@echo "x 1.5 2" | ./problem1 | awk '/[0,9]*/{print" Expected 3, Actual",$$0}'
	@echo "echo \"/ 1.5 2\" | ./problem1"
	@echo "/ 1.5 2" | ./problem1 | awk '/[0,9]*/{print" Expected 0.75, Actual",$$0}'
	@echo "echo \"< 1.5 2\" | ./problem1"
	@echo "< 1.5 2" | ./problem1 | awk '/[0,9]*/{print" Expected true, Actual",$$0}'
	@echo "echo \"> 1.5 2\" | ./problem1"
	@echo "> 1.5 2" | ./problem1 | awk '/[0,9]*/{print" Expected false, Actual",$$0}'
	@echo

problem1: problem1.cc
	$(link) $@ $^


# Problem 2
#
test-problem2 : problem2
	@echo "PROBLEM 2"
	@echo "./problem2 + 4 2"
	@./problem2 + 4 2 | awk '/[0,9]*/{print" Expected 6, Actual",$$0}'
	@echo "./problem2 x 4 2"
	@./problem2 x 4 2 | awk '/[0,9]*/{print" Expected 8, Actual",$$0}'
	@echo "./problem2 - 4 2"
	@./problem2 - 4 2 | awk '/[0,9]*/{print" Expected 2, Actual",$$0}'
	@echo "./problem2 / 4 2"
	@./problem2 / 4 2 | awk '/[0,9]*/{print" Expected 2, Actual",$$0}'
	@echo "./problem2 % 4 2"
	@./problem2 % 4 2 | awk '/[0,9]*/{print" Expected 0, Actual",$$0}'
	@echo "./problem2 ^ 4 2"
	@./problem2 ^ 4 2 | awk '/[0,9]*/{print" Expected 16, Actual",$$0}'
	@echo

problem2: problem2.cc
	$(link) $@ $^


# Problem 3
#
test-problem3 : problem3
	@echo "PROBLEM 3"
	./problem3
	@echo

problem3:  problem3.o problem3-test.o
	$(link) $@ $^

problem3-test.o: problem3_test.cc problem3.h
	$(compile) -o $@ $<

problem3.o: problem3.cc problem3.h
	$(compile) $<


# Problem 4
#
test-problem4 : problem4
	@echo "PROBLEM 4"
	./problem4
	@echo

problem4:  problem4.o problem4-test.o
	$(link) $@ $^

problem4-test.o: problem4_test.cc problem4.h
	$(compile) -o $@ $<

problem4.o: problem4.cc problem4.h
	$(compile) $<


# Problem 5
#
test-problem5 : problem5
	@echo "PROBLEM 5"
	./problem5

problem5:  problem5.o problem5-test.o
	$(link) $@ $^

problem5-test.o: problem5_test.cc problem5.h
	$(compile) -o $@ $<

problem5.o: problem5.cc problem5.h
	$(compile) $<


clean:
	@rm -f problem1 problem2 problem3 problem4 problem5 *.o
