#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    string hand = "RPS";
    vector<int> count(3, 0); // Count of available options for each hand
    int total = 0;

    // First pass: calculate scores for the opponent's first move
    for (int i = 0; i < N; ++i) {
        int score = 0;
        for (char h : hand) {
            if ((h == 'R' && S[i] == 'S') || (h == 'P' && S[i] == 'R') || (h == 'S' && S[i] == 'P')) {
                score++; // Opponent wins with this hand
                count[h - 'R']--; // Reduce the count of this hand as it's not available anymore
                break;
            }
        }
        total += score;
    }

    // Second pass: calculate scores for the opponent's second move
    for (int i = 1; i < N; ++i) {
        int score = 0;
        for (char h : hand) {
            if ((h == 'R' && S[i] == 'S') || (h == 'P' && S[i] == 'R') || (h == 'S' && S[i] == 'P')) {
                score++; // Opponent wins with this hand
                count[h - 'R']--; // Reduce the count of this hand as it's not available anymore
                break;
            }
        }
        total += score;
    }

    cout << total;
    return 0;
}