// ku01_next.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;




int main()
{
	set<int> f = { 0 };
	int n, t, k,i=0,loop=0;
	cin >> n >> k >> t;
	t--;
	do {
		i = (i + k) % (n);
		f.insert(i);

	} while (not (i == 0 or i == t) );
	
	cout << f.size()<<endl;


	return 0;
}