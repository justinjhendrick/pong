UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIBS = -lboost_system -lboost_thread
endif
ifeq ($(UNAME_S),Darwin)
	LIBS = -lboost_system-mt -lboost_thread-mt
endif

default:
	clang++ -O3 -Weverything *.cpp -std=c++11 $(LIBS) -o pong

clean:
	rm a.out
