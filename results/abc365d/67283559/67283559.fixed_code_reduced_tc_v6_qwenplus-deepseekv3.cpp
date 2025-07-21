#include <bits/stdc++.h>
using namespace std;

int calculateMaxScore(int N, const string& S) {
    int maxScore = 0;
    // Try all possible initial choices
    for (char initial : {'R', 'P', 'S'}) {
        vector<char> next;
        // Initialize next choices excluding the initial choice
        for (char c : {'R', 'P', 'S'}) {
            if (c != initial) next.push_back(c);
        }
        int score = 0;
        // First move
        if ((initial == 'R' && S[0] == 'S') ||
            (initial == 'P' && S[0] == 'R') ||
            (initial == 'S' && S[0] == 'P')) {
            score++;
        }
        // Subsequent moves
        for (int i = 1; i < N; ++i) {
            char bestMove = ' ';
            int currentScore = 0;
            // Check available moves
            for (char move : next) {
                if ((move == 'R' && S[i] == 'S') ||
                    (move == 'P' && S[i] == 'R') ||
                    (move == 'S' && S[i] == 'P')) {
                    bestMove = move;
                    currentScore = 1;
                    break;
                }
            }
            if (bestMove == ' ') {
                // No winning move, choose one that doesn't lose
                for (char move : next) {
                    if ((move == 'R' && S[i] == 'R') ||
                        (move == 'P' && S[i] == 'P') ||
                        (move == 'S' && S[i] == 'S')) {
                        bestMove = move;
                        currentScore = 0;
                        break;
                    }
                }
                if (bestMove == ' ') {
                    // All moves lose, choose any
                    bestMove = next[0];
                    currentScore = 0;
                }
            }
            score += currentScore;
            // Update next choices: exclude the used move
            next.clear();
            for (char c : {'R', 'P', 'S'}) {
                if (c != bestMove) next.push_back(c);
            }
        }
        maxScore = max(maxScore, score);
    }
    return maxScore;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    cout << calculateMaxScore(N, S) << endl;
    return 0;
}