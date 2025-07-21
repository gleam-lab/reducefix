#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    long double cost = 0;
    long double total_cost = 0;
    pair<long long, long long> current_position(0, 0);
    
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        
        // Calculate the distance to the next point
        cost = sqrt(pow(x - current_position.first, 2) + pow(y - current_position.second, 2));
        
        // Update the total distance
        total_cost += cost;
        
        // Update the current position
        current_position = {x, y};
    }
    
    // Calculate the return distance to the origin
    cost = sqrt(pow(current_position.first, 2) + pow(current_position.second, 2));
    
    // Add the return distance to the total cost
    total_cost += cost;
    
    // Print the total travel cost
    cout << fixed << setprecision(10) << total_cost << endl;
    
    return 0;
}