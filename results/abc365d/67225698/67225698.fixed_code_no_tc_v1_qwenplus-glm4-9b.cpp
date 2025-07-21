#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int main() {
    fast_io();
    int t = 1;
    // cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = 0;
        ll cnt = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
            } else {
                ans += (cnt + 1) / 2;
                cnt = 1;
            }
        }
        ans += (cnt + 1) / 2;
        cout << ans << "\n";
    }
    return 0;
}