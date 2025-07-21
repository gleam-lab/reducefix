#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    sort(all(a)); // Sort the votes
    reverse(all(a)); // Reverse to sort in descending order

    // Remaining votes
    ll R = k - accumulate(all(a), 0LL);

    ll votes_needed = 0, votes_to_win = 0;
    for (int i = 0; i < n; i++) {
        votes_needed += a[i];
        votes_to_win = (i + 1 < n) ? a[i + 1] : 0;

        if (votes_needed + R >= votes_to_win * m) {
            votes_needed = votes_to_win * m - votes_needed;
            break;
        }
    }

    vector<ll> result(n);
    for (int i = 0; i < n; i++) {
        if (i < m || n - i - 1 < m) {
            result[i] = votes_needed;
        } else {
            result[i] = -1;
        }
    }

    for (ll i : result) cout << i << ' ';
    return 0;
}