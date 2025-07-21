#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 0; i < N; i++) {
        long long cycles = H[i] / 3;
        long long remainder = H[i] % 3;
        T += cycles * 3;
        if (remainder > 0) {
            if ((T + 1) % 3 == 0) {
                T += 1;
                remainder -= 3;
            } else {
                T += 1;
                remainder -= 1;
            }
            if (remainder > 0) {
                T += 1;
                remainder -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}