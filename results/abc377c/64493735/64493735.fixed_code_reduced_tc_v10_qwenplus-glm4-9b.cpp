#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

// Function to check if a point is within the grid boundaries
bool isValid(int x, int y, int N) {
    return x >= 1 && x <= N && y >= 1 && y <= N;
}

// Function to get the capture region for a piece at (x, y)
vector<Point> getCaptureRegion(int x, int y, int N) {
    vector<Point> region = {
        Point(x + 2, y + 1), Point(x + 1, y + 2), Point(x - 1, y + 2),
        Point(x - 2, y + 1), Point(x - 2, y - 1), Point(x - 1, y - 2),
        Point(x + 1, y - 2), Point(x + 2, y - 1)
    };
    // Filter the valid points within the grid boundaries
    vector<Point> validRegion;
    for (auto p : region) {
        if (isValid(p.x, p.y, N)) {
            validRegion.push_back(p);
        }
    }
    return validRegion;
}

int main() {
    int N, M;
    cin >> N >> M;
    set<Point> allCaptureRegions;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        vector<Point> region = getCaptureRegion(a, b, N);
        for (auto p : region) {
            allCaptureRegions.insert(p);
        }
    }

    // Calculate the number of valid squares
    long long totalSquares = N * N;
    long long invalidSquares = allCaptureRegions.size();
    cout << totalSquares - invalidSquares << endl;

    return 0;
}