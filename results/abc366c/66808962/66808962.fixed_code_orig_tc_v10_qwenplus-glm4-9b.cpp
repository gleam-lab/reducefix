int q;
cin >> q;

int ans=0;
for(int i=0;i<q;i++){
    int n,x;
    cin >> n;

    if(n==1){
        cin >> x;
        if(!m.count(x)) { // Check if the ball with integer x is not yet in the map
            m[x] = 1;
            ans++;
        } else m[x]++;
    } else if(n==2){
        cin >> x;
        m[x]--;
        if(m[x] == 0) ans--; // Decrement unique count if integer x is removed
    } else {
        cout << ans << endl;
    }
}