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

    // Sort the array
    sort(A.begin(), A.end());

    // We'll find the smallest range after removing K elements
    // We do this by considering only the smallest K elements and the largest N-K elements
    // that could be removed
    int minRange = A[N-1] - A[0]; // Initial range without any removal

    // Now we look for a better range by trying to remove elements
    // We check the range between the first K elements and the remaining elements
    for (int i = 0; i <= K; ++i) {
        int currentMin = A[i];
        int currentMax = A[N-1-i];
        minRange = min(minRange, currentMax - currentMin);
    }

    cout << minRange << endl;
    return 0;
}