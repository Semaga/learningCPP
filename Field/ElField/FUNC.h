#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include "CHR_PRP.h"
#include "SUB_PRP.h"

void VectorToZero(std::vector <std::vector <double> >&v);

void WriteVectorToFile(std::vector <std::vector <double> > &v, std::vector <CHR_PRP> &Charge, SUB_PRP &Substrate);

void ReadInputFile(const std::string &InputeFile, SUB_PRP &Substrate, int &NumberOfParticle);

std::vector <std::string> split(std::string & s, char delimeter = ' ');

#endif