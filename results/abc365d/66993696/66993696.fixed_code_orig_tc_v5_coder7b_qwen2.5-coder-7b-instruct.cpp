#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<int> cnt(3, 0); // To count occurrences of P, R, S
    for(char c : s) {
        cnt[c-'A']++;
    }
    
    // If there is only one type of character, we can't change it
    if(cnt[0] == n || cnt[1] == n || cnt[2] == n) {
        cout << n;
        return 0;
    }
    
    // Calculate the maximum number of changes needed
    int ans = INT_MAX;
    for(int i = 0; i < 3; i++) {
        int temp = 0;
        for(int j = 0; j < 3; j++) {
            if(i != j) {
                temp += cnt[j];
            } else {
                temp += cnt[j]/2 + (cnt[j]%2);
            }
        }
        ans = min(ans, temp);
    }
    
    cout << ans;
    return 0;
}