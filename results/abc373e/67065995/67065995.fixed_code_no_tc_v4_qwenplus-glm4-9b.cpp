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
    k -= accumulate(a.begin(), a.end(), 0ll); // Subtract the votes already counted from k
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    
    // Sort the array to use binary search later
    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    // Prefix sum array for sorted_a
    vector<ll> pref(n+1);
    for (int i = 0; i < n; i++) {
        pref[i+1] = sorted_a[i] + pref[i];
    }

    // Calculate the winning vote count
    ll winning_votes = sorted_a[n - m] + m * (m + 1) / 2;

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; i++) {
        // Number of votes to win
        ll votes_needed = winning_votes - a[i];
        
        // If the candidate already has the winning votes, no more votes are needed
        if (votes_needed <= 0) {
            ans[ord[i]] = 0;
            continue;
        }
        
        // Binary search to find the minimum additional votes needed
        auto check = [&](ll x) -> bool {
            ll votes_needed_now = x;
            ll count_more_votes = 0;
            for (int j = n - 1; j >= 0 && votes_needed_now > 0; j--) {
                if (sorted_a[j] + votes_needed_now <= k) {
                    votes_needed_now -= sorted_a[j];
                    count_more_votes++;
                }
            }
            return count_more_votes >= m;
        };

        ll l = 0, r = k + 1;
        while (l < r) {
            ll mid = (l + r) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (l > k) {
            ans[ord[i]] = -1; // Not enough votes to win even under the best scenario
        } else {
            ans[ord[i]] = l;
        }
    }

    for (ll i : ans) cout << i << ' ';
    cout << '\n';
}