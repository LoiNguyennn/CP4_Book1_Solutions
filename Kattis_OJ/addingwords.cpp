#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<string, int> mp;
    unordered_set<int> val;
    string in;
    while (getline(cin, in)) {
        stringstream sin(in);
        string token;
        sin >> token;
        bool flag = false;
        if (token == "def") {
            sin >> token;
            int t;
            sin >> t;
            if (mp.find(token) != mp.end())
                val.erase(mp[token]);
            mp[token] = t;
            val.insert(t);
        } else if (token == "calc") {
            vector<string> v;
            while (sin >> token) {
                cout << token << " ";
                if (token != "+" && token != "-" && token != "=") {
                    if (mp.find(token) != mp.end())
                        v.push_back(token);
                    else
                        flag = true;
                } else if (token == "+" || token == "-") {
                    v.push_back(token);
                }
            }
            if (flag) {
                cout << "unknown\n";
            } else {
                stack<int> s;
                string curop;
                for (int i = 0; i < v.size(); ++i) {
                    if (v[i] != "+" && v[i] != "-") {
                        s.push(mp[v[i]]);
                        if (s.size() == 2) {
                            int res = 0;
                            if (curop == "+") {
                                int operand2 = s.top();
                                s.pop();
                                int operand1 = s.top();
                                s.pop();
                                res = operand1 + operand2;
                            } else {
                                int operand2 = s.top();
                                s.pop();
                                int operand1 = s.top();
                                s.pop();
                                res = operand1 - operand2;
                            }
                            s.push(res);
                        }
                    }
                    else
                        curop = v[i];
                }
                if (val.find(s.top()) == val.end())
                    cout << "unknown\n";
                else 
                    for (auto x : mp) {
                        if (x.second == s.top()) {
                            cout << x.first << endl;
                            break;
                        }
                    }
            }
        } else {
            mp.clear();
            val.clear();
        }
    }
    return 0;
}