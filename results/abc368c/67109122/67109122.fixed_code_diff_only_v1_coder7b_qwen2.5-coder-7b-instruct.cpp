#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 0; i < N; i++) {
        while (H[i] > 0) {
            if ((T + 1) % 3 == 0) H[i] -= 3;
            else H[i] -= 1;
            T++;
        }
    }
    cout << T << endl;
    return 0;
}