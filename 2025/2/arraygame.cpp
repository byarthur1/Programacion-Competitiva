#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    
    int i = 0, li = -1, c = 0;
    while(i < n && a[i] > li){
        li = a[i];
        c++;
        i++;
    }

    int c2 = 0;
    i = n-1, li = -1;
    while(i >= 0 && a[i] > li){
        li = a[i];
        c2++;
        i--;
    }

    if(c%2 || c2%2){
        cout << "Alice\n";
    } else{
        cout << "Bob\n";
    }

    return 0;
}