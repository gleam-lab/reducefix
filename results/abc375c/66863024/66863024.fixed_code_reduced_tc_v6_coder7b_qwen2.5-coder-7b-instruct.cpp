#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    long double x = 0, y = 0, total_cost = 0;
    
    for(int i = 0; i < n; ++i) {
        long double nx, ny;
        cin >> nx >> ny;
        
        total_cost += sqrt((x - nx) * (x - nx) + (y - ny) * (y - ny));
        
        x = nx;
        y = ny;
    }
    
    total_cost += sqrt(x * x + y * y);
    
    printf("%.10Lf\n", total_cost);
    
    return 0;
}