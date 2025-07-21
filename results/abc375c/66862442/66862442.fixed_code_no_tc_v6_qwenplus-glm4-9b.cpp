#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long x = 0, y = 0, total_cost = 0;

    for (int i = 0; i < N; ++i) {
        long long X, Y;
        cin >> X >> Y;
        
        total_cost += sqrt((x - X) * (x - X) + (y - Y) * (y - Y));
        x = X; y = Y;
    }
    total_cost += sqrt((x * x + y * y)); // åç¹ã¸æ»ã

    cout << fixed << setprecision(6) << total_cost << '\n';

    return 0;
}