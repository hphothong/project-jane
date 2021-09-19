# Compiler to use
CC = g++

# Compiler flags
CFLAGS = -g -Wall

# The default target for 'make'
default: shell

shell:
				$(CC) $(CFLAGS) -o shell src/shell/shell.cpp

.PHONY: clean

clean:
	$(RM) *.o *~ *.exe