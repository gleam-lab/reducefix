#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort candidates based on their current vote counts
    vector<pair<ll, int>> candidates;
    for(int i = 0; i < n; i++) {
        candidates.push_back({a[i], i});
    }
    sort(candidates.begin(), candidates.end());

    // Calculate prefix sums of sorted candidates' votes
    vector<ll> prefix(n + 1);
    for(int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + candidates[i].first;
    }

    // Initialize answers with -1 (impossible to win)
    vector<ll> ans(n, -1);

    // Process each candidate in order of their current vote counts
    for(int i = 0; i < n; i++) {
        ll votes_needed = 0;
        int rank = n - i; // Rank of the current candidate among others

        // Calculate the maximum number of votes that can be distributed to other candidates
        ll max_votes_to_others = prefix[n] - prefix[i + 1];

        // Check if the current candidate can win even if all remaining votes go to others
        if(max_votes_to_others < (rank - 1)) {
            continue;
        }

        // Binary search to find the minimum additional votes needed
        ll left = 0, right = k + 1;
        while(left < right) {
            ll mid = left + (right - left) / 2;
            ll total_votes_if_win = prefix[n] + mid;

            // Calculate the number of candidates that would have more votes than the current candidate
            int count_more_than_current = 0;
            for(int j = 0; j < n; j++) {
                if(candidates[j].first + mid > candidates[i].first) {
                    count_more_than_current++;
                }
            }

            // If the count is less than M, the current candidate can win
            if(count_more_than_current < m) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // Update the answer for the current candidate
        if(left != k + 1) {
            ans[candidates[i].second] = left;
        }
    }

    // Output the results
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}