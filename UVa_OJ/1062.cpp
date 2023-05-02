#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    int numTest = 1;
    while (cin >> s && s != "end") {
        vector<char> containers;
        for (int i = 0; i < s.length(); ++i) {
            int place = -1;
            char smallest = 'Z';

            for (int j = 0; j < containers.size(); ++j) {
                if (s[i] <= containers[j] && containers[j] <= smallest) {
                    place = j;
                    smallest = containers[j];
                }
            }

            if (place == -1) {
                containers.push_back(s[i]);
            } else {
                containers[place] = s[i];
            }
        }
        cout << "Case " << numTest++ << ": " << containers.size() << endl;
    }
    return 0;
}