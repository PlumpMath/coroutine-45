#makefile

#macro definition
CFLAGS = -c -Wall
OFLAGS = -o
CppCompile = g++
LIBLINK = -ldl -lpthread
exe = coroutine_svr_main


#OBJECT
OBJS =$(patsubst %.cpp,%.o,$(wildcard ../src/*.cpp))
OBJS += $(patsubst %.c,%.o,$(wildcard ../src/*.c))
HEADDIR=-I../include


VPATH =../include:../src

$(exe): $(OBJS)
	$(CppCompile) $(OFLAGS) $@ $^ $(HEADDIR)

*.o: *.cpp
	$(CppCompile) $(CFLAGS) $^ $(HEADDIR)  

.PHONY: clean
clean:
	rm $(exe) $(OBJS)
