#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> H(N);
    for(int i = 0; i < N; ++i) cin >> H[i];

    long long T = 0;
    while(true){
        bool done = true;
        for(int i = 0; i < N; ++i){
            if(H[i] > 0){
                done = false;
                if(T % 3 == 0) H[i] -= 3;
                else H[i]--;
                T++;
            }
        }
        if(done) break;
    }

    cout << T << '\n';
    return 0;
}