#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> xs(N + 1), ys(N + 1);
    xs[0] = ys[0] = 0;

    for (int i = 1; i <= N; ++i) {
        cin >> xs[i] >> ys[i];
    }

    double total = 0.0;

    for (int i = 1; i <= N; ++i) {
        total += sqrt((xs[i] - xs[i - 1]) * (xs[i] - xs[i - 1]) + 
                      (ys[i] - ys[i - 1]) * (ys[i] - ys[i - 1]));
    }

    total += sqrt(xs[N] * xs[N] + ys[N] * ys[N]);

    printf("%.10f\n", total);

    return 0;
}