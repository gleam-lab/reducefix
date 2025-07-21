#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<long long> A(N), B(Q);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < Q; ++i) {
        cin >> B[i];
    }

    for (int i = 0; i < Q; ++i) {
        // Calculate all distances from B[i] to points in A
        vector<pair<long long, int>> distances;
        for (int j = 0; j < N; ++j) {
            long long distance = abs(B[i] - A[j]);
            distances.emplace_back(distance, j);
        }

        // Sort by distance
        sort(distances.begin(), distances.end());

        // Output the k-th closest distance
        cout << distances[i].first << endl;
    }

    return 0;
}