#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> count(3);
    for (char c : s) {
        count[c - 'P']++;
    }

    int ans = 0;
    int p_count = 0, r_count = 0, s_count = 0;
    for (char c : s) {
        if (c == 'P') {
            if (r_count > 0) {
                ans += r_count;
                r_count--;
            }
            p_count++;
        } else if (c == 'R') {
            if (s_count > 0) {
                ans += s_count;
                s_count--;
            }
            r_count++;
        } else {
            if (p_count > 0) {
                ans += p_count;
                p_count--;
            }
            s_count++;
        }
    }

    cout << ans << '\n';

    return 0;
}