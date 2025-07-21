#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;

    for (int i = 0; i < N; i++) {
        if (H[i] % 3 == 0) {
            T += H[i] / 3;
        } else {
            T += (H[i] / 3) + 1;
        }
        H[i] -= (H[i] / 3) * 3;
    }

    for (int i = 0; i < N; i++) {
        if (H[i] > 0) {
            T += H[i];
        }
    }

    cout << T << endl;
    return 0;
}