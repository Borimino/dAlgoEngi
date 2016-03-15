#!/bin/bash

for (( i = 1; i <= 3001; i+=300 )); do
	sed "s/\(int m =\) \([0-9][0-9]*\)\(;\)/\1 $i\3/" matrixNaive.cpp > matrixNaiveTMP1.cpp
	sed "s/\(int n =\) \([0-9][0-9]*\)\(;\)/\1 $i\3/" matrixNaiveTMP1.cpp > matrixNaiveTMP2.cpp
	sed "s/\(int p =\) \([0-9][0-9]*\)\(;\)/\1 $i\3/" matrixNaiveTMP2.cpp > matrixNaiveTMP3.cpp

	g++ -O3 matrixNaiveTMP3.cpp
	perf stat ./a.out > /dev/null

	rm matrixNaiveTMP1.cpp matrixNaiveTMP2.cpp matrixNaiveTMP3.cpp
done
