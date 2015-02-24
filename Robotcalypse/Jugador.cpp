#ifndef _JUGADOR // Estas instrucciones son para agrupar (estilo namespace).
#define _JUGADOR

#include "Main.h"

enum eArma
{
	Pistola,
	Metralleta,,
	NubeNormal,
	NubePlus,
	NubeDesvanece
};

typedef struct JUGADOR
{
	int Vida;
	int FactorAtaque;
	int FactorDefensa;
	int PosX;
	int PosY;
	int PosYSalto;
	float VelocidadX;
	float VelocidadY;
	float VelocidadYSalto;
	float DuracionDeSalto;
	float TimepoUltimoCalculadoPosX;
	float TimepoUltimoCalculadoPosY;
	float TiempoCalculadoVelocidadX;
	float TiempoCalculadoVelocidadY;
	int IdSprite;
	int eArma;

}TJUGADOR;