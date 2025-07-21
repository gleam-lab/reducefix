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

    // Initialize maximum and minimum for the resulting sequence B
    int maxB = A[N - K - 1]; // The largest remaining element
    int minB = A[K];        // The smallest element we have to remove

    // The minimum possible value of maxB - minB is at least the difference
    // between the largest remaining and the smallest removed elements
    cout << maxB - minB << endl;

    return 0;
}