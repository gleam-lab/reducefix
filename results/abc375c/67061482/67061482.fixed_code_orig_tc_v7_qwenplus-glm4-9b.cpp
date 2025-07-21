#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    double x = 0, y = 0;
    double total_distance = 0;

    for (int i = 0; i < N; ++i) {
        int x1, y1;
        cin >> x1 >> y1;
        total_distance += sqrt(pow(x - x1, 2) + pow(y - y1, 2));
        x = x1, y = y1;
    }

    total_distance += sqrt(pow(x - 0, 2) + pow(y - 0, 2));  // Add the distance back to the origin

    cout.precision(10);
    cout << fixed << total_distance << endl;

    return 0;
}