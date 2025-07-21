#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for(int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double cost = 0;
    for(int i = 1; i <= n; ++i) {
        cost += sqrt(pow(points[i % n].first - points[(i - 1) % n].first, 2) 
                    + pow(points[i % n].second - points[(i - 1) % n].second, 2));
    }

    cout << cost << endl;

    return 0;
}