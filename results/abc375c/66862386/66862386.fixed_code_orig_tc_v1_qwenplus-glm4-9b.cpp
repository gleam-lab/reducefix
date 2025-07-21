#include <iostream>
#include <cmath> // For sqrt and pow

using namespace std;

int main() {
    int N;
    cin >> N;

    long double x = 0, y = 0;
    long double distance = 0;
    long double total_cost = 0;

    for (int i = 0; i < N; i++) {
        int nextX, nextY;
        cin >> nextX >> nextY;

        distance = sqrt(pow(nextX - x, 2) + pow(nextY - y, 2));

        total_cost += distance;

        x = nextX;
        y = nextY;
    }

    // Include the return journey to the origin
    total_cost += sqrt(pow(x, 2) + pow(y, 2));

    cout << total_cost << endl;

    return 0;
}