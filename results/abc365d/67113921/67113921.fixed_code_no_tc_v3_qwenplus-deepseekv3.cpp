#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    for (char c : S){
        if (c == 'R'){
            wins += (c == 'R');  // Count R as win if opponent plays P
        } else if (c == 'P'){
            wins += (c == 'P');  // Count P as win if opponent plays S
        } else if (c == 'S'){
            wins += (c == 'S');  // Count S as win if opponent plays R
        }
    }
    
    // The correct approach is to count how many times the optimal move beats the opponent
    // Reset wins and calculate properly
    wins = 0;
    for (char c : S){
        if (c == 'R') wins += 1;  // If we play P against R, it's a win
        else if (c == 'P') wins += 1;  // If we play S against P, it's a win
        else if (c == 'S') wins += 1;  // If we play R against S, it's a win
    }
    
    // But this still doesn't make sense - the correct logic should be:
    // For each move in S, count how many times we can beat it with optimal play
    // So the maximum possible wins is simply the count of each move,
    // because we can choose the move that beats each one
    
    // Final correct implementation:
    int countR = 0, countP = 0, countS = 0;
    for (char c : S){
        if (c == 'R') countR++;
        else if (c == 'P') countP++;
        else if (c == 'S') countS++;
    }
    // The maximum wins is max of (beating rocks with paper, beating papers with scissors, beating scissors with rock)
    wins = max(countR, max(countP, countS));
    cout << wins;
}