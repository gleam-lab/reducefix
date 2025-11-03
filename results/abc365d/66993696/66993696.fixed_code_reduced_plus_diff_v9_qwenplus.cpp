#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    // Count frequency of each move
    map<char, int> cnt;
    for (char c : s) {
        cnt[c]++;
    }
    
    // The optimal strategy is to choose the move that beats the most frequent move
    // P beats R, R beats S, S beats P
    int ans = 0;
    ans = max(ans, cnt['R']); // Choose P to beat all R
    ans = max(ans, cnt['S']); // Choose R to beat all S
    ans = max(ans, cnt['P']); // Choose S to beat all P
    
    cout << ans << endl;
    return 0;
}