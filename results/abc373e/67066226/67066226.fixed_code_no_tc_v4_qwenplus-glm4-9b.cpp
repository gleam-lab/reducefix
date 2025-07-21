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
    ll total_votes = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_votes += a[i];
    }

    // Calculate the votes each candidate needs to guarantee victory
    vector<ll> needed(n);
    for (int i = 0; i < n; ++i) {
        needed[i] = k + 1 - total_votes + a[i] - (n - m);
        if (needed[i] < 0) needed[i] = 0;
    }

    // Sort candidates by the number of votes they have received
    sort(needed.begin(), needed.end());

    // Calculate the minimum additional votes needed for each candidate
    vector<ll> ans(n, -1);
    ll remaining_votes = k - total_votes;
    ll votes_to_give = 0;
    for (int i = 0; i < n; ++i) {
        votes_to_give += needed[i];
        if (votes_to_give > remaining_votes) {
            break;
        }
        ans[i] = votes_to_give;
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        if (ans[i] == -1 && needed[i] == 0) {
            ans[i] = 0; // If the candidate already has the maximum votes needed
        }
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}