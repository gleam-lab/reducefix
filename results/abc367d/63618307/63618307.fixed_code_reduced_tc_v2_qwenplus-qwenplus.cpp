#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<ll, ll> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve()
{
    int n;
    ll M;
    cin >> n >> M;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = (prefix_sum[i] + a[i]) % M;
    }

    map<ll, ll> count_map;
    ll result = 0;

    // To count subarrays with sum divisible by M, we initialize the map with prefix_sum[0] = 1
    count_map[0] = 1;

    for (int i = 1; i <= n; i++) {
        // We want to find number of previous prefix sums equal to current prefix_sum[i]
        result += count_map[prefix_sum[i]];
        count_map[prefix_sum[i]]++;
    }

    cout << result << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}