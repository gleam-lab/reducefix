#include <queue>

// Use a min-heap to store the vertices for efficient retrieval of the k-th largest vertex.
priority_queue<int, vector<int>, greater<int>> minHeap;

// In the Union function, after merging the sets, do the following:
if (V[u].size() < V[v].size()) {
    std::swap(V[u], V[v]); // Swap the sets to maintain a consistent order
}
for (int num : V[v]) {
    V[u].insert(num);
    minHeap.push(num); // Push the vertices into the min-heap
}
while (minHeap.size() > k) {
    V[u].erase(minHeap.top()); // Remove the smallest element from the set
    minHeap.pop();
}