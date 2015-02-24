#ifndef _JUEGO
#define _JUEGO

#include "Main.h"
#define COLORDEPTH 32
#define ANCHOPANTALLA 800
#define ALTOPANTALLA 600
#define ALTOVIRTUAL 800
#define ANCHOVIRTUAL 8000
#define PPM 3.125
#define ACEL_GRAVEDAD 600//710
#define VELOCIDAD_Y -140//-140
#define VELOCIDAD_X_NAVE 300
#define MoveSpeed 5
#define TOTAL_ANGULOS 360
#define DIF_ANGULOS 15 
#define MIN_ANGULO 8
#define MAX_ANGULO 7
#define ANGULO_SUP 90
#define ANGULO_INF 270
#define ATAQUE_MAX 6
#define DEFENSA_MAX 5
#define HP_TOTAL 100
#define SALIDA_ARMA1 100
#define SALIDA_ARMA2 300
#define SALIDA_BOSS 5000
#define SALIDA_ITEM 40

enum eTipoDeItem
{
	AumentaAtaque,
	AumentaDefensa,
	AumentaHP,
	Bomba
};

enum eArma
{
	DisparoSimple,
	LanzadorDeGranadas,
	MultiplesDisparos,
	DisparoLargo,
};

enum eDireccionMovimientoVillano 
{
	CaminarDerecha,
	CaminarIzquierda,
	DispararDerecha,
	DispararIzquierda
};


enum eDireccionMovimientoNave
{
	SoloVolar,
	AbrirCompuerta,
	CerrarCompuerta,
	Atacar
};

enum eDireccionMovimientoTanque 
{
	MoverDerecha,
	MoverIzquierda,
	DispararDerechaT,
	DispararIzquierdaT,
	DispararMoviendoseDerecha,
	DispararMoviendoseIzquierda	
};

enum eIdCaracter
{
	Villano,
	VillanoRodante,
	Tanque,
	Nave,
	Jefe,
	Jugador,
	Item,
	Tapa,
	ArmaACoger,
	JefeMano
};

enum eDireccionMovimiento 
{	
	VolarD,
	VolarI,
	SaltarDerecha = 52,
	SaltarIzquierda,
	EnElPisoDerecha,
	EnElPisoIzquierda,
	EnElPisoDispararR,
	EnElPisoDispararL
};

enum eDireccionColision
{
	DesdeArriba,
	DesdeAbajo,
	DesdeDerecha,
	DesdeIzquierda,
	Todos
};

enum eEstadoJuego
{
	EnError,
	EnInicio,
	EnProceso,
	EnPausa,
	EnOpcion,
	Reiniciar,
	Finalizado
};

typedef struct JUEGO
{
	int PosActualBuffer;
	int PosActualBufferFondo;
	int PosActualFondo;
	int EnemigosEliminados;
	int EnemigosEnJuego;
	BITMAP* BufferVirtual;
	BITMAP* BufferPantalla;
	TCARACTER Jugador[2];
	TCARACTER Jefe;
	TCARACTER Manos[2];
	TCARACTER Plataformas[2];
	int CantidadJugadores;
	TLISTA Sprites;
	TLISTA Sonidos;
	TLISTA Enemigos;
	TLISTA Items;
	TLISTA Proyectiles;
	TLISTA Carretera;
	TLISTA Fondo;	
	TLISTA Explosiones;
	TLISTA Tapas;
	TLISTA ArmasACoger;
	FONT* LetraDeJuego;
	float TiempoInicioPartida;
	float TiempoSalidaVillano1;
	float TiempoSalidaVillano2;
	float TiempoSalidaVillano3;
	float TiempoSalidaVillano4;
	float TiempoSalidaItem;
	float TiempoDeExplosionesBoss;
	float TiempoDetenerExplosionesBoss;
	float TeclaPresionada;
	float TiempoEncimaPlataforma;
	float TiempoCaidaManos;
	bool ContraElJefe;
	TCARACTER Fuego;
	eEstadoJuego EstadoJuego;
	bool GameOver;
	bool MostrarInicio;
	bool ShowStats;
	bool CrearExplosionesBoss;
	float TiempoPerdioVida;
	bool PerdioVida;
	bool Apocalipse;
	bool ManosBoss;
	bool TiempoMano;
	bool Golpeado;
	bool Win;
	MIDI* BackGround;
}TJUEGO;

int ReinicializarJuego(TJUEGO*, eEstadoJuego);

int InicializarJuego(TJUEGO*);

int FinalizarJuego(TJUEGO*);

int ActualizarJuego(TJUEGO*);

int RenderizarJuego(TJUEGO*);

int ActualizarJugador(TJUEGO*);

void Villanos(TJUEGO*);

void CrearVillano(TJUEGO*, eIdCaracter);

bool ExisteColision(TJUEGO*, TCARACTER*, TCARACTER*, eDireccionColision, float, int);

void ActualizarFondo(TJUEGO*);

void ActualizarCarretera(TJUEGO* Juego);

void RenderizarBlitTransparente(BITMAP *, BITMAP *, int, int, int, int, int, int);

void RenderizarSpriteInvertido(TJUEGO*, BITMAP*, int, int);

void RestarHP(TJUEGO*, TCARACTER*, TCARACTER*, int);

void ActualizarItems(TJUEGO*);

void RenderizarSpriteInvertido(TJUEGO*, BITMAP* , int , int);

void CaidaConGravedad(TJUEGO*, TCARACTER*, float, int);

void AnguloDeDisparo(TJUEGO*, int);

void PantallaInicio(TJUEGO*);

void ActualizarNave(TJUEGO*, TCARACTER*, float);

void CrearExplosion(TJUEGO*, TCARACTER*, TCARACTER*);

void ActualizarArmas(TJUEGO*);

void CrearTapas(TJUEGO*);

void RenderizarGameOver(TJUEGO*);

void PausarJuego(TJUEGO*);

void AsignarArma(TJUEGO*, TCARACTER*,  int, int*);

void CrearJugadores(TJUEGO *);

void InicializarJugadores(TJUEGO*);

void ActualizarJefe(TJUEGO*);

void CrearExplosionBoss(TJUEGO*);

void DejarCaerMano(TJUEGO*);

void RenderizarWin(TJUEGO*);

#endif