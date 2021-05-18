//g++ -std=c++17 -Wall -Wextra -O2 "Problem C.cpp" -lm
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
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
int conta_pois();

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
        /*for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n ; j++){
                if(graph[i][j] != 0){
                  cout << graph[i][j]<<" ";   
                }
               
            }
            cout << "\n";
        }*/

     
        for(int i = 1; i <= n ; i++){
            if(dfs[i] ==-1)
                tarjan(i);
        }
        cout << conta_pois() <<"\n";
        t = 1;
        S =  stack<int>();
        Scc =  stack<stack<int>>();
        
    }

    return 0;
}

//Acrescentar maior
int conta_pois(){
    int count = 0;
    stack<int> aux;
    while(!Scc.empty()){
        aux = Scc.top();
        Scc.pop();
        if(aux.size() > 1){
            count++;
        }
    }

    
    return count;
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
