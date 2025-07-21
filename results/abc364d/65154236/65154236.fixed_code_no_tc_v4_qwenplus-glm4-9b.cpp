#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    vector<pair<long long, int>> queries;
    for (int j = 0; j < Q; ++j) {
        int B, k;
        cin >> B >> k;
        queries.emplace_back(abs(A[k] - B), k);
    }

    // Sort queries based on distance to B, then by k in case of ties
    sort(queries.begin(), queries.end());

    // Create a vector to store the sorted distances from A[i] to B[j]
    vector<long long> distances(N + 1);

    for (auto& q : queries) {
        int k = q.second;
        long long distance = q.first;
        distances[k] = distance;
    }

    // Sort the distances and output the results
    sort(distances.begin(), distances.end());
    for (auto& q : queries) {
        int k = q.second;
        cout << distances[k] << endl;
    }

    return 0;
}