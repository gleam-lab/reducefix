#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 200005;

i64 A[N], sorted[N];

struct Candidate {
    i64 total_votes;
    int idx;
};

bool compare(const Candidate &a, const Candidate &b) {
    return a.total_votes > b.total_votes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    i64 k;
    cin >> n >> m >> k;
    
    vector<i64> C(n, -1);
    vector<Candidate> candidates(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> candidates[i].total_votes;
        candidates[i].idx = i;
    }
    
    // Sort candidates by votes descending
    sort(candidates.begin(), candidates.end(), compare);
    
    // Precompute prefix sums of the top (n - m + 1) candidates
    vector<i64> prefix_sum(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + candidates[i].total_votes;
    }
    
    i64 sum_all = prefix_sum[n];
    i64 remaining = k - sum_all;
    
    for (int i = 0; i < n; ++i) {
        int idx = candidates[i].idx;
        
        // Binary search to find minimum required additional votes
        i64 l = 0, r = remaining;
        bool possible = false;
        while (l <= r) {
            i64 mid = (l + r) / 2;
            i64 target = candidates[i].total_votes + mid;
            
            // Find how many candidates have more than target votes
            int cnt = upper_bound(sorted, sorted + n, target, greater<>{}) - sorted;
            
            if (cnt < m) {
                possible = true;
                C[idx] = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        if (!possible) {
            C[idx] = -1;
        }
    }
    
    for (auto c : C) {
        cout << c << " ";
    }
    cout << endl;
}