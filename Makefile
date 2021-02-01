all: clean watchdog

watchdog: test_estop.o
	g++ src/watchdog.cpp -o watchdog $<

test_estop.o:
	g++ -c src/test_estop.cpp

clean:
	$(RM) watchdog test_estop.o