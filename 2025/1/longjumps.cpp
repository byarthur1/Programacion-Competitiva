#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, lg, x, y;
    cin >> n >> lg >> x >> y;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    bool condx = false, condy = false;

    for(int l=0; l<n; ++l){
        if((long long)a[l] + (long long)x > (long long)lg) break;
        if(binary_search(a.begin(), a.end(), a[l] + x)){
            condx = true;
            break;
        }
    }
    for(int l=0; l<n; ++l){
        if((long long)a[l] + (long long)y > (long long)lg) break;
        if(binary_search(a.begin(), a.end(), a[l] + y)){
            condy = true;
            break;
        }
    }

    if(condx && condy){
        cout << 0 << '\n';
        return 0;
    } 

    if(condx){
        cout << 1 << '\n' << y << '\n';
        return 0;
    }

    if(condy){
        cout << 1 << '\n' << x << '\n';
        return 0;
    }

    for(int l=0; l<n; ++l){

        if((long long)a[l] + (long long)x + (long long)y <= (long long)lg && binary_search(a.begin(), a.end(), a[l] + x + y)){
            cout << 1 << '\n' << a[l] + x << '\n';
            return 0;
        }

        if((long long)a[l] + (long long)x <= (long long)lg && binary_search(a.begin(), a.end(), a[l] + x - y)){
            cout << 1 << '\n' << a[l] + x << '\n';
            return 0;
        }

        if((long long)a[l] - (long long)x >= (long long)0 && binary_search(a.begin(), a.end(), a[l] + y - x)){
            cout << 1 << '\n' << a[l] - x << '\n';
            return 0;
        }

    }

    cout << 2 << '\n' << x << ' ' << y << '\n';
    return 0;

}