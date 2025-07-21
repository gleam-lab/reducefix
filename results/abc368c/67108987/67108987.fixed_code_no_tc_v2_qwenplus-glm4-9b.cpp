#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    
    while (!all_of(H.begin(), H.end(), [](int health) { return health <= 0; })) {
        for (int i = 0; i < N; i++) {
            if (T % 3 == 0 && H[i] > 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
        }
        T++;
    }
    
    cout << T << endl;
    return 0;
}