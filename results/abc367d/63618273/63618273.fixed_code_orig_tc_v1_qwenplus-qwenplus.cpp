#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> PII;

const int N = 2e5 + 10, mod = 1e9 + 7;

void solve() {
    int n;
    ll M;
    cin >> n >> M;
    vector<ll> a(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<ll> prefixSum(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = (prefixSum[i - 1] + a[i]) % M;
    }

    map<ll, ll> cnt;
    ll ans = 0;

    // We need to count the number of pairs (i,j) such that (prefixSum[j] - prefixSum[i-1]) % M == 0
    // Which is equivalent to prefixSum[j] % M == prefixSum[i-1] % M
    // So we maintain a frequency map of prefixSum[i] % M

    cnt[0] = 1; // To handle subarrays starting from index 0
    for (int i = 1; i <= n; ++i) {
        ans += cnt[prefixSum[i]];
        cnt[prefixSum[i]]++;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}