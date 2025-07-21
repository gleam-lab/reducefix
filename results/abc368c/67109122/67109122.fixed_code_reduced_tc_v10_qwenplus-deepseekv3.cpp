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
        if (rem == 0) {
            T += cycles * 3;
            continue;
        }
        if (cycles == 0) {
            while (H[i] > 0) {
                T++;
                if (T % 3 == 0) H[i] -= 3;
                else H[i] -= 1;
            }
        } else {
            T += cycles * 3;
            long long temp_T = T;
            while (rem > 0) {
                temp_T++;
                if (temp_T % 3 == 0) rem -= 3;
                else rem -= 1;
            }
            T = temp_T;
        }
    }
    cout << T << endl;
    return 0;
}