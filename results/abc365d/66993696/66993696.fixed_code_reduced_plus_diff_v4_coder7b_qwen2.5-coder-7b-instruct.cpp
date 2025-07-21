#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<int> cnt(3, 0); // Counters for 'P', 'R', 'S'
    for(char c : s) {
        if(c == 'P') cnt[0]++;
        else if(c == 'R') cnt[1]++;
        else cnt[2]++;
    }
    
    int result = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i != j) {
                int can_win = min(cnt[i], cnt[j]);
                result = max(result, can_win * 2 + max(cnt[(i + 1) % 3] + cnt[(i + 2) % 3], cnt[(j + 1) % 3] + cnt[(j + 2) % 3]);
            }
        }
    }
    
    cout << result << endl;
    return 0;
}