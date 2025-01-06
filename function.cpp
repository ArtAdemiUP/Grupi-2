
#include "functions.h"
#include <iostream>

void shtoShpenzim(std::vector<Shpenzim>& shpenzimet) {
    Shpenzim shpenzimiIri;
    
    std::cout << "Shkruaj shumën: ";
    std::cin >> shpenzimiIri.shuma;
    
    std::cout << "Shkruaj kategorinë (Ushqim/Transport/Argëtim): ";
    std::cin >> shpenzimiIri.kategoria;
    
    std::cout << "Shkruaj përshkrimin: ";
    std::cin.ignore();
    std::getline(std::cin, shpenzimiIri.pershkrimi);
    
    shpenzimet.push_back(shpenzimiIri);
    std::cout << "Shpenzimi u shtua me sukses!\n";
}

void shikoShpenzimet(const std::vector<Shpenzim>& shpenzimet) {
    if (shpenzimet.empty()) {
        std::cout << "Nuk ka shpenzime për të shikuar.\n";
        return;
    }
    
    std::cout << "\nLista e Shpenzimeve:\n";
    std::cout << "ID  Shuma  Kategoria  Përshkrimi\n";
    
    for (int i = 0; i < shpenzimet.size(); i++) {
        std::cout << i << "  $"
             << shpenzimet[i].shuma << "  "
             << shpenzimet[i].kategoria << "  "
             << shpenzimet[i].pershkrimi << std::endl;
    }
}

double llogaritTotali(const std::vector<Shpenzim>& shpenzimet) {
    double totali = 0.0;
    for (const auto& shpenzim : shpenzimet) {
        totali += shpenzim.shuma;
    }
    return totali;
}

void llogaritNgaKategoria(const std::vector<Shpenzim>& shpenzimet, const std::string& kategoria) {
    double totaliKategorise = 0.0;
    bool gjetur = false;
    
    for (const auto& shpenzim : shpenzimet) {
        if (shpenzim.kategoria == kategoria) {
            totaliKategorise += shpenzim.shuma;
            gjetur = true;
        }
    }
    
    if (gjetur) {
        std::cout << "Totali i shpenzimeve në kategorinë " << kategoria << ": $" << totaliKategorise << std::endl;
    } else {
        std::cout << "Nuk ka shpenzime në kategorinë " << kategoria << ".\n";
    }
}

void fshiShpenzim(std::vector<Shpenzim>& shpenzimet, int id) {
    if (id < 0 || id >= shpenzimet.size()) {
        std::cout << "ID e pavlefshme. Asnjë shpenzim nuk u fshi.\n";
        return;
    }
    
    shpenzimet.erase(shpenzimet.begin() + id);
    std::cout << "Shpenzimi u fshi me sukses!\n";
}
