#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    long long T = 0;
    for (int i = 0; i < N; ++i) {
        long long h = H[i];
        long long full_cycles = h / 5;
        long long rem = h % 5;
        long long local_T = 0;
        if (rem == 0) {
            local_T = full_cycles * 3;
        } else {
            if (full_cycles > 0) {
                rem += 5;
                full_cycles--;
            }
            if (rem <= 2) {
                local_T = full_cycles * 3 + rem;
            } else {
                local_T = full_cycles * 3 + 3;
            }
        }
        T += local_T;
    }
    cout << T << endl;
    return 0;
}