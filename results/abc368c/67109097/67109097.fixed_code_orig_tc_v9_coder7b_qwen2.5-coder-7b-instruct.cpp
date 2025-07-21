#include<bits/stdc++.h>
using namespace std;

long long calculateT(int H) {
    if(H == 0) return 0;
    long long T = H / 3;
    T += (H % 3 != 0);
    return T;
}

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 9);
    for (int i = 1; i <= N; i++) cin >> H[i];
    long long totalT = 0;
    for (int i = 1; i <= N; i++) {
        totalT += calculateT(H[i]);
    }
    cout << totalT << endl;
    return 0;
}