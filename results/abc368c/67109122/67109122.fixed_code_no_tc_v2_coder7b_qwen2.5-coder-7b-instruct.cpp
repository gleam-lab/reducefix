#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 1); // Change size to N+1 for 1-based indexing
    for (int i = 1; i <= N; i++) cin >> H[i];
    long long T = 0;
    
    while(true) { // Replace the for loop with a while true loop
        bool anyEnemyLeft = false; // Track if any enemy has remaining health
        
        for (int i = 1; i <= N; i++) {
            if (H[i] > 0) { // Check if the current enemy has remaining health
                anyEnemyLeft = true;
                if (T % 3 == 0) H[i] -= 3;
                else H[i] -= 1;
                T++;
            }
        }
        
        if (!anyEnemyLeft) break; // Break the loop if no enemies have remaining health
    }
    
    cout << T << endl;
    return 0;
}