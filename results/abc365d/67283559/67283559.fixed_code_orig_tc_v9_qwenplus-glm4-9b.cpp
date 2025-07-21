#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<char> hand = {'R', 'P', 'S'};
    int total1 = 0, total2 = 0;
    char opponentMove;
    
    // First player fixed strategy
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'R') {
            total1++;
            hand.erase(remove(hand.begin(), hand.end(), 'S'), hand.end());
        } else if (S[i] == 'P') {
            total1++;
            hand.erase(remove(hand.begin(), hand.end(), 'R'), hand.end());
        } else if (S[i] == 'S') {
            total1++;
            hand.erase(remove(hand.begin(), hand.end(), 'P'), hand.end());
        }
    }
    
    // Second player optimal strategy
    for (int i = 1; i < N; ++i) {
        if (S[i - 1] == 'R') {
            total2++;
            hand.erase(remove(hand.begin(), hand.end(), 'S'), hand.end());
        } else if (S[i - 1] == 'P') {
            total2++;
            hand.erase(remove(hand.begin(), hand.end(), 'R'), hand.end());
        } else if (S[i - 1] == 'S') {
            total2++;
            hand.erase(remove(hand.begin(), hand.end(), 'P'), hand.end());
        }
        if (i < N - 1)
            opponentMove = S[i];
        else
            opponentMove = hand[0];  // In case of the last move
    }
    
    cout << max(total1, total2);
}