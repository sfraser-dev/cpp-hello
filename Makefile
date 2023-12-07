CXX := clang++
CPPFLAGS := -c -g -Wall 

all: hello.exe hello2.exe compiler-language-info.exe test.exe

hello.exe: hello.o
	$(CXX) $< -o $@

hello.o:
	$(CXX) $(CPPFLAGS) hello.cpp -I.

hello2.exe: hello2.o hello2.h
	$(CXX) $< -o $@

hello2.o:
	$(CXX) $(CPPFLAGS) hello2.cpp -I.

compiler-language-info.exe: compiler-language-info.o 
	$(CXX) $< -o $@

compiler-language-info.o:
	$(CXX) $(CPPFLAGS) compiler-language-info.cpp -I.

# link the object code to other libraries (eg: std c++ library) and output executable
test.exe: test.o test-joe.o
	$(CXX) $^ -o $@

# compile sourde to object code
test.o: test.cpp test-joe.h 
	$(CXX) $(CPPFLAGS) test.cpp -I.

# compile sourde to object code
test-joe.o: test-joe.cpp test-joe.h
	$(CXX) $(CPPFLAGS) test-joe.cpp -I.

clean:
	$(RM) *.o *.exe
