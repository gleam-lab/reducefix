#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    int wins = 0;
    for (char c : S) {
        if (c == 'R') {
            wins++;  // Play 'P' to win
        } else if (c == 'P') {
            wins++;  // Play 'S' to win
        } else if (c == 'S') {
            wins++;  // Play 'R' to win
        }
    }
    cout << wins;
}