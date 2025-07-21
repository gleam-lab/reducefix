#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Total votes remaining
    ll total_remaining = k;
    for (ll ai : a) {
        total_remaining -= ai;
    }

    vector<int> idx(n);
    iota(all(idx), 0);

    // Sort candidates by current votes
    sort(all(idx), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> sorted_a(n);
    for (int i = 0; i < n; i++) {
        sorted_a[i] = a[idx[i]];
    }

    // Prefix sum of sorted votes
    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> res(n);

    for (int i = 0; i < n; i++) {
        int pos = i; // position in sorted list
        ll low = 0, high = total_remaining, answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll min_votes_needed = sorted_a[pos] + mid;

            // We want to find how many candidates have votes > min_votes_needed
            // Binary search the number of candidates with votes > min_votes_needed
            int cnt = n - (upper_bound(all(sorted_a), min_votes_needed) - sorted_a.begin());

            if (cnt < m) {
                // Not enough people below i can be beaten, need more votes
                low = mid + 1;
            } else {
                // It's possible with this mid, try smaller
                answer = mid;
                high = mid - 1;
            }
        }

        // Now check if it's actually possible with answer additional votes
        if (answer == -1 || answer > total_remaining) {
            res[idx[i]] = -1;
        } else {
            res[idx[i]] = answer;
        }
    }

    for (ll x : res) {
        cout << x << ' ';
    }
}