#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char prev = '\0'; // Initialize to an invalid move

    for (char c : S) {
        char current;
        if (c == 'R') {
            current = 'P';
        } else if (c == 'P') {
            current = 'S';
        } else { // 'S'
            current = 'R';
        }

        if (current != prev) {
            wins++;
            prev = current;
        } else {
            // If the same as previous, we can't win this round, so reset prev to allow next move to win
            prev = '\0';
        }
    }

    cout << wins << endl;
    return 0;
}