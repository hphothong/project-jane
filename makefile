# Compiler to use
CC = g++

# Compiler flags
CFLAGS = -g -Wall

# The default target for 'make'
default: shell

shell: lexer.o position.o token.o
						$(CC) $(CFLAGS) -o shell src/shell/shell.cpp lexer.o position.o token.o

lexer.o:
						$(CC) $(CFLAGS) -c src/compiler/lexer.cpp

position.o:
						$(CC) $(CFLAGS) -c src/compiler/position.cpp

token.o:
						$(CC) $(CFLAGS) -c src/compiler/tokens/*.cpp

.PHONY: clean

clean:
	$(RM) *.o *~ *.exe *.stackdump