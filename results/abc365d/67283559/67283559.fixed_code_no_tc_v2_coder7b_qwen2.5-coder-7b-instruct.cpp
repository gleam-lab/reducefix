#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> hand = {'R', 'P', 'S'};
    int total = 0;

    // Calculate the first part of the score
    for (int i = 0; i < N; ++i) {
        int score = 0;
        char use;
        for (char h : hand) {
            if ((h == 'R' && S[i] == 'S') || (h == 'P' && S[i] == 'R') || (h == 'S' && S[i] == 'P')) {
                score++;
                use = h;
                break;
            }
        }
        if (score == 0) use = S[i];
        total += score;
        hand.erase(remove(hand.begin(), hand.end(), use), hand.end());
    }

    // Reset hand for the second part of the score calculation
    hand = {'R', 'P', 'S'};
    int total2 = 0;

    // Calculate the second part of the score
    for (int i = 1; i < N; ++i) {
        int score = 0;
        char use;
        for (char h : hand) {
            if ((h == 'R' && S[i] == 'S') || (h == 'P' && S[i] == 'R') || (h == 'S' && S[i] == 'P')) {
                score++;
                use = h;
                break;
            }
        }
        if (score == 0) use = S[i];
        total2 += score;
        hand.erase(remove(hand.begin(), hand.end(), use), hand.end());
    }

    cout << max(total, total2) << endl;
    return 0;
}