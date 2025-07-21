#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    long long x = 0, y = 0, prev_x = 0, prev_y = 0, distance = 0;

    for (int i = 0; i < N; ++i) {
        cin >> prev_x >> prev_y;
        distance += abs(prev_x - x) + abs(prev_y - y); // Manhattan distance approximation for simplicity
        x = prev_x;
        y = prev_y;
    }

    distance += abs(x) + abs(y); // Distance back to origin

    cout << distance << '\n';

    return 0;
}