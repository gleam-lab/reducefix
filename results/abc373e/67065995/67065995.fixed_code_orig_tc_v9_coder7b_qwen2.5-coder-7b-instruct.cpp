#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_streambuf(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort the votes in descending order
    sort(a.rbegin(), a.rend());

    vector<ll> prefix(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        ll needed_votes = 0;
        if(i >= n - m) {
            needed_votes = a[i] + 1;
        } else {
            needed_votes = prefix[n - m] - prefix[i] + 1;
        }

        if(k >= needed_votes) {
            ans[i] = needed_votes - a[i];
        }
    }

    for(auto x : ans) {
        cout << x << " ";
    }
    return 0;
}