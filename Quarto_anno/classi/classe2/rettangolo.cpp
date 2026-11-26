#include "Rettangolo.hpp"

Rettangolo::Rettangolo(){
	base=0;
	altezza=0;
}

void Rettangolo::setBase(float b){
	base=b;
}

void Rettangolo::setAltezza(float h){
	altezza=h;
}

float Rettangolo::getBase(){
	return base;
}

float Rettangolo::getAltezza(){
	return altezza;
}

float Rettangolo::area(){
	return base*altezza;
}

float Rettangolo::perimetro(){
	return 2*(base+altezza);
}