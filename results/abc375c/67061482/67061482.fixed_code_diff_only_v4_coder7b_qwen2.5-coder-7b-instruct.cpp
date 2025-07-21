#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    long long x = 0, y = 0, total_cost = 0;

    for (int i = 0; i < N; ++i) {
        long long dx, dy;
        cin >> dx >> dy;
        total_cost += abs(dx - x) + abs(dy - y);
        x = dx;
        y = dy;
    }

    total_cost += abs(x) + abs(y);
    cout << total_cost << '\n';

    return 0;
}