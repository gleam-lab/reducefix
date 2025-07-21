#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> PII;

void solve() {
    int n;
    ll M;
    cin >> n >> M;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = (prefix_sum[i - 1] + a[i]) % M;
    }

    map<ll, ll> count;
    ll result = 0;

    // We need to count how many times each prefix sum mod M has occurred
    // Initialize with prefix_sum[0] = 0 having count 1
    count[0] = 1;

    for (int i = 1; i <= n; ++i) {
        // For current prefix_sum[i], we want to find how many previous j's satisfy:
        // (prefix_sum[i] - prefix_sum[j]) % M == 0
        // That is, how many times prefix_sum[i] has appeared before
        result += count[prefix_sum[i]]++;
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}