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
    char prevWinMove = '\0'; // Initialize to a null character to indicate no previous move
    for (char c : S) {
        char winMove;
        if (c == 'R') {
            winMove = 'P';
        } else if (c == 'P') {
            winMove = 'S';
        } else { // 'S'
            winMove = 'R';
        }
        if (winMove != prevWinMove) {
            wins++;
            prevWinMove = winMove;
        }
    }
    cout << wins;
    return 0;
}