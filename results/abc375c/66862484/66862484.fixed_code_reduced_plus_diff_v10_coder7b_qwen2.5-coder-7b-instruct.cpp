#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the Euclidean distance between two points
double euclideanDistance(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double totalCost = 0;

    // Calculate the total cost of moving from each point to the next and back to the origin
    for (int i = 0; i < N; ++i) {
        int x1 = points[i].first;
        int y1 = points[i].second;
        int x2 = points[(i + 1) % N].first;
        int y2 = points[(i + 1) % N].second;
        totalCost += euclideanDistance(x1, y1, x2, y2);
    }

    // Print the total cost with high precision
    printf("%.15f\n", totalCost);

    return 0;
}