#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    int i = 0;
    while (i < N) {
        long long a = H[i] / 3;
        H[i] -= a * 3;
        T += a * 3;
        if (H[i] > 0) {
            H[i]--;
            T++;
        }
        i++;
    }
    while (i < N) {
        if (H[i] % 3 == 0) {
            T += H[i] / 3;
            H[i] = 0;
        } else {
            H[i]--;
            T++;
        }
        i++;
    }
    cout << T << endl;
    return 0;
}