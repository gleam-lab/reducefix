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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Total remaining votes
    ll total_remaining = k;
    for (ll ai : a) total_remaining -= ai;

    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> result(n);

    for (int i = 0; i < n; ++i) {
        ll need_votes = 0;
        ll candidate_votes = a[i];

        // Binary search to find minimum X such that candidate i wins with X more votes
        ll low = 0, high = total_remaining;
        bool possible = false;

        while (low <= high) {
            ll mid = (low + high) / 2;

            // We want to find how many candidates have strictly more than current_candidate_votes
            ll current_candidate_votes = candidate_votes + mid;
            int cnt = 0;

            // Use binary search to count how many candidates can possibly beat this candidate
            int left = 0, right = n - 1;
            int pos = n;

            while (left <= right) {
                int center = (left + right) / 2;
                if (sorted_a[center] > current_candidate_votes) {
                    pos = center;
                    right = center - 1;
                } else {
                    left = center + 1;
                }
            }

            // If there are less than M candidates with more votes than this candidate, then it's valid
            if (n - pos < m) {
                possible = true;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (!possible) {
            result[i] = -1;
        } else {
            result[i] = max<ll>(0, low);
        }
    }

    for (ll val : result) cout << val << " ";
    cout << endl;

    return 0;
}