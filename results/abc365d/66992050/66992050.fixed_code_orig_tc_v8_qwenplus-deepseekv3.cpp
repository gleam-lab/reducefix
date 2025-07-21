#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    char last_opponent = 'N'; // Initialize to an invalid move
    int ans = 0;
    for (char c : S) {
        if (last_opponent == 'N') {
            // First move, choose any (but count if it beats the previous which doesn't exist)
            last_opponent = c;
        } else {
            if (c == 'P') {
                if (last_opponent == 'R') {
                    ans++;
                    last_opponent = 'S'; // Choose scissors to beat rock
                } else if (last_opponent == 'S') {
                    // Do nothing, opponent's last move was scissors, paper loses
                    last_opponent = 'P';
                } else if (last_opponent == 'P') {
                    // Choose scissors to beat paper
                    ans++;
                    last_opponent = 'S';
                }
            } else if (c == 'R') {
                if (last_opponent == 'S') {
                    ans++;
                    last_opponent = 'R'; // Choose rock to beat scissors
                } else if (last_opponent == 'P') {
                    // Do nothing, opponent's last move was paper, rock loses
                    last_opponent = 'R';
                } else if (last_opponent == 'R') {
                    // Choose paper to beat rock
                    ans++;
                    last_opponent = 'P';
                }
            } else if (c == 'S') {
                if (last_opponent == 'P') {
                    ans++;
                    last_opponent = 'S'; // Choose scissors to beat paper
                } else if (last_opponent == 'R') {
                    // Do nothing, opponent's last move was rock, scissors lose
                    last_opponent = 'S';
                } else if (last_opponent == 'S') {
                    // Choose rock to beat scissors
                    ans++;
                    last_opponent = 'R';
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}