#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    long long x = 0, y = 0;
    long double ans = 0;
    
    for(long long i = 0; i < n; ++i) {
        long long nx, ny;
        cin >> nx >> ny;
        
        ans += sqrt(pow(nx - x, 2) + pow(ny - y, 2));
        
        x = nx;
        y = ny;
    }
    
    ans += sqrt(x * x + y * y);
    
    cout << ans << endl;
    
    return 0;
}