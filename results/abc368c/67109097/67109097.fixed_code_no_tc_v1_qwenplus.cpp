#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    long long T = 0;
    int current_enemy = 0;

    while (current_enemy < N) {
        T++;
        // Check if T is multiple of 3 -> deal 3 damage, else deal 1 damage
        long long damage = (T % 3 == 0) ? 3 : 1;
        
        // Attack the frontmost enemy with health > 0
        if (H[current_enemy] > 0) {
            H[current_enemy] -= damage;
            // If this enemy is defeated, move to next
            if (H[current_enemy] <= 0) {
                current_enemy++;
            }
        }
        // Note: Since we only attack frontmost alive enemy, and we process enemies in order,
        // the above condition ensures we always attack the first non-defeated enemy.
    }

    cout << T << endl;
    return 0;
}