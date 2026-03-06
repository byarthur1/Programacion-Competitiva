// https://judge.yosupo.jp/problem/cartesian_tree

/* 
    Ver el primer elemento a un lado que es menor:

        Pila p
        Para cada elemento:
            Buscar el primer elemento de la pila que es menor a este quitando los de encima
            Este es el elemento, si la pila se ha vaciado, no existe
            Meter el elemento actual en la pila
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    vector<int> l(n), r(n);
    stack<int> st;
    for(int i=0; i<n; ++i){
        while(!st.empty() && a[i] < a[st.top()]) st.pop();
        if(!st.empty()) l[i] = st.top();
        else l[i] = -1;
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1; i>=0; --i){
        while(!st.empty() && a[i] < a[st.top()]) st.pop();
        if(!st.empty()) r[i] = st.top();
        else r[i] = -1;
        st.push(i);
    }

    for(int i=0; i<n; ++i){
        if(i != 0) cout << ' ';
        int iz = l[i], de = r[i];
        int padre = 0;
        if(iz != -1 && de != -1) padre = a[iz] > a[de] ? iz : de;
        else if(iz != -1) padre = iz;
        else if(de != -1) padre = de;
        else padre = i;
        cout << padre;
    }
    cout << endl;

    return 0;
}