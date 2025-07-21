#include <bits/stdc++.h>
using namespace std;

int main() {
    double a = 0, b = 0, c, d, total_distance = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> c >> d;
        total_distance += sqrt((a - c) * (a - c) + (b - d) * (b - d));
        a = c;
        b = d;
    }
    total_distance += sqrt(a * a + b * b);
    cout << fixed << setprecision(10) << total_distance << endl;
    return 0;
}