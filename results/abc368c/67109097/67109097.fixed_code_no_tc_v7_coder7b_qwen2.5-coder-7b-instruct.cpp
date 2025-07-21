#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 9);
    for (int i = 1; i <= N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 1; i <= N; i++) {
        if(H[i]>0){
            T += (H[i] + 2) / 3; // Calculate how many times we need to attack
        }
    }
    cout << T << endl;
    return 0;
}