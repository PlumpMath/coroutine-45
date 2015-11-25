#makefile
#coroutine_svr project makfile

#macro definition
COMPILE = g++
WARNING = -Wall
CFLAGS = -c
OFLAGS = -o

#lib 
LIBLINK = -ldl -lpthread

#visual path
VPATH = ../include:../src

#exe file
EXE = coroutine_svr_main

#OBJECT
OBJS =$(notdir $(patsubst %.cpp,%.o,$(wildcard ../src/*.cpp)))

#INCLUDE DIRECTORY.
INC=-I../include

#link all .o to exe file.
$(EXE): $(OBJS)
	$(COMPILE) $(OFLAGS) $@ $^

#compile all cpp file to .o file.
%.o: %.cpp
	$(COMPILE) $(WARNING) $(INC) $(CFLAGS) $^

.PHONY: clean
clean:
	@rm -rf $(exe) $(OBJS)
