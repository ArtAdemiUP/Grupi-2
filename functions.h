
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include "expense.h"

void shtoShpenzim(std::vector<Shpenzim>& shpenzimet);
void shikoShpenzimet(const std::vector<Shpenzim>& shpenzimet);
double llogaritTotali(const std::vector<Shpenzim>& shpenzimet);
void llogaritNgaKategoria(const std::vector<Shpenzim>& shpenzimet, const std::string& kategoria);
void fshiShpenzim(std::vector<Shpenzim>& shpenzimet, int id);

#endif 