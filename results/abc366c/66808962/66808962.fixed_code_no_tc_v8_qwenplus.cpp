#include<iostream>
#include<map>
using namespace std;
using ll = long long;

int main(){
    map<int,int> m;
    int q;
    cin >> q;

    for(int i=0;i<q;i++){
        int n;
        cin >> n;

        if(n==1){
            int x;
            cin >> x;
            m[x]++;
        }else if(n==2){
            int x;
            cin >> x;
            m[x]--;
            if(m[x] == 0) {
                m.erase(x);
            }
        }else{
            cout << m.size() << endl;
        }
    }
    return 0;
}