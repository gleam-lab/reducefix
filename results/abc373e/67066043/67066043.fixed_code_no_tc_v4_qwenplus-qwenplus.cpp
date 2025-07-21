#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> ord(n);
    iota(all(ord), 0);

    // Sort candidates by current votes
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> res(n, -1);

    for (int idx = 0; idx < n; ++idx) {
        int i = ord[idx]; // original index of the candidate
        ll low = 0, high = k + 1;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total_needed = 0;

            // We assume candidate i gets `mid` additional votes
            ll new_vote_count = a[i] + mid;

            // We want to ensure that fewer than M candidates have more votes than this candidate
            // So at most (M-1) candidates can be strictly above this one
            // Therefore, we need to make sure that at least (n - M + 1) candidates have <= new_vote_count

            // Find how many candidates currently have > new_vote_count
            // Binary search on sorted_a
            int pos = n - (upper_bound(all(sorted_a), new_vote_count) - sorted_a.begin());

            if (pos < m) {
                // Already enough
                answer = mid;
                high = mid - 1;
            } else {
                // Need to increase some other candidates to not exceed new_vote_count
                // Find how many candidates we must reduce to <= new_vote_count
                int need_reduce = pos - (m - 1);
                // We will take the top (need_reduce) candidates who are > new_vote_count and cap them

                // Find first position in sorted_a where value > new_vote_count
                int l = upper_bound(all(sorted_a), new_vote_count) - sorted_a.begin();
                int r = n - need_reduce;

                if (l <= r) {
                    total_needed = (n - (r - l)) * new_vote_count - (prefix[n - l] - prefix[n - r]);
                    if (total_needed <= k) {
                        answer = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                } else {
                    low = mid + 1;
                }
            }
        }

        res[i] = answer;
    }

    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}