#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(n + 1), c(n + 1);
    
    // Read initial vote counts
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
        b[i + 1] = a[i];
    }

    // Sort the vote counts
    sort(b.begin(), b.end());

    // Calculate prefix sums of sorted vote counts
    for (ll i = 1; i <= n; ++i) {
        c[i] = c[i - 1] + b[i];
    }

    // Determine the minimum additional votes needed for each candidate
    for (ll i = 0; i < n; ++i) {
        ll x = b[i];
        ll remaining_votes = k;
        ll candidates_exceeding_x = upper_bound(b.begin(), b.end(), x + remaining_votes) - b.begin();
        
        if (candidates_exceeding_x < n - m) {
            cout << 0 << " ";
        } else {
            ll min_additional_votes = -1;
            for (ll j = i + 1; j <= n; ++j) {
                if (b[j] > x && (c[j] - c[i]) + remaining_votes >= b[j]) {
                    if (min_additional_votes == -1 || b[j] - x < min_additional_votes) {
                        min_additional_votes = b[j] - x;
                    }
                }
            }
            cout << (min_additional_votes != -1 ? min_additional_votes : -1) << " ";
        }
    }

    return 0;
}