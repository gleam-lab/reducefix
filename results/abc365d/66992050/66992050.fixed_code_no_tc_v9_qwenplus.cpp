#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    string S;
    cin >> N >> S;
    
    char last_move = 'N'; // Last move in the sequence we chose
    int ans = 0;
    
    for (char c : S) {
        if (c == 'P') {
            // To counter Paper, we should play Scissors
            if (last_move != 'S') {
                ans++;
                last_move = 'S';
            } else {
                last_move = 'P';
            }
        } else if (c == 'R') {
            // To counter Rock, we should play Paper
            if (last_move != 'P') {
                ans++;
                last_move = 'P';
            } else {
                last_move = 'R';
            }
        } else if (c == 'S') {
            // To counter Scissors, we should play Rock
            if (last_move != 'R') {
                ans++;
                last_move = 'R';
            } else {
                last_move = 'S';
            }
        }
    }
    
    cout << ans;
    return 0;
}