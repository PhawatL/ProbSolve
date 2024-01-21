#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // Include the numeric header

using namespace std;

int main() {

    int array[300] = {0};
    
    int loop, tmp;
    cin >> loop;
    
    for (int i = 0; i < loop; i++){
        cin >> tmp;
        array[tmp]++;
    }
    
    int max=0;
    
    for (int i=0;i<300;i++){
        
        if (array[i] >max){
            max = array[i];
        }
    }
    
    cout << max << endl;
    return 0;
}
