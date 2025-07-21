#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main()
{
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

    // Sort candidates based on their current vote count
    vector<pair<ll, int>> candidates(n);
    for(int i = 0; i < n; i++) {
        candidates[i] = {a[i], i};
    }
    sort(candidates.begin(), candidates.end());

    // Calculate prefix sum of sorted vote counts
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + candidates[i].first;
    }

    // Initialize answer array with -1
    vector<ll> ans(n, -1);

    for(int i = 0; i < n; i++) {
        ll target_votes = candidates[i].first;
        ll needed_votes = 0;

        // Calculate the number of candidates that can surpass the current candidate
        int surpass_count = 0;
        for(int j = i + 1; j < n; j++) {
            if(candidates[j].first > target_votes) {
                surpass_count++;
                needed_votes += candidates[j].first - target_votes;
            }
        }

        // Check if the current candidate can win with the needed votes
        if(surpass_count < m) {
            ans[candidates[i].second] = max(0LL, needed_votes / (m - surpass_count));
            if(needed_votes % (m - surpass_count)) {
                ans[candidates[i].second]++;
            }
        }
    }

    // Print the result
    for(auto &i : ans) cout << i << ' ';
    return 0;
}