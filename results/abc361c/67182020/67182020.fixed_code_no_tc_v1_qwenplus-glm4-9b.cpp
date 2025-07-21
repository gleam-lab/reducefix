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
    
    // Sort the array to find the minimum possible range
    sort(A.begin(), A.end());
    
    // If K is even, we can directly take the middle two elements after removal
    if (K % 2 == 0) {
        cout << A[N - K / 2] - A[K / 2] << endl;
    } else {
        // If K is odd, we consider the case where we might need to skip an element
        cout << max((long long)A[N - 1 - (K / 2) + 1] - A[K / 2], (long long)A[N - 1 - (K / 2)] - A[K / 2 + 1]) << endl;
    }
    
    return 0;
}