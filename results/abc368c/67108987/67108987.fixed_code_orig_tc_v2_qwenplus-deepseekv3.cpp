#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;

    for (int i = 0; i < N; i++) {
        long long remaining = H[i];
        // Number of full triple attacks (1,1,3) which sum to 5 damage per 3 T steps
        long long full_cycles = remaining / 5;
        remaining -= full_cycles * 5;
        T += full_cycles * 3;

        if (remaining > 0) {
            T += 1;
            remaining -= 1;
        }
        if (remaining > 0) {
            T += 1;
            remaining -= 1;
        }
        if (remaining > 0) {
            T += 1;
            remaining -= 3;
        }
    }

    cout << T << endl;
    return 0;
}