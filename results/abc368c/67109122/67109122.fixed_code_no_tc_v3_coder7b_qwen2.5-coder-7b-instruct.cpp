#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N + 1); // Adjusted size to N+1 for easier indexing
    for (int i = 1; i <= N; i++) cin >> H[i];
    long long T = 0;
    
    while(true){
        bool anyAlive = false; // Flag to check if there's at least one alive enemy
        for(int i = 1; i <= N; i++){
            if(H[i] > 0){
                anyAlive = true;
                break;
            }
        }
        
        if(!anyAlive) break; // Break loop if no enemies left
        
        for(int i = 1; i <= N; i++){
            if(H[i] > 0){
                T++; // Increment T before attacking
                if(T % 3 == 0) H[i] -= 3;
                else H[i] -= 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}