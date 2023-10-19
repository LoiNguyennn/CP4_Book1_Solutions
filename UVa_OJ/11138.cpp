#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int G[500][500];
vector<int> match, visited;
int bolts, nuts;


int Aug(int L) {
    if (visited[L]) return 0;
    visited[L] = 1;
    for (int R = 0; R < nuts; ++R) {
        if (G[L][R])
            if (match[R] == -1 || Aug(match[R])) {
                match[R] = L;
                return 1;
            }
    }
    return 0;
}

int main() {
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; ++tc) {
        cin >> bolts >> nuts;
        for (int i = 0; i < bolts; ++i) 
            for (int j = 0; j < nuts; ++j) 
                cin >> G[i][j];
        
        match.assign(nuts, -1);
        int MCBM = 0;
        for (int L = 0; L < bolts; ++L) {
            visited.assign(bolts, 0);
            MCBM += Aug(L);
        }
        cout << "Case " << tc << ": a maximum of " << MCBM << " nuts and bolts can be fitted together\n";
    }        
    return 0;
}