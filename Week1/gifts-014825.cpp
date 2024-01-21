#include <iostream>

using namespace std;

int main() {

    int loop, score, n;
    score=0;
    cin >> loop;
    for (int i =0;i<loop;i++)
    {
        cin >> n;
        if (n > 0)
            score += n;
    }
    cout << score;

    return 0;
}