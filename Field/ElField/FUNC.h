#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <vector>
#include <fstream>

#include "CHR_PRP.h"
#include "SUB_PRP.h"

void VectorToZero(std::vector <std::vector <double> >&v);

void WriteVectorToFile(std::vector <std::vector <double> > &v, std::vector <CHR_PRP> &Charge, SUB_PRP &Substrate);


// template <typename T>
// void WriteVectorToFile(std::vector <std::vector <T> > &v, std::vector <CHR_PRP> &Charge, SUB_PRP &Substrate);

#endif