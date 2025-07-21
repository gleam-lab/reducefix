#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int,int> m;
    int q;
    cin >> q;

    int ans=0;
    for(int i=0;i<q;i++){
        int n;
        cin >> n;

        if(n==1){
            int x;
            cin >> x;
            if(m[x] == 0) { // If the count was zero before incrementing
                ans++;
            }
            m[x]++;
        }else if(n==2){
            int x;
            cin >> x;
            m[x]--;
            if(m[x] == 0) { // If the count becomes zero after decrementing
                ans--;
            }
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}