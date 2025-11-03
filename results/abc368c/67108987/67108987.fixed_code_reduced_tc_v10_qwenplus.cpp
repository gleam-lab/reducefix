#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    long long T = 0;
    int idx = 0;

    while (idx < N) {
        T++;
        // Determine damage: 3 if T is divisible by 3, else 1
        long long damage = (T % 3 == 0) ? 3 : 1;

        // Attack the first enemy with health > 0
        while (idx < N && H[idx] <= 0) idx++;
        if (idx >= N) break;

        H[idx] -= damage;
    }

    cout << T << endl;
    return 0;
}