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
    char prevWinMove = '\0'; // Initialize to an invalid move

    for (char c : S) {
        char currentWinMove;
        if (c == 'R') {
            currentWinMove = 'P';
        } else if (c == 'P') {
            currentWinMove = 'S';
        } else if (c == 'S') {
            currentWinMove = 'R';
        }

        if (currentWinMove != prevWinMove) {
            wins++;
            prevWinMove = currentWinMove;
        }
    }
    cout << wins;
    return 0;
}