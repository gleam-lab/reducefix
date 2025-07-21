#include<bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<ll, ll> PII;
const int mod = 1e9 + 7;

void solve() {
    int n;
    ll M;
    cin >> n >> M;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = (prefix_sum[i] + a[i]) % M;
    }

    map<ll, ll> count_map;
    ll result = 0;
    count_map[0] = 1; // To handle subarrays starting from index 0

    for (int i = 1; i <= n; ++i) {
        // Count how many times this remainder has been seen before
        result += count_map[prefix_sum[i] % M];
        count_map[prefix_sum[i] % M]++;
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}