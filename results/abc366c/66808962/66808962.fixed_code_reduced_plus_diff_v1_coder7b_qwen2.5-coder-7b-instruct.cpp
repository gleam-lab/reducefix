#include<iostream>
#include<unordered_set>

using namespace std;

int main(){
    unordered_set<int> s;
    int q;
    cin >> q;

    while(q--){
        int n,x;
        cin >> n;

        if(n==1){
            cin >> x;
            s.insert(x);
        } else if(n==2){
            cin >> x;
            s.erase(x);
        } else {
            cout << s.size() << '\n';
        }
    }

    return 0;
}