#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string S;
    cin >> S;

    const vector<char> hand = {'R', 'P', 'S'};

    auto scoreForNextMove = [&](char current, char next) -> int {
        if ((current == 'R' && next == 'S') || (current == 'P' && next == 'R') || (current == 'S' && next == 'P')) return 1;
        return 0;
    };

    int maxScore = 0;
    for (const auto& move : hand) {
        int score = 0;
        vector<char> remainingHand(hand.begin(), hand.end());
        remainingHand.erase(find(remainingHand.begin(), remainingHand.end(), move));

        for (int i = 0; i < N; ++i) {
            if (scoreForNextMove(S[i], move)) {
                score += 1;
            } else {
                move = S[i];
            }
        }

        maxScore = max(maxScore, score);
    }

    cout << maxScore << '\n';

    return 0;
}