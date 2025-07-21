#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 1);
    long long T = 0;
    long long damage = 0;

    for (int i = 1; i <= N; i++) {
        cin >> H[i];
        // If the current damage is less than the enemy's health, we need to attack
        if (damage < H[i]) {
            // Calculate the additional damage needed
            long long additional_damage = H[i] - damage;
            // If the additional damage is a multiple of 3, increase T by additional_damage / 3
            // Otherwise, increase T by (additional_damage / 3) + 1
            T += (additional_damage + 2) / 3;
            damage = min(damage + 3, H[i]); // Increase the damage and stop at enemy's health
        }
    }

    cout << T << endl;
    return 0;
}