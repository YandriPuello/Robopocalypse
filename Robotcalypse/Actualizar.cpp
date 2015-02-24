#include "main.h"
void CrearTapas(TJUEGO * Juego)
{

	
	TCARACTER* NuevaTapa = new TCARACTER(); 
	NuevaTapa->Id = Tapa;	
	NuevaTapa->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 29))->data;
	NuevaTapa->FactorAtaque = 0;
	NuevaTapa->Ancho = NuevaTapa->SpriteCaracter->w;
	NuevaTapa->Alto = NuevaTapa->SpriteCaracter->h;
	NuevaTapa->PosX = Juego->PosActualBuffer + SCREEN_W;
	NuevaTapa->PosY = 660- NuevaTapa->SpriteCaracter->w/2 ;
	NuevaTapa->PosYSalto = NuevaTapa->PosY;
	NuevaTapa->VelocidadX = NuevaTapa->VelocidadY = 0;
	//NuevoEnemigo->IdSprite = 1;
	NuevaTapa->TimepoUltimoCalculadoPosY = 0;
	NuevaTapa->CurrentFrame[0] = 0;
	NuevaTapa->CurrentFrame[1] = 0;
	NuevaTapa->TiempoCalculadoVelocidadY=0;
	NuevaTapa->FrameX = 4;
	NuevaTapa->FrameY = 1;
	NuevaTapa->AnchoDividido = NuevaTapa->SpriteCaracter->w/NuevaTapa->FrameX;
	NuevaTapa->AltoDividido = NuevaTapa->SpriteCaracter->h/NuevaTapa->FrameY;
	NuevaTapa->FrameCounter = 0;
	NuevaTapa->SwitchFrame = 2;
	NuevaTapa->TimepoUltimoCalculadoPosY = 0;
	NuevaTapa->Exploto=false;
	CrearNodo(&Juego->Tapas, NuevaTapa, true);

	
	Juego->Fuego.SpriteCaracter=(BITMAP*)BuscarNodoIndice(&Juego->Sprites,31)->data;


	Juego->Fuego.PosX = Juego->PosActualBuffer + SCREEN_W;
	Juego->Fuego.PosY = 660- NuevaTapa->SpriteCaracter->w/2 ;
	Juego->Fuego.FactorAtaque = 2;
	Juego->Fuego.Ancho = Juego->Fuego.SpriteCaracter->w-20;
	Juego->Fuego.Alto = Juego->Fuego.SpriteCaracter->h-20;
	Juego->Fuego.CurrentFrame[0] = 0;
	Juego->Fuego.CurrentFrame[1] = 0;
	Juego->Fuego.Exploto=false;
	Juego->Fuego.FrameX = 16;
	Juego->Fuego.FrameY = 1;
	Juego->Fuego.AnchoDividido = Juego->Fuego.SpriteCaracter->w/Juego->Fuego.FrameX;
	Juego->Fuego.AltoDividido =Juego->Fuego.SpriteCaracter->h/Juego->Fuego.FrameY;
	Juego->Fuego.FrameCounter = 0;
	Juego->Fuego.SwitchFrame = 6;



}


void CrearJugadores(TJUEGO * Juego)
{
}