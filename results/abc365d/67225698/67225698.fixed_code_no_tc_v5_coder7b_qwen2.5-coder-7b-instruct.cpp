#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int wins = 0;
    char last_played = '\0';
    bool can_lose_next = false;
    
    for (int i = 0; i < n; ++i) {
        if (last_played != '\0') {
            if ((s[i] == 'R' && last_played == 'S') ||
                (s[i] == 'S' && last_played == 'P') ||
                (s[i] == 'P' && last_played == 'R')) {
                wins++;
                can_lose_next = true;
            } else {
                can_lose_next = false;
            }
        }
        
        if (can_lose_next) {
            wins--;
        }
        
        last_played = s[i];
    }
    
    cout << wins << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}