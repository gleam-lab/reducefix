#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n;
    double x = 0, y = 0, total_cost = 0;
    
    cin >> n;
    while(n--) {
        int dx, dy;
        cin >> dx >> dy;
        
        // Calculate the Euclidean distance using Pythagorean theorem
        double distance = sqrt(dx * dx + dy * dy);
        total_cost += distance;
        
        // Update current position
        x = dx;
        y = dy;
    }

    // Return to origin
    total_cost += sqrt(x * x + y * y);

    cout << fixed << setprecision(10) << total_cost << endl;
    return 0;
}