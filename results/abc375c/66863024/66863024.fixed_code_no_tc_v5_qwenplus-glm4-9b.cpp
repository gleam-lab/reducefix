#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long N;
    cin >> N;
    long long x, y;
    long long total_cost = 0;
    long long ox = 0, oy = 0;

    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        total_cost += abs(x - ox) + abs(y - oy); // Calculate the cost to move to the next point
        ox = x;
        oy = y;
    }
    total_cost += sqrt((double)(ox * ox) + (double)(oy * oy)); // Add the cost to return to the origin

    cout << total_cost << endl;
    return 0;
}