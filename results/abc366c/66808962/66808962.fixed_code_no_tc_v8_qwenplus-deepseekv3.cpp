#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int,int> m;
    int q;
    cin >> q;

    int ans=0;
    for(int i=0;i<q;i++){
        int n,x;
        cin >> n;

        if(n==1){
            cin >> x;
            if(m[x] == 0) { // If the ball wasn't in the bag before
                ans++;
            }
            m[x]++;
        }else if(n==2){
            cin >> x;
            m[x]--;
            if(m[x] == 0) {
                ans--;
                m.erase(x); // Remove the entry to save memory
            }
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}