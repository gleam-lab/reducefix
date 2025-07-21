#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    long long T = 0;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
        if (H[i] % 3 == 0) {
            // If H[i] is divisible by 3, divide by 3 to get the number of attacks needed
            T += H[i] / 3;
        } else {
            // If H[i] is not divisible by 3, it requires one extra attack
            T += H[i] / 3 + 1;
        }
    }
    cout << T << endl;
    return 0;
}