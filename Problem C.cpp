//g++ -std=c++17 -Wall -Wextra -O2 "Problem C.cpp" -lm
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <tuple>
using namespace std;

int n;
vector<vector<int>> graph;
vector<int> low;
vector<int> dfs;
int t = 1;
stack<int> S;
stack<stack<int>> Scc;
vector<bool> containsStack;


void tarjan(int v);
pair<int,int> conta_pois();

int main() {
    
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //n numero de nos
    //m numero de ligaçoes
    // q numero de questoes
    //Ponto A , Ponto B e D a distancia entre ele;
    int num_casos,  m, q, A, B, D;
    cin >> num_casos;

    for(int _ = 0; _ < num_casos; _++){
        cin >> n >> m >> q;
        graph = vector<vector<int>>(n+1,vector<int>(n+1));
        low = vector<int>(n+1,0);
        dfs = vector<int>(n+1,-1);
        containsStack = vector<bool>(n+1,false);
    
        for(int __ = 0; __ < m; __++){
            cin >> A >> B >> D;
            graph[A][B] = D;
            //cout << A << " " << B << " " << D << "\n";    
        }


     
        for(int i = 1; i <= n ; i++){
            if(dfs[i] == -1)
                tarjan(i);
        }
        
        
        pair<int,int> p = conta_pois();
        
        if(q == 1){
            cout << p.first <<"\n";
        }
        else if(q == 2){
            cout << p.first << " " << p.second << "\n";  
        }
        else if (q == 3){
            cout << p.first << " " << p.second << " " << "0" << "\n";  
        }
        else{
            cout << p.first << " " << p.second <<" " << "0" <<" " << "0" << "\n";  
        }

        t = 1;
        S =  stack<int>();
        //Scc =  stack<stack<int>>();
        
    }

    return 0;
}

//Acrescentar maior
pair<int,int> conta_pois(){
    int count = 0;
    size_t maior = 0;
    stack<int> aux;
    while(!Scc.empty()){
        aux = Scc.top();
        Scc.pop();
        if(aux.size() > 1){
            count++;
            if(aux.size() > maior){
                maior = aux.size();
            }
        }

    }
    //cout << "maoir:" << maior <<"\n";
    return pair(count, maior);
}

void tarjan(int v){
    low[v] = dfs[v] = t;
    t = t + 1;
    S.push(v);
    containsStack[v] = true;
    for(int w = 0; w <= n; w++){
        if(graph[v][w] != 0){
            //cout <<"vertice: "<< v <<"\n";
            //cout << graph[w][v]<<"\n";
            if(dfs[w] == -1){
                tarjan(w);
                low[v] = min(low[v], low[w]);
            }
            else if(containsStack[w]){
                low[v] = min(low[v],dfs[w]);
            }  
        }
        
    }
    if(low[v] == dfs[v]){
        stack<int> C;
        int w;
        do{
           w = S.top(); 
           S.pop();
           containsStack[w] = false;
           C.push(w);
        }while(w != v);
        Scc.push(C);
    }
}
