#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    long double ans = 0;
    long double x = 0, y = 0;
    long double nextx, nexty;

    for(int i = 0; i < N; i++) {
        cin >> nextx >> nexty;
        ans += sqrtl((nextx - x) * (nextx - x) + (nexty - y) * (nexty - y));
        x = nextx;
        y = nexty;
    }

    // Return to origin
    ans += sqrtl(x * x + y * y);

    cout << ans << endl;

    return 0;
}