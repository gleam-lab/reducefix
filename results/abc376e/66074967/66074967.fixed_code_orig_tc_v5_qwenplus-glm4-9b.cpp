#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 9;

vector<int> A, B;
vector<int> B_prev;

int main() {
    int n, k;
    cin >> n >> k;
    
    A.resize(n);
    B.resize(n);
    
    for (int &x : A) cin >> x;
    for (int &x : B) cin >> x;
    
    vector<int> A_sorted(A.begin(), A.end());
    sort(A_sorted.begin(), A_sorted.end());
    
    for (int i = 0; i < n; ++i) {
        // Find the largest element in A_sorted that is <= A[i]
        auto it = lower_bound(A_sorted.begin(), A_sorted.end(), A[i]);
        if (it != A_sorted.begin()) --it;
        B_prev[i] = B[*it - 1];
    }
    
    // Sort B_prev to use it in DP
    sort(B_prev.begin(), B_prev.end());
    
    // Dynamic programming to find min sums
    vector<long long> dp1(n + 1), dp2(n + 1);
    fill(dp1.begin(), dp1.end(), 1e18), fill(dp2.begin(), dp2.end(), 1e18);
    dp1[0] = dp2[0] = 0;
    
    for (int i = 0; i < n; ++i) {
        dp1[i + 1] = min(dp1[i + 1], dp1[i] + A[i]);
        dp2[i + 1] = min(dp2[i + 1], dp2[i] + B_prev[i]);
    }
    
    // Output the result for this test case
    cout << dp1[k] * dp2[k] << endl;
    
    return 0;
}