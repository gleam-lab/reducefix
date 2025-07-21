#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    int wins = 0;
    char lastMove = '\0'; // Initialize to an invalid move

    for (char c : S) {
        char currentWinMove;
        if (c == 'R') {
            currentWinMove = 'P';
        } else if (c == 'P') {
            currentWinMove = 'S';
        } else { // 'S'
            currentWinMove = 'R';
        }

        if (currentWinMove != lastMove) {
            wins++;
            lastMove = currentWinMove;
        }
    }
    cout << wins << '\n';
    return 0;
}