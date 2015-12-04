#makefile
#coroutine_svr project makfile

#macro definition
COMPILE = g++
WARNING = -Wall
CFLAGS = -c
OFLAGS = -o

#lib 
LIBLINK = -lcolib -lpthread -ldl -lhiredis

#lib directory
LIBDIR = -L../../libco-master/lib -L../lib

#visual path
VPATH = ../include:../src

#exe file
EXE = coroutine_svr_main

#OBJECT
OBJS =$(notdir $(patsubst %.cpp,%.o,$(wildcard ../src/*.cpp)))
OBJS +=$(notdir $(patsubst %.c,%.o,$(wildcard ../src/*.c)))

#INCLUDE DIRECTORY.
INC=-I../include -I../../libco-master/

#link all .o to exe file.
$(EXE): $(OBJS)
	$(COMPILE) $(OFLAGS) $@ $^ $(LIBDIR) $(LIBLINK)

#compile all cpp file to .o file.
%.o: %.cpp
	$(COMPILE) $(WARNING) $(INC) $(CFLAGS) $^

%.o: %.c
	$(COMPILE) $(WARNING) $(INC) $(CFLAGS) $^

.PHONY: clean
clean:
	@rm -rf $(exe) $(OBJS)
