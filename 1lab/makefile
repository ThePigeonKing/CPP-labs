run: main.cpp
	g++ -g -fsanitize=address main.cpp struct.cpp -o main.out
	./main.out

rerun: main.out
	./main.out

dbg: main.cpp
	g++ -g -fsanitize=address main.cpp struct.cpp -o main.out
	lldb main.out

tests: main.cpp
	@g++ -g -fsanitize=address main.cpp struct.cpp -o main.out
	@cat test1 | ./main.out
	@cat test2 | ./main.out
	@cat test3 | ./main.out

format: main.cpp
	clang-format -i -style=google *.cpp *.h

clear: *.out
	rm *.out