#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, k;
};

bool compare(const Point& a, const Point& b) {
    return a.x < b.x;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<Point> points(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x;
        points[i].k = i + 1;  // Store k as 1-based index
    }
    
    // Sort points by their x-coordinate
    sort(points.begin(), points.end(), compare);
    
    vector<double> distances(Q);
    
    for (int q = 0; q < Q; ++q) {
        int b;
        cin >> b >> points[q].k;
        
        // Binary search to find the k-th closest point
        int low = 0, high = N - 1;
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (points[mid].x >= b) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }
        
        // Calculate the distance from the closest point found to b
        int closestIndex = low;
        double distance = abs(points[closestIndex].x - b);
        distances[q] = distance;
        
        // Output the result for this query
        cout << fixed << setprecision(0) << distance << endl;
    }
    
    return 0;
}