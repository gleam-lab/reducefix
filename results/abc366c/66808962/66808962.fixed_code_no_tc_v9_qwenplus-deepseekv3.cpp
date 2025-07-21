#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int,int> m;
    int q;
    cin >> q;

    int ans = 0;
    for(int i=0;i<q;i++){
        int n,x;
        cin >> n;

        if(n==1){
            cin >> x;
            m[x]++;
            if(m[x] == 1) ans++; // Only increment if it's the first ball of this value
        }else if(n==2){
            cin >> x;
            m[x]--;
            if(m[x] == 0) {
                ans--; // Only decrement if there are no more balls of this value
                m.erase(x); // Optional: remove the key to save space
            }
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}