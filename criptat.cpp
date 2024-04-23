#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

char litera;

bool cmp(string a, string b) {
    // sortam cuvintele dupa numarul de aparitii al
    // literei curente, raportat la lungimea cuvantului
    int nr_aparitii_a = count(a.begin(), a.end(), litera);
    int nr_aparitii_b = count(b.begin(), b.end(), litera);
    double raport_a = (double) nr_aparitii_a / a.size();
    double raport_b = (double) nr_aparitii_b / b.size();
    if (raport_a != raport_b)
        return (raport_a > raport_b);
    // daca rapoartele sunt egale, alegem cuv mai lung
    return (a.size() > b.size());
}



int main() {
    ifstream fin("criptat.in");
    ofstream fout("criptat.out");

    long unsigned int n;
    long unsigned int i;
    fin >> n;
    vector<string> cuvinte(n);
    for (i = 0; i < n; i++)
        fin >> cuvinte[i];

    fin.close();

    for (i = 0; i < n; i++)
        printf("%s\n", cuvinte[i].c_str());

    vector<char> alf;
    long unsigned int j;
    // Construim alfabetul
    for (i = 0; i < n; i++)
        for (j = 0; j < cuvinte[i].size(); j++)
            if (find(alf.begin(), alf.end(), cuvinte[i][j]) == alf.end())
                alf.push_back(cuvinte[i][j]);

    int lungime_maxima = 0;
    int lung_curr = 0;
    int nr_ap_tot = 0;
    // Pentru fiecare litera din alfabet, contruim parola
    // avand ca litera dominanta litera curenta
    for (i = 0; i < alf.size(); i++) {
        litera = alf[i];
        sort(cuvinte.begin(), cuvinte.end(), cmp);
        nr_ap_tot = 0;
        lung_curr = 0;
        for (j = 0; j < cuvinte.size(); j++) {
            int nr_ap_c = count(cuvinte[j].begin(), cuvinte[j].end(), litera);
            double l = (double) (lung_curr + cuvinte[j].size()) / 2;
            // Daca conditia ramane adevarata, adaugam cuvantul
            if (nr_ap_tot + nr_ap_c > l) {
                lung_curr += cuvinte[j].size();
                nr_ap_tot += nr_ap_c;
            }
        }
        // Daca noua parola este mai lunga
        // decat cele precedente, o alegem pe aceasta.
        if (lung_curr > lungime_maxima)
            lungime_maxima = lung_curr;
    }

    fout << lungime_maxima;
    fout.close();

    return 0;
}
