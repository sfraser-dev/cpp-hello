#!/usr/bin/perl
use warnings;
use strict;
use feature qw(say);
use Cwd;

# compile to get .o object files
`clang++ -c test.cpp test-joe.cpp`;
# link files and produce .exe
`clang++ test.o test-joe.o -o test-exe-file.exe`;
# run (using full path name of the executable)
my $cwd = getcwd;
my $exe = $cwd."/test-exe-file.exe";
# print program output to screen
my $output = `$exe`;
say $output;