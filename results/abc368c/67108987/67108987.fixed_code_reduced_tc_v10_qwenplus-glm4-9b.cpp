#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N + 9);
    for (int i = 1; i <= N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 1; i <= N; i++) {
        if (H[i] > 0) {
            // Calculate the number of full 3's we can subtract from H[i]
            long long full_3 = H[i] / 3;
            T += full_3 * 3;
            H[i] -= full_3 * 3;
            // Calculate the remainder of H[i] after subtracting full 3's
            long long remainder = H[i] % 3;
            if (remainder > 0) {
                T += 1;
                H[i] -= 1;
            }
            if (remainder == 2 && H[i] > 0) {
                T += 1;
                H[i] -= 3;
            }
        }
    }
    cout << T << endl;
    return 0;
}