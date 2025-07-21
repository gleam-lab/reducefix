#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> x(N+1);
    vector<long long> y(N+1);

    // Initialize the origin position
    x[0] = 0;
    y[0] = 0;

    for (int i = 1; i <= N; ++i) {
        cin >> x[i] >> y[i];
    }

    long long total_distance = 0;

    // Calculate the total distance traveled by Takahashi
    for (int i = 1; i <= N; ++i) {
        long long dx = x[i] - x[i-1];
        long long dy = y[i] - y[i-1];
        total_distance += sqrt(dx * dx + dy * dy);
    }

    // Add the distance back to the origin
    total_distance += sqrt(x[N] * x[N] + y[N] * y[N]);

    // Print the total distance
    cout.precision(12);
    cout << fixed << total_distance << endl;

    return 0;
}