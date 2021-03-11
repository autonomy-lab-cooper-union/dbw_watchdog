CXX = g++

src = $(wildcard ./src/*.cpp)
obj = $(src:.cpp=.o)
all: clean watchdog

watchdog: $(obj)
	$(CXX) -pthread -o $@ $^ /mnt/c/users/aligh/Desktop/hacker/IGVC/dbw_watchdog/src/libsocketcan/src/libsocketcan.o -latomic 
	$(RM) $(obj)

clean:
	$(RM) $(obj) watchdog
