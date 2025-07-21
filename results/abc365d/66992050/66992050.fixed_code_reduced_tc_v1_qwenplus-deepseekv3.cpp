#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    char last_opponent_move = 'N'; // 'N' indicates no previous move
    int ans = 0;
    
    for (char c : S) {
        if (last_opponent_move == 'N') {
            // First move is always a successful attack
            ans++;
            if (c == 'P') {
                last_opponent_move = 'R';
            } else if (c == 'R') {
                last_opponent_move = 'S';
            } else if (c == 'S') {
                last_opponent_move = 'P';
            }
        } else {
            if ((c == 'P' && last_opponent_move == 'R') ||
                (c == 'R' && last_opponent_move == 'S') ||
                (c == 'S' && last_opponent_move == 'P')) {
                ans++;
                if (c == 'P') {
                    last_opponent_move = 'R';
                } else if (c == 'R') {
                    last_opponent_move = 'S';
                } else if (c == 'S') {
                    last_opponent_move = 'P';
                }
            }
        }
    }
    
    cout << ans;
    return 0;
}