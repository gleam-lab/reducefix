#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long double total = 0.0;
    int curr_x = 0, curr_y = 0;

    for (int i = 0; i < N; ++i) {
        int next_x, next_y;
        cin >> next_x >> next_y;

        long double dx = static_cast<long double>(next_x - curr_x);
        long double dy = static_cast<long double>(next_y - curr_y);
        total += sqrt(dx * dx + dy * dy);

        curr_x = next_x;
        curr_y = next_y;
    }

    // Return to origin
    long double dx = static_cast<long double>(0 - curr_x);
    long double dy = static_cast<long double>(0 - curr_y);
    total += sqrt(dx * dx + dy * dy);

    cout.precision(15);
    cout << fixed << total << '\n';

    return 0;
}