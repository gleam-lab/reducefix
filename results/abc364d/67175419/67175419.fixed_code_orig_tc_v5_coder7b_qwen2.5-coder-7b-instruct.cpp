#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long coord;
    int index;
};

bool compare(Point a, Point b) {
    return a.coord < b.coord;
}

vector<long long> solve(vector<int>& a, vector<int>& b, vector<int>& k) {
    int n = a.size();
    int m = b.size();

    vector<Point> points(n * m);
    vector<long long> results(m);

    // Populate the points array with coordinates and their corresponding indices
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            points[j * n + i] = {abs(a[i] - b[j]), j};
        }
    }

    // Sort the points based on their distances
    sort(points.begin(), points.end(), compare);

    // For each query, find the k-th smallest distance
    for (int i = 0; i < m; ++i) {
        results[i] = points[k[i] - 1].coord;
    }

    return results;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(m);
    vector<int> k(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i] >> k[i];
    }

    vector<long long> results = solve(a, b, k);

    for (long long result : results) {
        cout << result << "\n";
    }

    return 0;
}