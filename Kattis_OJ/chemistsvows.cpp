#include <bits/stdc++.h>

using namespace std;

unordered_set<string> atom;
vector<int> memo;
string s;

bool dp(int i) {
    if (i == s.size()) return true;
    if (memo[i] != -1) return memo[i];
    if (atom.count(s.substr(i, 1)) && dp(i + 1))
        return memo[i] = true;
    if (i + 1 < s.size() && atom.count(s.substr(i, 2)) && dp(i + 2))
        return memo[i] = true;
    return memo[i] = false;
}

int main() {
    atom.insert("h");
    atom.insert("he");
    atom.insert("li");
    atom.insert("be");
    atom.insert("b");
    atom.insert("c");
    atom.insert("n");
    atom.insert("o");
    atom.insert("f");
    atom.insert("ne");
    atom.insert("na");
    atom.insert("mg");
    atom.insert("al");
    atom.insert("si");
    atom.insert("p");
    atom.insert("s");
    atom.insert("cl");
    atom.insert("ar");
    atom.insert("k");
    atom.insert("ca");
    atom.insert("sc");
    atom.insert("ti");
    atom.insert("v");
    atom.insert("cr");
    atom.insert("mn");
    atom.insert("fe");
    atom.insert("co");
    atom.insert("ni");
    atom.insert("cu");
    atom.insert("zn");
    atom.insert("ga");
    atom.insert("ge");
    atom.insert("as");
    atom.insert("se");
    atom.insert("br");
    atom.insert("kr");
    atom.insert("rb");
    atom.insert("sr");
    atom.insert("y");
    atom.insert("zr");
    atom.insert("nb");
    atom.insert("mo");
    atom.insert("tc");
    atom.insert("ru");
    atom.insert("rh");
    atom.insert("pd");
    atom.insert("ag");
    atom.insert("cd");
    atom.insert("in");
    atom.insert("sn");
    atom.insert("sb");
    atom.insert("te");
    atom.insert("i");
    atom.insert("xe");
    atom.insert("cs");
    atom.insert("ba");
    atom.insert("hf");
    atom.insert("ta");
    atom.insert("w");
    atom.insert("re");
    atom.insert("os");
    atom.insert("ir");
    atom.insert("pt");
    atom.insert("au");
    atom.insert("hg");
    atom.insert("tl");
    atom.insert("pb");
    atom.insert("bi");
    atom.insert("po");
    atom.insert("at");
    atom.insert("rn");
    atom.insert("fr");
    atom.insert("ra");
    atom.insert("rf");
    atom.insert("db");
    atom.insert("sg");
    atom.insert("bh");
    atom.insert("hs");
    atom.insert("mt");
    atom.insert("ds");
    atom.insert("rg");
    atom.insert("cn");
    atom.insert("fl");
    atom.insert("lv");
    atom.insert("la");
    atom.insert("ce");
    atom.insert("pr");
    atom.insert("nd");
    atom.insert("pm");
    atom.insert("sm");
    atom.insert("eu");
    atom.insert("gd");
    atom.insert("tb");
    atom.insert("dy");
    atom.insert("ho");
    atom.insert("er");
    atom.insert("tm");
    atom.insert("yb");
    atom.insert("lu");
    atom.insert("ac");
    atom.insert("th");
    atom.insert("pa");
    atom.insert("u");
    atom.insert("np");
    atom.insert("pu");
    atom.insert("am");
    atom.insert("cm");
    atom.insert("bk");
    atom.insert("cf");
    atom.insert("es");
    atom.insert("fm");
    atom.insert("md");
    atom.insert("no");
    atom.insert("lr");
    

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> s;
        memo.assign(s.size(), -1);
        if (dp(0)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}