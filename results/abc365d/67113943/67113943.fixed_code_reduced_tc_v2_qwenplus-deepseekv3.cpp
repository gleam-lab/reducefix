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
    for (int i = 0; i < N; ++i) {
        char c = S[i];
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else if (c == 'S') {
            winmove = 'R';
        }
        wins++;
        // Check if the next move is the same to avoid counting consecutive same wins
        if (i + 1 < N && S[i+1] == c) {
            i++; // Skip the next move to prevent overcounting
        }
    }
    cout << wins;
}