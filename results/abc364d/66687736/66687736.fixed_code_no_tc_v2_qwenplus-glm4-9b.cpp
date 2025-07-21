#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<long long> A(N);
    map<long long, int> countMap;

    // Read the positions of all points A
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        countMap[A[i]]++;
    }

    // Prepare the query pairs and sort them
    vector<pair<long long, int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }
    sort(queries.begin(), queries.end());

    // Use a map to keep track of the count of points less than the current point
    map<long long, int> pointCount;
    long long currentPoint = A[0];
    long long left = 0, right = 0;
    pointCount[currentPoint] = countMap[currentPoint];

    for (auto& query : queries) {
        long long Bj = query.first;
        int kj = query.second;

        while (left < N && A[left] < Bj) {
            left++;
            if (countMap[A[left]] > 0) {
                pointCount[A[left]]++;
            }
        }

        // Move right pointer to find the kj-th closest point
        while (right <= left && kj > pointCount[A[right]]) {
            pointCount[A[right]]--;
            right++;
        }

        // Output the distance for the kj-th closest point
        cout << abs(A[right] - Bj) << endl;
    }

    return 0;
}