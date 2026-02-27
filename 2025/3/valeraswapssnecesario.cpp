#include <bits/stdc++.h>
using namespace std;

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
}

int main(){

    list<int> grafo;
    int aux;
    while(cin >> aux) grafo.push_back(aux);
    arreglar_lista(grafo);

    for(int x : grafo) cout << x << ' ';
    cout << endl;

    if(!grafo.empty()){        
        for(pair<int, int> p : funcion_de_grafos(grafo.begin(), grafo.end())){
            cout << p.first << ' ' << p.second << '\n';
        }
    }

    return 0;
}