#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
int t, n, k;
int A[maxN], B[maxN], ratios[maxN];

bool cmp(int i, int j) {
    if (A[i] / B[i] != A[j] / B[j]) return A[i] / B[i] > A[j] / B[j];
    return B[i] < B[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> n >> k;
        long long maxA = 0, sumB = 0, res = LLONG_MAX;
        
        for (int i = 0; i < n; ++i) {
            cin >> A[i] >> B[i];
            ratios[i] = i;
        }
        
        sort(ratios, ratios + n, cmp);
        
        for (int i = 0; i < n; ++i) {
            if (i >= k) break;
            int idx = ratios[i];
            sumB += B[idx];
            maxA = max(maxA, A[idx]);
            res = min(res, maxA * sumB);
        }
        
        cout << res << '\n';
    }
    
    return 0;
}