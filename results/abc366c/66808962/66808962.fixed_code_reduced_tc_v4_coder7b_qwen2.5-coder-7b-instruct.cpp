#include<iostream>
#include<set>

using namespace std;

int main(){
    set<int> s;
    int q;
    cin >> q;

    while(q--){
        int n, x;
        cin >> n;

        if(n == 1){
            cin >> x;
            s.insert(x);
        } else if(n == 2){
            cin >> x;
            s.erase(s.find(x));
        } else {
            cout << s.size() << endl;
        }
    }

    return 0;
}