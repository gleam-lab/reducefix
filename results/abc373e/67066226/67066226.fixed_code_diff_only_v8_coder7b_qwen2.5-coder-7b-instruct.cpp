#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Calculate the maximum votes a candidate can get without winning
    vector<ll> max_votes(n);
    for(int i = 0; i < n; ++i) {
        max_votes[i] = a[i] + (k / (n - m)) + ((k % (n - m) > i) ? 1 : 0);
    }

    // Determine the minimum additional votes needed for each candidate
    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        if(max_votes[i] <= a[i]) continue;
        ans[i] = max_votes[i] - a[i];
    }

    // Print the results
    for(ll x : ans) {
        cout << x << " ";
    }
    return 0;
}