#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    vector<ll> result(n, -1);
    for (int i = 0; i < n; ++i) {
        ll target = a[i] + 1;
        int count_needed = min(m - 1, n - i - 1);
        ll required_votes = (count_needed * target) - prefix[n - count_needed];

        if (required_votes <= k) {
            result[indices[i]] = required_votes;
        }
    }

    for (ll x : result) {
        cout << x << " ";
    }

    return 0;
}