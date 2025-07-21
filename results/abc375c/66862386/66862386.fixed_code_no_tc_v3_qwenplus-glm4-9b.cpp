#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    long double total_cost = 0.0;
    pair<long long, long long> current_position = {0, 0};
    
    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;
        total_cost += sqrt(pow(current_position.first - x, 2) + pow(current_position.second - y, 2));
        current_position = {x, y};
    }
    
    // Calculate the return cost to the origin
    total_cost += sqrt(pow(current_position.first, 2) + pow(current_position.second, 2));
    
    cout << fixed << setprecision(10) << total_cost << endl;
    
    return 0;
}