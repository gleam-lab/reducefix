#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 0; i < N; i++) {
        long long cycles = H[i] / 5;
        long long remaining = H[i] % 5;
        T += cycles * 3;
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