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
    char last_undefeated = S[0];
    int ans = 0;
    for (int i = 1; i < N; ++i) {
        char current = S[i];
        if ((last_undefeated == 'R' && current == 'S') ||
            (last_undefeated == 'S' && current == 'P') ||
            (last_undefeated == 'P' && current == 'R')) {
            // current loses to last_undefeated, no action
            continue;
        } else if ((current == 'R' && last_undefeated == 'S') ||
                   (current == 'S' && last_undefeated == 'P') ||
                   (current == 'P' && last_undefeated == 'R')) {
            // current beats last_undefeated
            ans++;
            last_undefeated = current;
        } else {
            // same characters, no action
            continue;
        }
    }
    cout << ans;
    return 0;
}