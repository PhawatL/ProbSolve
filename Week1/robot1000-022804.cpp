#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int x = 0, y = 0;
    for (char i : s) {
        if (i == 'N') {
            y++;
        } else if (i == 'W') {
            x--;
        } else if (i == 'E') {
            x++;
        } else if (i == 'S') {
            y--;
        } else {
            x = 0;
            y = 0;
        }
    }

    std::cout << x << " " << y << std::endl;

    return 0;
}
