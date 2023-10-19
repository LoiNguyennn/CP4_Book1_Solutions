#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

typedef pair<string, int> si;

vector<si> hierholzer(int s, vector<vector<si>>& AL) {
    stack<si> st;
    vector<si> ans;
    st.emplace("", s);

    int idx[26] = {0};

    while (!st.empty()) {
        string e = st.top().first;
        int u = st.top().second;
        if (idx[u] < AL[u].size()) {
            st.emplace(AL[u][idx[u]]);
            ++idx[u];
        } else {
            ans.emplace_back(e, u);
            st.pop();
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}    

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        vector<vector<si>> AL(26);
        int in_deg[26] = {0};
        int out_deg[26] = {0};

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            int u = s[0] - 'a';
            int v = s[s.length() - 1] - 'a';
            AL[u].emplace_back(s, v);
            ++in_deg[v];
            ++out_deg[u];
        }

        for (int i = 0; i < 26; ++i)
            sort(AL[i].begin(), AL[i].end());

        int extra_in = 0, extra_out = 0, in_equal_out = 0;
        int start_node_1 = 0, start_node_2 = -1;
        for (int i = 0; i < 26; ++i) {
            if (out_deg[i] - in_deg[i] == 1) {
                ++extra_in;
                start_node_1 = i;
            } else if (in_deg[i] - out_deg[i] == 1) {
                ++extra_out;
            } else if (in_deg[i] == out_deg[i]) {
                ++in_equal_out;
                if (in_deg[i] > 0 && start_node_2 == -1)
                    start_node_2 = i;
            }
        }

        vector<si> ans;
        if (in_equal_out == 26) {
            ans = hierholzer(start_node_2, AL);
        } else if (extra_in == 1 && extra_out == 1 && in_equal_out == 24) {
            ans = hierholzer(start_node_1, AL);
        }

        if (ans.size() != n + 1) {
            cout << "***\n";
        } else {
            for (int i = 1; i < ans.size() - 1; ++i)
                cout << ans[i].first << ".";
            cout << ans[ans.size() - 1].first << endl;
        }
    }
    return 0;
}