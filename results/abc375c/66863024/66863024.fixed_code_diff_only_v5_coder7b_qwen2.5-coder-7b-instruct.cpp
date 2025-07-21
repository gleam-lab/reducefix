#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    long double cost = 0;
    long double x = 0, y = 0;

    for (int i = 0; i < N; ++i) {
        long double nx, ny;
        cin >> nx >> ny;
        cost += sqrt((x - nx) * (x - nx) + (y - ny) * (y - ny));
        x = nx;
        y = ny;
    }

    // Return to origin
    cost += sqrt(x * x + y * y);

    cout.precision(10);
    cout << cost << endl;
    return 0;
}