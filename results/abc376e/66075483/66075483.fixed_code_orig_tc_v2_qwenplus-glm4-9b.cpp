#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int32_t main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];
        
        // Sort A in descending order
        sort(A.begin(), A.end(), greater<int>());
        
        // Initialize variables for the sliding window
        long long sum = 0, minSum = 0;
        int start = 0;
        
        // Calculate the sum of the first K-1 elements in A
        for (int i = 0; i < K-1; ++i) {
            sum += A[i];
        }
        
        // Initialize minimum sum for the first window
        minSum = sum;
        
        // Slide the window across A
        for (int end = K-1; end < N; ++end) {
            sum += A[end] - A[start];
            start++;
            minSum = min(minSum, sum);
        }
        
        // The minimum answer for this test case is the product of the maximum A_i and the minimum possible sum of B_i
        cout << A[0] * minSum << endl;
    }
    return 0;
}