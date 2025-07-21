#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 1);
    for (int i = 1; i <= N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 1; i <= N; i++) {
        long long remaining = H[i];
        if (i > 1) {
            remaining -= T;
            if (remaining <= 0) continue;
        }
        long long cycles = remaining / 5;
        remaining -= cycles * 5;
        T += cycles * 3;
        while (remaining > 0) {
            T++;
            if (T % 3 == 0) remaining -= 3;
            else remaining -= 1;
        }
    }
    cout << T << endl;
    return 0;
}