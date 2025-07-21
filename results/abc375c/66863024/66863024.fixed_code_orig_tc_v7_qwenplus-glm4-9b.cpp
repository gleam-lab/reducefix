#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> points(N);
    int x, y;

    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        points[i] = {x, y};
    }

    long double cost = 0.0;
    int nowX = 0, nowY = 0;
    for (int i = 0; i < N; ++i) {
        int nextX = points[i].first;
        int nextY = points[i].second;
        cost += sqrtl((long double)(nextX - nowX) * (nextX - nowX) + (long double)(nextY - nowY) * (nextY - nowY));
        nowX = nextX;
        nowY = nextY;
    }
    cost += sqrtl((long double)nowX * (long double)nowX + (long double)nowY * (long double)nowY);

    cout.precision(10);
    cout << fixed << cost << endl;

    return 0;
}