#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    long long T = 0;
    for (int i = 0; i < N; i++) cin >> H[i];
    
    long long i = 0;
    while (i < N) {
        long long sum = 0;
        while (i < N && H[i] > 0) {
            sum += H[i];
            i++;
        }
        
        T += sum;
        if (sum % 3 == 0) {
            T += (sum / 3) - 1;
        } else {
            T += sum / 3;
        }
    }
    
    cout << T << endl;
    return 0;
}