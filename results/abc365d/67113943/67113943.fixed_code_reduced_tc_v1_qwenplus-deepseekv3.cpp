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
    for (char c : S) {
        if (c == 'R') {
            wins += 1; // We choose 'P' to win
        } else if (c == 'P') {
            wins += 1; // We choose 'S' to win
        } else if (c == 'S') {
            wins += 1; // We choose 'R' to win
        }
    }
    cout << wins;
    return 0;
}