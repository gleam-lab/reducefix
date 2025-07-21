#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        
        vector<int> A(n), B(n);
        for(int i = 0; i < n; ++i) cin >> A[i];
        for(int i = 0; i < n; ++i) cin >> B[i];
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end(), greater<int>());
        
        int max_A = A[k-1];
        int sum_B = 0;
        for(int i = 0; i < k; ++i) sum_B += B[i];
        
        cout << max_A * sum_B << '\n';
    }
    return 0;
}