#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    string S;
    cin >> N >> S;
    
    char past = 'N';  // No previous move
    int ans = 0;
    
    for(char c : S){
        if(c == 'P'){
            if(past != 'S'){
                ans++;
                past = 'S';  // After P, we need S to counter
            } else {
                past = 'P';
            }
        }
        else if(c == 'R'){
            if(past != 'P'){
                ans++;
                past = 'P';  // After R, we need P to counter
            } else {
                past = 'R';
            }
        }
        else if(c == 'S'){
            if(past != 'R'){
                ans++;
                past = 'R';  // After S, we need R to counter
            } else {
                past = 'S';
            }
        }
    }
    
    cout << ans;
    return 0;
}