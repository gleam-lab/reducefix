#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long double total = 0.0;
    long double curr_x = 0.0, curr_y = 0.0;
    long double start_x = 0.0, start_y = 0.0;

    for (int i = 0; i < N; ++i) {
        long double x, y;
        cin >> x >> y;

        long double dx = curr_x - x;
        long double dy = curr_y - y;
        total += sqrt(dx * dx + dy * dy);

        curr_x = x;
        curr_y = y;
    }

    // Return to origin
    long double dx = curr_x - start_x;
    long double dy = curr_y - start_y;
    total += sqrt(dx * dx + dy * dy);

    cout.precision(15);
    cout << fixed << total << endl;

    return 0;
}