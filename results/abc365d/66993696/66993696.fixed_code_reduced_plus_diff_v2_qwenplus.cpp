#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    // Count frequency of each move
    map<char, int> count;
    for (char c : s) {
        count[c]++;
    }
    
    // The optimal strategy: beat the most frequent move
    // P beats R, R beats S, S beats P
    int max_wins = 0;
    max_wins = max(max_wins, count['R']); // Play P to beat all R
    max_wins = max(max_wins, count['S']); // Play R to beat all S
    max_wins = max(max_wins, count['P']); // Play S to beat all P
    
    cout << max_wins << endl;
    
    return 0;
}