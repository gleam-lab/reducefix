#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::string S;
    std::cin >> N;
    std::cin >> S;

    int wins = 0;
    char winmove = 'A'; // Initialize with a character not in ['R', 'P', 'S']
    for (char c : S) {
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else if (c == 'S') {
            winmove = 'R';
        }
        if (winmove != c) {
            wins++;
        }
    }

    std::cout << wins << std::endl;

    return 0;
}