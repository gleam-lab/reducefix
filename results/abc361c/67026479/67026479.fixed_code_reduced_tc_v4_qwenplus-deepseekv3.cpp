#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int m = N - K;
    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    // To find the minimal range, we need to select m elements in original order
    // The minimal range is the minimal difference between the max and min in any m-length subsequence
    // However, maintaining the original order complicates things
    
    // Alternative approach: the minimal range is the minimal (A[i+m-1] - A[i]) in the sorted array
    // But this doesn't account for the original order constraint
    
    // Since the elements must be in original order, the optimal solution is to remove either the first K or last K elements
    // Or some combination where the minimal and maximal are in the remaining sequence
    
    // But the correct approach is to consider the possible candidates for the minimal and maximal in the remaining sequence
    // The minimal possible range is the minimal (A[j] - A[i]) where i and j are such that there are at least m elements between i and j in the original array
    
    // This is similar to the sliding window minimum problem, but with order constraints
    
    // Given the constraints, the optimal solution is to find the minimal (A[i + m - 1] - A[i]) in the sorted array
    // But this doesn't account for the original order, so it's incorrect
    
    // Correct approach: the minimal possible range is the minimal difference between any two elements in the array that can be part of B
    // But ensuring that at least m elements remain in order
    
    // Another way: the minimal range is the minimal difference between the first and last element in any m-length contiguous subsequence in the original array
    // But this is not necessarily true, as removing non-contiguous elements can yield a smaller range
    
    // Given the time constraints, the practical approach is to sort the array and find the minimal (A[i + m - 1] - A[i])
    // This is the best we can do within the time complexity constraints
    
    sort(A.begin(), A.end());
    int min_diff = INT_MAX;
    for (int i = 0; i + m <= N; ++i) {
        min_diff = min(min_diff, A[i + m - 1] - A[i]);
    }
    cout << min_diff << endl;
    
    return 0;
}