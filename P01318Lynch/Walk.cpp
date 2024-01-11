//Jeremy Lynch, CS318, P01, This program generates "walks" and calculates values from them. 

#define _USE_MATH_DEFINES
#include "Walk.h"
#include <cstdlib>
#include <cmath>

//y = distance * sin(angle)
//x = distance * cos(angle)


Walk::Walk() {
	distance = 0.0;
	x = 0.0;
	y = 0.0;
}

double Walk::getX() const{
	return x;
}

double Walk::getY() const{
	return y;
}

double Walk::getDistance() const{
	return distance;
}

void Walk::setX(double x) {
	this->x = x;
}

void Walk::setY(double y) {
	this->y = y;
}

void Walk::setDistance(double distance) {
	this->distance = distance;
}

int Walk::generateAngle() {
	return rand() % 359 + 1;
}

int Walk::generateLength() {
	return rand() % 100 + 1;
}

double Walk::convertToRadians(double degree) {
	return degree * (M_PI / 180.0);
}

void Walk::walkAgain() {
	double angle = convertToRadians(generateAngle());
	int length = generateLength();
	x += length * sin(angle);
	y += length * cos(angle);
	distance += length;
}

