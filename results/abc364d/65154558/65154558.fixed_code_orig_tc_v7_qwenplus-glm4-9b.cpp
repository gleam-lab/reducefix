#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 200000; // Adjusted N to avoid overflow

int a[N + 1]; // Assuming a[i] holds the number of points from A to B that are within i distance

void sort_points(int &x, int &y) {
    if (x > y) swap(x, y);
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> b(q), k(q);
    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> k[i];
    }

    // Sort b and k together for easier processing
    pair<int, int> points[100000];
    for (int i = 0; i < q; ++i) {
        points[i] = make_pair(b[i], k[i]);
    }
    sort(points, points + q);

    // Initialize the array where each index i holds the number of points within i distance
    for (int i = 0; i <= 2 * N; ++i) {
        a[i] = 0;
    }

    // Populate the array with distances
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int left = max(x - N, 0), right = min(x + N, 2 * N);
        for (int j = left; j <= right; ++j) {
            a[j]++;
        }
    }

    // Output the results
    for (int i = 0; i < q; ++i) {
        int dist = points[i].first;
        int k_j = points[i].second;
        int answer = 0;
        for (int j = 0; j < k_j; ++j) {
            answer += a[j];
        }
        // If we haven't found enough points by then, we need to search further
        while (answer < k_j && dist < 2 * N) {
            dist++;
            answer += a[dist];
        }
        cout << dist << endl;
    }

    return 0;
}