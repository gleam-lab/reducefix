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
        // Check if T is multiple of 3
        long long damage = (T % 3 == 0) ? 3 : 1;
        
        // Attack the frontmost alive enemy
        H[current_enemy] -= damage;
        
        // If current enemy is defeated, move to next
        while (current_enemy < N && H[current_enemy] <= 0) {
            current_enemy++;
        }
    }

    cout << T << endl;
    return 0;
}