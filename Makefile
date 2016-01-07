default:
	clang++ -O3 -Weverything *.cpp -std=c++11 -lboost_system -lboost_thread -o pong

clean:
	rm a.out
