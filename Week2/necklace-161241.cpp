// ku01_next.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<int, list<int>> m;
	unordered_map<int, int> address;
	int loop;
	cin >> loop;
	for (int i = 1; i < loop+1; i++) {
		list<int> l{ i };
		m[i] = l;
		address[i] = i;
	}
	/*for (const auto& it : m) {
		cout << it.first << " : ";
		for (auto it1 : it.second) {
			cout << it1 << " ";
		}cout << "\n";
	}*/
	int a, b,tmp;
	for (int ll = 1; ll < loop; ll++) {
		cin >> a >> b;
		tmp = address[b];
		while (tmp != address[tmp]) {
			tmp = address[tmp];
		}
		auto insertPos = m[tmp].begin();
		for (int i : m[tmp]) {
			insertPos++;
			// cout << i << "Hehe\n";
			if (i == b)
				break;

		}
		m[tmp].splice(insertPos, m[a]);
		address[a] = b;
		/*for (const auto& it : m) {
			cout << it.first << " : ";
			for (auto it1 : it.second) {
				cout << it1 << " ";
			}cout << "\n";
		}cout << "Address\n";
		for (const auto& a_it : address) {
			cout << a_it.first << " : " << a_it.second << "\n";
		}
		cout << "\n";*/
	}
	for (int ans : m[tmp]) {
		cout << ans << " ";
	}


	return 0;
}

