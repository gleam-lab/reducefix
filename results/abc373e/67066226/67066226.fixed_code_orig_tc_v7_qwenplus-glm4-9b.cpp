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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        total_votes += a[i];
    }
    k -= total_votes;

    // Sort candidates based on current votes
    sort(a.begin(), a.end(), greater<ll>());

    vector<ll> ans(n);
    for(int i = 0; i < n; i++) {
        bool can_win = true;
        ll additional_votes_needed = 0;

        // Binary search to find minimum votes needed
        int low = 0, high = k;
        while (low <= high) {
            int mid = (low + high) / 2;
            int votes_needed_to_win = (m - 1) * (a[i] + mid + 1) - (total_votes - a[i] - mid);

            if (votes_needed_to_win <= k) {
                additional_votes_needed = votes_needed_to_win;
                high = mid - 1;
            } else {
                low = mid + 1;
                can_win = false;
            }
        }

        if (can_win) {
            ans[i] = additional_votes_needed;
        } else {
            ans[i] = -1; // Cannot win
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}