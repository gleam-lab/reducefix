#include<bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;

const int N = 2e5 + 10, mod = 1e9 + 7;

void solve()
{
    int n;
    ll M;
    cin >> n >> M;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<ll> prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i]) % M;
    }

    map<ll, ll> cnt;
    ll ans = 0;
    cnt[0] = 1; // Handle subarrays starting from index 0

    for (int i = 1; i <= n; ++i) {
        // Count how many times this mod value has been seen before
        ans += cnt[prefix[i]]++;
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}