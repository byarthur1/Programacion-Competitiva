// https://codeforces.com/gym/669876/problem/B
#include <bits/stdc++.h>
using namespace std;

int main(){

    int t; cin >> t;

    while(t--){

        int d;
        cin >> d;
        double a = 0, b = d, c = ((double)d)/2;

        if(d < 4 && d > 0){
            cout << "N\n";
            continue;
        }

        while(abs(d-c*(d-c)) >= 1e-8){
            if(d > c*(d-c)) b = c;
            else a = c;
            c = (a+b)/2;
        }

        cout << fixed << setprecision(9);
        cout << "Y " << c << " " << d-c << '\n';

    }

    return 0;
}