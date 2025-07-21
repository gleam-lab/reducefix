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
        char counter;
        if (current == 'R') {
            counter = 'P';
        } else if (current == 'P') {
            counter = 'S';
        } else { // 'S'
            counter = 'R';
        }
        if (i == 0 || counter != prev_move) {
            wins++;
            prev_move = counter;
        }
    }
    cout << wins;
}