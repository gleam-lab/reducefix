#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<pair<int, int>> all_distances;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < Q; ++j) {
            int b, k;
            cin >> b >> k;
            all_distances.push_back({abs(A[i] - b), i});
        }
    }

    // Sort all distances
    sort(all_distances.begin(), all_distances.end());

    // For each query point, find the k-th closest point
    for (const auto& dist : all_distances) {
        // dist.first is the distance, dist.second is the index in A
        // Output the distance
        cout << dist.first << endl;
    }

    return 0;
}