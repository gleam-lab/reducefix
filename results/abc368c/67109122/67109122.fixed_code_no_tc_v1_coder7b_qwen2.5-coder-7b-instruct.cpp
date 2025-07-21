#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 1); // Change size to N+1 for easier indexing
    for(int i = 1; i <= N; i++)
        cin >> H[i];

    long long T = 0;
    for(int i = 1; i <= N; i++){
        if(H[i] % 3 == 0){ // Check if health is divisible by 3 first
            T += H[i] / 3; // Directly add full rounds of attacks
            H[i] = 0; // Set health to 0 after direct attacks
        } else {
            while(H[i] > 0){
                if(T % 3 == 0)
                    H[i] -= 3; // Decrease health by 3 if T is multiple of 3
                else
                    H[i] -= 1; // Otherwise decrease by 1
                T++; // Increment time counter
            }
        }
    }

    cout << T << endl;
    return 0;
}