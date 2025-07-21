#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;

    // Define the possible moves
    const std::vector<char> hand = {'R', 'P', 'S'};

    // Function to determine the score of using a move against another
    auto getScore = [](char move, char opponent) -> int {
        if ((move == 'R' && opponent == 'S') || 
            (move == 'P' && opponent == 'R') || 
            (move == 'S' && opponent == 'P')) {
            return 1;
        }
        return 0;
    };

    // Initialize scores
    int total1 = 0, total2 = 0;

    // First strategy: Play optimally based on the first move
    char firstMove = S[0];
    for (char move : hand) {
        if (move != firstMove) {
            for (int i = 0; i < N; ++i) {
                total1 += getScore(move, S[i]);
            }
            break;
        }
    }

    // Second strategy: Play optimally based on the last move
    char lastMove = S[N-1];
    for (char move : hand) {
        if (move != lastMove) {
            for (int i = 0; i < N; ++i) {
                total2 += getScore(move, S[i]);
            }
            break;
        }
    }

    // Output the maximum score between the two strategies
    std::cout << std::max(total1, total2) << std::endl;

    return 0;
}