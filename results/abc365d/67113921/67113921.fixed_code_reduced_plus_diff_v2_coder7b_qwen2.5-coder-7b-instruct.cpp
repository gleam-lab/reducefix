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
    if (N > 0) {
        char prev = S[0];
        for (int i = 1; i < N; ++i) {
            if (S[i] == prev) {
                wins++;
                prev = (prev == 'R') ? 'P' : (prev == 'P') ? 'S' : 'R';
            } else {
                prev = S[i];
            }
        }
    }
    
    cout << wins + 1;
    return 0;
}