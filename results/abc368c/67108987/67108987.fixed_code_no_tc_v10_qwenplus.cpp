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
        // Determine damage based on T
        long long damage = (T % 3 == 0) ? 3 : 1;
        
        // Attack the first enemy with health > 0
        while (current_enemy < N && H[current_enemy] <= 0) {
            current_enemy++;
        }
        
        if (current_enemy < N) {
            H[current_enemy] -= damage;
        }
    }

    cout << T << endl;
    return 0;
}