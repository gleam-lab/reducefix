#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N), B(N);
    
    // Input votes each candidate has received so far
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Calculate votes needed to guarantee victory
    for (int i = 0; i < N; ++i) {
        B[i] = max(0, A[i] - (K - A[i]) + 1 - M);
    }
    
    // Sort B to prepare for prefix sum and binary search
    sort(B.begin(), B.end());
    
    // Compute prefix sum of B
    vector<int> prefixSum(B.size() + 1, 0);
    for (int i = 1; i <= B.size(); ++i) {
        prefixSum[i] = prefixSum[i - 1] + B[i - 1];
    }
    
    // Binary search to find minimum additional votes needed
    for (int i = 0; i < N; ++i) {
        int lower = 0, upper = K - (K - A[i]) + 1 - M;
        while (lower < upper) {
            int mid = (lower + upper + 1) / 2;
            if (prefixSum[i] + mid >= prefixSum[i + M]) {
                upper = mid - 1;
            } else {
                lower = mid;
            }
        }
        A[i] = upper;
    }
    
    // Output the result
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    return 0;
}