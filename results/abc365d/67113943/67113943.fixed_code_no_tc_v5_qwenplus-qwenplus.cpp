#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char opponentMove, myMove = 'a';  // 'a' as placeholder before first move

    for (char c : S) {
        // Determine the winning move against opponent's move 'c'
        char winMove;
        if (c == 'R') winMove = 'P';
        else if (c == 'P') winMove = 'S';
        else winMove = 'R';  // opponent played 'S'

        // If we can change our move, do it and count a win
        if (myMove != winMove) {
            myMove = winMove;
            wins++;
        }
        // Else, we keep the same move, no need to increment wins
    }

    cout << wins << endl;
    return 0;
}