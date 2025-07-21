#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::string S;
    std::cin >> N >> S;

    int wins = 0;
    char prevMove = 'A'; // Initialize with a character not in R, P, S

    for (const auto& move : S) {
        if ((move == 'R' && prevMove != 'P') ||
            (move == 'P' && prevMove != 'S') ||
            (move == 'S' && prevMove != 'R')) {
            ++wins;
        }
        prevMove = move;
    }

    std::cout << wins << '\n';

    return 0;
}