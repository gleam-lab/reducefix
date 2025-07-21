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
        long long rem = H[i] % 5;
        T += cycles * 3;
        if (rem > 0) {
            if (rem <= 2) {
                T += rem;
            } else {
                T += 3;
            }
        }
    }
    cout << T << endl;
    return 0;
}