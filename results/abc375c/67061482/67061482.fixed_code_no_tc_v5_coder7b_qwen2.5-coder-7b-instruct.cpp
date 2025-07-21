#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c, d, cost;
    int N;
    cin >> N;
    a = 0;
    b = 0;
    cost = 0;
    for (int i = 0; i < N; i++) {
        cin >> c >> d;
        cost += sqrt((a - c) * (a - c) + (b - d) * (b - d));
        a = c;
        b = d;
    }
    cost += sqrt(a * a + b * b);
    printf("%.6f\n", cost); // Ensure the output is formatted correctly
}