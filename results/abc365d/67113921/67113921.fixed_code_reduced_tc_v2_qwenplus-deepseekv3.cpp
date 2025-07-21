#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    char prev_move = '\0';
    for (int i = 0; i < N; ++i) {
        char current = S[i];
        char winmove;
        if (current == 'R') {
            winmove = 'P';
        } else if (current == 'P') {
            winmove = 'S';
        } else {
            winmove = 'R';
        }
        if (winmove != prev_move) {
            wins++;
            prev_move = winmove;
        } else {
            if (i + 1 < N) {
                char next = S[i+1];
                char next_winmove;
                if (next == 'R') {
                    next_winmove = 'P';
                } else if (next == 'P') {
                    next_winmove = 'S';
                } else {
                    next_winmove = 'R';
                }
                if (next_winmove != winmove) {
                    prev_move = '\0';
                } else {
                    prev_move = current;
                }
            } else {
                prev_move = current;
            }
        }
    }
    cout << wins;
}