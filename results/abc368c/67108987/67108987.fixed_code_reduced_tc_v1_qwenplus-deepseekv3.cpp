#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 0; i < N; i++) {
        long long full_cycles = H[i] / 5;
        H[i] -= full_cycles * 5;
        T += full_cycles * 3;
        if (H[i] > 0) {
            if (H[i] <= 2) {
                T += H[i];
            } else {
                T += 3 - (H[i] == 4 ? 1 : 0);
            }
        }
    }
    cout << T << endl;
    return 0;
}