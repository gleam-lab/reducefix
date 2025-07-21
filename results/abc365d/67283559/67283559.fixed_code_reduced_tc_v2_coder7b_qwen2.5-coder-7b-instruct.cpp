#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> hand = {'R', 'P', 'S'};
    int total = 0;

    for (int i = 0; i < N; ++i) {
        int score = 0;
        char use = S[i];

        // Determine the best move to beat the current stone
        for (char h : hand) {
            if ((h == 'R' && S[i] == 'S') || 
                (h == 'P' && S[i] == 'R') || 
                (h == 'S' && S[i] == 'P')) {
                score++;
                use = h;
                break;
            }
        }

        total += score;
        // Update the hand to exclude the chosen move
        hand.erase(remove(hand.begin(), hand.end(), use), hand.end());
    }

    cout << total << endl;
    return 0;
}