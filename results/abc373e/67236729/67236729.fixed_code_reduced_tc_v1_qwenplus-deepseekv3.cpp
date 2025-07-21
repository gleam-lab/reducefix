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
    for (auto &a : A) {
        cin >> a;
        K -= a;
    }
    
    vector<i64> B = A;
    sort(B.begin(), B.end());
    
    vector<i64> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + B[i];
    }
    
    auto check = [&](i64 val, i64 X) -> bool {
        i64 new_val = val + X;
        int pos = upper_bound(B.begin(), B.end(), new_val) - B.begin();
        int cnt = N - pos;
        
        if (cnt >= M) {
            return false;
        }
        
        i64 needed = 0;
        if (cnt < M - 1) {
            int take = M - 1 - cnt;
            if (pos - take < 0) {
                return false;
            }
            needed = new_val * take - (prefix[pos] - prefix[pos - take]);
        }
        
        return needed <= K - X;
    };
    
    for (int i = 0; i < N; ++i) {
        i64 val = A[i];
        i64 low = 0, high = K, ans = -1;
        
        while (low <= high) {
            i64 mid = (low + high) / 2;
            if (check(val, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        cout << ans << " ";
    }
    
    cout << "\n";
    return 0;
}