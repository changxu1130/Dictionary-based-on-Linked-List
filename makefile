# Define C compiler & flags
CC = gcc
CFLAGS = -Wall -g
# Define libraries to be linked (for example -lm)
LDLIBS = -lm

# Define set of implementation source files and object files
SRC = driver.c data.c dict.c 
# OBJ is the same as SRC, just replace .c with .o
OBJ = $(SRC:.c=.o)
 
# Define the executable name(s)
EXE = combination

all: dict1 dict2
dict1: driver.o data.o dict.o
	gcc -g -o dict1 driver.o data.o dict.o

dict2: driver.o data.o dict.o
	gcc -g -o dict2 driver.o data.o dict.o

# Other targets specify how to create .o files and what they rely on
driver.o: driver.c 
	gcc -g -c driver.c 

data.o: data.c data.h 
	gcc -g -c data.c 

dict.o: dict.c dict.h  
	gcc -g -c dict.c 

clean:
	rm -f *.o dict1 dict2 

