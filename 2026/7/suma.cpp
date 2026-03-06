#include<bits/stdc++.h>
using namespace std;

int main(){

    int n = 5;
    vector<int> v = {1, 2, 3, 4, 5};

    vector<int> sumi(n), sumd(n);
    long long sumatotal = 0;
    for(int i=0; i<n; ++i){
        sumi[i] = sumatotal;
        sumatotal += v[i];
    }
    sumatotal = 0;
    for(int i=n-1; i>=0; --i){
        sumd[i] = sumatotal;
        sumatotal += v[i];
    }

    cout << sumatotal - sumi[1] - sumd[3] << endl;

    return 0;
}