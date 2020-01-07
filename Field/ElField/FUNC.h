#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <vector>
#include "CHR_PRP.h"
#include "SUB_PRP.h"

template <typename T>
void WriteVectorToFile(std::vector <std::vector <T> > &v, 
	std::vector <CHR_PRP> &Charge, SUB_PRP &Substrate);
#endif