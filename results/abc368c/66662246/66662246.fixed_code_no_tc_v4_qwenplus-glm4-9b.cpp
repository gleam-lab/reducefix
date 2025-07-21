#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    ll total_attacks = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    
    for (int health : h) {
        // Calculate the number of full rounds of 3 attacks that can be applied
        total_attacks += health / 3;
        // Calculate the remainder health after the full rounds
        health %= 3;
        // For each remaining health point, perform 1 attack
        if (health > 0) {
            total_attacks += 1;
        }
    }
    
    cout << total_attacks << endl;
    return 0;
}