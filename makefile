# Compiler to use
CC = g++

# Compiler flags
CFLAGS = -g -Wall

# The default target for 'make'
default: shell

shell: lexer.o token.o
					$(CC) $(CFLAGS) -o shell src/shell/shell.cpp lexer.o token.o

lexer.o:
					$(CC) $(CFLAGS) -c src/compiler/lexer.cpp

token.o:
					$(CC) $(CFLAGS) -c src/compiler/tokens/*.cpp

.PHONY: clean

clean:
	$(RM) *.o *~ *.exe *.stackdump