#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort the array to easily find the min and max of the remaining elements
    sort(A.begin(), A.end());
    
    // We are removing K elements, so we will have N-K remaining elements
    // If K is even, we can safely remove one element from both ends
    // If K is odd, we need to determine if it's better to remove more from one end or split the removal evenly
    if (K % 2 == 0) {
        // If K is even, simply remove one element from each end
        cout << A[N-K] - A[K-1] << endl;
    } else {
        // If K is odd, calculate the scenario where we remove max(K//2) elements from one end and K//2 + 1 from the other
        int k2 = K / 2;
        int maxIndex = max(K2 - 1, K2 + 1);
        cout << A[N-K] - A[maxIndex] << endl;
    }
    
    return 0;
}