# a collection of distict files, not a single project
CXX := clang++
CPPFLAGS := -g -Wall 
LDFLAGS :=
INCLUDEDIRS := -I.

all: hello.exe hello2.exe compiler-language-info.exe test.exe

# $@ is the target file, $< is the first dependency only, $^ is all dependencies
hello.exe: hello.o
	$(CXX) $(LDFLAGS) $< -o $@

hello.o: hello.cpp
	$(CXX) $(CPPFLAGS) -c $< $(INCLUDEDIRS)

hello2.exe: hello2.o hello2.h
	$(CXX) $(LDFLAGS) $< -o $@

hello2.o: hello2.cpp
	$(CXX) $(CPPFLAGS) -c $< $(INCLUDEDIRS)

compiler-language-info.exe: compiler-language-info.o 
	$(CXX) $(LDFLAGS) $< -o $@

compiler-language-info.o: compiler-language-info.cpp
	$(CXX) $(CPPFLAGS) -c $< $(INCLUDEDIRS)

# link the object code to other libraries (eg: std c++ library) and output executable
test.exe: test.o test-joe.o
	$(CXX) $(LDFLAGS) $^ -o $@

# compile sourde to object code
test.o: test.cpp test-joe.h 
	$(CXX) $(CPPFLAGS) -c $< $(INCLUDEDIRS)

# compile sourde to object code
test-joe.o: test-joe.cpp test-joe.h
	$(CXX) $(CPPFLAGS) -c $< $(INCLUDEDIRS)

# use wildcard style to stop complaints if file isn't there to be deleted
.PHONY: clean
clean:
	rm -f $(wildcard *.o) $(wildcard *.exe)
