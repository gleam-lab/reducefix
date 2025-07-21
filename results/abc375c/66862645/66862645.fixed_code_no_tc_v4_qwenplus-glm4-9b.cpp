#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    long double cost = 0;
    long double total_cost = 0;
    int nowX = 0, nowY = 0;

    for (int i = 0; i < N; ++i) {
        int nextX, nextY;
        cin >> nextX >> nextY;
        cost = sqrt(pow(nextX - nowX, 2) + pow(nextY - nowY, 2));
        total_cost += cost;
        nowX = nextX;
        nowY = nextY;
    }

    // Add the cost to return to the origin
    total_cost += sqrt(pow(nowX - 0, 2) + pow(nowY - 0, 2));

    cout << fixed << setprecision(10) << total_cost << endl;
    return 0;
}