#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }

    vector<pair<ll, int>> candidates;
    for(int i = 0; i < n; i++) {
        candidates.push_back({a[i], i});
    }
    sort(candidates.begin(), candidates.end(), [](const pair<ll, int>& a, const pair<ll, int>& b) {
        return a.first < b.first;
    });

    vector<ll> remaining_votes = candidates[n - m]; // Votes needed to win with m less candidates
    vector<ll> prefix_sum(n, 0);

    for(int i = n - 1; i >= 0; i--) {
        prefix_sum[i] = prefix_sum[i + 1] + candidates[i].first;
    }

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; i++) {
        ll votes_needed = 0;

        // Check if this candidate can already secure their victory
        if(i < n - m) {
            continue;
        }

        // Calculate votes needed to ensure victory
        ll max_votes = prefix_sum[i] + remaining_votes - candidates[i].first;
        if(max_votes <= k) {
            votes_needed = remaining_votes - (prefix_sum[i] - k) - candidates[i].first;
        } else {
            ans[candidates[i].second] = -1;
            continue;
        }

        ans[candidates[i].second] = votes_needed;
    }

    for(int i = 0; i < n; i++) {
        if(ans[i] == -1)
            cout << -1 << " ";
        else
            cout << ans[i] << " ";
    }

    return 0;
}