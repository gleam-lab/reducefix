#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    
    // Reading the array elements
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array
    sort(A.begin(), A.end());
    
    // Calculate the minimum possible value of max(B) - min(B)
    // We remove K elements from the array
    // - For K/2 elements from the smallest side
    // - For K/2 elements from the largest side
    // (or a bit more from the largest side if K is odd)
    int min_diff;
    if (K % 2 == 0) {
        min_diff = A[N - K/2] - A[K/2];
    } else {
        min_diff = max(A[N - K/2 - 1] - A[K/2 + 1], A[N - K/2] - A[K/2]);
    }
    
    // Output the result
    cout << min_diff << endl;
    
    return 0;
}