#include <iostream>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ost;

ost male, fmale;

int getLessthan(string& s, int gender) {
    if (gender == 1) {
        auto it = male.lower_bound(s);
        if (it == male.end())
            return male.size();
        return male.order_of_key(*it);
    } else {
        auto it = fmale.lower_bound(s);
        if (it == fmale.end())
            return fmale.size();
        return fmale.order_of_key(*it);
    }
}

char name[100];
char st[100], en[100];
int gender;

int main() {
    int c;
    while (scanf("%d", &c)) {
        if (c == 0) break;
        if (c == 1) {
            scanf("%s %d", name, &gender);
            string s(name);
            if (gender == 1)
                male.insert(s);
            else 
                fmale.insert(s);
        } else if (c == 2) {
            scanf("%s", name);
            string s(name);
            auto it = male.find(s);
            if (it != male.end())
                male.erase(it);
            else fmale.erase(s);
        } else {
            scanf("%s %s %d", st, en, &gender);
            string s(st);
            string e(en);
            int ans = 0;
            if (gender == 1 || gender == 0) 
                ans += getLessthan(e, 1) - getLessthan(s, 1);;
            if (gender == 2 || gender == 0) 
                ans += getLessthan(e, 2) - getLessthan(s, 2);
            printf("%d\n", ans);
        }
    }
    return 0;
}