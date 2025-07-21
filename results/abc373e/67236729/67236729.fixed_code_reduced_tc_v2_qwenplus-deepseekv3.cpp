#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    i64 K;
    cin >> N >> M >> K;
    
    vector<i64> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<pair<i64, int>> sorted(N);
    for (int i = 0; i < N; ++i) {
        sorted[i] = {A[i], i};
    }
    sort(sorted.begin(), sorted.end());
    
    vector<i64> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted[i].first;
    }
    
    vector<i64> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        i64 target = A[i];
        int pos = upper_bound(sorted.begin(), sorted.end(), make_pair(target, N)) - sorted.begin();
        
        i64 low = 0, high = K;
        i64 res = -1;
        while (low <= high) {
            i64 mid = low + (high - low) / 2;
            i64 new_votes = target + mid;
            
            auto it = upper_bound(sorted.begin(), sorted.end(), make_pair(new_votes, N));
            int cnt = sorted.end() - it;
            
            if (cnt < M) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (res != -1) {
            i64 remaining = K - res;
            i64 new_votes = target + res;
            auto it = upper_bound(sorted.begin(), sorted.end(), make_pair(new_votes, N));
            int cnt = sorted.end() - it;
            
            if (cnt >= M) {
                res = -1;
            } else {
                i64 sum_above = 0;
                if (cnt > 0) {
                    sum_above = prefix[N] - prefix[N - cnt];
                }
                i64 required = new_votes * cnt - sum_above;
                if (required > remaining) {
                    res = -1;
                }
            }
        }
        
        ans[i] = res;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << (ans[i] == -1 ? -1 : max(0LL, ans[i])) << " ";
    }
    cout << "\n";
    
    return 0;
}