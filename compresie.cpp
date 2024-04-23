#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("compresie.in");
    ofstream fout("compresie.out");

    int n;
    fin >> n;

    int suma_a = 0;
    int suma_b = 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i];
        suma_a += a[i];
    }

    int m;
    fin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        fin >> b[i];
        suma_b += b[i];
    }
    fin.close();
    // In cazul in care sumele nu sunt egale,
    // compresia nu este posibila
    if (suma_a != suma_b) {
        fout << -1;
        return 0;
    }
    int i = 0;
    int j = 0;
    int lungime = 0;
    suma_a = a[i];
    suma_b = b[j];
    while (i < n && j < m) {
        // Daca sumele sunt egale, fac compresia
        // si trec la urmatoarele elemente
        if (suma_a == suma_b) {
            lungime++;
            i++;
            j++;
            suma_a += a[i];
            suma_b += b[j];
        // Altfel, inaintez intr-unul dintre vectori pana ajung la sume egale
        } else if (suma_a < suma_b) {
            i++;
            suma_a += a[i];
        }  else if (suma_a > suma_b) {
            j++;
            suma_b += b[j];
        }
    }
    fout << lungime;
    fout.close();

    return 0;
}
