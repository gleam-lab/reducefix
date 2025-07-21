#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    // The best case is to remove the smallest K/2 elements and the largest K/2 elements
    // This minimizes the range of the remaining elements
    int minB = A[K/2];
    int maxB = A[N - K/2 - 1];

    // If K is odd, we need to consider the second largest K/2 elements as well
    if (K % 2 == 1) {
        minB = min(minB, A[K/2 + 1]);
        maxB = max(maxB, A[N - K/2 - 2]);
    }

    cout << maxB - minB << endl;

    return 0;
}