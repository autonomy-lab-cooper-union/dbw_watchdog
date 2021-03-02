CXX = g++

src = $(wildcard ./src/*.cpp)
src += libsocketcan.c
obj = $(src:.cpp=.o)
obj += libsocketcan.o
all: clean watchdog

watchdog: $(obj)
	$(CXX) -pthread -o $@ $^ -latomic
	$(RM) $(obj)

clean:
	$(RM) $(obj) watchdog
