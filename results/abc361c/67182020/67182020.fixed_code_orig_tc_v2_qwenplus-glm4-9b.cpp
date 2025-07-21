#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Min-heap to track the smallest values in the current window
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // Max-heap to track the largest values in the current window
    priority_queue<int> maxHeap;

    int minDiff = INT_MAX;

    // Initialize the first window
    for (int i = 0; i < K; i++) {
        minHeap.push(A[i]);
        maxHeap.push(-A[i]);
    }

    // Calculate the difference for the first window
    int currentMin = minHeap.top();
    int currentMax = -maxHeap.top();
    minDiff = min(minDiff, currentMax - currentMin);

    // Slide the window across the array
    for (int i = K; i < N; i++) {
        // Remove the element going out of the window
        minHeap.pop();
        maxHeap.pop();
        minHeap.push(A[i - K]);
        maxHeap.push(-A[i - K]);

        // Update the minimum and maximum for the current window
        currentMin = minHeap.top();
        currentMax = -maxHeap.top();

        // Calculate the new difference and update minDiff if necessary
        minDiff = min(minDiff, currentMax - currentMin);
    }

    cout << minDiff << endl;

    return 0;
}