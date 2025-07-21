#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> healths(n);
    long long total_attacks = 0;

    for (int i = 0; i < n; ++i) {
        cin >> healths[i];
        // Calculate the minimum number of attacks needed for this enemy
        long long attacks_needed = (healths[i] + 2) / 3; // Ceiling of health/3
        // Add the number of attacks needed for this enemy
        total_attacks += attacks_needed;
    }

    cout << total_attacks << endl;
    return 0;
}