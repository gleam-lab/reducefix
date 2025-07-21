#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2e5 + 5;
int a[N];

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<pair<int, int>> queries;
    queries.resize(Q);

    for (int i = 0; i < Q; i++) {
        int b, k;
        cin >> b >> k;
        queries[i] = {b, k};
    }

    // Sort points A to find the closest k-th ones
    vector<pair<int, int>> sorted_points(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sorted_points[i] = {a[i], i};
    }
    sort(sorted_points.begin(), sorted_points.end());

    // For each query, find the k-th closest point to B_j
    for (auto& [b, k] : queries) {
        int left = 0, right = N - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (sorted_points[mid].first - sorted_points[k - 1].first < b - sorted_points[mid].first) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        cout << abs(sorted_points[left].first - b) << endl;
    }

    return 0;
}