#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    string S;
    cin >> N >> S;
    
    char prev = 'N';  // Previous move in the sequence
    int ans = 0;
    
    for (char c : S) {
        if (c == 'P') {
            if (prev != 'S') {
                ans++;
            }
            prev = 'P';
        }
        else if (c == 'R') {
            if (prev != 'P') {
                ans++;
            }
            prev = 'R';
        }
        else if (c == 'S') {
            if (prev != 'R') {
                ans++;
            }
            prev = 'S';
        }
    }
    
    cout << ans;
    return 0;
}