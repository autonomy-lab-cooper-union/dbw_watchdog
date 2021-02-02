CXX = g++

src = $(wildcard ./src/*.cpp)
obj = $(src:.cpp=.o)

all: clean watchdog

watchdog: $(obj)
	$(CXX) -pthread -o $@ $^
	$(RM) $(obj)

clean:
	$(RM) $(obj) watchdog
