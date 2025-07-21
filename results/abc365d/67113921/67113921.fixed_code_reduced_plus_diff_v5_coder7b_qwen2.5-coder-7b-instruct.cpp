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
    char prevMove = ' ';
    for (char move : S) {
        if (prevMove == ' ') {
            // First move of the game
            prevMove = move;
        } else {
            if ((move == 'R' && prevMove == 'S') || (move == 'P' && prevMove == 'R') || (move == 'S' && prevMove == 'P')) {
                wins++;
            }
            prevMove = move;
        }
    }

    cout << wins << endl;

    return 0;
}