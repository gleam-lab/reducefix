#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> hand = {'R','P','S'};
    auto getScore = [&](char move, char opponent) {
        if ((move == 'R' && opponent == 'S') ||
            (move == 'P' && opponent == 'R') ||
            (move == 'S' && opponent == 'P')) {
            return 1;
        }
        return 0;
    };

    int maxTotal = 0;

    // Try all possible starting hands (i.e., which one to exclude initially)
    for (char exclude : hand) {
        vector<char> current;
        for (char c : hand) {
            if (c != exclude) {
                current.push_back(c);
            }
        }

        int total = 0;
        for (int i = 0; i < N; i++) {
            int bestScore = -1;
            char bestMove = ' ';

            // Try each available move
            for (char move : current) {
                int score = getScore(move, S[i]);
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = move;
                }
            }

            total += bestScore;

            // Update available moves: remove the one we just used
            vector<char> next;
            for (char c : current) {
                if (c != bestMove) {
                    next.push_back(c);
                }
            }
            current = next;
        }
        maxTotal = max(maxTotal, total);
    }

    cout << maxTotal << endl;
    return 0;
}