#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char my_move = 'a'; // no previous move initially

    for (char c : S) {
        char winmove;
        if (c == 'R') winmove = 'P';
        else if (c == 'P') winmove = 'S';
        else winmove = 'R';

        if (my_move != winmove) {
            wins++;
            my_move = winmove;
        } else {
            my_move = c; // play the current move if we can't win
        }
    }

    cout << wins << endl;
}