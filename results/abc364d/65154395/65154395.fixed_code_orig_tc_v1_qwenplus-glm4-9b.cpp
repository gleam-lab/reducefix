#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int pos;
    bool isA;  // true if it's from array A, false if from B
};

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<Point> points;
    points.reserve(N + Q);

    // Read points A
    for (int i = 0; i < N; ++i) {
        int pos;
        cin >> pos;
        points.emplace_back(pos, true);
    }

    // Read points B and k_j
    for (int i = 0; i < Q; ++i) {
        int pos, k_j;
        cin >> pos >> k_j;
        points.emplace_back(pos, false);
    }

    // Sort points by position
    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        return a.pos < b.pos;
    });

    // Process each B_j
    for (int i = 0; i < Q; ++i) {
        int k_j = 1;  // Start from the first point
        int j = 0;
        while (k_j > 0) {
            if (points[j].isA) k_j--;
            j++;
        }
        // The j-th point is the k-th closest to B_i
        int distance = abs(points[j - 1].pos - points[i + N].pos);  // j-1 because i+1 is the index in A
        cout << distance << endl;
    }

    return 0;
}