#ifndef _Utilidades
#define _Utilidades

#include "Main.h"

string IntToStr(int n)
{
	stringstream resultado;
	resultado << n;
	return resultado.str();
}

string FloatToStr(int n)
{
	stringstream resultado;
	resultado << n;
	return resultado.str();
}

#endif