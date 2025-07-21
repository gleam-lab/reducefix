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
    
    vector<i64> B = A;
    sort(B.begin(), B.end());
    
    vector<i64> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + B[i];
    }
    
    vector<i64> res(N);
    for (int i = 0; i < N; ++i) {
        i64 a = A[i];
        i64 low = 0, high = K, ans = -1;
        
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_a = a + mid;
            
            int pos = upper_bound(B.begin(), B.end(), new_a) - B.begin();
            int cnt = N - pos;
            
            if (cnt < M) {
                i64 sum = prefix[N] - prefix[pos];
                i64 needed = new_a * cnt - sum;
                if (needed <= K - mid) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }
        res[i] = ans;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << res[i] << " \n"[i == N - 1];
    }
    
    return 0;
}