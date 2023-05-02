#include <iostream>

using namespace std;

string word(int n) {
    string temp;
    while(n > 0) {
        temp.push_back(n % 26 + 'a');
        n /= 26;
    }
    return temp;
}

int main() {
    int n;
    cin >> n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cout << word(i) << " ";
    }
    cout << '\n';
    return 0;
}