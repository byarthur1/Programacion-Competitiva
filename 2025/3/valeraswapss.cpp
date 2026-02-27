#include <bits/stdc++.h>
using namespace std;
/*
list<pair<int, int>> funcion_de_grafos(list<int>::iterator a, list<int>::iterator b){
    
    //En teoria el primer elemento, es decir, el del iterador a será el más pequeño, así que buscamos el segundo más pequeño

    list<pair<int, int>> nueva;
    auto it = a;    
    it++;
    if(it == b) return nueva;


    int mini = *it;
    auto itmini = it;
    while(it != b){
        if(*it < mini){
            mini = *it;
            itmini = it;
        }
        it++;
    }

    //itmini tiene el segundo elemento menor

    nueva.push_back(make_pair(*a, *itmini));
    nueva.merge(funcion_de_grafos(a, itmini));
    nueva.merge(funcion_de_grafos(itmini, b));
    return nueva;
}

void arreglar_lista(list<int>& lista){
    //Esto pone el menor elemento de la lista como el primero rotandola 
    if(lista.size() <= 1) return;
    list<int>::iterator itmini;
    int mini = INT_MAX;
    for(auto it = lista.begin(); it != lista.end(); it++){
        if(*it < mini){
            mini = *it;
            itmini = it;
        }
    } 
    rotate(lista.begin(), itmini, lista.end());
}*/

int encuentra(vector<int>& a, int x){
    if(a[x] < 0) return x;
    return a[x] = encuentra(a, a[x]);
}

void unionn(vector<int>& a, int x, int y){
    int rx = encuentra(a, x);
    int ry = encuentra(a, y);
    if(rx == ry) return;
    if(a[rx] < a[ry]) a[ry] = rx;
    else{
        if(a[rx] == a[ry]) a[ry]--;
        a[rx] = ry;
    } 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m; 
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        v[i]--;
    }
    cin >> m;
    list<list<int>> lista_grafos;   //En cada lista de esta lista se está guardado un grafo como tal

    // Esto encuentra los swaps necesarios para llegar a la permutacion identidad
    long long sol = 0;
    vector<bool> b(n);
    for(int i=0; i<n; ++i) b[i] = false;
    for(int i=0; i<n; ++i){
        if(v[i] == i) {
            continue;
        }
        if(b[i]) continue;
        int current = i, original = i;
        list<int> nueva;
        do{
            current = v[current];
            nueva.push_back(current);
            b[current] = true;
            sol++;
        } while(current != original);
        lista_grafos.push_back(nueva);
        sol--;
    }
    //

    if(sol >= m){
        
        if(sol == m){
            cout << 0 << endl;
            return 0;
        } 
/*
        list<pair<int, int>> ey;

        //Funcion que hay que hacer aquí: para cada lista que hay en lista_grafos, obtener una de pares de enteros con los swaps ordenados
        //Despues hacer un merge e ir metiendolo todo ordenado en ey.

        for(auto it = lista_grafos.begin(); it != lista_grafos.end(); it++){
            arreglar_lista(*it);
            ey.merge(funcion_de_grafos(((*it)).begin(), ((*it)).end()));
        }        

        cout << sol - m << '\n';
        auto it = ey.begin();
        cout << it->first + 1 << ' ' << it->second + 1;
        it++;
        for(int i=1; i<sol-m && it != ey.end(); ++i){
            cout << ' ' << it->first + 1 << ' ' << it->second + 1;
            it++;
        }*/

        //Estructura de arboles de relaciones de equivalencia
        
        cout << sol - m << '\n';

        int solucionados = 0;
        while(solucionados < sol - m){
            vector<int> a(n);
            for(int i=0; i<n; ++i) b[i] = false;
            for(int i=0; i<n; ++i){
                if(v[i] == i){
                    a[i] = -1;
                    continue;
                } 
                if(b[i]) continue;
                int current = i, original = i;
                a[i] = -1;
                b[i] = true;
                do{
                    current = v[current];
                    a[current] = i;
                    b[current] = true;
                } while(v[current] != original);
            }
            bool ee = true;
            for(int i=0; i<n && ee; ++i) for(int j=0; j<n && ee; ++j){
                if(i == j) continue;
                if(encuentra(a, i) == encuentra(a, j)){
                    if(solucionados > 0) cout << ' ';
                    cout << i+1 << ' ' << j+1;
                    ee = false;
                    int aa = 0, bb = 0;
                    for(int k=0; k<n; ++k){
                        if(v[k] == i){
                            aa = k;
                            break;
                        }
                    }
                    for(int k=0; k<n; ++k){
                        if(v[k] == j){
                            bb = k;
                            break;
                        }
                    }
                    swap(v[aa], v[bb]);
                    solucionados++;
                }
            }
        }

        cout << '\n';

    } else{
        
        //Ahora necesito todos los posibles swaps que desordenan
        //Relaciones de equivalencia ?

        vector<int> a(n);
        for(int i=0; i<n; ++i) a[i] = -1;
        for(list<int> l : lista_grafos){
            if(l.empty()) continue;
            auto it = l.begin();
            int p = *it;
            it++;
            while(it != l.end()){
                unionn(a, p, *it);
                it++;
            }
        }
        
        cout << m - sol << '\n';

        int salida = 0;
        for(int i=1; i<n && salida < m-sol; ++i){
            if(encuentra(a, 0) != encuentra(a, i)){
                if(salida > 0) cout << ' ';
                cout << 1 << ' ' << i+1;
                unionn(a, 0, i);
                salida++;
            } 
        }

    }

    return 0;
}

//Debería de mejorar este codigo bastante