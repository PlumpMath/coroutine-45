
CFLAGS = -c -Wall
OFLAGS = -o
CppCompile = g++
LIBLINK = -ldl -lpthread
exe = coroutine_svr_main


#OBJECT
OBJS =$(patsubst %.cpp,%.o,$(wildcard ../src/*.cpp))
OBJS += $(patsubst %.c,%.o,$(wildcard ../src/*.c))

VPATH =../include:../src

$(exe): $(OBJS)
	$(CppCompile) $(OFLAGS) $@ $^ 

*.o: *.cpp
	$(CppCompile) $(CFLAGS) $@ $^ 

.PHONY: clean
clean:
	rm $(exe) $(OBJS)
