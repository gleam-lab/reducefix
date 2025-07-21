#include <bits/stdc++.h>
using namespace std;

int main() {
    double a = 0, b = 0, cou = 0;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        double c, d;
        cin >> c >> d;
        cou += sqrt((a - c) * (a - c) + (b - d) * (b - d));
        a = c;
        b = d;
    }
    cou += sqrt(a * a + b * b); // Correctly add the return trip cost
    printf("%.10f\n", cou); // Ensure precision up to 10 decimal places
}