#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 1);
    for (int i = 1; i <= N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 1; i <= N; i++) {
        while (H[i] > 0) {
            T++;
            if (T % 3 == 0) H[i] -= 3;
            else H[i]--;
        }
    }
    cout << T << endl;
    return 0;
}