#include <iostream>
#include <string>
#include <vector>

int cmp(char x, char y) {
    if (x == 'P') return y == 'S' ? -1 : (y == 'R' ? 1 : 0);
    if (x == 'R') return y == 'P' ? -1 : (y == 'S' ? 1 : 0);
    if (x == 'S') return y == 'R' ? -1 : (y == 'P' ? 1 : 0);
    return -100;
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // Assume 'X' is not a valid game character
}

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    
    int changes = 0;
    char prev = s[0];
    for (int i = 1; i < n; ++i) {
        char curr = s[i];
        if (cmp(prev, curr) != 0) {
            changes++;
            prev = curr;
        }
    }

    std::cout << changes << std::endl;
    return 0;
}