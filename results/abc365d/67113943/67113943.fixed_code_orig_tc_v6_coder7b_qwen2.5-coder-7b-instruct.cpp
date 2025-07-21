#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::string S;
    std::cin >> N >> S;

    int wins = 0;
    char winmove = 'A'; // Initialize with any character not in the set {'R', 'P', 'S'}
    char prev = 'A';   // Initialize with any character not in the set {'R', 'P', 'S'}

    for (char c : S) {
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else if (c == 'S') {
            winmove = 'R';
        }

        if (winmove != prev) {
            wins++;
            prev = winmove;
        } else {
            prev = c;
        }
    }

    std::cout << wins << '\n';

    return 0;
}