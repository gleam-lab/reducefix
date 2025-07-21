#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int, int> m;
    int q;
    cin >> q;
    int distinct_count = 0;

    for(int i = 0; i < q; i++){
        int query_type, x;
        cin >> query_type;

        if(query_type == 1){
            cin >> x;
            if(m[x] == 0){
                distinct_count++;
            }
            m[x]++;
        }else if(query_type == 2){
            cin >> x;
            m[x]--;
            if(m[x] == 0){
                distinct_count--;
            }
        }else if(query_type == 3){
            cout << distinct_count << endl;
        }
    }
    return 0;
}