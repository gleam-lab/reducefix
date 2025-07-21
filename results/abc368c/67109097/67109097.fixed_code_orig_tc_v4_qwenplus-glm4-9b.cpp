#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    long long T = 0;
    for (int i = 0; i < N; i++) {
        if (H[i] < 3) {
            T += H[i];
        } else {
            int t = (H[i] - 1) / 3 + 1;
            T += t + 3;
            if ((T - 1) % 3 == 0) {
                T -= 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}