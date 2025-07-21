#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> A(n), B(n);
        for(int i=0; i<n; i++) cin >> A[i];
        for(int i=0; i<n; i++) cin >> B[i];

        // Sort based on A_i in descending order
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end());

        // Calculate initial sum of B_i for first k elements
        long long sum_B = accumulate(B.begin(), B.begin()+k, 0LL);

        // Initialize result with the product of max A_i and sum of first k B_i
        long long res = 1LL * A[0] * sum_B;

        // Iterate through the remaining elements to find the minimum product
        for(int i=1; i<=n-k; i++) {
            // Update sum_B by removing the smallest element and adding the next largest B_i
            sum_B -= B[k-i];
            sum_B += B[n-i-1];
            
            // Update the result with the new product if it's smaller
            res = min(res, 1LL * A[i] * sum_B);
        }

        cout << res << '\n';
    }
    return 0;
}