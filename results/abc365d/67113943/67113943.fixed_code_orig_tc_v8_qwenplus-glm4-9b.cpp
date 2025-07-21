#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    char prev = 'a'; // Initialize prev to a non-character value to ensure the first comparison is valid

    for (char c : S) {
        char winmove;
        if (prev == 'R') {
            winmove = (c == 'S') ? 'R' : 'P';
        } else if (prev == 'P') {
            winmove = (c == 'R') ? 'P' : 'S';
        } else if (prev == 'S') {
            winmove = (c == 'P') ? 'S' : 'R';
        } else {
            // This case should never occur since prev is initialized to a non-character value
            continue;
        }

        if (winmove != c) {
            wins++;
            prev = winmove;
        } else {
            prev = c;
        }
    }
    cout << wins;
}