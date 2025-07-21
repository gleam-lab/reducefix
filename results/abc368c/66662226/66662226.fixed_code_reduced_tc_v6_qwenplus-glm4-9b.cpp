#include <iostream>
#include <vector>
#include <cmath>

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
        // Calculate the number of full powers needed to reduce the health to a multiple of 3
        total_attacks += (health - 1) / 3;
        // Reduce the health to the nearest multiple of 3
        health -= ((health - 1) / 3) * 3;
        // Now attack the enemy with 1, 2, or 3 hits until health is 0 or less
        while (health > 0) {
            if (total_attacks % 3 == 0 && health >= 3) {
                health -= 3;
                total_attacks += 3;
            } else {
                health--;
                total_attacks++;
            }
        }
    }

    cout << total_attacks << endl;

    return 0;
}