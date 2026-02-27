#include <bits/stdc++.h>
using namespace std;
#define IMAX 1000000000

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t;
    string s;

    while(t--){

        cin >> n;
        getline(cin, s);
        vector<char> v(n);
        for(int i=0; i<n; i++){
            cin.get(v[i]);
        }
        int mini = IMAX;
        for(char k = 'a'; k <= 'z'; ++k){
            int it1 = 0, it2 = n-1;
            int intento = 0;
            while(it1 < it2){
                if(v[it1] == v[it2]){
                    it1++, it2--;
                    continue;
                }
                if(v[it1] == k){
                    it1++;
                    intento++;
                    continue;
                }
                if(v[it2] == k){
                    it2--;
                    intento++;
                    continue;
                }
                intento = IMAX;
                break;
            }
            if(mini > intento){
                mini = intento;
            }
        }

        if(mini >= IMAX){
            cout << -1 << endl;
        }else{
            cout << mini << endl;
        }
    }

    return 0;
}