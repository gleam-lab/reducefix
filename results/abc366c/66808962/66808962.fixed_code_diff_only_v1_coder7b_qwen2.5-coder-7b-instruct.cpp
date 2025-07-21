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
    set<int> s; // Use set instead of map for better performance
    int q;
    cin >> q;

    int ans=0;
    for(int i=0;i<q;i++){
        int n,x;
        cin >> n;

        if(n==1){
            cin >> x;
            s.insert(x); // Insert directly into set
            ans = s.size(); // Update count of unique elements
        }else if(n==2){
            cin >> x;
            s.erase(s.find(x)); // Erase element from set
            ans = s.size(); // Update count of unique elements
        }else{
            cout << ans << endl;
        }
    }
    // cout << m.size() << endl;
    return 0;
}