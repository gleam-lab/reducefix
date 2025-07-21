#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long ans = 0;
    long long x, y;
    
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        ans += sqrt((x * x + y * y));
    }
    // Return to the origin
    ans += sqrt((x * x + y * y));
    
    cout << ans << endl;
    return 0;
}