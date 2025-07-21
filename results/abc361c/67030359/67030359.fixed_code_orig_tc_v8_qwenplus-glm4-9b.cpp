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

    // Sort the array
    sort(A.begin(), A.end());

    // Initial maximum difference after removing K elements from both ends
    int max_diff = A[N - K] - A[K - 1];

    // Iterate through the array to find the minimum possible difference
    for (int i = 0; i < K; i++) {
        // Calculate the new difference if we remove some elements in the end
        int new_diff = A[N - K - i - 1] - A[i];
        max_diff = min(max_diff, new_diff);
    }

    cout << max_diff << endl;

    return 0;
}