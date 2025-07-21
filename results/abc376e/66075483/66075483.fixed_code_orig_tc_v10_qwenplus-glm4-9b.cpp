#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define int long long
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;

int t, n, k;
int A[N], B[N];
int sums[N]; // Precompute prefix sums for array B

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
            sums[i + 1] = sums[i] + B[i]; // Compute prefix sums for array B
        }
        
        int ans = inf;
        sort(A, A + n); // Sort A to get the maximum element at A[n-1]
        
        // We need to find the minimum value of (max_A_i) * (sum_B_j) for j from 0 to k-1
        // We can do this by calculating the sum of B for subsets of size k
        // and multiplying by the maximum element from A
        for (int i = 0; i <= n - k; ++i) { // i is the start index of the range
            int sum_B = sums[i + k - 1] - sums[i]; // Sum of B for the subset
            ans = min(ans, A[n - 1] * sum_B);
        }
        
        cout << ans << endl;
    }
    return 0;
}