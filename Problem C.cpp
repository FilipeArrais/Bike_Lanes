//g++ -std=c++17 -Wall -Wextra -O2 "Problem C.cpp" -lm
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int resolver(){
    return 1;
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num_casos, n, m, q, A, B, D;
    cin >> num_casos;

    for(int _ = 0; _ < num_casos; _++){
        cin >> n >> m >> q;
        
        for(int __ = 0; __ < m; __++){
            cin >> A >> B >> D;
            //cout << A << " " << B << " " << D << "\n";    
        }
        //cout << resolver() << "\n";
    }

    return 0;
}