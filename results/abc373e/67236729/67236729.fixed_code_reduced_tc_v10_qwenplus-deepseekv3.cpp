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
    
    if (M == N) {
        for (int i = 0; i < N; ++i) {
            cout << 0 << " ";
        }
        cout << "\n";
        return 0;
    }
    
    vector<i64> B = A;
    sort(B.begin(), B.end());
    vector<i64> prefix(N + 1, 0);
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
                i64 needed = 0;
                if (cnt < M - 1) {
                    int start = N - (M - 1 - cnt);
                    if (start >= 0) {
                        needed = prefix[N] - prefix[start] - new_a * (M - 1 - cnt);
                    }
                }
                
                if (new_a * (M - 1) - (prefix[N] - prefix[N - (M - 1)] - needed) <= K - mid) {
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
    
    for (i64 num : res) {
        cout << num << " ";
    }
    cout << "\n";
    
    return 0;
}