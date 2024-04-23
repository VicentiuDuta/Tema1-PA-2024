Problema 1: Alimentare Servere
    
    Pentru rezolvarea acestei probleme, am ales sa folosesc o structura "server", avand campurile putere si curent. Primul pas in rezolvarea acesteia il constituie sortarea vectorului de servere dupa cantitatile de curent individuale. Apoi, am folosit algoritmul de cautare binara pentru a obtine puterea maxima de calcul a sistemului. Complexitatea, in urma folosirii cautarii binare, este O(log n).

Problema 2: Colorare
    
    Pentru implementarea task-ului 2 al temei, am folosit regulile de calcul ale tranzitiilor dintre H si V (V -> V = 2, V -> H = 2, H -> V = 1, H -> H = 3; intial: V = 3, H = 6). Pentru a calcula puterile numerelor intr-un mod eficient, am folosit o functie de exponentiere gasita pe https://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn/ , care are complexitatea O(log n).

Problema 3: Compresie
    
    Pentru rezolvarea problemei 3, am folosit 2 'pointeri', unul pentru fiecare sir. Daca sumele sunt egale, inaintez cu ambii pointeri. Daca suma unui sir este mai mica, avansez cu indexul acelui sir pentru a incerca sa cresc suma partiala. Complexitatea algoritmului este O(n + m), unde n si m sunt lungimile celor doua siruri.

Problema 4: Criptat
    
    In cadrul implementarii task-ului 4, am inceput prin a construi un alfabet format din toate literele cuvintelor. Apoi, pentru fiecare litera din alfabet, am sortat vectorul dupa numarul de aparitii al literei respective, raportat la lungimea cuvantului. In cazul in care rapoartele erau egale, am ales cuvantul cu lungimea mai mare. Dupa sortare, am luat rand pe rand cuvintele si am verificat daca conditia ca litera dominanta sa aiba mai multe aparitii decat jumatate din lungimea parolei ramane adevarata, iar in acest caz am adaugat cuvantul in parola de la pasul curent. La fiecare pas, verific daca parola curenta este mai lunga decat alta parola obtinuta la pasii anterior, iar in caz afirmativ lungimea maxima va deveni lungimea parolei de la pasul curent. Complexitatea algoritmului este O(n log n).

Problema 5: Oferta
    
    Pentru rezolvarea ultimului task, am folosit programarea dinamica. Astfel, la pasul i, dp[i] = pretul minim obtinut prin gruparea primelor i produse. Am folosit o abordare de tip bottom-up, iar de aceea am luat primele 3 produse separat. Apoi, pentru restul produselor, am verificat care dintre cele 4 cazuri ar fi mai ieftin(din ultimele 3 produse: aplic reducerea pe primele 2 si il iau pe al treilea separat, aplic reducerea pe ultimele 2 si il iau pe primul separat, aplic reducerea pe toate cele 3 produsele sau il iau pe ultimul individual), solutia finala gasindu-se in dp[n - 1]. Complexitatea algoritmului este O(n), fiecare produs fiind procesat o singura data.
