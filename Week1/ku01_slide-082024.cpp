// ku01_next.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;




int main()
{

	int loop,cp=0;
	

	cin >> loop;
	vector<int> arr(loop);
	for (auto& x : arr) cin >> x;
	for (int i = 0; i < arr.size();i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[i] < arr[j]) 
				cp++;
		}
	}

	cout << cp;

	return 0;
}

