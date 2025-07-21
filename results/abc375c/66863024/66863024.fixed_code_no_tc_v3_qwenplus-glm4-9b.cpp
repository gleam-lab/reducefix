#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    long double x = 0, y = 0, ans = 0.0;
    for (int i = 0; i < N; ++i) {
        long long XX, YY;
        cin >> XX >> YY;
        long double dx = XX - x;
        long double dy = YY - y;
        ans += sqrt(dx * dx + dy * dy);
        x = XX;
        y = YY;
    }
    // Add the cost of returning to the origin
    ans += sqrt(x * x + y * y);
    
    cout.precision(10);
    cout << fixed << ans << endl;
    
    return 0;
}