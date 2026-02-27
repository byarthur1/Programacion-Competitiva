// https://codeforces.com/gym/672441/problem/B
// Wrong answer
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int b[9] = {500,200,100,50,20,10,5,2,1};

    int n; cin >> n;
    int n2 = n;

    if(n2 >= 2000){
        n2 = n%2000;
    } 

    if(n2 == 0 || n2 == 4 || n2 == 40 || n2 == 44 || n2 == 400 || n2 == 404 || n2 == 440 || n2 == 444){
        cout << "splittable\n";
    } else{
        vector<int> sol;
        if(n%1000 == 0){
            while(n > 0){
                sol.push_back(200);
                n -= 200;
            }
        } else{
            int j = 0;
                while(n > 0 && j < 9){
                    if(n >= b[j]){
                        sol.push_back(b[j]);
                        n -= b[j];
                    } else{
                        j++;
                    }
                }
        }
        
        cout << sol.size() << endl;
        for(int i=0; i<sol.size(); ++i){
            if(i != 0) cout << ' ';
            cout << sol[i];
        }
        cout << '\n';
    }

    return 0;
}