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
        k -= a[i];
    }

    // Calculate the maximum votes needed for a candidate to win
    vector<ll> max_votes_needed(n);
    for (int i = 0; i < n; i++) {
        if (n - m - 1 - i >= 0)
            max_votes_needed[i] = a[n - m - 1 - i] + 1;
        else
            max_votes_needed[i] = 0;
    }

    // Sort the candidates based on current votes
    vector<pair<ll, int>> candidates;
    for (int i = 0; i < n; i++)
        candidates.push_back({a[i], i});

    sort(candidates.rbegin(), candidates.rend());

    // Binary search for the minimum additional votes needed
    vector<ll> result(n, -1);
    for (auto [votes, index] : candidates) {
        if (result[index] != -1)
            continue;

        ll left = 0, right = k + 1;
        while (left < right) {
            ll mid = (left + right) / 2;
            bool can_win = true;

            for (int i = 0; i < n; i++) {
                if (i == index)
                    continue;

                if (a[i] + mid >= max_votes_needed[i]) {
                    can_win = false;
                    break;
                }
            }

            if (can_win)
                right = mid;
            else
                left = mid + 1;
        }

        result[index] = left;
    }

    for (ll x : result)
        cout << x << " ";

    return 0;
}