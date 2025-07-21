#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string s;
    cin >> n >> s;

    // The optimal strategy is to greedily choose the winning move unless it creates a conflict with previous choice
    // We'll perform two passes:
    // - One starting with the first character as original
    // - One trying different initial choices for better result

    auto solve = [&](string &s) {
        int len = s.size();
        vector<char> c(len);
        // Map moves: P -> S, R -> P, S -> R (winning move)
        for (int i = 0; i < len; ++i) {
            if (s[i] == 'P') c[i] = 'S';
            else if (s[i] == 'R') c[i] = 'P';
            else c[i] = 'R';
        }

        int count = len;
        for (int i = 1; i < len; ++i) {
            if (c[i] == c[i-1]) {
                // Conflict, use original move instead
                c[i] = s[i];
                count--;
            }
        }
        return count;
    };

    // Try all possible first move options and pick best result
    int result = 0;
    for (char first : {'S', 'P', 'R'}) { // All possible initial winning moves
        vector<char> c(n);
        c[0] = first;
        int cnt = n;

        if (c[0] == s[0]) {
            c[0] = s[0]; // Can't win in this case
            cnt--;
        }

        for (int i = 1; i < n; ++i) {
            if (s[i] == 'P') c[i] = 'S';
            else if (s[i] == 'R') c[i] = 'P';
            else c[i] = 'R';

            if (c[i] == c[i-1]) {
                c[i] = s[i];
                cnt--;
            }
        }

        result = max(result, cnt);
    }

    cout << result << endl;
    return 0;
}