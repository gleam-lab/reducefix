#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<char> hand = {'R', 'P', 'S'};
    int total = 0;
    int total2 = 0;
    int used = -1; // To keep track of the last used character

    // Loop for calculating scores based on next optimal characters
    for (int i = 0; i < N; i++) {
        int score = 0;
        if (used != -1) { // If there was an optimal character chosen previously
            for (int j = 0; j < hand.size(); j++) {
                if (hand[j] == used) {
                    score += 3; // Add 3 points for using the optimal character
                    hand.erase(remove(hand.begin(), hand.end(), used), hand.end());
                    break;
                }
            }
        }
        total += score;
        if (score == 0) { // If no optimal character was used, mark current character
            used = S[i];
        }
    }

    // Reset hand and used character
    hand = {'R', 'P', 'S'};
    used = -1;

    // Loop for calculating scores based on current optimal characters
    for (int i = 0; i < N; i++) {
        int score = 0;
        if (used != -1) {
            for (int j = 0; j < hand.size(); j++) {
                if (hand[j] == used) {
                    score += 3;
                    used = -1;
                    hand.erase(remove(hand.begin(), hand.end(), used), hand.end());
                    break;
                }
            }
        }
        total2 += score;
        if (score == 0) {
            used = S[i];
        }
    }

    cout << max(total, total2);
    return 0;
}