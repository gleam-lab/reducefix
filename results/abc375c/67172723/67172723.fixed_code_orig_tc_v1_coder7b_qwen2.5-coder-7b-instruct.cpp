#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i];
    }

    double ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += hypot(xs[i + 1] - xs[i], ys[i + 1] - ys[i]);
    }
    ans += hypot(xs[0] - xs[n - 1], ys[0] - ys[n - 1]);

    printf("%.10f\n", ans);
    return 0;
}