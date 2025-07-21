#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;
    
    vector<i64> A(n);
    for (auto &x : A) {
        cin >> x;
    }
    
    i64 remaining = k;
    for (auto x : A) {
        remaining -= x;
    }
    
    if (m == n) {
        // Everyone gets elected since less than M= n candidates can have more votes
        for (int i = 0; i < n; ++i) {
            cout << 0 << " ";
        }
        cout << "\n";
        return;
    }

    vector<i64> sortedA = A;
    sort(sortedA.begin(), sortedA.end());
    
    // Prefix sum from largest to smallest
    vector<i64> prefix(n + 2, 0);
    for (int i = n - 1; i >= 0; --i) {
        prefix[i] = prefix[i + 1] + sortedA[i];
    }

    for (int i = 0; i < n; ++i) {
        i64 a_i = A[i];
        
        // Binary search on minimal X
        i64 left = 0, right = remaining, ans = -1;
        
        auto isEnough = [&](i64 x) -> bool {
            i64 total = remaining - x;
            a_i += x;
            
            // Find how many candidates strictly greater than a_i
            int idx = upper_bound(sortedA.begin(), sortedA.end(), a_i) - sortedA.begin();
            int cnt = n - idx;
            
            if (cnt < m) {
                // Need at most (m - cnt) candidates to surpass a_i
                int l = max(0, idx - (m - cnt));
                i64 sum = prefix[l] - prefix[idx];
                
                if (a_i * (m - cnt) < sum) {
                    return false;
                }
            }
            return cnt < m;
        };
        
        while (left <= right) {
            i64 mid = (left + right) / 2;
            if (isEnough(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << (ans == -1 ? -1 : ans) << " ";
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    solve();
    return 0;
}