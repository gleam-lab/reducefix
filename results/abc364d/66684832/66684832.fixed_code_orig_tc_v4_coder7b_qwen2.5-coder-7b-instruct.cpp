#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    int coord, index;
};

// Comparator for sorting points based on their coordinate
bool comparePoints(const Point& a, const Point& b) {
    return a.coord < b.coord;
}

// Comparator for the min-heap
struct CompareDist {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].coord;
        points[i].index = i;
    }

    // Sort points by their coordinate
    sort(points.begin(), points.end(), comparePoints);

    while (q--) {
        int x, k;
        cin >> x >> k;

        // Min-heap to store k smallest distances
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareDist> pq;

        for (int i = 0; i < n; ++i) {
            int dist = abs(points[i].coord - x);
            pq.push({dist, points[i].index});

            // If heap size exceeds k, remove the largest distance
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // The top of the heap is the k-th smallest distance
        cout << pq.top().first << endl;
    }

    return 0;
}