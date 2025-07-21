#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // Sort the array to easily find the minimum and maximum after removing elements
    sort(A.begin(), A.end());
    
    // The minimum possible value of max(B) - min(B) after removing K elements
    int result = A[N-1] - A[0]; // Initial value without removing any elements
    
    // Consider removing elements from the start and end of the sorted array
    for (int i = 0; i <= min(K, N-1); i++) {
        // Remove one element from the end
        result = min(result, A[N-2-i] - A[i]);
        // If we still have the chance to remove more, consider removing two elements from the start
        if (K - i >= 2) {
            result = min(result, A[N-3-i] - A[1+i]);
        }
        // If we can remove exactly K elements, break the loop
        if (i == K-1) break;
    }
    
    cout << result << endl;
    return 0;
}