#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<i64> a(n);
    for (auto &x : a) cin >> x;

    i64 total_remaining = k;
    for (auto x : a) total_remaining -= x;

    vector<pair<i64, int>> sorted_a(n);
    for (int i = 0; i < n; ++i) {
        sorted_a[i] = {a[i], i};
    }
    sort(sorted_a.begin(), sorted_a.end());

    vector<int> res(n);

    for (int i = 0; i < n; ++i) {
        i64 orig_vote = a[i];
        // Binary search on X: minimum number of additional votes needed
        i64 low = 0, high = total_remaining;
        int candidate_idx = -1;
        for (int j = 0; j < n; ++j) {
            if (sorted_a[j].second == i) {
                candidate_idx = j;
                break;
            }
        }

        auto is_sufficient = [&](i64 add_vote) {
            i64 new_vote = orig_vote + add_vote;
            // We need fewer than M candidates with strictly more votes than new_vote
            // So at most M-1 candidates can have > new_vote
            // Find how many current candidates already have > new_vote
            int cnt = n - (upper_bound(sorted_a.begin(), sorted_a.end(), make_pair(new_vote, n)) - sorted_a.begin());
            if (cnt < m) return true;
            // Need to increase some votes of this candidate so that at most M-1 have more
            // Let's find the threshold vote such that exactly (M-1) candidates have higher votes
            // Then compute how much we need to add to ensure our candidate beats those below
            vector<i64> top_m;
            for (int j = n - 1; j >= max(0, n - m + 1); --j) {
                if (j != candidate_idx)
                    top_m.push_back(sorted_a[j].first);
            }
            // If there are less than M candidates with higher votes, already good
            if ((int)top_m.size() < m) return true;
            // Compute required votes to beat the weakest in top M
            i64 need = 0;
            for (auto v : top_m) {
                if (v >= new_vote) {
                    need += (v - new_vote + 1);
                }
            }
            return need <= total_remaining - add_vote;
        };

        i64 ans = -1;
        i64 l = 0, r = total_remaining;
        while (l <= r) {
            i64 mid = (l + r) / 2;
            if (is_sufficient(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        res[i] = ans;
    }

    for (auto x : res) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}