#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long x = 0, y = 0;
    double c = 0;
    pair<long long, long long> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < n; i++) {
        c += sqrt((x - a[i].first) * (x - a[i].first) + (y - a[i].second) * (y - a[i].second));
        x = a[i].first;
        y = a[i].second;
    }
    c += sqrt(x * x + y * y);
    cout << fixed << setprecision(10) << c << endl;
    return 0;
}