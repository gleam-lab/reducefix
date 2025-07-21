#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    map<int, int> indexMap;
    vector<long long> prefixSum(N + 1, 0);

    // Read all A values and create a map to index each value
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        indexMap[A[i]] = i;
    }

    // Create a prefix sum array to efficiently calculate the sum of top k indices
    for (int i = 1; i <= N; ++i) {
        prefixSum[i] = prefixSum[i - 1] + indexMap[i];
    }

    // Process each query
    while (Q--) {
        int B, k;
        cin >> B >> k;

        // Calculate the distance sum for the k-th closest point A to B
        long long distanceSum = 0;
        for (int i = k; i <= N; ++i) {
            distanceSum += abs(A[i - 1] - B);
        }

        // Convert the distance sum to the smallest x such that all points A_i are greater than x
        long long x = ceil(distanceSum / N);

        // Output the result
        cout << x << endl;
    }

    return 0;
}