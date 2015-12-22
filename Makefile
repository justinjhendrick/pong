default:
	clang++ -g -Weverything *.cpp -std=c++11 -lboost_system -lboost_thread

clean:
	rm a.out
