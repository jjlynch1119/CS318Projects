//Jeremy Lynch, CS318, P04 - Dorothy and Emeralds, Use a priority queue to calculate # of emeralds Dorothy can gather in a set amount of time

#include <iostream>
#include <queue>
#include <random>
	
using namespace std;

int main()
{
	srand(time(0));

	int baskets{};
	int minutes{};
	int emeralds{};
	priority_queue<int> pq;

	cout << "**** Dorothy and Emeralds ****";
	cout << "\n\nEnter the number of baskets: ";
	cin >> baskets;
	cout << "\nEnter the number of minutes: ";
	cin >> minutes;

	for (int i = 0; i < baskets; i++)
	{
		pq.push(rand() % 100);
		//pq.push(100);
		//pq.push(25);
	}

	while(minutes > 0)	{
		emeralds += pq.top();
		pq.push(pq.top() / 2);
		pq.pop();
		
		minutes--;
	}

	cout << "\nDorothy has gathered " <<  emeralds << " emeralds!";
}