#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> points(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    double totalCost = 0.0;
    
    // Calculate the distance from the origin to the first point
    totalCost += sqrt(pow(points[0].first, 2) + pow(points[0].second, 2));
    
    // Calculate the distance from point i to point i+1
    for (int i = 0; i < N - 1; ++i) {
        double xDist = points[i].first - points[i + 1].first;
        double yDist = points[i].second - points[i + 1].second;
        totalCost += sqrt(xDist * xDist + yDist * yDist);
    }
    
    // Calculate the distance from the last point back to the origin
    double lastPointDist = sqrt(pow(points[N - 1].first, 2) + pow(points[N - 1].second, 2));
    totalCost += lastPointDist;
    
    cout.precision(20); // To ensure precision up to 10^-6
    cout << fixed << totalCost << endl;
    
    return 0;
}