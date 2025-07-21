#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> min_votes_to_win(vector<ll>& a, int m, ll k) {
    int n = a.size();
    vector<ll> res(n, -1);

    // Sort indices based on current vote counts
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] < a[j]; });

    // Calculate prefix sums of sorted vote counts
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[idx[i]];
    }

    // Iterate over sorted indices
    for (int i = 0; i < n; ++i) {
        int rank = i + 1;
        int needed = 0;
        
        // Calculate the number of votes needed to win
        for (int j = 0; j < rank - 1; ++j) {
            needed += (a[idx[j]] + 1) * (m - (rank - j)) - pref[j + 1];
        }
        
        // Check if it's possible within the remaining votes
        if (k >= needed) {
            res[idx[i]] = needed;
            k -= needed;
        }
    }

    return res;
}

int main() {
    ios_base::sync_witheczy