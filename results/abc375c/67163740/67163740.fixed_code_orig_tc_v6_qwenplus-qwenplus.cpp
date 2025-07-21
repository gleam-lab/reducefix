#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    double x = 0, y = 0, total = 0;
    cin >> n;
    
    for(int i = 0; i < n; ++i) {
        double a, b;
        cin >> a >> b;
        total += sqrt((x - a)*(x - a) + (y - b)*(y - b));
        x = a;
        y = b;
    }
    
    total += sqrt(x*x + y*y);
    
    cout.precision(15);
    cout << fixed << total << endl;
    
    return 0;
}