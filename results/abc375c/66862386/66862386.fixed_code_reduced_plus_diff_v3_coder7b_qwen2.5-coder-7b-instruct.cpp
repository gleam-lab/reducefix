#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;

    long long x = 0, y = 0;
    double total_cost = 0;

    for(long long i = 0; i < n; ++i){
        long long nx, ny;
        cin >> nx >> ny;

        double dx = nx - x, dy = ny - y;
        total_cost += sqrt(dx * dx + dy * dy);

        x = nx;
        y = ny;
    }

    // Return to origin
    total_cost += sqrt(x * x + y * y);

    cout << setprecision(10) << total_cost << '\n';

    return 0;
}