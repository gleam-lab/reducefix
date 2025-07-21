#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    long long total_attacks = 0;

    for (int i = 0; i < n; ++i) {
        cin >> health[i];
        // Calculate the number of triple damage attacks needed
        total_attacks += (health[i] + 2) / 3; // This is equivalent to ceil(health[i] / 3)
        // Calculate the remaining health after triple damage attacks
        health[i] -= (health[i] + 2) / 3 * 3;
        // Calculate the number of single damage attacks needed for the remaining health
        total_attacks += health[i];
    }

    cout << total_attacks << endl;
    return 0;
}