#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    long double x = 0, y = 0;
    long double total_cost = 0;
    
    for(long long i = 0; i < n; ++i) {
        long double nx, ny;
        cin >> nx >> ny;
        
        total_cost += sqrt((x - nx) * (x - nx) + (y - ny) * (y - ny));
        x = nx;
        y = ny;
    }
    
    total_cost += sqrt(x * x + y * y);
    
    cout.precision(10);
    cout << total_cost << endl;
    
    return 0;
}