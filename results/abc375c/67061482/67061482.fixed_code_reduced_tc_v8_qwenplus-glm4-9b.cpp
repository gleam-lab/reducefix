#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<double, double>> points(N);
    
    double x = 0.0, y = 0.0;
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    for (int i = 0; i < N; ++i) {
        double dx = points[i].first - x;
        double dy = points[i].second - y;
        x = points[i].first;
        y = points[i].second;
        double distance = sqrt(dx * dx + dy * dy);
        cout << fixed << setprecision(9) << distance;
        if (i < N - 1) {
            cout << " ";
        }
    }
    
    double dx = 0 - x;
    double dy = 0 - y;
    double return_distance = sqrt(dx * dx + dy * dy);
    cout << fixed << setprecision(9) << return_distance;
    
    return 0;
}