#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;

void solve() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> s(n + 10);
    for (int i = 1; i <= n; i++) {
        s[i] = (s[i - 1] + a[i]) % mod;
    }
    map<int, int> mp;
    ll ans = 0, L = s[n];
    for (int i = 1; i <= n; i++) {
        ans += mp[(s[i] - L + mod) % mod];
        mp[s[i]]++;
    }
    cout << ans;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}