#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int, int> m;
    int q;
    cin >> q;
    int ans = 0;
    
    for(int i = 0; i < q; i++){
        int n, x;
        cin >> n;
        
        if(n == 1){
            cin >> x;
            m[x]++;
            if(m[x] == 1) ans++; // Only increment if it's the first occurrence
        } else if(n == 2){
            cin >> x;
            m[x]--;
            if(m[x] == 0) ans--; // Only decrement if it's the last occurrence
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}