CXX = g++

src = $(wildcard ./src/*.cpp)
src += $(wildcard ./src/*.c)
obj = $(src:.cpp=.o)
obj += $(src:.c=.o)

all: clean watchdog

watchdog: $(obj)
	$(CXX) -pthread -o $@ $^ -latomic
	$(RM) $(obj)

clean:
	$(RM) $(obj) watchdog
