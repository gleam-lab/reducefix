#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double total = 0.0;
    double prev_x = 0.0, prev_y = 0.0;
    double curr_x, curr_y;

    for (int i = 0; i < N; ++i) {
        cin >> curr_x >> curr_y;
        double dx = curr_x - prev_x;
        double dy = curr_y - prev_y;
        total += sqrt(dx * dx + dy * dy);
        prev_x = curr_x;
        prev_y = curr_y;
    }

    // Return to origin
    double dx = 0.0 - prev_x;
    double dy = 0.0 - prev_y;
    total += sqrt(dx * dx + dy * dy);

    cout << fixed << setprecision(10) << total << endl;

    return 0;
}