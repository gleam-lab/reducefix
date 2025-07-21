#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    double x = 0, y = 0, c = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        c += sqrt(x * x + y * y); // Cost to reach the current point from the origin
        c += sqrt((xi - x) * (xi - x) + (yi - y) * (yi - y)); // Cost to move from the previous point to the current one
        x = xi;
        y = yi;
    }
    c += sqrt(x * x + y * y); // Cost to return to the origin from the last visited point
    cout << setprecision(10) << c << endl;
    return 0;
}