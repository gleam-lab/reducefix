#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    char prev = ' ';
    for (int i = 0; i < N; ++i) {
        if (prev == ' ') {
            // Initial move can be any, so we choose R
            prev = 'R';
        } else {
            // Choose the move that beats Aoki's current move and is different from the previous move
            if (S[i] == 'R') {
                prev = 'P';
            } else if (S[i] == 'P') {
                prev = 'S';
            } else { // S
                prev = 'R';
            }
        }
        if (prev != S[i]) {
            wins++;
        }
    }
    cout << wins;
}