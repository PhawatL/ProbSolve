// ku01_next.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;




int main()
{

	int num, ans=0,loop,min=2147483647,tmp;
	
	cin >> num >> loop;
	vector<int> arr(num);

	for (int& x:arr) {
	
		cin >> tmp;
		x = tmp;
		min = min > tmp ? tmp : min;
		
	}
	for (auto &x : arr) {


		ans += x / ((float)(x - min)) > loop ? 1 : 0;
	}
	cout << ans;
	



	return 0;
}