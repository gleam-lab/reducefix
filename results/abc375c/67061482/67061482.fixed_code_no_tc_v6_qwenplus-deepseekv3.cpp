#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    double a = 0.0, b = 0.0;  // current position starts at origin
    double total_distance = 0.0;
    
    for (int i = 0; i < N; ++i) {
        double c, d;
        cin >> c >> d;
        total_distance += sqrt((a - c) * (a - c) + (b - d) * (b - d));
        a = c;
        b = d;
    }
    
    // Add distance back to origin
    total_distance += sqrt(a * a + b * b);
    
    cout << fixed << setprecision(10) << total_distance << endl;
    return 0;
}