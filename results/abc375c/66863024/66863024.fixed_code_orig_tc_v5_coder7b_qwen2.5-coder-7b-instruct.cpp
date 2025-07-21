#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    cin >> n;
    
    long double x = 0, y = 0, ans = 0;
    
    while(n--) {
        long long nx, ny;
        cin >> nx >> ny;
        
        ans += hypot(nx - x, ny - y);
        x = nx;
        y = ny;
    }
    
    ans += hypot(x, y); // Return to origin
    
    cout << setprecision(15) << ans << '\n';
    
    return 0;
}