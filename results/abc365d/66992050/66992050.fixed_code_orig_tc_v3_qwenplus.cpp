#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    string S;
    cin >> N >> S;
    
    // Use dynamic programming to track minimum moves ending with each gesture
    // dp[0] = last was Rock ('R')
    // dp[1] = last was Paper ('P')
    // dp[2] = last was Scissors ('S')
    vector<int> dp(3, 0);
    
    for (char c : S) {
        vector<int> new_dp = dp;
        
        if (c == 'R') {
            // Current gesture is Rock
            // Can either continue from previous Rock, or switch from Scissors (S->R)
            new_dp[0] = max(dp[0], dp[2]) + 1;
        }
        else if (c == 'P') {
            // Current gesture is Paper
            // Can either continue from previous Paper, or switch from Rock (R->P)
            new_dp[1] = max(dp[1], dp[0]) + 1;
        }
        else if (c == 'S') {
            // Current gesture is Scissors
            // Can either continue from previous Scissors, or switch from Paper (P->S)
            new_dp[2] = max(dp[2], dp[1]) + 1;
        }
        
        dp = new_dp;
    }
    
    // Answer is the maximum of all possible ending states
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}