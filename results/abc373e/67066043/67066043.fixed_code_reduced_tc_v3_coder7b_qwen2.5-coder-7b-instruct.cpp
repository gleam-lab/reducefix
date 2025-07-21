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

    // Calculate the total votes needed for each candidate to win
    vector<ll> target_votes(n);
    for (int i = 0; i < n; ++i) {
        target_votes[i] = k / (n - m - (i < n - m ? 1 : 0)) + (k % (n - m - (i < n - m ? 1 : 0)) > 0 ? 1 : 0);
    }

    // Calculate the additional votes needed for each candidate
    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        if (a[i] >= target_votes[i]) {
            ans[i] = 0;
        } else {
            ans[i] = target_votes[i] - a[i];
        }
    }

    // Ensure the answer does not exceed the remaining votes
    for (int i = 0; i < n; ++i) {
        if (ans[i] > k) {
            ans[i] = -1;
        }
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}