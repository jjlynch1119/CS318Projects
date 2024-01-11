//Jeremy Lynch, CS318, P01, This program generates "walks" and calculates values from them. 

#include "Walk.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

ostream& operator<<(ostream& os, const Walk& w);

int main() {
	int points;
	int numWalks;
	vector<Walk> walks;
	srand(time(0));

	cout << fixed << setprecision(2);
	cout << "*** Random Walks ***\n\n";
	cout << "This program generates a number of random walks.\n\n";
	cout << "Enter number of points for each walk: ";
	cin >> points;
	cout << "\nEnter number of walks to generate: ";
	cin >> numWalks;
	cout << "\n\n";

	for (int i = 0; i < numWalks; i++) {

		Walk curr;
		for (int j = 0; j < points; j++) {
			curr.walkAgain();
			cout << "Walk/Step: " << i + 1 << "/" << j + 1 << ":" << curr << " \n";
		}

		walks.push_back(curr);
		cout << "\n";
	}

	sort(walks.begin(), walks.end(), [](Walk& lhs, Walk& rhs) {
		return lhs.getDistance() < rhs.getDistance();
	});

	cout << "Walks Sorted: \n";

	double totalDist = 0;
	for (auto it = walks.begin(); it != walks.end(); it++) {
		cout << "    Point: " << it->getX() << ", " << it->getY() << " Distance : " << it->getDistance() << "\n";
		totalDist += it->getDistance();
	}

	cout << "\nAverage Distance: " << totalDist / walks.size();

	cout << "\n\nShortest Distance/Walk: " << walks.at(0).getDistance();
	
	double median = 0;
	if (walks.size() % 2 == 0)	
		median = (walks.at((walks.size() / 2) - 1).getDistance() + (walks.at(walks.size() / 2).getDistance())) / 2;
	else
		median = walks.at(walks.size() / 2).getDistance();
		

	cout << "\nMedian Distance/Walk: " << median;

	cout << "\nLongest Distance/Walk: " << walks.at(walks.size() - 1).getDistance() << "\n";

	return 0;
}

ostream& operator<<(ostream& os, const Walk& w) {
	cout << "Point: " << w.getX() << ", " << w.getY() << " Distance: " << w.getDistance();
	return os;
}