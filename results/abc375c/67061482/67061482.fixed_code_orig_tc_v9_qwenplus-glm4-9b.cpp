#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> points(N + 1); // To store the points including the origin.
    points[0] = make_pair(0, 0); // Origin point.
    
    int x, y;
    for (int i = 1; i <= N; ++i) {
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }
    
    double cost = 0.0;
    for (int i = 1; i <= N; ++i) {
        int ax = points[i].first;
        int ay = points[i].second;
        int bx = points[i - 1].first;
        int by = points[i - 1].second;
        cost += sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
    }
    
    // Add the distance back to the origin after the loop.
    int ox = points[N].first;
    int oy = points[N].second;
    cost += sqrt(pow(ox, 2) + pow(oy, 2));

    cout.precision(10);
    cout << fixed << cost << endl;
    
    return 0;
}