#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> healths(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> healths[i];
    }

    int t = 0;
    for (int i = 0; i < n; ++i) {
        if (healths[i] == 0) continue;
        
        // Calculate how many full 3's we can apply
        int full_triples = healths[i] / 3;
        // Remaining health after applying full triples
        int remaining_health = healths[i] % 3;
        
        // For the remaining health, each unit needs one operation
        int operations_for_remaining = remaining_health;
        
        // Add the full triples and the operations for remaining health
        t += full_triples * 3 + operations_for_remaining;
    }
    
    cout << t << endl;
    return 0;
}