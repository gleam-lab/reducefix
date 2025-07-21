#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    double x = 0, y = 0, total_cost = 0;
    
    for(int i = 0; i < N; ++i) {
        double next_x, next_y;
        cin >> next_x >> next_y;
        total_cost += sqrt(x*x + y*y); // Cost from current position to the origin
        total_cost += sqrt((x-next_x)*(x-next_x) + (y-next_y)*(y-next_y)); // Cost from current position to the next point
        x = next_x;
        y = next_y;
    }
    total_cost += sqrt(x*x + y*y); // Cost from the last point back to the origin
    
    cout << total_cost << endl;
    return 0;
}