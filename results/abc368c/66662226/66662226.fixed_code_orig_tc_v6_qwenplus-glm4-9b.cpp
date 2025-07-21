#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long healths[n];
    long long total_attacks = 0;
    long long remaining_health = 0;

    for (int i = 0; i < n; i++) {
        cin >> healths[i];
        // Calculate full 3-attack sequences
        total_attacks += (healths[i] - 1) / 3;
        // Calculate remaining health after full sequences
        remaining_health += (healths[i] - 1) % 3;
    }

    // Calculate total attacks needed
    // Full 3-attack sequences each count as 3, but we've added one extra attack
    total_attacks += (remaining_health + 2) / 3 * 3;

    cout << total_attacks << endl;

    return 0;
}