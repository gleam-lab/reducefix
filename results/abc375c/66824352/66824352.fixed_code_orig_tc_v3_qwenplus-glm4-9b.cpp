#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    long long x = 0, y = 0;  // Use long long to avoid overflow
    double total_cost = 0.0;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        x += a;
        y += b;
    }

    // Calculate the distance from the final position to the origin
    total_cost = sqrt(x * x + y * y);

    // Output the total cost with a precision of 10^-6
    cout << fixed << setprecision(10) << total_cost << endl;

    return 0;
}