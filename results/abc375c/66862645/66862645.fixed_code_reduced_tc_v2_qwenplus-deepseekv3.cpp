#include <bits/stdc++.h>
using namespace std;

int main() {
    long double total_cost = 0;
    int N;
    cin >> N;
    
    int current_x = 0, current_y = 0;
    
    for (int i = 0; i < N; ++i) {
        int next_x, next_y;
        cin >> next_x >> next_y;
        
        long double dx = current_x - next_x;
        long double dy = current_y - next_y;
        long double distance = sqrt(dx * dx + dy * dy);
        total_cost += distance;
        
        current_x = next_x;
        current_y = next_y;
    }
    
    long double dx = current_x - 0;
    long double dy = current_y - 0;
    long double distance = sqrt(dx * dx + dy * dy);
    total_cost += distance;
    
    cout << fixed << setprecision(15) << total_cost << endl;
    
    return 0;
}