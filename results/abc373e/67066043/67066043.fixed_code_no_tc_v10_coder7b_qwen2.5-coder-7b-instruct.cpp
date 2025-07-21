#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Calculate the current maximum votes a candidate can have after all remaining votes are counted
    vector<ll> max_votes(n);
    for(int i = 0; i < n; ++i) {
        max_votes[i] = a[i] + k / n;
        if(i < k % n) {
            max_votes[i]++;
        }
    }

    // Sort the candidates based on their current votes
    vector<pair<ll, int>> sorted_a(n);
    for(int i = 0; i < n; ++i) {
        sorted_a[i].first = a[i];
        sorted_a[i].second = i;
    }
    sort(sorted_a.begin(), sorted_a.end());

    // Determine the minimum number of additional votes needed for each candidate
    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        int idx = sorted_a[i].second;
        if(a[idx] >= max_votes[idx]) continue;

        // Calculate the number of candidates that could surpass this candidate if they get enough votes
        int count = 0;
        for(int j = i + 1; j < n; ++j) {
            if(sorted_a[j].first > a[idx]) {
                count++;
            }
        }

        // Check if the candidate can win even if all remaining votes go to them
        if(count < m) {
            ans[idx] = max_votes[idx] - a[idx];
        } else {
            // If the candidate cannot win even with all remaining votes, check if they can win with just one vote
            for(int j = i + 1; j < n; ++j) {
                if(sorted_a[j].first > a[idx] - 1) {
                    count--;
                }
            }
            if(count < m) {
                ans[idx] = max_votes[idx] - a[idx] + 1;
            }
        }
    }

    // Print the results
    for(int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}