#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int N = 2e5 + 5;

vector<int> adjList[N];

int findKthLargest(int node, int k) {
    set<int> neighbors;
    for (int neighbor : adjList[node]) {
        neighbors.insert(neighbor);
    }
    set<int> sortedNeighbors(neighbors);
    if (k > sortedNeighbors.size()) {
        return -1;
    }
    return *(--next(sortedNeighbors.begin(), k - 1));
}

int main() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            // Add edge between vertices a and b
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        } else if (t == 2) {
            // Find the k-th largest vertex connected to vertex b
            cout << findKthLargest(b, k) << '\n';
        }
    }
    return 0;
}