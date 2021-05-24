//g++ -std=c++17 -Wall -Wextra -O2 "ProblemC_3.cpp" -lm
#include <iostream>
//#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> edge;

vector<vector<int>> graph;
vector<vector<int>> Scc;
vector<bool> containsStack;
vector<int> low;
vector<int> dfs;
vector<int> S;

//kruskal
vector<pair<int, edge>> G;
vector<int> set;
vector<int> rank1;
int soma_lane = 0;
int maior_lane = 0;

int q, n, t = 1;


void tarjan(int v);
pair<int,int> conta_pois();

int main() {
    
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //n numero de nos
    //m numero de ligaçoes
    // q numero de questoes
    //Ponto A , Ponto B e D a distancia entre ele;
    int num_casos,  m, A, B, D;
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
            cout << p.first << " " << p.second << " " << maior_lane << "\n";  
        }
        else{
            cout << p.first << " " << p.second << " " << maior_lane <<" " << soma_lane << "\n";  
        }

        t = 1;
        soma_lane = 0;
        maior_lane = 0;
        S =  vector<int>();
        Scc =  vector<vector<int>>();
        
    }

    return 0;
}

int find_set(int a){
    if(set[a] != a)
        set[a] = find_set(set[a]);
    return set[a];    
}

void link(int a, int b){
    if(rank1[a] > rank1[b])
        set[b] = a;
    else
        set[a] = b;
    if(rank1[a] == rank1[b])
        rank1[b]++;
}

void union_set(int a, int b){
    link(find_set(a), find_set(b));
}

void make_set(){
    //inicializar
    set = vector<int>(n+1);
    rank1 = vector<int>(n+1);
    
    for(auto poi: Scc[Scc.size() -1]){
        set[poi] = poi;
    }
}

void Kruskal(){
    //inicializar
    int count = 0;
    make_set();

    //ordenar vetor
    sort(G.begin(), G.end());
    
    for(auto a: G){
        pair<int, int> edge = a.second;
        //cout << a.first << "\t" << edge.first << " " << edge.second << "\n";
        if(find_set(edge.first) != find_set(edge.second)){
            count += a.first;
            union_set(edge.first, edge.second);
        }
    } 
    
    if(count > maior_lane)
        maior_lane = count;

    soma_lane += count;    
}

pair<int,int> conta_pois(){
    int count = 0;
    size_t maior = 0;
    for(auto i: Scc){
        if(i.size() > 1){
            count++;
            if(i.size() > maior){
                maior = i.size();
            }
        }
    }
    return pair(count, maior);
}

void tarjan(int v){
    low[v] = dfs[v] = t;
    t = t + 1;
    S.push_back(v);
    containsStack[v] = true;
    for(int w = 0; w <= n; w++){
        if(graph[v][w] != 0){
            
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
        vector <int> C;
        int w;
        do{
            w = S[S.size() - 1]; 
            S.pop_back();
            containsStack[w] = false;
            C.push_back(w);
        }while(w != v);

        Scc.push_back(C);
    
        if(q > 2){
            for(auto z: C){
                for(auto x: C){
                    if(graph[x][z] != 0) 
                        G.push_back({graph[x][z], {x, z}});
                }             
            }

            Kruskal();
            G.clear();
        }
    }
}
