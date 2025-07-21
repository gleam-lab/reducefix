#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 0; i < N; i++) {
        long long h = H[i];
        // The attacks come in patterns: 1,1,3,1,1,3,...
        // For each full cycle of 3 attacks, the total damage is 1+1+3 = 5.
        long long full_cycles = h / 5;
        long long remaining = h % 5;
        T += full_cycles * 3;
        h = remaining;
        while (h > 0) {
            T++;
            if (T % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}