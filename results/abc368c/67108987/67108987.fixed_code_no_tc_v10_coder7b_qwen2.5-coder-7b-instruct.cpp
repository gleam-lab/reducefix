#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 1); // Changed size to N+1 to avoid out-of-bound access
    for(int i = 1; i <= N; i++) cin >> H[i];

    long long T = 0;
    for(int i = 1; i <= N; i++) {
        while(H[i] > 0) { // Changed loop condition to check if health is greater than 0
            T++;
            if(T % 3 == 0)
                H[i] -= 3;
            else
                H[i] -= 1;
        }
    }

    cout << T << endl;
    return 0;
}