#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N + 9);
    for(int i = 0; i < N; i++) cin >> H[i]; // Changed from i=1 to i=0 as array index starts from 0 in C++
    long long T = 0;
    for(int i = 0; i < N; i++) { // Changed from i=1 to i=0 as array index starts from 0 in C++
        if(H[i] > 0){
            T++; 
            if(T % 3 == 0)
                H[i] -= 3; // Decrease health by 3 if T is a multiple of 3
            else
                H[i]--; // Otherwise decrease health by 1
        }
    }
    cout << T << endl;
    return 0;
}