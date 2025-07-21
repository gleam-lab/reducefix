#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long x = 0, y = 0;
    double total_cost = 0.0;

    for (int i = 0; i < N; ++i) {
        long long new_x, new_y;
        cin >> new_x >> new_y;

        total_cost += sqrt(pow(x - new_x, 2) + pow(y - new_y, 2));
        x = new_x;
        y = new_y;
    }

    // Return to the origin
    total_cost += sqrt(x * x + y * y);

    cout << setprecision(15) << total_cost << endl;

    return 0;
}