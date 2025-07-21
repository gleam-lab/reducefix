#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }

    vector<ll> prefix(2 * n + 1, 0);
    for (int i = 0; i < 2 * n; ++i) {
        prefix[i + 1] = (prefix[i] + a[i]) % m;
    }

    ll res = 0;
    unordered_map<ll, int> freq;
    for (int i = 1; i <= 2 * n; ++i) {
        if (i > n) {
            ll prev_mod = prefix[i - n];
            freq[prev_mod]--;
            if (freq[prev_mod] == 0) {
                freq.erase(prev_mod);
            }
        }
        res += freq[prefix[i]];
        freq[prefix[i]]++;
    }

    cout << res << endl;
    return 0;
}