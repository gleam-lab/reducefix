#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    long long x = 0, y = 0;
    double total_cost = 0.0;

    for (int i = 0; i < N; ++i) {
        long long X, Y;
        cin >> X >> Y;
        long long dx = X - x;
        long long dy = Y - y;
        total_cost += sqrt(dx * dx + dy * dy);
        x = X;
        y = Y;
    }

    // Return to origin
    total_cost += sqrt(x * x + y * y);

    cout << fixed << setprecision(10) << total_cost << endl;

    return 0;
}