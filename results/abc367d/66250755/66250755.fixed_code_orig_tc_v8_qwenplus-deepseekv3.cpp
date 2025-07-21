#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
    }

    ll res = 0;
    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = (prefix[i] + a[i]) % m;
    }

    unordered_map<ll, ll> freq;
    freq[0] = 1; // to account for subarrays starting from index 0

    for (int i = 1; i <= n; ++i) {
        res += freq[prefix[i]];
        freq[prefix[i]]++;
    }

    cout << res << "\n";
    return 0;
}