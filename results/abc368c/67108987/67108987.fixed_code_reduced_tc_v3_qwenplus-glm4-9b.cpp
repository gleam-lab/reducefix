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
        } else if (H[i] % 3 == 1) {
            T += (H[i] - 4) / 3 + 3;
        } else { // H[i] % 3 == 2
            T += H[i] / 3 + 2;
        }
    }
    
    cout << T << endl;
    return 0;
}