#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    long long mod = 0; // T % 3 for the next attack
    for (int i = 0; i < N; i++) {
        long long h = H[i];
        if (mod == 0) {
            // Check if we can use full cycles of 3 attacks (5 damage)
            long long cycles = h / 5;
            T += cycles * 3;
            h -= cycles * 5;
            mod = (mod + cycles * 3) % 3;
        }
        // Handle the remaining health
        while (h > 0) {
            T++;
            if (T % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
            if (h <= 0) break;
        }
        mod = T % 3;
    }
    cout << T << endl;
    return 0;
}