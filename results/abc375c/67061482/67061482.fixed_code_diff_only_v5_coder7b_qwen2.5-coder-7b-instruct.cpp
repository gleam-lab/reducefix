#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    cin >> N;

    double x = 0, y = 0, total_cost = 0;
    
    while(N--) {
        double nx, ny;
        cin >> nx >> ny;
        
        // Calculate Euclidean distance to next point and add to total cost
        total_cost += sqrt((x - nx) * (x - nx) + (y - ny) * (y - ny));
        
        // Update current position
        x = nx;
        y = ny;
    }

    // Return to origin
    total_cost += sqrt(x * x + y * y);

    cout << total_cost << endl;
    
    return 0;
}