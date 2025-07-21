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
    
    vector<pair<i64, int>> sortedA(N);
    for (int i = 0; i < N; ++i) {
        sortedA[i] = {A[i], i};
    }
    sort(sortedA.begin(), sortedA.end());
    
    vector<i64> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i].first;
    }
    
    vector<i64> res(N, -1);
    
    for (int i = 0; i < N; ++i) {
        i64 a = A[i];
        i64 low = 0, high = K, ans = -1;
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_a = a + mid;
            
            int pos = upper_bound(sortedA.begin(), sortedA.end(), make_pair(new_a, N)) - sortedA.begin();
            int cnt = N - pos;
            
            if (cnt < M) {
                i64 needed = 0;
                int start = max(0, N - (M - 1));
                if (pos < start) {
                    needed = (new_a + 1) * (start - pos) - (prefix[start] - prefix[pos]);
                }
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