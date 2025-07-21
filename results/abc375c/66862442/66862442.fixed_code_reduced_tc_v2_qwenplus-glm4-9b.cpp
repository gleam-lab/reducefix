#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    ld curX = 0, curY = 0;
    double total_cost = 0;

    for (int i = 0; i < N; ++i) {
        ll x, y;
        cin >> x >> y;

        total_cost += sqrt((curX - x) * (curX - x) + (curY - y) * (curY - y));
        curX = x;
        curY = y;
    }
    total_cost += sqrt(curX * curX + curY * curY); // Return to origin

    cout.precision(12);
    cout << fixed << total_cost << '\n';
}