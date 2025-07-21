#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 9);
    for (int i = 1; i <= N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 1; i <= N; i++) {
        long long a = H[i] / 5;
        H[i] -= a * 5;
        T += a * 3;
        while(H[i] > 0){
            if(T % 3 == 0){
                H[i] -= 3;
                T++;
            }
            else{
                H[i]--;
                T++;
            }
        }
    }
    cout << T << endl;
    return 0;
}