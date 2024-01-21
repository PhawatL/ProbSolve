// ku01_next.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

vector <int> first_order_decode(vector<int> array, int N) {
	vector<int> ans;
	if (array[0] > N) {
		ans.push_back(1);
	}
	else {
		ans.push_back(0);
	}
	for (int i = 0; i < N - 1; i++) {
		if (array[i] < array[i + 1]) {
			ans.push_back(1);
		}
		else {
			ans.push_back(0);
		}
	}

	return ans;
}
vector <int> second_order_decode(vector<int> array, int N) {
	vector<int> ans = { array[0] };

	for (int i = 0; i < N - 1; i++) {

		if (array[i + 1] > 2 * ans[i]) {

			ans.push_back(array[i + 1] - 2 * ans[i]);
		}
		else {
			ans.push_back(array[i + 1] - ans[i]);
		}


	}return ans;


}
int main()
{
	int N, encode, tmp;
	cin >> N >> encode;
	vector<int> array;
	for (int i = 0; i < N; i++) {

		cin >> tmp;
		array.push_back(tmp);
	}
	switch (encode)
	{
	case 2:
		array = second_order_decode(array, N);
	case 1:
		array = first_order_decode(array, N);
	default:
		break;
	}
	for (auto i : array) {
		cout << i << endl;
	}
	return 0;
}

