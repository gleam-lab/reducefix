#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    double a = 0.0, b = 0.0;
    double total_cost = 0.0;
    for (int i = 0; i < N; i++) {
        double c, d;
        cin >> c >> d;
        total_cost += sqrt((a - c) * (a - c) + (b - d) * (b - d));
        a = c;
        b = d;
    }
    total_cost += sqrt(a * a + b * b);
    cout << fixed << setprecision(10) << total_cost << endl;
    return 0;
}