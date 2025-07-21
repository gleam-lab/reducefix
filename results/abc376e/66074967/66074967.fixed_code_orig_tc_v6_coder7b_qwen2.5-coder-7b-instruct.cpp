#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

const int inf = 1e9 + 7;

int solve(int n, int k, vector<int>& A, vector<int>& B) {
    // Sort arrays A and B
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Initialize variables to store the result
    int ans = inf;

    // Use a sliding window approach to find the minimum product
    for (int i = 0; i <= n - k; ++i) {
        int max_A = A[i + k - 1];  // Maximum value in the current window of A
        int sum_B = 0;
        for (int j = 0; j < k; ++j) {
            sum_B += B[i + j];  // Sum of the corresponding values in B
        }
        ans = min(ans, max_A * sum_B);  // Update the minimum product
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }

        // Solve the problem for the current test case
        int result = solve(n, k, A, B);
        cout << result << endl;
    }
    return 0;
}