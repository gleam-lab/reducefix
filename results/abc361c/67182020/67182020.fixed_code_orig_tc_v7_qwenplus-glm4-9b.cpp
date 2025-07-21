#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    
    // Input the sequence A
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort the sequence to make it easier to find the minimum and maximum values
    sort(A.begin(), A.end());
    
    // If K is even, we can simply remove the middle K/2 elements from both ends
    // to find the min and max values of the remaining elements.
    if (K % 2 == 0) {
        int leftMax = A[N - 1 - K / 2];
        int rightMin = A[K / 2];
        cout << leftMax - rightMin << endl;
    } else {
        // If K is odd, we need to consider removing K/2 elements from one end and K/2 + 1 from the other
        // to find the min and max values of the remaining elements.
        int leftMax = A[N - 1 - (K / 2 + 1)];
        int rightMin = A[K / 2];
        cout << max(leftMax - rightMin, A[N - 2 - (K / 2 + 1)] - A[K / 2 + 1]) << endl;
    }

    return 0;
}