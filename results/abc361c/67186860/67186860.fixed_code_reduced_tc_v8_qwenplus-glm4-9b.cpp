#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minRangeAfterRemoving(vector<int>& A, int K) {
    sort(A.begin(), A.end()); // Sort the array

    if (K % 2 == 0) {
        // For even K, remove the smallest and largest elements
        return A[A.size() - 1] - A[0];
    } else {
        // For odd K, remove the smallest and the next smallest/largest elements
        return A[A.size() - K] - A[1];
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << minRangeAfterRemoving(A, K) << endl;
    return 0;
}