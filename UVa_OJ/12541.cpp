#include <bits/stdc++.h>

using namespace std;

struct Person {
    string name;
    int day, month, year;
};

int LessThan(Person a, Person b) {
    if (a.year != b.year) return a.year > b.year;
    if (a.month != b.month) return a.month > b.month;
    return a.day > b.day;
}

void heapify(Person a[], int n, int id) {
    if (id >= n / 2) return;
    int k = 2 * id + 1;
    if (k < n) {
        if (k + 1 < n && LessThan(a[k], a[k + 1]))
            ++k;
        if (LessThan(a[id], a[k]))
            swap(a[id], a[k]);
    }
    heapify(a, n, k);
}

int main() {
    int n;
    cin >> n;
    Person a[n];
    for (int i = 0; i < n; ++i) 
        cin >> a[i].name >> a[i].day >> a[i].month >> a[i].year;

    int id = n / 2;
    while (id >= 0) {
        heapify(a, n, id);
        --id;
    }

    for (int i = n - 1; i >= 0; --i) {
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }

    cout << a[0].name << endl;
    cout << a[n - 1].name << endl;
    return 0;
}