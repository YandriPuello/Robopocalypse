#ifndef _JUGADOR // Estas instrucciones son para agrupar (estilo namespace).
#define _JUGADOR

#include "Main.h"


typedef struct Arma
{
	int Id;
	int RangoAtaque;
	int FactorAtaque;
	int VelocidadAtaqueEscalar;
	float TiempoDisparar;
	BITMAP* BalaSprite;
	int AnchoDividido;
	int AltoDividido; 
	SAMPLE* EfectoSonido;
	float AceleracionBalaY;
	float AceleracionBalaX;
}TARMA;

typedef struct Caracter
{
	int Id;
	int HP;
	int Vidas;
	int FactorAtaque;
	int FactorDefensa;
	int PosXInicial;
	int PosYInicial;
	int PosX;
	int PosY;
	int PosYReal;
	int PosYSalto;
	int Alto;
	int Ancho;
	float VelocidadXInicial;
	float VelocidadYInicial;
	float VelocidadX;
	float VelocidadY;
	float VelocidadYSalto;
	float DuracionDeSalto;
	float AcelaracionY;
	float AcelaracionX;
	float TimepoUltimoCalculadoPosX;
	float TimepoUltimoCalculadoPosY;
	float TiempoCalculadoVelocidadX;
	float TiempoCalculadoVelocidadY;
	float TiempoDisparo;
	int AnguloDisparo;
	int IdSprite;
	int IdJugador;
	int FrameX;
	int FrameY;
	int AnchoDividido;
	int AltoDividido; 
	int CurrentFrame[2];
	int FrameCounter;
	int SwitchFrame;
	int BombasLanzadas;
	int ScoreJugador;
	int ScoreCaracter;
	bool Moviendose;
	bool Disparando;
	bool DisparandoMoviendose;
	bool isActive;
	bool Saltando;
	bool EnElPiso;
	bool Exploto;
	bool CambioArma;
	BITMAP* SpriteCaracter;
	BITMAP* Avatar;
	TLISTA Armas;
	TARMA Arma;
	SAMPLE * Sonido1;

	float TiempoActualDisparo;

}TCARACTER;

#endif