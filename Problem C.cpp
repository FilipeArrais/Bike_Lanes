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
int t = 0;
stack<int> S;
stack<stack<int>> Scc;
vector<bool> containsStack;


void tarjan(int v);

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
        low = vector<int>(n+1,-1);
        dfs = vector<int>(n+1,-1);
        containsStack = vector<bool>(n);
    
        for(int __ = 0; __ < m; __++){
            cin >> A >> B >> D;
            graph[A][B] = D;
            //cout << A << " " << B << " " << D << "\n";    
        }

     
        for(int i = 0; i < n ; i++){
            if(dfs[i+1]==-1)
                tarjan(i+1);
        }
        cout << Scc.size() <<"\n";
        t = 0;
        S =  stack<int>();
        Scc =  stack<stack<int>>();
        
    }

    return 0;
}


void tarjan(int v){
    low[v] = dfs[v] = t;
    t = t + 1;
    S.push(v);
    containsStack[v] = true;
    for(auto w : graph[v]){
        if(dfs[w] == -1){
            tarjan(w);
            low[w] = min(low[v], low[w]);
        }
        else if(containsStack[w]){
            low[v] = min(low[v],dfs[w]);
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
