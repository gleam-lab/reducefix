#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 0) {
        cout << "0\n";
        return;
    }
    long long ans = 0;
    long long cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            cnt++;
        } else {
            ans += cnt / 2;
            cnt = 1;
        }
    }
    ans += cnt / 2;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}