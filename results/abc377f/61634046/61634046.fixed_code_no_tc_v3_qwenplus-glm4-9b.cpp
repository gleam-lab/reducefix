#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int a, b, d;
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<Point> points(m);
    for (int i = 0; i < m; i++) {
        cin >> points[i].a >> points[i].b;
        points[i].d = (points[i].a + points[i].b) % 2;
    }
    
    // Sort points by their coordinates to prepare for counting inversions
    sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
        if (p1.a == p2.a) return p1.b < p2.b;
        return p1.a < p2.a;
    });
    
    // Calculate the number of inversions in each row
    vector<long long> rowInversions(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        // Count how many points are to the right of the current point in the same row
        long long count = 0;
        for (int j = 0; j < m; j++) {
            if (points[j].a == i && points[j].d == 0) {
                count++;
                if (points[j].b > i) {
                    count++;
                }
            }
        }
        rowInversions[i] = count;
    }
    
    // Calculate the number of inversions in each column
    vector<long long> colInversions(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        // Count how many points are below the current point in the same column
        long long count = 0;
        for (int j = 0; j < m; j++) {
            if (points[j].b == i && points[j].d == 1) {
                count++;
                if (points[j].a > i) {
                    count++;
                }
            }
        }
        colInversions[i] = count;
    }
    
    // Calculate the total number of inversions
    long long inversions = 0;
    for (int i = 1; i <= n; i++) {
        inversions += rowInversions[i] + colInversions[i];
    }
    
    // The number of empty squares is the total number of squares minus the number of inversions
    cout << (n * n) - inversions << endl;
    
    return 0;
}