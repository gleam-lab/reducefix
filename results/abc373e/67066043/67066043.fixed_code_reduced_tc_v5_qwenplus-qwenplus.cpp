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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Total remaining votes
    ll total_remaining = k;
    for (ll ai : a) total_remaining -= ai;

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> res(n, -1);

    for (int idx = 0; idx < n; ++idx) {
        int i = ord[idx]; // original index
        ll base = a[i];

        ll low = 0, high = total_remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = base + mid;

            // Binary search to find how many candidates have votes > target
            int cnt = n - (upper_bound(all(sorted_a), target) - sorted_a.begin());

            if (cnt >= m) {
                // Already in top M-1 or better, candidate wins
                answer = mid;
                high = mid - 1;
            } else {
                // Need to increase votes
                // We need to make sure that even in worst-case scenario,
                // this candidate gets into the top M positions

                // Find how many candidates currently have > target
                int higher = n - (lower_bound(all(sorted_a), target + 1) - sorted_a.begin());

                // We want at most M - 1 candidates strictly greater than target
                if (higher >= m) {
                    // Already good
                    answer = mid;
                    high = mid - 1;
                } else {
                    // Need to raise target so that only M-1 candidates are above
                    // Let's compute how many votes needed to beat enough candidates
                    int need_to_beat = higher - (m - 1);
                    if (need_to_beat <= 0) {
                        answer = mid;
                        high = mid - 1;
                    } else {
                        // Try to find how much more needed to surpass those candidates
                        // Find how many of the top (higher - (m - 1)) candidates we must overtake
                        int pos = n - (higher);
                        int must_overcome = higher - (m - 1);
                        int l = pos, r = n - 1;
                        while (must_overcome--) {
                            ll extra_needed = sorted_a[r--] - target + 1;
                            mid += extra_needed;
                            if (mid > total_remaining) break;
                            target += extra_needed;
                        }
                        if (mid <= total_remaining) {
                            answer = mid;
                            high = mid - 1;
                        } else {
                            low = mid + 1;
                        }
                    }
                }
            }
        }

        if (answer <= total_remaining) {
            res[i] = answer;
        } else {
            res[i] = -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (res[i] == 0 && a[i] + res[i] < 0) {
            res[i] = -1; // edge case protection
        }
        cout << res[i] << " ";
    }
    cout << "\n";
}