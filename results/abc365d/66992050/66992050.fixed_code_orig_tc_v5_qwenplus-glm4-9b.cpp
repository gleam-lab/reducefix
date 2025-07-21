#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int N;
    string S;
    cin >> N >> S;
    char past = 'N';
    int ans = 0;
    for(char c: S){
        if(c == 'P' && past == 'S' || c == 'R' && past == 'P' || c == 'S' && past == 'R') {
            ans++;
            past = c;
        } else if(past == 'N' || c == past) {
            past = c;
        }
    }
    cout << ans;
    return 0;
}