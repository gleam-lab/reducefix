#include <bits/stdc++.h>
using namespace std;

int main() {
    double a = 0.0, b = 0.0;
    int N;
    cin >> N;
    double total = 0.0;
    for (int i = 0; i < N; ++i) {
        double c, d;
        cin >> c >> d;
        total += hypot(a - c, b - d); // hypot is safe against overflow and provides precision
        a = c;
        b = d;
    }
    total += hypot(a, b);
    
    // Set precision high enough to meet error requirements
    cout.precision(15);
    cout << fixed << total << endl;
    
    return 0;
}