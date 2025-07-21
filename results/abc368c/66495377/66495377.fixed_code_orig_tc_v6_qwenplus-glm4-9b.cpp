#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long total_attacks = 0;
    
    for (int i = 0; i < n; ++i) {
        long long h;
        cin >> h;
        
        // Calculate the number of full cycles of 3 attacks
        int full_cycles = h / 3;
        // Calculate the remaining health after full cycles
        long long remaining_health = h % 3;
        
        // Add the full cycles to the total attacks
        total_attacks += full_cycles * 3;
        // Add the remaining health attacks
        total_attacks += remaining_health;
    }
    
    cout << total_attacks << endl;
    
    return 0;
}