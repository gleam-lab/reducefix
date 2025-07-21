#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    double total_distance = 0.0;
    int x = 0, y = 0;
    
    for (int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;
        total_distance += sqrt(pow(x - xi, 2) + pow(y - yi, 2));
        x = xi;
        y = yi;
    }
    
    total_distance += sqrt(pow(x, 2) + pow(y, 2));
    cout << fixed << setprecision(10) << total_distance << endl;
    
    return 0;
}