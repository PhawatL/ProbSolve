// ku01_next.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
	int m,input,tmp;
	cin >> m;
	
	cin >> input;
	tmp = input;
	unordered_set<int> set{ input };
	vector<int> cum{ input };
	for (int i = 0; i < m-1; i++) {
		cin >> input;
		tmp += input;
		cum.push_back(tmp);
		set.insert(input);
		set.insert(tmp);
	}
	for (int i = 0; i < cum.size(); i++) {
		for (int j = i + 1; j < cum.size(); j++) {
			set.insert(cum[j] - cum[i]);
		}
	}cout << set.size() << "\n";

}

