#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M, K;
    cin >> N >> M >> K;
    
    vector<i64> A(N);
    for (i64 &a : A) {
        cin >> a;
    }
    
    vector<i64> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    
    vector<i64> prefix(N + 1, 0);
    for (i64 i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }
    
    i64 total = prefix[N];
    i64 remaining = K - total;
    
    for (i64 i = 0; i < N; ++i) {
        i64 a = A[i];
        
        i64 low = 0, high = remaining;
        i64 ans = -1;
        
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_a = a + mid;
            
            i64 pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_a) - sorted_A.begin();
            i64 count = N - pos;
            
            if (count < M) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (ans != -1) {
            i64 new_a = a + ans;
            i64 pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_a) - sorted_A.begin();
            i64 needed = 0;
            
            if (count >= M) {
                ans = -1;
            } else {
                i64 start = N - (M - 1);
                if (start < 0) start = 0;
                i64 sum = prefix[N] - prefix[start];
                
                i64 required = (new_a + 1) * (M - 1 - (N - pos)) - (sum - (pos <= start ? 0 : prefix[pos] - prefix[start]));
                if (required > remaining - ans) {
                    ans = -1;
                }
            }
        }
        
        cout << (ans == -1 ? -1 : ans) << " ";
    }
    
    cout << endl;
    
    return 0;
}