#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    double x = 0.0, y = 0.0, cost = 0.0;
    
    for (int i = 0; i < N; i++) {
        int cx, cy;
        cin >> cx >> cy;
        cost += sqrt((x - cx) * (x - cx) + (y - cy) * (y - cy));
        x = cx;
        y = cy;
    }
    
    // Return to the origin
    cost += sqrt(x * x + y * y);
    
    cout.precision(10);
    cout << fixed << cost << endl;
    
    return 0;
}