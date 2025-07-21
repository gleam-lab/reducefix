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
    char prev = 'a'; // Initialize to a character not in {'R','P','S'}

    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }

        if (winmove != prev) {
            wins++;
            prev = winmove;
        } else {
            // We cannot win this round, so we play the same as opponent
            prev = c;
        }
    }

    cout << wins << endl;
}