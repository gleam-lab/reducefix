#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> A(n), B(n);
        for(int i = 0; i < n; i++) cin >> A[i];
        for(int i = 0; i < n; i++) cin >> B[i];

        // Sort A in descending order and B in ascending order
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end());

        // Calculate the result using the first K elements from both sorted arrays
        int res = 0;
        for(int i = 0; i < k; i++) {
            res += A[i] * B[i];
        }

        cout << res << '\n';
    }
    
    return 0;
}