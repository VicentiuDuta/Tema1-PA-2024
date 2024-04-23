#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct server {
    int putere;
    int curent;
};

double bsearch(vector<server> servere, int n, double c_min, double c_max) {
    double c_mij = (c_min + c_max) / 2.0;
    double putere_minima_curenta = 1000000000.0;
    vector<double> puteri_noi(n);

    long unsigned int pozitie_putere_minima = -1;
    int i;
    // Calculam noile puteri si puterea minima de la pasul curent
     for (i = 0; i < n; i++) {
        puteri_noi[i] = servere[i].putere - abs(c_mij - servere[i].curent);
            if (puteri_noi[i] < putere_minima_curenta) {
                putere_minima_curenta = puteri_noi[i];
                pozitie_putere_minima = i;
            }
        }
    if (c_max - c_min < 0.05)
        return putere_minima_curenta;
    // Daca puterea minima este gasita in prima jumatate
    // continuam cautarea acolo
    if (pozitie_putere_minima < servere.size() / 2) {
        double rezultat = bsearch(servere, n, c_min, c_mij);
        if (rezultat >= putere_minima_curenta)
            return rezultat;
        return putere_minima_curenta;
    // Altfel, continuam in a doua jumatate
    } else {
        double rezultat = bsearch(servere, n, c_mij, c_max);
        if (rezultat >= putere_minima_curenta)
            return rezultat;
        return putere_minima_curenta;
    }
}
// Sortam crescator, in functie de curent
bool cmp(server a, server b) {
    return a.curent < b.curent;
}

int main() {
    ifstream fin("servere.in");
    ofstream fout("servere.out");

    int n, i;
    fin >> n;
    vector<server> servere(n);
    for (i = 0; i < n; i++)
        fin >> servere[i].putere;
    for (i = 0; i < n; i++)
        fin >> servere[i].curent;
    fin.close();

    // Calculam minimul si maximul curentilor
    double minim = 1000000000.0;
    double maxim = 0.0;

    for (i = 0; i < n; i++) {
        if (servere[i].curent < minim)
            minim = servere[i].curent;

        if (servere[i].curent > maxim)
            maxim = servere[i].curent;
    }
    // Sortam serverele pentru a putea aplica cautarea binara
    sort(servere.begin(), servere.end(), cmp);
    double putere_minima = bsearch(servere, n, minim, maxim);
    fout << fixed << setprecision(1) << putere_minima << "\n";
    fout.close();
    return 0;
}
