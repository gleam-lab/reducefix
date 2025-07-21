#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int &x : A) cin >> x;

    int maxB = INT_MIN, minB = INT_MAX;
    int currentSum = 0, count = 0;

    // Initial window of size N
    for (int i = 0; i < N; ++i) {
        currentSum += A[i];
        count++;
        if (count == K) {
            maxB = max(maxB, currentSum);
            minB = min(minB, currentSum);
        }
    }

    // Slide the window K times
    for (int i = 0; i < K; ++i) {
        currentSum -= A[i]; // Remove A[i] from the window
        currentSum += A[i + K]; // Add A[i + K] to the window
        count--;
        maxB = max(maxB, currentSum);
        minB = min(minB, currentSum);
    }

    cout << maxB - minB << endl;
    return 0;
}