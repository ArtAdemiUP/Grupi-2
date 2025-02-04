using namespace std;
#include "functions.h"
#include <iostream>

void shtoShpenzim(vector<Shpenzim>& shpenzimet) {
    Shpenzim shpenzimiIri;
    
    cout << "Shkruaj shumën: ";
    cin >> shpenzimiIri.shuma;
    
    cout << "Shkruaj kategorinë (Ushqim/Transport/Argëtim): ";
    cin >> shpenzimiIri.kategoria;
    
    cout << "Shkruaj përshkrimin: ";
    cin.ignore();
    getline(cin, shpenzimiIri.pershkrimi);
    
    shpenzimet.push_back(shpenzimiIri);
    cout << "Shpenzimi u shtua me sukses!\n";
}

void shikoShpenzimet(const vector<Shpenzim>& shpenzimet) {
    if (shpenzimet.empty()) {
        cout << "Nuk ka shpenzime për të shikuar.\n";
        return;
    }
    
    cout << "\nLista e Shpenzimeve:\n";
    cout << "ID  Shuma  Kategoria  Përshkrimi\n";
    
    for (int i = 0; i < shpenzimet.size(); i++) {
        cout << i << "  $"
             << shpenzimet[i].shuma << "  "
             << shpenzimet[i].kategoria << "  "
             << shpenzimet[i].pershkrimi << endl;
    }
}

double llogaritTotali(const vector<Shpenzim>& shpenzimet) {
    double totali = 0.0;
    for (const auto& shpenzim : shpenzimet) {
        totali += shpenzim.shuma;
    }
    return totali;
}

void llogaritNgaKategoria(const vector<Shpenzim>& shpenzimet, const string& kategoria) {
    double totaliKategorise = 0.0;
    bool gjetur = false;
    
    for (const auto& shpenzim : shpenzimet) {
        if (shpenzim.kategoria == kategoria) {
            totaliKategorise += shpenzim.shuma;
            gjetur = true;
        }
    }
    
    if (gjetur) {
        cout << "Totali i shpenzimeve në kategorinë " << kategoria << ": $" << totaliKategorise << endl;
    } else {
        cout << "Nuk ka shpenzime në kategorinë " << kategoria << ".\n";
    }
}

void fshiShpenzim(vector<Shpenzim>& shpenzimet, int id) {
    if (id < 0 || id >= shpenzimet.size()) {
        cout<< "ID e pavlefshme. Asnjë shpenzim nuk u fshi.\n";
        return;
    }
    
    shpenzimet.erase(shpenzimet.begin() + id);
    cout << "Shpenzimi u fshi me sukses!\n";
}
