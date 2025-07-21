#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double total = 0.0;
    long long prevX = 0, prevY = 0;

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;
        double dx = x - prevX;
        double dy = y - prevY;
        total += sqrt(dx * dx + dy * dy);
        prevX = x;
        prevY = y;
    }
    double dx = -prevX;
    double dy = -prevY;
    total += sqrt(dx * dx + dy * dy);

    cout << fixed << setprecision(9) << total << '\n';
}