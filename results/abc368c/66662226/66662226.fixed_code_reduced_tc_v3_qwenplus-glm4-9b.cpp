#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> healths(n);
    long long total_attacks = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> healths[i];
    }
    
    for (int health : healths) {
        while (health > 0) {
            if (health % 3 == 0) {
                // If the health is a multiple of 3, we can use one attack
                health -= 3;
            } else {
                // Otherwise, we need to attack three times to reduce the health by one
                health -= 1;
            }
            total_attacks++;
        }
    }
    
    cout << total_attacks << endl;
    return 0;
}