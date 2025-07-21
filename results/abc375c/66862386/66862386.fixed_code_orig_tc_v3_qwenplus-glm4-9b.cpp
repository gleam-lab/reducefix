#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    long double totalCost = 0.0;
    int nowX = 0, nowY = 0;
    
    int N;
    cin >> N;
    vector<int> X(N), Y(N);

    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }

    for (int i = 0; i < N; ++i) {
        int nextX = X[i], nextY = Y[i];
        long double distance = sqrt(pow(nextX - nowX, 2) + pow(nextY - nowY, 2));
        totalCost += distance;
        nowX = nextX;
        nowY = nextY;
    }

    // Return to the origin
    long double distanceToOrigin = sqrt(pow(nowX, 2) + pow(nowY, 2));
    totalCost += distanceToOrigin;

    cout << fixed << setprecision(10) << totalCost << endl;

    return 0;
}