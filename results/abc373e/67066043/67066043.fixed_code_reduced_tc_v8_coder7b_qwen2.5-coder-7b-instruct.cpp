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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort candidates by the number of votes they currently have
    vector<pair<ll, int>> candidates;
    for (int i = 0; i < n; ++i) {
        candidates.emplace_back(a[i], i);
    }
    sort(candidates.begin(), candidates.end());

    // Calculate the prefix sum of votes
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + candidates[i].first;
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        ll votes_needed = 0;
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                if (candidates[j].first > candidates[i].first) {
                    votes_needed++;
                }
            }
        }
        if (votes_needed < m) {
            ans[candidates[i].second] = 0;
        } else {
            ll min_votes = LLONG_MAX;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    if (candidates[j].first > candidates[i].first) {
                        ll additional_votes = candidates[j].first - candidates[i].first + 1;
                        min_votes = min(min_votes, additional_votes);
                    }
                }
            }
            ans[candidates[i].second] = min_votes;
        }
    }

    for (ll x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}