#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 200005

ll a[N], sorted[N];

// Check if candidate with current votes x can win with X additional votes
// remaining_votes is total unused votes, others can distribute among themselves
bool can_win(ll x, ll X, ll remaining_votes, ll n, ll m, ll k) {
    ll target = x + X;

    // Binary search to find how many candidates can have >= target votes
    // We sort all candidates' votes and try to raise this candidate to target
    // We need at most (n - m) other candidates to have more than target
    // So we check the (n - m)-th largest vote after allocation

    ll left = 0, right = n;
    while (left < right) {
        ll mid = (left + right) / 2;
        ll needed = 0;
        // Make sure top (n - m) candidates are at least `target`
        for (ll i = mid; i <= n; ++i) {
            if (sorted[i] < target) {
                needed += target - sorted[i];
            }
        }
        if (needed <= remaining_votes) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left <= n - m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;

    ll sum_a = 0;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        sum_a += a[i];
    }
    k -= sum_a;

    for (ll i = 1; i <= n; ++i) {
        sorted[i] = a[i];
    }
    sort(sorted + 1, sorted + n + 1);

    vector<ll> res(n + 1, -1);

    for (ll i = 1; i <= n; ++i) {
        ll low = 0, high = k;
        bool possible = false;

        // Pre-check if already elected
        ll cnt = 0;
        for (ll j = 1; j <= n; ++j) {
            if (j != i && a[j] > a[i]) cnt++;
        }
        if (cnt < m) {
            res[i] = 0;
            continue;
        }

        // Binary search on X: number of additional votes needed
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total_needed = mid;
            ll remaining = k - mid;

            // Copy current votes
            ll temp[N];
            for (ll j = 1; j <= n; ++j) temp[j] = a[j];
            temp[i] += mid;
            sort(temp + 1, temp + n + 1);

            // Count how many have more than temp[i]
            ll count_more = 0;
            for (ll j = 1; j <= n; ++j) {
                if (j != i && temp[j] > temp[i]) {
                    count_more++;
                }
            }
            if (count_more < m) {
                possible = true;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (possible) {
            res[i] = low;
        } else {
            res[i] = -1;
        }
    }

    for (ll i = 1; i <= n; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}