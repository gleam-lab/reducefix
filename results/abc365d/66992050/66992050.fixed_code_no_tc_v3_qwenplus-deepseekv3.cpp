#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    char past = '\0'; // Initialize to invalid
    int ans = 0;
    for (char c : S) {
        if (past == '\0') {
            past = c; // First move, no win possible
            continue;
        }
        if ((c == 'P' && past == 'R') || 
            (c == 'R' && past == 'S') || 
            (c == 'S' && past == 'P')) {
            ans++;
        }
        past = c; // Always update past to current move
    }
    cout << ans;
    return 0;
}