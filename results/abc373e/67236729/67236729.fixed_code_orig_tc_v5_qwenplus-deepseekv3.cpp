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
    
    vector<i64> B = A;
    sort(B.begin(), B.end());
    vector<i64> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + B[i];
    }
    
    i64 total = accumulate(A.begin(), A.end(), 0LL);
    i64 remaining = K - total;
    
    for (int i = 0; i < N; ++i) {
        i64 low = 0, high = remaining;
        i64 ans = -1;
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_val = A[i] + mid;
            
            int pos = upper_bound(B.begin(), B.end(), new_val) - B.begin();
            int cnt = N - pos;
            
            if (cnt < M) {
                i64 needed = 0;
                if (cnt < M - 1) {
                    int start = max(0, N - (M - 1 - cnt));
                    needed = prefix[N] - prefix[start];
                    needed -= (start > 0 ? B[start - 1] : 0);
                    needed += (start > 0 ? (new_val - B[start - 1]) : new_val);
                } else {
                    needed = 0;
                }
                
                if (new_val * (M - cnt) - needed <= remaining - mid) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }
        cout << ans << " ";
    }
    cout << "\n";
    
    return 0;
}