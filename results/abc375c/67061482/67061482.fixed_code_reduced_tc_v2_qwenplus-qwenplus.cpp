#include <bits/stdc++.h>
using namespace std;

int main() {
    double a = 0.0, b = 0.0, c, d;
    int N;
    cin >> N;
    
    double total_cost = 0.0;
    
    for (int i = 0; i < N; ++i) {
        cin >> c >> d;
        total_cost += hypot(a - c, b - d); // More precise than manual sqrt
        a = c;
        b = d;
    }
    
    total_cost += hypot(a, b);
    
    // Print with sufficient precision
    cout.precision(15);
    cout << fixed << total_cost << endl;
    
    return 0;
}