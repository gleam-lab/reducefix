#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    if (N == 0) {
        cout << 0;
        return 0;
    }
    
    char past = S[0];
    int ans = 0;
    
    for (int i = 1; i < N; ++i) {
        char current = S[i];
        if (current == 'P' && past == 'R') {
            ans++;
            past = current;  // Only update past if current wins
        } else if (current == 'R' && past == 'S') {
            ans++;
            past = current;
        } else if (current == 'S' && past == 'P') {
            ans++;
            past = current;
        } else {
            past = current;  // Update past even if no win
        }
    }
    
    cout << ans;
    return 0;
}