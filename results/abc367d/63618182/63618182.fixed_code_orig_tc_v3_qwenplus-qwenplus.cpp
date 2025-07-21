#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<ll> prefixSum(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = (prefixSum[i - 1] + a[i]) % M;
    }

    map<ll, ll> count;
    ll result = 0;

    // We want to count the number of subarrays where (prefix[j] - prefix[i]) % M == 0
    // which is equivalent to prefix[j] % M == prefix[i] % M
    for (int i = 0; i <= n; ++i) {
        ll rem = prefixSum[i] % M;
        if (rem < 0) rem += M;
        result += count[rem];
        count[rem]++;
    }

    cout << result << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}