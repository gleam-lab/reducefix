#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;
    
    vector<i64> a(n);
    for (auto &x : a) {
        cin >> x;
        k -= x;
    }
    
    if (m >= n) {
        cout << string(n, '0') << "\n";
        return;
    }
    
    vector<pair<i64, int>> sorted_a(n);
    for (int i = 0; i < n; ++i) {
        sorted_a[i] = {a[i], i};
    }
    
    sort(sorted_a.begin(), sorted_a.end());
    
    vector<i64> prefix_sum(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_a[i].first;
    }
    
    vector<i64> res(n);
    
    for (int idx = 0; idx < n; ++idx) {
        i64 val = a[idx];
        
        // Binary search on additional votes needed
        i64 low = 0, high = k;
        i64 answer = -1;
        
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_val = val + mid;
            
            // Find how many candidates have votes > new_val
            // We can use binary search to find first candidate with value > new_val
            int cnt = n - (upper_bound(sorted_a.begin(), sorted_a.end(), make_pair(new_val + 1, -1)) - sorted_a.begin());
            
            if (cnt < m) {
                // Not enough candidates have votes > new_val, we might need more
                low = mid + 1;
            } else {
                // Too many candidates have votes > new_val, try smaller mid
                high = mid - 1;
                answer = mid;
            }
        }
        
        // If answer is still -1, check if already valid
        if (answer == -1) {
            int cnt = n - (upper_bound(sorted_a.begin(), sorted_a.end(), make_pair(a[idx] + 1, -1)) - sorted_a.begin());
            if (cnt < m) {
                res[idx] = 0;
            } else {
                // Need to calculate minimum votes to guarantee win
                low = 0, high = k;
                while (low <= high) {
                    i64 mid = (low + high) / 2;
                    i64 new_val = val + mid;
                    
                    // Find how many candidates have votes strictly greater than new_val
                    int cnt = n - (upper_bound(sorted_a.begin(), sorted_a.end(), make_pair(new_val + 1, -1)) - sorted_a.begin());
                    
                    // Find how many candidates have votes equal to new_val
                    int eq_cnt = upper_bound(sorted_a.begin(), sorted_a.end(), make_pair(new_val + 1, -1)) - 
                                 lower_bound(sorted_a.begin(), sorted_a.end(), make_pair(new_val, -1));
                    
                    // Check if we are in the top M
                    if (cnt < m && cnt + eq_cnt >= m) {
                        i64 need = 0;
                        // Find position of our candidate
                        int pos = lower_bound(sorted_a.begin(), sorted_a.end(), make_pair(new_val, -1)) - sorted_a.begin();
                        // Get sum of the top M candidates excluding ourself if needed
                        if (pos < n - cnt) {
                            need = new_val + 1 - sorted_a[n - cnt - 1].first;
                        }
                        if (need <= k - mid) {
                            answer = mid;
                            high = mid - 1;
                            continue;
                        }
                    }
                    
                    if (cnt >= m) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                
                if (answer != -1 && answer <= k) {
                    res[idx] = answer;
                } else {
                    res[idx] = -1;
                }
            }
        } else {
            res[idx] = answer;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    solve();
    return 0;
}