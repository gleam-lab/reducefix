#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    double cx = 0, cy = 0, total_cost = 0;
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        total_cost += sqrt(cx * cx + cy * cy);
        cx = x;
        cy = y;
    }
    total_cost += sqrt(cx * cx + cy * cy);
    cout << setprecision(10) << total_cost << endl;
    return 0;
}