#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000000
#define INP() freopen("input.txt", "r", stdin)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    cin >> n;
    unordered_set<string> s;
    char last = ' ';
    int i;
    for (i = 0; i < n; ++i) {
        string word;
        cin >> word;
        if (last != ' ' && word[0] != last)
            break;
        if (s.find(word) != s.end()) 
            break;
        s.insert(word);
        last = word[word.length() - 1];
    }
    if (i == n)
        cout << "Fair Game\n";
    else 
        cout << "Player " << i % 2 + 1 << " lost\n";
    
    return 0;
}