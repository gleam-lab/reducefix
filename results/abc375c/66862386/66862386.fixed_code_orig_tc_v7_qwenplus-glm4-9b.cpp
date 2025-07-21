#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long N;
    cin >> N;

    long long X[N], Y[N];
    long long nowX = 0, nowY = 0;

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    long long total_distance = 0;

    // Accumulate distance from the origin to each point and from the last point to the origin.
    for (int i = 0; i < N; i++) {
        long long dist = sqrt(pow(nowX - X[i], 2) + pow(nowY - Y[i], 2));
        total_distance += dist;
        nowX = X[i];
        nowY = Y[i];
    }

    // Add the distance from the last point to the origin.
    total_distance += sqrt(pow(nowX - 0, 2) + pow(nowY - 0, 2));

    cout << total_distance << endl;

    return 0;
}