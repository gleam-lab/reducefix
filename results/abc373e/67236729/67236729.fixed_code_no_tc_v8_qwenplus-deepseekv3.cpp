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
    for (auto &a : A) cin >> a;
    
    vector<pair<i64, int>> sorted(N);
    for (int i = 0; i < N; ++i) {
        sorted[i] = {A[i], i};
    }
    sort(sorted.rbegin(), sorted.rend());
    
    vector<i64> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted[i].first;
    }
    
    vector<i64> res(N, -1);
    i64 remaining = K - accumulate(A.begin(), A.end(), 0LL);
    
    for (int i = 0; i < N; ++i) {
        i64 ai = A[i];
        
        // Binary search for the minimal X
        i64 low = 0, high = remaining, ans = -1;
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_ai = ai + mid;
            
            // Find how many candidates have votes > new_ai
            auto it = upper_bound(sorted.begin(), sorted.end(), make_pair(new_ai, N), greater<pair<i64, int>>());
            int cnt = it - sorted.begin();
            
            if (cnt < M) {
                // Already meets the condition
                ans = mid;
                high = mid - 1;
            } else {
                // Need to ensure we can push enough candidates below new_ai
                i64 needed = prefix[M] - prefix[cnt] - (M - cnt) * new_ai;
                if (remaining - mid >= needed) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        
        res[i] = ans;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << res[i] << " \n"[i == N - 1];
    }
    
    return 0;
}