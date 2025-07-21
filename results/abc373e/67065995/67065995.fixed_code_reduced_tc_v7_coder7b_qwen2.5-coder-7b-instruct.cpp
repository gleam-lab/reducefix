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
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<pair<ll, int>> candidates;
    for(int i = 0; i < n; ++i) {
        candidates.emplace_back(a[i], i);
    }

    sort(candidates.begin(), candidates.end());

    vector<ll> prefix_sum(n + 1);
    for(int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + candidates[i].first;
    }

    vector<ll> result(n, -1);
    for(int i = 0; i < n; ++i) {
        ll required_votes = 0;
        if(i >= n - m) {
            continue;
        }

        ll current_votes = candidates[i].first;
        int count_greater = 0;

        for(int j = i + 1; j < n; ++j) {
            if(candidates[j].first > current_votes) {
                ++count_greater;
            }
        }

        if(count_greater < m) {
            continue;
        }

        ll total_remaining_votes = k;
        ll remaining_candidates = n - i - 1;
        
        if(remaining_candidates == 0) {
            result[candidates[i].second] = 0;
            continue;
        }

        ll min_votes_needed = (m * (candidates[i].first + 1)) - prefix_sum[n];
        
        if(min_votes_needed <= total_remaining_votes) {
            result[candidates[i].second] = 0;
        } else {
            result[candidates[i].second] = min_votes_needed - total_remaining_votes;
        }
    }

    for(int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}