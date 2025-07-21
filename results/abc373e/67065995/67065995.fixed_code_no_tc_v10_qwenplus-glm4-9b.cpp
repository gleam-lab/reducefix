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

    // Sort candidates by votes received so far in descending order
    vector<pair<ll, int>> candidates(n);
    for (int i = 0; i < n; i++) {
        candidates[i] = {a[i], i};
    }
    sort(candidates.rbegin(), candidates.rend());

    vector<ll> ans(n, -1);
    // Start from the last M-1 candidates and go backwards
    for (int i = m - 1; i < n; i++) {
        if (k == 0) {
            ans[candidates[i].second] = 0;
            continue;
        }
        ll votes_needed;
        // Calculate the number of votes needed to guarantee victory
        // We want to be at least as many votes as the (i+1)-th candidate
        votes_needed = candidates[i].first + (m - 1) - (a[candidates[i].second]);
        if (votes_needed > k) {
            // If we cannot guarantee victory, set to -1
            ans[candidates[i].second] = -1;
        } else {
            // Calculate the additional votes needed beyond the votes already cast
            ans[candidates[i].second] = votes_needed - a[candidates[i].second];
            k -= votes_needed - a[candidates[i].second];
        }
    }

    // Output the results
    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            cout << -1 << " ";
        } else {
            cout << ans[i] << " ";
        }
    }
    cout << endl;

    return 0;
}