#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    for (int i = 0; i < n; ++i) {
        cin >> health[i];
    }

    // Function to calculate the number of attacks needed for a given enemy's health
    auto calculateAttacks = [&](int health) {
        if (health <= 0) return 0;
        int attacks = 0;
        while (health > 0) {
            attacks += health / 3;
            health %= 3;
            if (health > 0) attacks += 1;
        }
        return attacks;
    };

    long long totalAttacks = 0;
    for (int i = 0; i < n; ++i) {
        totalAttacks += calculateAttacks(health[i]);
    }

    cout << totalAttacks << endl;

    return 0;
}