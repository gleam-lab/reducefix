#include <bits/stdc++.h>
using namespace std;

int compute_max_score(const string& S, const vector<char>& hand) {
    int N = S.size();
    vector<char> next = hand;
    int total = 0;
    char last_use = '\0';

    for (int i = 0; i < N; ++i) {
        int score = 0;
        char use = '\0';

        // Try each possible move in the current available moves
        for (char n : next) {
            if ((n == 'R' && S[i] == 'S') || 
                (n == 'P' && S[i] == 'R') || 
                (n == 'S' && S[i] == 'P')) {
                score = 1;
                use = n;
                break;
            }
        }

        // If no winning move is available, pick any move (can't score)
        if (score == 0) {
            for (char n : next) {
                use = n;
                break;
            }
        }

        // Update total score and update the available moves for next round
        total += score;
        vector<char> new_next;
        for (char d : hand) {
            if (d != use) {
                new_next.push_back(d);
            }
        }
        next = new_next;
    }

    return total;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> hand = {'R', 'P', 'S'};

    // Case 1: Play normally from the first character
    int score1 = compute_max_score(S, hand);

    // Case 2: Skip the first character
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    string S2 = S.substr(1);
    int score2 = compute_max_score(S2, hand);

    cout << max(score1, score2) << endl;
}