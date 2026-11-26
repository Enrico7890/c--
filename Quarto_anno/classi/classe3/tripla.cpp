#include "Tripla.hpp"

Tripla::Tripla(){
	a=0;
	b=0;
	c=0;
}

void Tripla::setA(float x){
	a=x;
}

void Tripla::setB(float x){
	b=x;
}

void Tripla::setC(float x){
	c=x;
}

float Tripla::getA(){
	return a;
}

float Tripla::getB(){
	return b;
}

float Tripla::getC(){
	return c;
}

float Tripla::somma(){
	return a+b+c;
}

float Tripla::prodotto(){
	return a*b*c;
}

float Tripla::media(){
	return (a+b+c)/3;
}