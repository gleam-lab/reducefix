#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<map>
#include<cmath>
#include<math.h>
#include<queue>
#include <iomanip> //setprecisionを使うため
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    set<int> s;
    int q;
    cin >> q;

    for(int i=0;i<q;i++){
        int n,x;
        cin >> n;

        if(n==1){
            cin >> x;
            s.insert(x);
        }else if(n==2){
            cin >> x;
            s.erase(s.find(x));
        }else{
            cout << s.size() << endl;
        }
    }
    return 0;
}