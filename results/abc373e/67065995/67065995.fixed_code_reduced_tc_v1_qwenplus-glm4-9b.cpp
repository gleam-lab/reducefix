#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    ll total_votes = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_votes += a[i];
    }

    // Candidates who have already been eliminated
    vector<ll> eliminated;

    // Sort candidates by votes received
    sort(a.begin(), a.end(), greater<ll>());

    vector<ll> remaining_votes(k);
    iota(remaining_votes.begin(), remaining_votes.end(), total_votes + 1);

    // Probability distribution of remaining votes
    vector<pair<ll, ll>> prob_dist;
    for (ll votes : remaining_votes) {
        for (int i = 0; i < votes; ++i) {
            prob_dist.push_back({1, votes - i});
        }
    }

    // Calculate minimum votes needed to ensure victory for each candidate
    vector<ll> min_votes_needed(n, -1);
    for (int i = 0; i < n; ++i) {
        if (a[i] + prob_dist.size() >= m) {
            min_votes_needed[i] = 0;
        } else {
            int required = m - (a[i] + prob_dist.size());
            if (required <= 0) {
                min_votes_needed[i] = 0;
            } else {
                // Binary search for the minimum required votes
                int l = 0, r = prob_dist.size() - 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (prob_dist[mid].second >= required) {
                        if (mid == 0 || prob_dist[mid - 1].second < required) {
                            min_votes_needed[i] = required;
                            break;
                        }
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                if (min_votes_needed[i] == -1) {
                    min_votes_needed[i] = -1;
                }
            }
        }
    }

    // Print results
    for (ll votes : min_votes_needed) {
        cout << votes << " ";
    }
    cout << endl;

    return 0;
}