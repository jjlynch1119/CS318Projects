//Jeremy Lynch, CS318, P01, This program generates "walks" and calculates values from them. 

#pragma once

#ifndef _WALKS_H_
#define _WALKS_H_

class Walk {
	private:
		double x;
		double y;
		double distance;
	public:
		Walk();
		double getX() const;
		double getY() const;
		double getDistance() const;
		void setX(double x);
		void setY(double y);
		void setDistance(double distance);
		int generateAngle();
		int generateLength();
		double convertToRadians(double degree);
		void walkAgain();
};

#endif