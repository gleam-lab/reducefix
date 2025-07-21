#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    for (long long h : H) {
        long long full_cycles = (h - 1) / 5;
        long long remaining = h - full_cycles * 5;
        long long additional = 0;
        if (remaining > 0) {
            if (remaining <= 1) additional = 1;
            else if (remaining <= 3) additional = 2;
            else additional = 3;
        }
        T += full_cycles * 3 + additional;
    }
    cout << T << endl;
    return 0;
}