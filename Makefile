CXX = g++
CXXFLAGS = -Wall -g

PolynomialDemo: PolynomialDemo.o Polynomial.o
	$(CXX) $(CXXFLAGS) -o PolynomialDemo PolynomialDemo.o Polynomial.o
PolynomialDemo.o: PolynomialDemo.cpp Polynomial.h
	$(CXX) $(CXXFLAGS) -c PolynomialDemo.cpp
Polynomial.o: Polynomial.h 
