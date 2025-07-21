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
    char prev = 'a'; // Initialize previous move to a character not in RPS
    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else if (c == 'S') {
            winmove = 'R';
        }
        if (winmove != prev) {
            wins++;
            prev = winmove;
        } else {
            prev = c;
        }
    }
    cout << wins;

    return 0;
}