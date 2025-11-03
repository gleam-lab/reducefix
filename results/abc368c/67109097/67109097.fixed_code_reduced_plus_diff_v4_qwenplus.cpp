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
    for (int i = 0; i < N; i++) {
        while (H[i] > 0) {
            T++;
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
            
            // If current enemy is defeated, move to next enemy
            // But we need to handle the case where multiple enemies might be defeated
            // in a single turn due to chain effects - however, per problem statement,
            // we always attack the frontmost enemy with health > 0
            if (H[i] <= 0) {
                break;
            }
        }
    }
    
    cout << T << endl;
    return 0;
}