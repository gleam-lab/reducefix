#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];
    long long T = 0;

    // Iterate over the enemies' health
    for (int i = 0; i < N; ++i) {
        // If the current total T is not a multiple of 3, we attack with 1 damage
        if (T % 3 != 0) {
            H[i]--;
            T++;
        }
        
        // Now T is a multiple of 3, and we can attack with 3 damage
        while (H[i] > 0) {
            H[i] -= 3;
            T += 3;
        }
    }
    cout << T << endl;
    return 0;
}