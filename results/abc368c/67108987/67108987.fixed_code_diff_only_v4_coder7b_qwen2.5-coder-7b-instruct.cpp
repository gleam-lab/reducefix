#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N + 1); // Change size to N+1 to avoid out-of-bound access
    for (int i = 1; i <= N; i++) cin >> H[i];
    long long T = 0;
    while (true) { // Use a loop instead of fixed iterations
        bool anyHit = false;
        for (int i = 1; i <= N; i++) {
            if (H[i] > 0) {
                anyHit = true;
                T++;
                H[i]--; // Decrease health by 1
                if (T % 3 == 0 && H[i] >= 3) {
                    H[i] -= 2; // Decrease health by 3 if T is a multiple of 3 and health is at least 3
                    T++;
                }
            }
        }
        if (!anyHit) break; // Break loop if no enemy was hit
    }
    cout << T << endl;
    return 0;
}