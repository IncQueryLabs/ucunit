#
# Sample Makefile for uCUnit
#

#----------------------------------------------------
# Toolchain configuration
#----------------------------------------------------
# Compiler
CC:=gcc
CFLAGS:= -std='c99' -g -Wall -Wextra -pedantic -Wconversion

#Linker
LD:=gcc
LDFLAGS:=-g

# Simulator/Emulator
RUN:=cmd /C

# Clean up
RM:=rm -f

#----------------------------------------------------
# Files
#----------------------------------------------------
# Name of target file
TARGET:=Testsuite

# Sourcefiles
SRCS:=           \
../Testsuite.c   \
./System.c 	    \
../uCUnit-xml.c	\

# Objectfiles
OBJS:=           \
./System.o     \
../Testsuite.o \
../uCUnit-xml.o	\

# Dependencies

DEPS:=			\

#----------------------------------------------------
# Build all
#----------------------------------------------------
all: $(TARGET)

run: $(TARGET)
	echo 'Running $(TARGET)...'
	$(RUN) $(TARGET)
	
#----------------------------------------------------
# Linker stage
#----------------------------------------------------
$(TARGET):	$(OBJS)
	echo 'Linking...'
	$(CC) -o $(TARGET) $^ $(LDFLAGS)

#----------------------------------------------------
# Compiler
#----------------------------------------------------
%.obj: %.c
	echo 'Compiling...'
	$(CC) -o $(notdir $@) -c $< $(CFLAGS)
	
#----------------------------------------------------
# Clean Project
#----------------------------------------------------
clean:
	echo 'Running clean...'
	$(RM) $(TARGET)
	$(RM) ../**/*.o core
	$(RM) ../*.o core
	$(RM) *.xml core
	echo 'Clean finished.'
	