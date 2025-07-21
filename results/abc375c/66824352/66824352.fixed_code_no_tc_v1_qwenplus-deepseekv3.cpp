#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x = 0, y = 0;
    double c = 0.0;
    for (int i = 0; i < n; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        c += sqrt(pow(x - xi, 2) + pow(y - yi, 2));
        x = xi;
        y = yi;
    }
    c += sqrt(pow(x, 2) + pow(y, 2));
    cout << fixed << setprecision(10) << c << endl;
    return 0;
}