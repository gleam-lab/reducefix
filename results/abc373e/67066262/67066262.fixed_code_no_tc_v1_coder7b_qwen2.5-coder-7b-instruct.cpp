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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Calculate the maximum number of votes any candidate can get
    ll max_votes = *max_element(a.begin(), a.end());
    
    // Calculate the minimum number of votes needed to ensure a candidate wins
    vector<ll> min_votes_to_win(n, 0);
    for (int i = 0; i < n; ++i) {
        if (a[i] + k < max_votes) {
            min_votes_to_win[i] = max_votes - a[i] - 1;
        } else {
            min_votes_to_win[i] = 0;
        }
    }

    // Ensure that if a candidate gets these votes, they will still win
    for (int i = 0; i < n; ++i) {
        if (min_votes_to_win[i] != 0) {
            bool can_win = true;
            for (int j = 0; j < n; ++j) {
                if (j != i && a[j] + k >= min_votes_to_win[i]) {
                    can_win = false;
                    break;
                }
            }
            if (!can_win) {
                min_votes_to_win[i] = -1;
            }
        }
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << min_votes_to_win[i] << " ";
    }
    return 0;
}