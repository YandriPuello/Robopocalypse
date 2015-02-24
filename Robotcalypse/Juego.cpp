#include "Main.h"

int InicializarJuego(TJUEGO* Juego)
{
	srand(time(NULL));
	allegro_init();
	install_keyboard();
	install_mouse();
	install_joystick(JOY_TYPE_AUTODETECT);
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, "A");

	set_color_depth(COLORDEPTH);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, ANCHOPANTALLA, ALTOPANTALLA, 0, 0);
	set_window_title("Juego");

	//Inicializando el buffer virtual(grande);
	Juego->BufferVirtual = create_bitmap(ANCHOVIRTUAL, ALTOVIRTUAL);
	clear_to_color(Juego->BufferVirtual, makecol(193, 40, 45));

	//Inicializando el buffer de la pantalla(pequeño);
	Juego->BufferPantalla = create_bitmap(ANCHOPANTALLA, ALTOPANTALLA);
	clear_to_color(Juego->BufferPantalla, makecol(0, 0, 0));

	//Cargando los Sprites.
	InicializarLista(&(Juego->Sprites));
	CrearNodo(&(Juego->Sprites), load_png("Target.png", NULL), true);//0
	CrearNodo(&(Juego->Sprites), load_png("Calle2.png", NULL), true);//2
	//Creo una variable para obtener la paleta de colores, del fondo
	PALETTE palette;
	CrearNodo(&(Juego->Sprites), load_png("CityBackground.png", palette), true);//1
	//seteo la paleta de colores obtenida
	set_palette(palette);
	//seteo la transparencia de los png
	set_alpha_blender();
	CrearNodo(&(Juego->Sprites), load_png("Calle2.png", NULL), true);//3
	CrearNodo(&(Juego->Sprites), load_png("BarraDeVidaVacia.png", NULL), true);//4
	CrearNodo(&(Juego->Sprites), load_png("BarraDeVidaAzul.png", NULL), true);//5
	CrearNodo(&(Juego->Sprites), load_png("BarraComun.png", NULL), true);//6
	CrearNodo(&(Juego->Sprites), load_png("Robopocalypse.png", NULL), true);//7

	CrearNodo(&(Juego->Sprites), load_png("Bala1.png", NULL), true);//8
	CrearNodo(&(Juego->Sprites), load_png("Bala2.png", NULL), true);//9
	CrearNodo(&(Juego->Sprites), load_png("BalaVillano1.png", NULL), true);//10
	CrearNodo(&(Juego->Sprites), load_png("BalaVillano2.png", NULL), true);//11
	CrearNodo(&(Juego->Sprites), load_png("BalaVillano3.png", NULL), true);//12
	CrearNodo(&(Juego->Sprites), load_png("BalaVillano4.png", NULL), true);//13

	CrearNodo(&(Juego->Sprites), load_png("ExplosionSheetV1.png", NULL), true);//14
	CrearNodo(&(Juego->Sprites), load_png("ExplosionSheetV2.png", NULL), true);//15
	CrearNodo(&(Juego->Sprites), load_png("ExplosionSheetV3.png", NULL), true);//16
	CrearNodo(&(Juego->Sprites), load_png("ExplosionSheetV4.png", NULL), true);//17
	CrearNodo(&(Juego->Sprites), load_png("ExplosionSheetCaracter.png", NULL), true);//18

	CrearNodo(&(Juego->Sprites), load_png("NaveFullSheet.png", NULL), true);//19
	CrearNodo(&(Juego->Sprites), load_png("PlayerSheetFull.png", NULL), true);//20
	CrearNodo(&(Juego->Sprites), load_png("PlayerSheetFull2.png", NULL), true);//21
	CrearNodo(&(Juego->Sprites), load_png("TanqueFullSheet.png", NULL), true);//22
	CrearNodo(&(Juego->Sprites), load_png("Villano1Sheet.png", NULL), true);//23
	CrearNodo(&(Juego->Sprites), load_png("Villano2FullSheet.png", NULL), true);//24

	CrearNodo(&(Juego->Sprites), load_png("head1.png", NULL), true);//25
	CrearNodo(&(Juego->Sprites), load_png("head2.png", NULL), true);//26
	CrearNodo(&(Juego->Sprites), load_png("ItemsFull.png", NULL), true);//27
	CrearNodo(&(Juego->Sprites), load_png("ItemsInfo.png", NULL), true);//28

	CrearNodo(&(Juego->Sprites), load_png("Sprites/mundo1/tapa_sheet.png", NULL), true);//29
	CrearNodo(&(Juego->Sprites), load_png("Sprites/mundo1/hoyo.png", NULL), true);//30
	CrearNodo(&(Juego->Sprites), load_png("Sprites/mundo1/candela.png", NULL), true);//31

	CrearNodo(&(Juego->Sprites), load_png("Sprites/fondo_game_over.png", NULL), true);//32
	CrearNodo(&(Juego->Sprites), load_png("Sprites/fondo_vida.png", NULL), true);//33
	CrearNodo(&(Juego->Sprites), load_png("Sprites/game_over.png", NULL), true);//34

	CrearNodo(&(Juego->Sprites), load_png("Bala1.png", NULL), true);//35
	CrearNodo(&(Juego->Sprites), load_png("Bala2.png", NULL), true);//36
	CrearNodo(&(Juego->Sprites), load_png("Bala3.png", NULL), true);//37
	CrearNodo(&(Juego->Sprites), load_png("Bala4.png", NULL), true);//38
	CrearNodo(&(Juego->Sprites), load_png("Bala1 (2).png", NULL), true);//39
	CrearNodo(&(Juego->Sprites), load_png("Bala2 (2).png", NULL), true);//40
	CrearNodo(&(Juego->Sprites), load_png("Bala3 (2).png", NULL), true);//41
	CrearNodo(&(Juego->Sprites), load_png("Bala4 (2).png", NULL), true);//42

	CrearNodo(&(Juego->Sprites), load_png("Arma2.png", NULL), true);//43
	CrearNodo(&(Juego->Sprites), load_png("Arma3.png", NULL), true);//44
	CrearNodo(&(Juego->Sprites), load_png("Arma3.png", NULL), true);//45

	CrearNodo(&(Juego->Sprites), load_png("Boss1FullSheet.png", NULL), true);//46
	CrearNodo(&(Juego->Sprites), load_png("Boss1Mano.png", NULL), true);//47

	CrearNodo(&(Juego->Sprites), load_png("Plataforma.png", NULL), true);//48
	CrearNodo(&(Juego->Sprites), load_png("BossBalaSola.png", NULL), true);//49
	CrearNodo(&(Juego->Sprites), load_png("Sprites/you_win.png", NULL), true);//50

	//Inicializar la lista de los sonidos:
	InicializarLista(&(Juego->Sonidos));
	CrearNodo(&(Juego->Sonidos), load_sample("Item.wav"), true);//0
	CrearNodo(&(Juego->Sonidos), load_sample("ItemBomb.wav"), true);//1
	CrearNodo(&(Juego->Sonidos), load_sample("Ready.wav"), true);//2
	CrearNodo(&(Juego->Sonidos), load_sample("SonidoJugadorBala1.wav"), true);//3
	CrearNodo(&(Juego->Sonidos), load_sample("SonidoJugadorBala2.wav"), true);//4
	CrearNodo(&(Juego->Sonidos), load_sample("SonidoJugadorBala3.wav"), true);//5
	CrearNodo(&(Juego->Sonidos), load_sample("SonidoJugadorBala4.wav"), true);//6
	CrearNodo(&(Juego->Sonidos), load_sample("SonidoBalaVillano1.wav"), true);//7
	CrearNodo(&(Juego->Sonidos), load_sample("SonidoBalaVillano2.wav"), true);//8
	CrearNodo(&(Juego->Sonidos), load_sample("SonidoBalaVillano3.wav"), true);//9
	CrearNodo(&(Juego->Sonidos), load_sample("SonidoBalaVillano4.wav"), true);//10
	CrearNodo(&(Juego->Sonidos), load_sample("SonidoBombaVillano4.wav"), true);//11
	CrearNodo(&(Juego->Sonidos), load_sample("Sonidos/gameover.wav"), true);//12
	CrearNodo(&(Juego->Sonidos), load_sample("Sonidos/win.wav"), true);//13

	InicializarLista(&(Juego->Tapas));
	CrearTapas(Juego);
	
	Juego->LetraDeJuego = load_font("PerfectDark12.pcx", NULL, NULL);

	//set_mouse_sprite((BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 0)->data));
	//Juego->CantidadJugadores=2;
	Juego->ContraElJefe = false;
	Juego->GameOver=false;
	Juego->Win=false;
	Juego->ShowStats=true;
	Juego->EstadoJuego = EnInicio;
	Juego->CrearExplosionesBoss = false;
	Juego->TiempoEncimaPlataforma = 0;
	
	//Iniciando las listas:
	InicializarLista(&Juego->Enemigos);
	InicializarLista(&Juego->Proyectiles);
	InicializarLista(&Juego->Carretera);
	InicializarLista(&Juego->Explosiones);
	InicializarLista(&Juego->ArmasACoger);
	InicializarLista(&Juego->Items);
	InicializarLista(&Juego->Fondo);

	return 0;
}

int ReinicializarJuego(TJUEGO* Juego, eEstadoJuego Estado)
{
	//Cargando los Sprites.
	InicializarLista(&(Juego->Tapas));
	CrearTapas(Juego);
	
	Juego->LetraDeJuego = load_font("PerfectDark12.pcx", NULL, NULL);

	//set_mouse_sprite((BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 0)->data));
	//Juego->CantidadJugadores=2;
	Juego->ContraElJefe = false;
	Juego->GameOver=false;
	Juego->Win=false;
	Juego->ShowStats=true;
	Juego->EstadoJuego = Estado;
	Juego->CrearExplosionesBoss = false;
	Juego->TiempoEncimaPlataforma = 0;
	
	//Iniciando las listas:
	InicializarLista(&Juego->Enemigos);
	InicializarLista(&Juego->Proyectiles);
	InicializarLista(&Juego->Carretera);
	InicializarLista(&Juego->Explosiones);
	InicializarLista(&Juego->ArmasACoger);
	InicializarLista(&Juego->Items);
	InicializarLista(&Juego->Fondo);

	return 0;
}

void Disparar( TJUEGO *Juego, TCARACTER* Caracter)	
{
	// Disparar significa inicializar un proyectil.
	//Esta función
	Caracter->TiempoDisparo = clock();
	play_sample(Caracter->Arma.EfectoSonido, 250, 128, 1000, false); 	
	TCARACTER *NuevoProyectil = new TCARACTER();
	NuevoProyectil->AnguloDisparo = Caracter->AnguloDisparo;

	float Seno = fixtof(fixsin(itofix(NuevoProyectil->AnguloDisparo*256/360)));
	float Coseno = fixtof(fixcos(itofix(NuevoProyectil->AnguloDisparo*256/360)));
	int DiferenciaPosPistola = 5;
	int AnguloProyectilX = Caracter->AnchoDividido/2 * Coseno - DiferenciaPosPistola;

	int AltoActual = Caracter->AltoDividido;//Esto es para cuando el jugador está en el piso.
	int PosYActual = Caracter->PosY;//Se debe corregir el alto del sprite y la posición en Y.
	int AltoDividioEnPiso = 42;
	int DiferenciaPosYEnPiso = 60;

	if(Caracter->EnElPiso == true)
		if(Caracter->IdSprite == Jugador)
		{
			AltoActual = AltoDividioEnPiso;
			PosYActual += DiferenciaPosYEnPiso;
		}
		int AnguloProyectilY = AltoActual/2 * Seno;

		//Para ajustar que la bala salga exactamente desde el final de la pistola:
		if(NuevoProyectil->AnguloDisparo >= 90 && NuevoProyectil->AnguloDisparo <= 210)
			AnguloProyectilX -= (DiferenciaPosPistola*2);
		else if(NuevoProyectil->AnguloDisparo >= 240 && NuevoProyectil->AnguloDisparo < 255)
			AnguloProyectilX += (DiferenciaPosPistola);
		else if(NuevoProyectil->AnguloDisparo == 255)
			AnguloProyectilX += (DiferenciaPosPistola*2);
		else if(NuevoProyectil->AnguloDisparo == 270)
			AnguloProyectilX -= (DiferenciaPosPistola*6);
		else if(NuevoProyectil->AnguloDisparo > 270 && NuevoProyectil->AnguloDisparo <= 300)
			AnguloProyectilX -= (DiferenciaPosPistola*4);
		else if(NuevoProyectil->AnguloDisparo >= 315 && NuevoProyectil->AnguloDisparo <= 330)
			AnguloProyectilX -= (DiferenciaPosPistola*2);

		NuevoProyectil->FactorAtaque = Caracter->FactorAtaque + Caracter->Arma.FactorAtaque;
		NuevoProyectil->PosXInicial = Caracter->PosX + Caracter->AnchoDividido/2 + AnguloProyectilX;
		NuevoProyectil->PosYInicial = PosYActual + Caracter->AltoDividido/2-26 - AnguloProyectilY;
		if(Caracter->IdSprite == Tanque)
			NuevoProyectil->PosYInicial = Caracter->PosY + Caracter->AltoDividido/2-26 - AnguloProyectilY -18;
		else if(Caracter->IdSprite == Jefe)
			NuevoProyectil->PosYInicial = Caracter->PosY + Caracter->AltoDividido/2-26 - AnguloProyectilY -80;
		NuevoProyectil->PosX = NuevoProyectil->PosXInicial;
		NuevoProyectil->PosY = NuevoProyectil->PosYInicial;
		NuevoProyectil->Arma.BalaSprite = Caracter->Arma.BalaSprite;
		NuevoProyectil->Arma.AnchoDividido = Caracter->Arma.BalaSprite->w;
		NuevoProyectil->Arma.AltoDividido = Caracter->Arma.BalaSprite->h;

		NuevoProyectil->VelocidadXInicial = Caracter->Arma.VelocidadAtaqueEscalar * PPM * Coseno;
		NuevoProyectil->VelocidadYInicial = Caracter->Arma.VelocidadAtaqueEscalar * PPM * Seno;
		NuevoProyectil->VelocidadX = NuevoProyectil->VelocidadXInicial;
		NuevoProyectil->VelocidadY = NuevoProyectil->VelocidadYInicial;
		NuevoProyectil->AcelaracionY = Caracter->Arma.AceleracionBalaY;
		NuevoProyectil->TiempoDisparo = clock();

		if(Caracter->Id == Jugador)
		{
			NuevoProyectil->IdSprite = Jugador;
			NuevoProyectil->IdJugador = Caracter->IdJugador;
		}
		else if(Caracter->Id == Villano)
			NuevoProyectil->IdSprite = Villano;
		NuevoProyectil->Id = Caracter->IdSprite;
		NuevoProyectil->FactorDefensa = 0;

		CrearNodo(&(Juego->Proyectiles), NuevoProyectil, true);
}

void InicializarJugadores(TJUEGO * Juego)
{
	for(int i=0; i < Juego->CantidadJugadores; i++)
	{
		Juego->Jugador[i].Saltando = true;
		Juego->Jugador[i].EnElPiso = false;
		Juego->Jugador[i].Id = Jugador;
		Juego->Jugador[i].IdJugador= i;
		Juego->Jugador[i].Vidas = 8;
		Juego->Jugador[i].HP = 100;
		Juego->Jugador[i].SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites),20+i))->data;
		Juego->Jugador[i].IdSprite = Jugador;
		Juego->Jugador[i].FactorAtaque = 5;
		Juego->Jugador[i].FactorDefensa = 0;
		Juego->Jugador[i].Ancho = Juego->Jugador[i].SpriteCaracter->w;
		Juego->Jugador[i].Alto = Juego->Jugador[i].SpriteCaracter->h;
		Juego->Jugador[i].PosX = 12+(80*i);
		Juego->Jugador[i].PosY = 0; //CarreteraActual->PosY + CarreteraActual->SpriteCaracter->h/2 + (CarreteraActual->SpriteCaracter->h/2)/2 - Juego->Jugador[i].AltoDividido;
		Juego->Jugador[i].PosYSalto = Juego->Jugador[i].PosY;
		Juego->Jugador[i].VelocidadX = Juego->Jugador[i].VelocidadY = 0;
		Juego->Jugador[i].VelocidadYSalto = 0	;
		//Juego->Jugador[i].Tipo = Jugador;
		Juego->Jugador[i].IdSprite = Jugador;
		Juego->Jugador[i].TimepoUltimoCalculadoPosY = 0;
		Juego->Jugador[i].CurrentFrame[0] = 0;
		Juego->Jugador[i].CurrentFrame[1] = 0;
		Juego->Jugador[i].FrameX = 6;
		Juego->Jugador[i].FrameY = 116;
		Juego->Jugador[i].AnchoDividido = Juego->Jugador[i].SpriteCaracter->w/Juego->Jugador[i].FrameX;
		Juego->Jugador[i].AltoDividido = Juego->Jugador[i].SpriteCaracter->h/Juego->Jugador[i].FrameY;
		Juego->Jugador[i].FrameCounter = 0;
		Juego->Jugador[i].SwitchFrame = 6;
		Juego->Jugador[i].TiempoDisparo = 0;
		Juego->Jugador[i].TimepoUltimoCalculadoPosY = clock();
		Juego->Jugador[i].AcelaracionY = 0;
		Juego->Jugador[i].ScoreJugador = 0;

		InicializarLista(&Juego->Jugador[i].Armas);

		TARMA* NuevaArma = new TARMA(); 
		//Juego->Jugador[i].Armas
		if(i==0)
		{
			NuevaArma->BalaSprite = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 35))->data;
			Juego->Jugador[i].Avatar = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites),25))->data;
		}
		else
		{
			NuevaArma->BalaSprite =  (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 39))->data;
			Juego->Jugador[i].Avatar = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 26))->data;
		}

		NuevaArma->Id = DisparoSimple;
		NuevaArma->EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 3))->data;
		NuevaArma->FactorAtaque = 1;
		NuevaArma->Id = 0;
		NuevaArma->VelocidadAtaqueEscalar = 700;
		NuevaArma->RangoAtaque = SCREEN_W/2;
		NuevaArma->TiempoDisparar = 0.21;
		CrearNodo(&Juego->Jugador[i].Armas, NuevaArma, true);

		Juego->Jugador[i].Arma = *(TARMA*)BuscarNodoIndice(&Juego->Jugador[i].Armas, 0)->data;
	}

	TCARACTER* NuevoEnemigo = new TCARACTER(); 
	NuevoEnemigo->Id = Villano;
	NuevoEnemigo->IdSprite = Villano;
	NuevoEnemigo->Vidas = 1;
	NuevoEnemigo->HP = 5;
	NuevoEnemigo->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 23))->data;
	NuevoEnemigo->FactorAtaque = 2;
	NuevoEnemigo->FactorDefensa = 5;
	NuevoEnemigo->ScoreCaracter = 5;
	NuevoEnemigo->Ancho = NuevoEnemigo->SpriteCaracter->w;
	NuevoEnemigo->Alto = NuevoEnemigo->SpriteCaracter->h;
	NuevoEnemigo->PosX = SCREEN_W + SCREEN_W/2;
	NuevoEnemigo->PosY = 453;
	NuevoEnemigo->PosYSalto = NuevoEnemigo->PosY;
	NuevoEnemigo->VelocidadX = NuevoEnemigo->VelocidadY = 0;
	NuevoEnemigo->TimepoUltimoCalculadoPosY = 0;
	NuevoEnemigo->CurrentFrame[0] = 0;
	NuevoEnemigo->CurrentFrame[1] = 0;
	NuevoEnemigo->FrameX = 4;
	NuevoEnemigo->FrameY = 8;
	NuevoEnemigo->AnchoDividido = NuevoEnemigo->SpriteCaracter->w/NuevoEnemigo->FrameX;
	NuevoEnemigo->AltoDividido = NuevoEnemigo->SpriteCaracter->h/NuevoEnemigo->FrameY;
	NuevoEnemigo->FrameCounter = 0;
	NuevoEnemigo->SwitchFrame = 6;
	NuevoEnemigo->TiempoDisparo = 0;
	NuevoEnemigo->Arma.BalaSprite = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 10))->data;
	NuevoEnemigo->Arma.EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 3))->data;
	NuevoEnemigo->Arma.FactorAtaque = 1;
	NuevoEnemigo->Arma.Id = 0;
	NuevoEnemigo->Arma.VelocidadAtaqueEscalar = 100;
	NuevoEnemigo->Arma.RangoAtaque = SCREEN_W/2;
	NuevoEnemigo->Moviendose = true;
	NuevoEnemigo->DisparandoMoviendose = false;
	NuevoEnemigo->Disparando = false;
	NuevoEnemigo->Arma.TiempoDisparar = 0.7;
	NuevoEnemigo->TimepoUltimoCalculadoPosY = clock();
	NuevoEnemigo->Arma.AceleracionBalaY = ACEL_GRAVEDAD*-1;

	CrearNodo(&Juego->Enemigos, NuevoEnemigo, true);
	
	TCARACTER* Fondo = new TCARACTER();
	Fondo->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 2))->data;
	Fondo->Ancho = Fondo->SpriteCaracter->w;
	Fondo->Alto = Fondo->SpriteCaracter->h;
	Fondo->PosX = 0;
	Fondo->PosY = 0 ;

	CrearNodo(&Juego->Fondo, Fondo, true);

	
	for(int i=0; i<=37600; i += 376)
	{
		TCARACTER* Carretera = new TCARACTER();
		Carretera->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 3))->data;
		Carretera->Ancho = Carretera->SpriteCaracter->w;
		Carretera->Alto = (Carretera->SpriteCaracter->h-1/2)/2;
		Carretera->PosX = i;
		Carretera->FrameX = 1;
		Carretera->FrameY = 1;
		Carretera->AnchoDividido = Carretera->SpriteCaracter->w/Carretera->FrameX;
		Carretera->AltoDividido = Carretera->SpriteCaracter->h/Carretera->FrameY;
		Carretera->PosY = SCREEN_H - Carretera->Alto;
		Carretera->PosYReal = SCREEN_H - Carretera->SpriteCaracter->h -1;
		Carretera->AltoDividido = 1;

		CrearNodo(&Juego->Carretera, Carretera, true);
	}

	Juego->EnemigosEnJuego = 1;

	
	TCARACTER* ItemInfo = new TCARACTER();

	//Inializar la iformación de los items:
	ItemInfo->Id = Item;
	ItemInfo->IdSprite = Item;
	ItemInfo->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 28))->data;
	ItemInfo->Ancho = ItemInfo->SpriteCaracter->w;
	ItemInfo->Alto = ItemInfo->SpriteCaracter->h;
	ItemInfo->FrameX = 5;
	ItemInfo->FrameY = 4;
	ItemInfo->AnchoDividido = ItemInfo->SpriteCaracter->w/ItemInfo->FrameX;
	ItemInfo->AltoDividido = ItemInfo->SpriteCaracter->h/ItemInfo->FrameY;
	ItemInfo->PosX = SCREEN_W/2 - ItemInfo->AnchoDividido/2 + Juego->PosActualBuffer;
	ItemInfo->PosY = SCREEN_H/4;
	ItemInfo->CurrentFrame[0] = 0;
	ItemInfo->CurrentFrame[1] = -1;
	ItemInfo->FrameCounter = 0;
	ItemInfo->SwitchFrame = 6;
	ItemInfo->TiempoDisparo = 0;
	ItemInfo->Arma.EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 0))->data;
	CrearNodo(&Juego->Items, ItemInfo, true);

	
	//Inicializar la música de fondo:
	Juego->BackGround = load_midi("stage_1.mid");
	//	play_midi(Juego->BackGround, true);
	for(int ju=0; ju < Juego->CantidadJugadores; ju++)
	{
		if(Juego->Jugador[ju].Vidas <=0)
			continue;
		Juego->Jugador[ju].Sonido1 = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 2))->data;
		play_sample(Juego->Jugador[ju].Sonido1, 2000, 128, 1000, false);
	}

}

int FinalizarJuego(TJUEGO* Juego)
{
	remove_mouse();
	remove_keyboard();
	remove_sound();
	for(int i=0; i<Juego->Sprites.cantidad; i++)
		destroy_bitmap((BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), i)->data));
	for(int i=0; i<Juego->Sonidos.cantidad; i++)
		destroy_sample((SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), i)->data));
	destroy_bitmap(Juego->BufferPantalla);
	destroy_font(Juego->LetraDeJuego);
	allegro_exit();
	return 0;
}

int ActualizarJuego(TJUEGO* Juego)
{
	if(Juego->EstadoJuego == EnInicio)
		PantallaInicio(Juego);
	if(Juego->EstadoJuego == Reiniciar)
	{
		for(int i=0; i<Juego->Enemigos.cantidad;)
			EliminarNodo(&Juego->Enemigos, (TCARACTER*)BuscarNodoIndice(&Juego->Enemigos, i)->data);
		for(int i=0; i<Juego->Carretera.cantidad;)
			EliminarNodo(&Juego->Carretera, (TCARACTER*)BuscarNodoIndice(&Juego->Carretera, i)->data);	
		CrearTapas(Juego);
		Juego->TiempoInicioPartida = clock();
		Juego->TiempoSalidaItem = clock();
		Juego->TiempoSalidaVillano1 = clock();
		Juego->TiempoSalidaVillano2 = clock();
		Juego->TiempoSalidaVillano3 = clock();
		Juego->TiempoSalidaVillano4 = clock();
		Juego->TiempoInicioPartida = clock();

		Juego->EnemigosEliminados = 0;
		Juego->TeclaPresionada=0;
		Juego->PosActualBuffer = 0;
		Juego->PosActualBufferFondo = -1;//Para que se imprima el segundo sprite del fondo.
		Juego->PosActualFondo = 0;

		InicializarJugadores(Juego);
		Juego->EstadoJuego = EnProceso;
	}

	ActualizarJugador(Juego);

	ActualizarJefe(Juego);

	Villanos(Juego);

	ActualizarFondo(Juego);

	ActualizarCarretera(Juego);

	ActualizarItems(Juego);

	ActualizarArmas(Juego);
	
	if(Juego->PerdioVida && clock() - Juego->TiempoPerdioVida > 300)
		Juego->PerdioVida=false;

	if(Juego->PosActualBuffer%(SCREEN_W*2) == 0 && Juego->PosActualBuffer>0)
	CrearTapas(Juego), Juego->PosActualBuffer+=5 ;

	//pausa
	poll_joystick();
	if((key[KEY_P] || joy[0].button[11].b || joy[1].button[11].b) && clock() - Juego->TeclaPresionada > 500)
		Juego->EstadoJuego=EnPausa, Juego->TeclaPresionada=clock();
	else if((key[KEY_E] || joy[0].button[8].b || joy[1].button[8].b) && clock() - Juego->TeclaPresionada > 500)
	{
		if(Juego->ShowStats)
			Juego->ShowStats=false;
		else
			Juego->ShowStats=true;

		Juego->TeclaPresionada=clock();
	}

	for(int i=0; i < Juego->Tapas.cantidad; i++)
	{
		//TCARACTER* Tapa= (TCARACTER*)(BuscarNodoIndice(&(Juego->Tapas),i))->data;
		TCARACTER* TapaAlcantarilla = (TCARACTER*)BuscarNodoIndice(&Juego->Tapas, i)->data;
		float TiempoSalto;
		if(TapaAlcantarilla->TiempoCalculadoVelocidadY == 0)
			TiempoSalto = 0;
		else 
			TiempoSalto = (clock() - TapaAlcantarilla->TiempoCalculadoVelocidadY)/CLOCKS_PER_SEC;
		for(int ju=0; ju < Juego->CantidadJugadores ; ju ++)
		{

			if(Juego->Jugador[ju].Vidas <=0)
				continue;

			if(ExisteColision(Juego, TapaAlcantarilla, &Juego->Jugador[ju], Todos, 0, 0) && !TapaAlcantarilla->Exploto)
			{
				TapaAlcantarilla->VelocidadYSalto -= 100;
				TapaAlcantarilla->AcelaracionY = -950;
				TapaAlcantarilla->TiempoCalculadoVelocidadY = clock();
				TapaAlcantarilla->Exploto = true;
				RestarHP(Juego, &Juego->Jugador[ju], TapaAlcantarilla, ju);
				Juego->Jugador[ju].CurrentFrame[1] += Juego->Jugador[ju].FrameY/2;//Mostar los sprites rojos.
				Juego->Jugador[ju].FrameX += Juego->Jugador[ju].FrameY/2;//Mostar los sprites rojos.
				//TapaAlcantarilla->TimepoUltimoCalculadoPosY=;
			}

			if(TapaAlcantarilla->Exploto && ExisteColision(Juego, &Juego->Fuego, &Juego->Jugador[ju], Todos, 0, 0))
			{
				RestarHP(Juego, &Juego->Jugador[ju], &Juego->Fuego, ju);
				Juego->Jugador[ju].CurrentFrame[1] += Juego->Jugador[ju].FrameY/2;//Mostar los sprites rojos.
				Juego->Jugador[ju].FrameX += Juego->Jugador[ju].FrameY/2;//Mostar los sprites rojos.
			}
		}
		if(TapaAlcantarilla->Exploto)
		{
			if(TapaAlcantarilla->AcelaracionY < 0)
				TapaAlcantarilla->AcelaracionY += 20;
			else
				TapaAlcantarilla->AcelaracionY = 0;
			TapaAlcantarilla->FrameCounter++;
			if(TapaAlcantarilla->FrameCounter >= TapaAlcantarilla->SwitchFrame)
			{
				TapaAlcantarilla->CurrentFrame[0] += TapaAlcantarilla->AnchoDividido;
				TapaAlcantarilla->FrameCounter = 0;
			}
			if(TapaAlcantarilla->CurrentFrame[0] >= TapaAlcantarilla->SpriteCaracter->w)
			{
				TapaAlcantarilla->CurrentFrame[0] = 0;
			}
		}	
		else
		{
			TapaAlcantarilla->CurrentFrame[0] = 0;
			TapaAlcantarilla->CurrentFrame[1] = 0;
		}

		if(TiempoSalto != 0 && TapaAlcantarilla->PosY > 0 - SCREEN_H/4)
			CaidaConGravedad(Juego, TapaAlcantarilla, TiempoSalto,0);

		//Eliminar las tapas que salen de la pantalla.
		if(TapaAlcantarilla->PosX > SCREEN_W*2 + Juego->PosActualBuffer || TapaAlcantarilla->PosX < Juego->PosActualBuffer-SCREEN_W)
			EliminarNodo(&(Juego->Tapas), TapaAlcantarilla);			
	}

	Juego->Fuego.FrameCounter++;
	if(Juego->Fuego.FrameCounter >= Juego->Fuego.SwitchFrame)
	{
		Juego->Fuego.CurrentFrame[0] += Juego->Fuego.AnchoDividido;
		Juego->Fuego.FrameCounter = 0;
	}
	if(Juego->Fuego.CurrentFrame[0] >= Juego->Fuego.SpriteCaracter->w)
	{
		Juego->Fuego.CurrentFrame[0]=0;
	}

	//Actualizar los proyectiles:
	for(int i=0; i<Juego->Proyectiles.cantidad && i>=0; i++)
	{
		TCARACTER* ProyectilActual = (TCARACTER*)BuscarNodoIndice(&(Juego->Proyectiles), i)->data;

		//Si las balas de los enemigos colisionan con el jugador:
		for(int ju=0; ju < Juego->CantidadJugadores; ju++)
		{
			if(Juego->Jugador[ju].Vidas <=0)
				continue;
			if(ExisteColision(Juego, &(Juego->Jugador[ju]), ProyectilActual, Todos, 0, ju) == true && ProyectilActual->IdSprite != Jugador)
			{
				if(Juego->Jugador[ju].CurrentFrame[1] + Juego->Jugador[ju].FrameY/2 < Juego->Jugador[ju].FrameY)
				{
					Juego->Jugador[ju].CurrentFrame[1] += Juego->Jugador[ju].FrameY/2;//Mostar los sprites rojos.
					Juego->Jugador[ju].FrameX += Juego->Jugador[ju].FrameY/2;//Mostar los sprites rojos.
				}
				RestarHP(Juego, &(Juego->Jugador[ju]), ProyectilActual, ju);

				TCARACTER* NuevaExplosion = new TCARACTER(); 
				int x;
				if(ProyectilActual->VelocidadX < 0)
					x = -3;
				else 
					x = Juego->Jugador[0].AnchoDividido;


				CrearExplosion(Juego, NuevaExplosion, ProyectilActual);
				NuevaExplosion->PosX = ProyectilActual->PosX + Juego->Jugador[0].AnchoDividido/x;

				if(ProyectilActual->Id == Nave)
					play_sample((SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 11))->data, 2000, 128, 1000, false);
				else if(ProyectilActual->Id == Jefe)
					Juego->CrearExplosionesBoss = false;

				EliminarNodo(&(Juego->Proyectiles), ProyectilActual);
				i--;
				break;
			}
		}
		if(i>=0)
			ProyectilActual = (TCARACTER*)BuscarNodoIndice(&(Juego->Proyectiles), i)->data;

		//Si las balas del jugador principal colisionan con los enemigos:
		for(int j=0; j<Juego->Enemigos.cantidad; j++)
		{
			TCARACTER* EnemigoActual = (TCARACTER*)BuscarNodoIndice(&Juego->Enemigos, j)->data;
			if(ExisteColision(Juego, EnemigoActual, ProyectilActual, Todos, 0, 0) == true && ProyectilActual->IdSprite != Villano)
			{
				if(EnemigoActual->CurrentFrame[1] + EnemigoActual->FrameY/2 < EnemigoActual->FrameY)
				{
					EnemigoActual->CurrentFrame[1] += EnemigoActual->FrameY/2;////Mostar los sprites rojos.
					EnemigoActual->FrameX += EnemigoActual->FrameY/2;//Mostar los sprites rojos.
				}
				RestarHP(Juego, EnemigoActual, ProyectilActual, 0);

				TCARACTER* NuevaExplosion = new TCARACTER(); 
				CrearExplosion(Juego, NuevaExplosion, ProyectilActual);
				NuevaExplosion->PosX = ProyectilActual->PosX;
				Juego->Jugador[ProyectilActual->IdJugador].ScoreJugador ++;

				if(Juego->Jugador[ProyectilActual->IdJugador].Arma.Id == LanzadorDeGranadas)
					play_sample((SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 11))->data, 150, 128, 1000, false);

				EliminarNodo(&(Juego->Proyectiles), ProyectilActual);
				i--;
				break;
			}
		}

		if(Juego->ContraElJefe == true)
		{
			if(ExisteColision(Juego, &Juego->Jefe, ProyectilActual, Todos, 0, 0) == true && ProyectilActual->IdSprite != Villano && ProyectilActual->IdSprite != Jefe)
			{
				if(Juego->Jefe.CurrentFrame[1] + Juego->Jefe.FrameY/2 < Juego->Jefe.FrameY)
				{
					Juego->Jefe.CurrentFrame[1] += Juego->Jefe.FrameY/2;////Mostar los sprites rojos.
					Juego->Jefe.FrameX += Juego->Jefe.FrameY/2;//Mostar los sprites rojos.
				}
				RestarHP(Juego, &Juego->Jefe, ProyectilActual, 0);

				TCARACTER* NuevaExplosion = new TCARACTER(); 
				CrearExplosion(Juego, NuevaExplosion, ProyectilActual);
				NuevaExplosion->PosX = ProyectilActual->PosX;

				Juego->Jugador[ProyectilActual->IdJugador].ScoreJugador ++;

				if(Juego->Jugador[ProyectilActual->IdJugador].Arma.Id == LanzadorDeGranadas)
					play_sample((SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 11))->data, 150, 128, 1000, false);

				EliminarNodo(&(Juego->Proyectiles), ProyectilActual);
				i--;
			}
		}

		if(i>=0)
			ProyectilActual = (TCARACTER*)BuscarNodoIndice(&(Juego->Proyectiles), i)->data;

		//Si las balas del jugador colisionan con algun item:
		for(int j=0; j<Juego->Items.cantidad; j++)
		{
			TCARACTER* ItemActual = (TCARACTER*)BuscarNodoIndice(&Juego->Items, j)->data;
			if(ProyectilActual->IdSprite != Villano && j!=0 && ExisteColision(Juego, ItemActual, ProyectilActual, Todos, 0, 0) == true)
			{
				if(ItemActual->CurrentFrame[1] + ItemActual->FrameY/2 < ItemActual->FrameY)
				{
					ItemActual->CurrentFrame[1] += ItemActual->FrameY/2;////Mostar los sprites rojos.
					ItemActual->FrameX += ItemActual->FrameY/2;//Mostar los sprites rojos.
				}
				RestarHP(Juego, ItemActual, ProyectilActual, 0);

				TCARACTER* NuevaExplosion = new TCARACTER(); 
				CrearExplosion(Juego, NuevaExplosion, ProyectilActual);
				NuevaExplosion->PosX = ProyectilActual->PosX;

				if(Juego->Jugador[ProyectilActual->IdJugador].Arma.Id == LanzadorDeGranadas)
					play_sample((SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 11))->data, 150, 128, 1000, false);

				EliminarNodo(&(Juego->Proyectiles), ProyectilActual);
				i--;
				break;
			}
		}

		if(i>=0)
			ProyectilActual = (TCARACTER*)BuscarNodoIndice(&(Juego->Proyectiles), i)->data;

		//Si las balas colisionan con el suelo.
		for(int j=0; j<Juego->Carretera.cantidad; j++)
		{
			TCARACTER* CarreteraActual = (TCARACTER*)BuscarNodoIndice(&Juego->Carretera, j)->data;
			if(ProyectilActual->PosY + ProyectilActual->AltoDividido > CarreteraActual->PosY -25)
			{
				TCARACTER* NuevaExplosion = new TCARACTER(); 

				if(ProyectilActual->Id == Jefe)
				{
					Juego->CrearExplosionesBoss = true;
					Juego->TiempoDetenerExplosionesBoss = clock();
				}
				else
				{
					CrearExplosion(Juego, NuevaExplosion, ProyectilActual);
					NuevaExplosion->PosX = ProyectilActual->PosX;
				}

				if(Juego->Jugador[ProyectilActual->IdJugador].Arma.Id == LanzadorDeGranadas)
					play_sample((SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 11))->data, 150, 128, 1000, false);

				if(ProyectilActual->Id == Nave)
					play_sample((SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 11))->data, 150, 128, 1000, false);

				EliminarNodo(&(Juego->Proyectiles), ProyectilActual);
				i--;
				break;
			}
		}

		if(i>=0)
			ProyectilActual = (TCARACTER*)BuscarNodoIndice(&(Juego->Proyectiles), i)->data;

		float tiempoActual = (clock() - ProyectilActual->TiempoDisparo) / CLOCKS_PER_SEC;

		//Componentes velocidad:
		ProyectilActual->VelocidadX = ProyectilActual->VelocidadXInicial;
		ProyectilActual->VelocidadY = ProyectilActual->VelocidadYInicial; 

		//Posiciones X y Y:
		ProyectilActual->PosX = ProyectilActual->PosXInicial + ProyectilActual->VelocidadX*tiempoActual;
		ProyectilActual->PosY = ProyectilActual->PosYInicial + 0.5*(ACEL_GRAVEDAD + ProyectilActual->AcelaracionY)*pow(tiempoActual,2) - ProyectilActual->VelocidadY*tiempoActual;

		//Eliminar las balas que salen de la pantalla.
		if(ProyectilActual->PosX > SCREEN_W*2 + Juego->PosActualBuffer || ProyectilActual->PosX < Juego->PosActualBuffer-SCREEN_W || ProyectilActual->PosY < 0-SCREEN_H/2 || ProyectilActual->PosY > SCREEN_H)
			EliminarNodo(&(Juego->Proyectiles), ProyectilActual);
	}

	for(int ju=0; ju<Juego->CantidadJugadores; ju++)
	{
		if(Juego->Jugador[ju].Vidas <= 0)
			continue;
		if(Juego->ContraElJefe == true)
		{
			for(int i=0; i<Juego->Explosiones.cantidad; i++)
			{
				TCARACTER* ExplosionActual = (TCARACTER*)BuscarNodoIndice(&Juego->Explosiones, i)->data;
				if(ExisteColision(Juego, &Juego->Jugador[ju], ExplosionActual, Todos, 0, 0) == true && ExplosionActual->IdSprite != Jugador)
				{
					RestarHP(Juego, &Juego->Jugador[ju], ExplosionActual, ju);
				}

			}
		}
	}


	//Hacer la animación de la explosión.
	for(int j=0; j<Juego->Explosiones.cantidad; j++)
	{
		TCARACTER* ExplosionActual = (TCARACTER*)BuscarNodoIndice(&Juego->Explosiones, j)->data;

		ExplosionActual->FrameCounter++;
		if(ExplosionActual->FrameCounter >= ExplosionActual->SwitchFrame)
		{
			ExplosionActual->CurrentFrame[0] += ExplosionActual->AnchoDividido;
			ExplosionActual->FrameCounter = 0;
		}
		if(ExplosionActual->CurrentFrame[0] >= ExplosionActual->SpriteCaracter->w)
		{
			EliminarNodo(&Juego->Explosiones, ExplosionActual);
			j--;
		}
	}

	return 0;
}

int ActualizarJugador(TJUEGO* Juego)
{
	for(int ju=0; ju < Juego->CantidadJugadores; ju++)
	{
		if(Juego->Jugador[ju].Vidas <=0)
			continue;

		poll_joystick();
		float TiempoActual;
		int SpritesEntreCaminarDisparar = 26;
		float TiempoDelSalto;
		Juego->Jugador[ju].FrameX = 6;
		Juego->Jugador[ju].AnchoDividido = Juego->Jugador[ju].SpriteCaracter->w/Juego->Jugador[ju].FrameX;
		Juego->Jugador[ju].SwitchFrame = 6;
		Juego->Jugador[ju].isActive = false;
		Juego->Jugador[ju].Saltando = true;

		//Aún no ha dado un primer salto
		if(Juego->Jugador[ju].TimepoUltimoCalculadoPosY == 0)
			TiempoDelSalto = 0;
		else 
			TiempoDelSalto = (clock() - Juego->Jugador[ju].TimepoUltimoCalculadoPosY)/CLOCKS_PER_SEC;

		//Conseguir ángulo entre el jugador y el cursor (mouse).
		//
		//Juego->Jugador[ju].AnguloDisparo = fixtoi(fixatan2(itofix(joy[0].stick[1].axis[0].pos + (Juego->Jugador[ju].PosY + Juego->Jugador[ju].AltoDividido/2 - 15)),
		//itofix(joy[0].stick[0].axis[2].pos + (Juego->Jugador[ju].PosX - Juego->PosActualBuffer + Juego->Jugador[ju].AnchoDividido/2 - 7))))* 360 / 256;

		//if(Juego->CantidadJugadores == 1 && 

		joy[ju].stick[1].axis[0].pos-=128;
		Juego->Jugador[ju].AnguloDisparo=fixtof(fixatan2(itofix(joy[ju].stick[1].axis[0].pos), itofix(joy[ju].stick[0].axis[2].pos)))*360/256;

		//Juego->Jugador[ju].AnguloDisparo=0;
		if(Juego->Jugador[ju].AnguloDisparo <= 0) 
			Juego->Jugador[ju].AnguloDisparo *= -1;
		else	
			Juego->Jugador[ju].AnguloDisparo = 360 - Juego->Jugador[ju].AnguloDisparo;

		//Arreglar los ángulos a cantidades de 15 en 15 por los sprites del jugador.
		for(int i=0; i<=360; i+=DIF_ANGULOS)
		{
			if(i <= Juego->Jugador[ju].AnguloDisparo + MAX_ANGULO && i > Juego->Jugador[ju].AnguloDisparo - MIN_ANGULO)
			{
				Juego->Jugador[ju].AnguloDisparo = i;
				break;
			}
		}

		if(Juego->Jugador[ju].AnguloDisparo == TOTAL_ANGULOS)
			Juego->Jugador[ju].AnguloDisparo = 0;

		//Asignar el sprite de acuerdo con el ángulo de disparo:
		for(int i=0; i<3; i++)
		{
			TCARACTER* CarreteraActual = (TCARACTER*)(BuscarNodoIndice(&(Juego->Carretera), i)->data);
			if(ExisteColision(Juego, &(Juego->Jugador[ju]), CarreteraActual, DesdeAbajo, TiempoDelSalto, ju))
			{
				Juego->Jugador[ju].Saltando = false;
				Juego->Jugador[ju].TiempoCalculadoVelocidadY = 0;
				AnguloDeDisparo(Juego, ju);
				break;
			}
		}

		//Si el jugador está encima del tanque:
		for(int j=0; j<Juego->Enemigos.cantidad; j++)
		{
			TCARACTER* EnemigoActual = (TCARACTER*)(BuscarNodoIndice(&(Juego->Enemigos), j)->data);
			if(EnemigoActual->IdSprite == Tanque)
			{
				if(ExisteColision(Juego, &(Juego->Jugador[ju]), EnemigoActual, DesdeAbajo, TiempoDelSalto, ju))
				{
					Juego->Jugador[ju].Saltando = false;
					Juego->Jugador[ju].TiempoCalculadoVelocidadY = 0;
					AnguloDeDisparo(Juego, ju);
					break;
				}
			}
		}

		if(Juego->ContraElJefe == true)
		{
			for(int i=0; i<=1; i++)
			{
				if(ExisteColision(Juego, &(Juego->Jugador[ju]), &Juego->Plataformas[i], DesdeAbajo, TiempoDelSalto, ju))
				{
					Juego->Jugador[ju].Saltando = false;
					Juego->Jugador[ju].TiempoCalculadoVelocidadY = 0;
					AnguloDeDisparo(Juego, ju);
					break;
				}
			}
		}

		//Si el jugador está saltando se reproduce la animanción de dar vueltas en el aire.
		if(Juego->Jugador[ju].Saltando == true) 
		{
			if(Juego->Jugador[ju].AnguloDisparo < ANGULO_SUP || Juego->Jugador[ju].AnguloDisparo > ANGULO_INF)
			{
				Juego->Jugador[ju].CurrentFrame[1] = SaltarDerecha;
				Juego->Jugador[ju].FrameX = SaltarDerecha;
			}
			else
			{
				Juego->Jugador[ju].CurrentFrame[1] = SaltarIzquierda;
				Juego->Jugador[ju].FrameX = SaltarIzquierda;
			}
			Juego->Jugador[ju].isActive = true;
			Juego->Jugador[ju].SwitchFrame = 1;
		}


		if(key[KEY_D] || joy[ju].stick[0].axis[0].d2 == -1)//Caminar Derecha
		{
			if(Juego->Jugador[ju].EnElPiso == true)
				Juego->Jugador[ju].AnguloDisparo = 0;
			else
			{
				if(Juego->Jugador[ju].AnguloDisparo <= ANGULO_SUP || Juego->Jugador[ju].AnguloDisparo >= ANGULO_INF)
				{
					if(Juego->Enemigos.cantidad == 0)
					{
						//Cuando está a la mitad de la pantalla comienza a moverse la pantalla también.:
						if(Juego->Jugador[ju].PosX - Juego->PosActualBuffer >= SCREEN_W/2 - Juego->Jugador[ju].AnchoDividido)
						{
							if(Juego->ContraElJefe == true)
							{
								if((Juego->Jefe.PosX + Juego->Jefe.AnchoDividido/2) - Juego->PosActualBuffer <= SCREEN_W/2);
								//{

								//}&& Juego->Jugador[ju].PosX + Juego->Jugador[ju].AnchoDividido >= Juego->PosActualBuffer + SCREEN_W);
								else
								{
									Juego->PosActualBuffer += MoveSpeed;
									Juego->PosActualFondo += MoveSpeed-3;

								}
							}
							else if((Juego->CantidadJugadores == 2 && (Juego->Jugador[0].Vidas== 0 || Juego->Jugador[1].Vidas== 0 )) || Juego->CantidadJugadores == 2 &&
								Juego->Jugador[0].PosX - Juego->PosActualBuffer >= SCREEN_W/2 - Juego->Jugador[0].AnchoDividido &&
								Juego->Jugador[1].PosX - Juego->PosActualBuffer >= SCREEN_W/2 - Juego->Jugador[1].AnchoDividido || Juego->CantidadJugadores ==1

								)
							{
								Juego->PosActualBuffer += MoveSpeed;
								Juego->PosActualFondo += MoveSpeed-3;
							}
						}

						if(Juego->ContraElJefe == true)
						{
							if(Juego->Jugador[ju].PosX + Juego->Jugador[ju].AnchoDividido < Juego->PosActualBuffer + SCREEN_W)
								Juego->Jugador[ju].PosX += MoveSpeed;
						}

						else if((Juego->CantidadJugadores == 2 && (Juego->Jugador[0].Vidas== 0 || Juego->Jugador[1].Vidas== 0 )) || Juego->CantidadJugadores == 2 && Juego->Jugador[ju].PosX - Juego->PosActualBuffer <= SCREEN_W - Juego->Jugador[ju].AnchoDividido || Juego->CantidadJugadores ==1)
								Juego->Jugador[ju].PosX += MoveSpeed;

						for(int i=0; i<3; i++)
						{
							TCARACTER* CarreteraActual = (TCARACTER*)(BuscarNodoIndice(&(Juego->Carretera), i)->data);
							//if(Juego->Jugador[ju].PosY == Calle)//Si está en el piso se reproduce la secuencia sprites de caminar.
							if(ExisteColision(Juego, &(Juego->Jugador[ju]), CarreteraActual, DesdeAbajo, TiempoDelSalto, ju))
								Juego->Jugador[ju].isActive = true;
							else if(Juego->Jugador[ju].FrameX != SaltarDerecha && Juego->Jugador[ju].FrameX != SaltarIzquierda)
							{
								Juego->Jugador[ju].VelocidadYSalto = 0;
								Juego->Jugador[ju].TimepoUltimoCalculadoPosY = clock();
							}
						}
						if(Juego->ContraElJefe == true)
						{
							for(int i=0; i<=1; i++)
							{
								if(ExisteColision(Juego, &(Juego->Jugador[ju]), &Juego->Plataformas[i], DesdeAbajo, TiempoDelSalto, ju))
									Juego->Jugador[ju].isActive = true;
								else if(Juego->Jugador[ju].FrameX != SaltarDerecha && Juego->Jugador[ju].FrameX != SaltarIzquierda)
								{
									Juego->Jugador[ju].VelocidadYSalto = 0;
									Juego->Jugador[ju].TimepoUltimoCalculadoPosY = clock();
								}
							}
						}
					}
					else
					{
						for(int i=0; i<Juego->Enemigos.cantidad; i++)
						{
							TCARACTER* EnemigoActual = (TCARACTER*)BuscarNodoIndice(&Juego->Enemigos, i)->data;

							if(ExisteColision(Juego, &(Juego->Jugador[ju]), EnemigoActual, DesdeDerecha, 0, ju) && EnemigoActual->IdSprite == Tanque);
							/*{
							//Quitar ; de arriba.
							//Play Sound. Choque con tanque;
							}*/
							else if(i+1 == Juego->Enemigos.cantidad)
							{
								//Cuando está a la mitad de la pantalla comienza a moverse la pantalla también.:
								if(Juego->Jugador[ju].PosX - Juego->PosActualBuffer >= SCREEN_W/2 - Juego->Jugador[ju].AnchoDividido)
								{
									if(Juego->ContraElJefe == true)
									{
										if((Juego->Jefe.PosX + Juego->Jefe.AnchoDividido/2) - Juego->PosActualBuffer <= SCREEN_W/2);
										//{

										//}&& Juego->Jugador[ju].PosX + Juego->Jugador[ju].AnchoDividido >= Juego->PosActualBuffer + SCREEN_W);
										else
										{
											Juego->PosActualBuffer += MoveSpeed;
											Juego->PosActualFondo += MoveSpeed-3;
										}
									}

									else if(Juego->CantidadJugadores == 2 && (Juego->Jugador[0].Vidas== 0 || Juego->Jugador[1].Vidas== 0 ) ||
										Juego->Jugador[0].PosX - Juego->PosActualBuffer >= SCREEN_W/2 - Juego->Jugador[0].AnchoDividido &&
										Juego->Jugador[1].PosX - Juego->PosActualBuffer >= SCREEN_W/2 - Juego->Jugador[1].AnchoDividido || Juego->CantidadJugadores ==1)
									{
										Juego->PosActualBuffer += MoveSpeed;
										Juego->PosActualFondo += MoveSpeed-3;
									}
								}

								if(Juego->ContraElJefe == true)
								{
									if(Juego->Jugador[ju].PosX + Juego->Jugador[ju].AnchoDividido < Juego->PosActualBuffer + SCREEN_W)
										Juego->Jugador[ju].PosX += MoveSpeed;

									for(int i=0; i<=1; i++)
									{
										if(ExisteColision(Juego, &(Juego->Jugador[ju]), &Juego->Plataformas[i], DesdeAbajo, TiempoDelSalto, ju))
											Juego->Jugador[ju].isActive = true;
										else if(Juego->Jugador[ju].FrameX != SaltarDerecha && Juego->Jugador[ju].FrameX != SaltarIzquierda)
										{
											Juego->Jugador[ju].VelocidadYSalto = 0;
											Juego->Jugador[ju].TimepoUltimoCalculadoPosY = clock();
										}
									}
								}
								else if(Juego->CantidadJugadores == 2 && Juego->Jugador[ju].PosX - Juego->PosActualBuffer <= SCREEN_W - Juego->Jugador[ju].AnchoDividido || Juego->CantidadJugadores ==1 && (Juego->Jugador[ju].PosX + Juego->Jugador[ju].AnchoDividido < Juego->PosActualBuffer + SCREEN_W))
									Juego->Jugador[ju].PosX += MoveSpeed;

								for(int i=0; i<3; i++)
								{
									TCARACTER* CarreteraActual = (TCARACTER*)(BuscarNodoIndice(&(Juego->Carretera), i)->data);
									//if(Juego->Jugador[ju].PosY == Calle)//Si está en el piso se reproduce la secuencia sprites de caminar.
									if(ExisteColision(Juego, &(Juego->Jugador[ju]), CarreteraActual, DesdeAbajo, TiempoDelSalto, ju))
										Juego->Jugador[ju].isActive = true;
									else if(Juego->Jugador[ju].FrameX != SaltarDerecha && Juego->Jugador[ju].FrameX != SaltarIzquierda)
									{
										Juego->Jugador[ju].VelocidadYSalto = 0;
										Juego->Jugador[ju].TimepoUltimoCalculadoPosY = clock();
									}
								}
								for(int j=0; j<Juego->Enemigos.cantidad; j++)
								{
									TCARACTER* EnemigoActual = (TCARACTER*)(BuscarNodoIndice(&(Juego->Enemigos), j)->data);
									//if(Juego->Jugador[ju].PosY == Calle)//Si está en el piso se reproduce la secuencia sprites de caminar.
									if(ExisteColision(Juego, &(Juego->Jugador[ju]), EnemigoActual, DesdeAbajo, TiempoDelSalto, ju))
										Juego->Jugador[ju].isActive = true;
								}
							}
						}
					}
				}
			}
		}
		else if(key[KEY_A] || joy[ju].stick[0].axis[0].d1 == -1)
		{
			if(Juego->Jugador[ju].EnElPiso == true)
				Juego->Jugador[ju].AnguloDisparo = ANGULO_SUP*2;
			else
			{
				if(Juego->Jugador[ju].AnguloDisparo >= 90 && Juego->Jugador[ju].AnguloDisparo <= 270)
				{
					if(Juego->Enemigos.cantidad == 0)
					{
						if(Juego->Jugador[ju].PosX <= Juego->PosActualBuffer);
						else
						{
							Juego->Jugador[ju].PosX -= MoveSpeed;
							Juego->Jugador[ju].isActive = true;
						}

						if(Juego->ContraElJefe == true)
						{
							for(int i=0; i<=1; i++)
							{
								if(ExisteColision(Juego, &(Juego->Jugador[ju]), &Juego->Plataformas[i], DesdeAbajo, TiempoDelSalto, ju) == true)
								Juego->Jugador[ju].isActive = true;
								else if(Juego->Jugador[ju].FrameX != SaltarDerecha && Juego->Jugador[ju].FrameX != SaltarIzquierda)
								{
									Juego->Jugador[ju].VelocidadYSalto = 0;
									Juego->Jugador[ju].TimepoUltimoCalculadoPosY = clock();
								}
							}
						}
					}
					else
					{
						for(int i=0; i<Juego->Enemigos.cantidad; i++)
						{
							TCARACTER* EnemigoActual = (TCARACTER*)BuscarNodoIndice(&Juego->Enemigos, i)->data;

							if(ExisteColision(Juego, &(Juego->Jugador[ju]), EnemigoActual, DesdeIzquierda, 0, ju) && EnemigoActual->IdSprite == Tanque);
							/*{
							//Quitar ; de arriba.
							//Play Sound. Choque con tanque. "pip"
							}*/
							else if(i+1 == Juego->Enemigos.cantidad)
							{
								if(Juego->Jugador[ju].PosX <= Juego->PosActualBuffer);
								//Play Sound here. Limite izquierdo. "pip"
								else
								{
									if(Juego->Jugador[ju].Saltando == true)
										Juego->Jugador[ju].PosX -= (MoveSpeed+1);
									else
										Juego->Jugador[ju].PosX -= (MoveSpeed);

									for(int i=0; i<3; i++)
									{
										TCARACTER* CarreteraActual = (TCARACTER*)(BuscarNodoIndice(&(Juego->Carretera), i)->data);
										if(ExisteColision(Juego, &(Juego->Jugador[ju]), CarreteraActual, DesdeAbajo, TiempoDelSalto, ju) == true)
											Juego->Jugador[ju].isActive = true;
										else if(Juego->Jugador[ju].FrameX != SaltarDerecha && Juego->Jugador[ju].FrameX != SaltarIzquierda)
										{
											Juego->Jugador[ju].VelocidadYSalto = 0;
											Juego->Jugador[ju].TimepoUltimoCalculadoPosY = clock();
										}
									}
									for(int i=0; i<Juego->Enemigos.cantidad; i++)
									{
										TCARACTER* EnemigoActual = (TCARACTER*)(BuscarNodoIndice(&(Juego->Enemigos), i)->data);
										//if(Juego->Jugador[ju].PosY == Calle)//Si está en el piso se reproduce la secuencia sprites de caminar.
										if(ExisteColision(Juego, &(Juego->Jugador[ju]), EnemigoActual, DesdeAbajo, TiempoDelSalto, ju) == true)
											Juego->Jugador[ju].isActive = true;
									}

									if(Juego->ContraElJefe == true)
									{
										for(int i=0; i<=1; i++)
										{
											if(ExisteColision(Juego, &(Juego->Jugador[ju]), &Juego->Plataformas[i], DesdeAbajo, TiempoDelSalto, ju) == true)
											Juego->Jugador[ju].isActive = true;
											else if(Juego->Jugador[ju].FrameX != SaltarDerecha && Juego->Jugador[ju].FrameX != SaltarIzquierda)
											{
												Juego->Jugador[ju].VelocidadYSalto = 0;
												Juego->Jugador[ju].TimepoUltimoCalculadoPosY = clock();
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}

		if(key[KEY_W] ||key[KEY_SPACE] || joy[ju].stick[0].axis[1].d1 == -1)
		{
			//if(Juego->Jugador[ju].PosY == Calle)
			for(int i=0; i<3; i++)
			{
				TCARACTER* CarreteraActual = (TCARACTER*)(BuscarNodoIndice(&(Juego->Carretera), i)->data);
				if(ExisteColision(Juego, &(Juego->Jugador[ju]), CarreteraActual, DesdeAbajo, TiempoDelSalto, ju))
				{
					if(Juego->Jugador[ju].AnguloDisparo < ANGULO_SUP || Juego->Jugador[ju].AnguloDisparo > ANGULO_INF)
					{
						Juego->Jugador[ju].CurrentFrame[1] = SaltarDerecha;
						Juego->Jugador[ju].FrameX = SaltarDerecha;
					}
					else
					{
						Juego->Jugador[ju].CurrentFrame[1] = SaltarIzquierda;
						Juego->Jugador[ju].FrameX = SaltarIzquierda;
					}
					Juego->Jugador[ju].TimepoUltimoCalculadoPosY = clock();
					Juego->Jugador[ju].VelocidadYSalto = VELOCIDAD_Y;
					Juego->Jugador[ju].isActive = true;
					break;
				}
			}
			for(int i=0; i<Juego->Enemigos.cantidad; i++)
			{
				TCARACTER* EnemigoActual = (TCARACTER*)(BuscarNodoIndice(&(Juego->Enemigos), i)->data);
				if(EnemigoActual->IdSprite == Tanque)
				{
					if(ExisteColision(Juego, &(Juego->Jugador[ju]), EnemigoActual, DesdeAbajo, TiempoDelSalto, ju))
					{
						if(Juego->Jugador[ju].AnguloDisparo < ANGULO_SUP || Juego->Jugador[ju].AnguloDisparo > ANGULO_INF)
						{
							Juego->Jugador[ju].CurrentFrame[1] = SaltarDerecha;
							Juego->Jugador[ju].FrameX = SaltarDerecha;
						}
						else
						{
							Juego->Jugador[ju].CurrentFrame[1] = SaltarIzquierda;
							Juego->Jugador[ju].FrameX = SaltarIzquierda;
						}
						Juego->Jugador[ju].TimepoUltimoCalculadoPosY = clock();
						Juego->Jugador[ju].VelocidadYSalto = VELOCIDAD_Y;
						Juego->Jugador[ju].isActive = true;
					}
				}
			}
			if(Juego->ContraElJefe == true)
			{
				for(int i=0; i<=1; i++)
				{
					if(ExisteColision(Juego, &(Juego->Jugador[ju]), &Juego->Plataformas[i], DesdeAbajo, TiempoDelSalto, ju))
					{
						if(Juego->Jugador[ju].AnguloDisparo < ANGULO_SUP || Juego->Jugador[ju].AnguloDisparo > ANGULO_INF)
						{
							Juego->Jugador[ju].CurrentFrame[1] = SaltarDerecha;
							Juego->Jugador[ju].FrameX = SaltarDerecha;
						}
						else
						{
							Juego->Jugador[ju].CurrentFrame[1] = SaltarIzquierda;
							Juego->Jugador[ju].FrameX = SaltarIzquierda;
						}
						Juego->Jugador[ju].TimepoUltimoCalculadoPosY = clock();
						Juego->Jugador[ju].VelocidadYSalto = VELOCIDAD_Y;
						Juego->Jugador[ju].isActive = true;
					}
				}
			}
		}
		else if((key[KEY_S] || joy[ju].stick[0].axis[1].d2 == -1) && Juego->Jugador[ju].Saltando == false )
		{
			if(Juego->Jugador[ju].AnguloDisparo < ANGULO_SUP || Juego->Jugador[ju].AnguloDisparo > ANGULO_INF)
			{
				Juego->Jugador[ju].CurrentFrame[1] = EnElPisoDerecha;
				Juego->Jugador[ju].FrameX = EnElPisoDerecha;
				Juego->Jugador[ju].AnguloDisparo = 0;
			}
			else
			{
				Juego->Jugador[ju].CurrentFrame[1] = EnElPisoIzquierda;
				Juego->Jugador[ju].FrameX = EnElPisoIzquierda;
				Juego->Jugador[ju].AnguloDisparo = ANGULO_SUP*2;
			}
			Juego->Jugador[ju].FrameX = 3;
			Juego->Jugador[ju].AnchoDividido = Juego->Jugador[ju].SpriteCaracter->w/Juego->Jugador[ju].FrameX;
			Juego->Jugador[ju].EnElPiso = true;
		}
		if(!key[KEY_S] && joy[ju].stick[0].axis[1].d2 != -1)
			Juego->Jugador[ju].EnElPiso = false;

		//Asiganción de los sprites de efecto de disparo.
		if(mouse_b & 1 || joy[ju].button[5].b)
		{
			TiempoActual = (clock() - Juego->Jugador[ju].TiempoDisparo)/CLOCKS_PER_SEC;//Tiempo que ha pasado desde el último disparo.

			//Cuando el jugador está en el piso:
			if(Juego->Jugador[ju].EnElPiso == true && Juego->Jugador[ju].Saltando == false)
			{
				if(Juego->Jugador[ju].AnguloDisparo == 0)
				{
					Juego->Jugador[ju].CurrentFrame[1] = EnElPisoDispararR;
					Juego->Jugador[ju].FrameX = EnElPisoDispararR;
					Juego->Jugador[ju].isActive = true;
					Juego->Jugador[ju].SwitchFrame = 2;
				}
				else
				{
					Juego->Jugador[ju].CurrentFrame[1] = EnElPisoDispararL;
					Juego->Jugador[ju].FrameX = EnElPisoDispararL;
					Juego->Jugador[ju].isActive = true;
					Juego->Jugador[ju].SwitchFrame = 2;
				}
			}
			else
			{
				//Cuando el jugador está en la carretera se deben mostar los sprites de disparos.
				for(int i=0; i<3; i++)
				{
					TCARACTER* CarreteraActual = (TCARACTER*)(BuscarNodoIndice(&(Juego->Carretera), i)->data);
					if(ExisteColision(Juego, &(Juego->Jugador[ju]), CarreteraActual, DesdeAbajo, TiempoDelSalto, ju) && !key[KEY_W] && !key[KEY_SPACE] && !key[KEY_A] && !key[KEY_D] && !key[KEY_S] && joy[ju].stick[0].axis[0].d2 != -1 && joy[ju].stick[0].axis[0].d1 != -1)
					{
						Juego->Jugador[ju].CurrentFrame[1] += SpritesEntreCaminarDisparar;
						Juego->Jugador[ju].FrameX += SpritesEntreCaminarDisparar;
						Juego->Jugador[ju].isActive = true;
						Juego->Jugador[ju].SwitchFrame = 2;
						break;
					}//if(Juego->Jugador[ju].PosY == Calle && !key[KEY_W] && !key[KEY_A] && !key[KEY_D] && !key[KEY_S])
				}

				//Cuando el jugador está encima del tanque y dispara de deben mostrar los sprites de disparo.
				for(int i=0; i<Juego->Enemigos.cantidad; i++)
				{
					TCARACTER* EnemigoActual = (TCARACTER*)(BuscarNodoIndice(&(Juego->Enemigos), i)->data);
					if(EnemigoActual->IdSprite == Tanque)
					{
						if(ExisteColision(Juego, &(Juego->Jugador[ju]), EnemigoActual, DesdeAbajo, TiempoDelSalto, ju) && !key[KEY_W] && !key[KEY_SPACE] && !key[KEY_A] && !key[KEY_D] && !key[KEY_S] && joy[ju].stick[0].axis[0].d2 != -1 && joy[ju].stick[0].axis[0].d1 != -1)
						{
							Juego->Jugador[ju].CurrentFrame[1] += SpritesEntreCaminarDisparar;
							Juego->Jugador[ju].FrameX += SpritesEntreCaminarDisparar;
							Juego->Jugador[ju].isActive = true;
							Juego->Jugador[ju].SwitchFrame = 2;
							break;
						}
					}
				}
			}

			if(TiempoActual > Juego->Jugador[ju].Arma.TiempoDisparar)
			{
				if(Juego->Jugador[ju].Arma.Id == MultiplesDisparos)
				{
					Disparar(Juego, &(Juego->Jugador[ju]));
					Juego->Jugador[ju].AnguloDisparo+=5;
					Disparar(Juego, &(Juego->Jugador[ju]));
					Juego->Jugador[ju].AnguloDisparo-=10;
					Disparar(Juego, &(Juego->Jugador[ju]));
				}
				else
					Disparar(Juego, &(Juego->Jugador[ju]));
			}
		}

		if(Juego->Jugador[ju].isActive)
		{
			Juego->Jugador[ju].FrameCounter++;
			if(Juego->Jugador[ju].FrameCounter >= Juego->Jugador[ju].SwitchFrame)
			{
				if(Juego->Jugador[ju].CurrentFrame[0] >= Juego->Jugador[ju].SpriteCaracter->w)
					Juego->Jugador[ju].CurrentFrame[0] = 0;
				else
					Juego->Jugador[ju].CurrentFrame[0] += Juego->Jugador[ju].AnchoDividido;
				Juego->Jugador[ju].FrameCounter = 0;
			}
			if(Juego->Jugador[ju].CurrentFrame[0] >= Juego->Jugador[ju].SpriteCaracter->w)
				Juego->Jugador[ju].CurrentFrame[0] = 0;
		}
		else
		{
			Juego->Jugador[ju].CurrentFrame[0] = 0;
			Juego->Jugador[ju].FrameCounter = 0;
		}

		CaidaConGravedad(Juego, &(Juego->Jugador[ju]), TiempoDelSalto, ju);
	}
	return 0;
}

void Villanos(TJUEGO* Juego)
{
	//	for(int ju=0; ju < Juego->CantidadJugadores; ju++)
	//{
	
	int TiempoParaVillano = 4, TiempoParaVRodante = 15, TiempoParaTanque = 40, TiempoParaNave = 55, MaximoEnemigos = 5;
	float TiempoAparicion = (clock() - Juego->TiempoSalidaVillano1)/CLOCKS_PER_SEC;

	for(int ju = 0; ju < Juego->CantidadJugadores; ju++)
	{
		if(Juego->EnemigosEnJuego == 10)
			Juego->Apocalipse = false;
		if((Juego->Jugador[ju].Arma.Id == MultiplesDisparos && Juego->Jugador[ju].FactorAtaque > 5 && Juego->EnemigosEnJuego <= 2) || Juego->Apocalipse)
			TiempoParaVillano = 0, TiempoParaVRodante = 1, TiempoParaTanque = 2, TiempoParaNave = 1, MaximoEnemigos = 10, Juego->Apocalipse = true;		
	}
	
	//Cuando el ataque o la defensa del jugador son altos los enemigos aparecen más rapido.
	if(Juego->ContraElJefe == false)
	{
		if(Juego->Jugador[0].FactorAtaque >= ATAQUE_MAX || Juego->Jugador[0].FactorDefensa >= DEFENSA_MAX || 
			(Juego->CantidadJugadores == 2 && (Juego->Jugador[1].FactorAtaque >= ATAQUE_MAX || Juego->Jugador[1].FactorDefensa >= DEFENSA_MAX)))
		{
			TiempoParaVillano = 3;
			TiempoParaVRodante = 6,
				TiempoParaTanque = 20, 
				TiempoParaNave = 30,
				MaximoEnemigos = 5;
		}

		if(TiempoAparicion > TiempoParaVillano && Juego->EnemigosEnJuego < MaximoEnemigos)
		{//Tiempo de aparición para el robot enemigo, villano 1.
			CrearVillano(Juego, Villano);
			Juego->EnemigosEnJuego ++;
			Juego->TiempoSalidaVillano1 = clock();
		}

		TiempoAparicion = (clock() - Juego->TiempoSalidaVillano2)/CLOCKS_PER_SEC;

		if(TiempoAparicion > TiempoParaVRodante && Juego->EnemigosEnJuego < MaximoEnemigos)
		{//Tiempo de aparición para el robotsito pequeño.
			Juego->EnemigosEnJuego ++;
			CrearVillano(Juego, VillanoRodante);
			Juego->TiempoSalidaVillano2 = clock();
		}

		TiempoAparicion = (clock() - Juego->TiempoSalidaVillano3)/CLOCKS_PER_SEC;

		if(TiempoAparicion > TiempoParaTanque && Juego->EnemigosEnJuego < MaximoEnemigos)
		{//Tiempo de aparición para el tanque.
			Juego->EnemigosEnJuego ++;
			CrearVillano(Juego, Tanque);
			Juego->TiempoSalidaVillano3 = clock();
		}

		TiempoAparicion = (clock() - Juego->TiempoSalidaVillano4)/CLOCKS_PER_SEC;

		if(TiempoAparicion > TiempoParaNave && Juego->EnemigosEnJuego < MaximoEnemigos)
		{//Tiempo de aparición para la nave.
			Juego->EnemigosEnJuego ++;
			CrearVillano(Juego, Nave);
			Juego->TiempoSalidaVillano4 = clock();
		}
	}

	for(int i=0; i<Juego->Enemigos.cantidad; i++)
	{
		TCARACTER* EnemigoActual = (TCARACTER*)(BuscarNodoIndice(&(Juego->Enemigos), i)->data);
		float TiempoDelSalto;

		if(EnemigoActual->TimepoUltimoCalculadoPosY != 0)
			TiempoDelSalto = (clock() - EnemigoActual->TimepoUltimoCalculadoPosY)/1000;
		else//Cuando el enemigo aparece el tiempo del salto es cero.
			TiempoDelSalto = 0;

		CaidaConGravedad(Juego, EnemigoActual, TiempoDelSalto, 0);
		float TiempoEntreDisparos = (clock() - EnemigoActual->TiempoDisparo)/CLOCKS_PER_SEC;

		if(EnemigoActual->IdSprite == Nave)//Actualizar la nave. Ya que la nave actua de forma diferente a los demas enemigos.
			ActualizarNave(Juego, EnemigoActual, TiempoEntreDisparos);
		else
		{
			int idJugador=0;
			if(Juego->CantidadJugadores > 1)
			{
				//int posxEnemigo=EnemigoActual->PosX-SCREEN_W;
				//1 izquierda y 2 derecha
				int ubicacion=0;
				int posxJugadorTotal=EnemigoActual->PosX- Juego->Jugador[idJugador].PosX;
				int posJu1=-1;
				int posJu2=-1;
				int pos=0;
				for(int ju=0; ju < Juego->CantidadJugadores; ju++)
				{
					if(Juego->Jugador[ju].Vidas==0)
						continue;

					//1 izquierda y 2 derecha
					if(EnemigoActual->PosX > Juego->Jugador[ju].PosX)
						ubicacion=2;
					else if(EnemigoActual->PosX < Juego->Jugador[ju].PosX)
						ubicacion=1;

					if(ubicacion==2)
						pos=EnemigoActual->PosX - Juego->Jugador[ju].PosX+Juego->Jugador[ju].AnchoDividido;
					else if(ubicacion==1)
						pos=Juego->Jugador[ju].PosX- EnemigoActual->PosX + EnemigoActual->AnchoDividido; 

					if(ju==0)
						posJu1=pos;
					else if(ju==1)
						posJu2=pos;

				}
				if(posJu2 > posJu1 && posJu1 !=-1)
					idJugador=0;
				
				if(posJu1 > posJu2 && posJu2 !=-1)
					idJugador=1;

				if(posJu1 ==-1)
					idJugador=1;
				else if(posJu2 ==-1)
					idJugador=0;

			}
			if(EnemigoActual->Disparando == true 
				|| EnemigoActual->DisparandoMoviendose == true 
				|| (EnemigoActual->PosX > Juego->Jugador[idJugador].PosX + SCREEN_W/3- 15 
				&& EnemigoActual->PosX  < Juego->Jugador[idJugador].PosX + SCREEN_W/3+15) 
				|| (EnemigoActual->PosX +  EnemigoActual->AnchoDividido > Juego->Jugador[idJugador].PosX - SCREEN_W/3-5 
				&& EnemigoActual->PosX + EnemigoActual->AnchoDividido <	 Juego->Jugador[idJugador].PosX))
			{
				EnemigoActual->SwitchFrame = 18;
				EnemigoActual->Disparando = true;
				EnemigoActual->DisparandoMoviendose = false;

				if(EnemigoActual->PosX + EnemigoActual->AnchoDividido/2 < Juego->PosActualBuffer)
				{
					EnemigoActual->Disparando = false;
					EnemigoActual->DisparandoMoviendose = true;
					EnemigoActual->PosX += MoveSpeed;

					if(EnemigoActual->IdSprite == Tanque )
					{
						EnemigoActual->CurrentFrame[1] = DispararMoviendoseDerecha;
						EnemigoActual->FrameX = DispararMoviendoseDerecha;
						EnemigoActual->SwitchFrame = 15;
					}
					else
					{
						EnemigoActual->CurrentFrame[1] = CaminarDerecha;
						EnemigoActual->FrameX = CaminarDerecha;
						EnemigoActual->SwitchFrame = 6;
					}

					EnemigoActual->AnguloDisparo = 0;
				}
				else if(EnemigoActual->PosX  > Juego->Jugador[idJugador].PosX)
				{//Cuando el enemigo está mas en la derecha que el jugador el enemigo apunta a la izquierda;
					EnemigoActual->CurrentFrame[1] = DispararIzquierda;
					EnemigoActual->FrameX = DispararIzquierda;
					EnemigoActual->AnguloDisparo = ANGULO_SUP*2;
				}
				else
				{//Cuando el enemigo está mas en la izquierda que el jugador el enemigo apunta a la derecha;
					EnemigoActual->CurrentFrame[1] = DispararDerecha;
					EnemigoActual->FrameX = DispararDerecha;
					EnemigoActual->AnguloDisparo = 0;
				}

				//Cuando el tiempo que debe de durar el enemigo 
				if(TiempoEntreDisparos > EnemigoActual->Arma.TiempoDisparar)
					Disparar(Juego, EnemigoActual);
			}
			else if(EnemigoActual->PosX > Juego->Jugador[idJugador].PosX + Juego->Jugador[idJugador].AnchoDividido)
			{
				EnemigoActual->PosX -= MoveSpeed;
				EnemigoActual->CurrentFrame[1] = CaminarIzquierda;
				EnemigoActual->FrameX = CaminarIzquierda;
			}
			if(EnemigoActual->PosX  < Juego->Jugador[idJugador].PosX && EnemigoActual->PosX < Juego->PosActualBuffer && EnemigoActual->IdSprite != Tanque)
			{
				if(EnemigoActual->PosX + EnemigoActual->AnchoDividido/2  < Juego->PosActualBuffer)
					EnemigoActual->PosX += 2;
				EnemigoActual->PosX += MoveSpeed;
				EnemigoActual->CurrentFrame[1] = CaminarDerecha;
				EnemigoActual->FrameX = CaminarDerecha;
				EnemigoActual->SwitchFrame = 8;
			}

			if(EnemigoActual->IdSprite == Tanque)
			{
				if(EnemigoActual->PosX + EnemigoActual->AnchoDividido < Juego->Jugador[idJugador].PosX - 20)
				{
					EnemigoActual->PosX += MoveSpeed;
					EnemigoActual->CurrentFrame[1] = CaminarDerecha;
					EnemigoActual->FrameX = CaminarDerecha;
				}
			}
			//Animación de sprites:
			if(EnemigoActual->Moviendose)
			{
				EnemigoActual->FrameCounter++;
				if(EnemigoActual->FrameCounter >= EnemigoActual->SwitchFrame)
				{
					if(EnemigoActual->CurrentFrame[0] /*+ Juego->Jugador[0].AnchoDividido*/ >= EnemigoActual->SpriteCaracter->w)
						EnemigoActual->CurrentFrame[0] = 0;
					else
						EnemigoActual->CurrentFrame[0] += EnemigoActual->AnchoDividido;
					EnemigoActual->FrameCounter = 0;
				}
				if(EnemigoActual->CurrentFrame[0] >= EnemigoActual->SpriteCaracter->w)
					EnemigoActual->CurrentFrame[0] = 0;
			}
			else
			{
				EnemigoActual->CurrentFrame[0] = 0;
				EnemigoActual->FrameCounter = 0;
			}
		}
	}
}

void CrearVillano(TJUEGO* Juego, eIdCaracter IDCaracter)
{
	TCARACTER* NuevoEnemigo = new TCARACTER(); 
	NuevoEnemigo->Id = Villano;
	NuevoEnemigo->Vidas = 1;
	switch (IDCaracter)
	{
	case Villano: 
		NuevoEnemigo->HP = 5;
		NuevoEnemigo->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 23))->data;
		NuevoEnemigo->FactorAtaque = 2;
		NuevoEnemigo->FactorDefensa = 5;
		NuevoEnemigo->FrameX = 4;
		NuevoEnemigo->FrameY = 8;
		NuevoEnemigo->ScoreCaracter = 5;
		NuevoEnemigo->Arma.BalaSprite = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 10))->data;
		NuevoEnemigo->Arma.EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 7))->data;
		NuevoEnemigo->Arma.FactorAtaque = 1;
		NuevoEnemigo->Arma.TiempoDisparar = 1;
		NuevoEnemigo->Arma.VelocidadAtaqueEscalar = 120;
		NuevoEnemigo->Arma.AceleracionBalaY = ACEL_GRAVEDAD*-1;
		NuevoEnemigo->IdSprite = Villano;
		NuevoEnemigo->Id = Villano;
		break;
	case VillanoRodante:
		NuevoEnemigo->HP = 10;
		NuevoEnemigo->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 24))->data;
		NuevoEnemigo->FactorAtaque = 2;
		NuevoEnemigo->FactorDefensa = 5;
		NuevoEnemigo->FrameX = 6;
		NuevoEnemigo->FrameY = 8;
		NuevoEnemigo->ScoreCaracter = 10;
		NuevoEnemigo->Arma.BalaSprite = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 11))->data;
		NuevoEnemigo->Arma.EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 8))->data;
		NuevoEnemigo->Arma.FactorAtaque = 5;
		NuevoEnemigo->Arma.TiempoDisparar = 1.5;
		NuevoEnemigo->Arma.VelocidadAtaqueEscalar = 150;
		NuevoEnemigo->IdSprite = VillanoRodante;
		NuevoEnemigo->Id = VillanoRodante;
		NuevoEnemigo->AcelaracionY = 0;
		NuevoEnemigo->Arma.AceleracionBalaY = ACEL_GRAVEDAD*-1;
		break;
	case Tanque:
		NuevoEnemigo->HP = 40;
		NuevoEnemigo->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 22))->data;
		NuevoEnemigo->FactorAtaque = 10;
		NuevoEnemigo->FactorDefensa = 5;
		NuevoEnemigo->FrameX = 3;
		NuevoEnemigo->FrameY = 12;
		NuevoEnemigo->ScoreCaracter = 15;
		NuevoEnemigo->Arma.BalaSprite = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 12))->data;
		NuevoEnemigo->Arma.EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 9))->data;
		NuevoEnemigo->Arma.TiempoDisparar = 1.5;
		NuevoEnemigo->Arma.VelocidadAtaqueEscalar = 300;
		NuevoEnemigo->IdSprite = Tanque;
		NuevoEnemigo->Id = Tanque;
		NuevoEnemigo->AcelaracionY = 0;
		NuevoEnemigo->Arma.AceleracionBalaY = ACEL_GRAVEDAD*-1;
		break;
	case Nave:
		NuevoEnemigo->HP = 40;
		NuevoEnemigo->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 19))->data;
		NuevoEnemigo->FactorAtaque = 20;
		NuevoEnemigo->FactorDefensa = 5;
		NuevoEnemigo->PosXInicial = Juego->PosActualBuffer + SCREEN_W/2;
		NuevoEnemigo->PosX = NuevoEnemigo->PosXInicial;
		NuevoEnemigo->FrameX = 4;
		NuevoEnemigo->FrameY = 8;
		NuevoEnemigo->ScoreCaracter = 20;
		NuevoEnemigo->Arma.BalaSprite = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 13))->data;
		NuevoEnemigo->Arma.EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 10))->data;
		NuevoEnemigo->Arma.FactorAtaque = 15;
		NuevoEnemigo->Arma.TiempoDisparar = 0.5;
		NuevoEnemigo->Arma.VelocidadAtaqueEscalar = 5;
		NuevoEnemigo->VelocidadXInicial = -200;
		NuevoEnemigo->VelocidadX = NuevoEnemigo->VelocidadXInicial;
		NuevoEnemigo->AcelaracionY = -590;
		NuevoEnemigo->AcelaracionX = -300;
		NuevoEnemigo->TiempoCalculadoVelocidadX = 0;
		NuevoEnemigo->IdSprite = Nave;
		NuevoEnemigo->Id = Nave;
		NuevoEnemigo->BombasLanzadas = 0;
		NuevoEnemigo->AnguloDisparo = 270;
		NuevoEnemigo->Arma.AceleracionBalaY = 0;

		break;
	}
	NuevoEnemigo->AnchoDividido = NuevoEnemigo->SpriteCaracter->w/NuevoEnemigo->FrameX;
	NuevoEnemigo->AltoDividido = NuevoEnemigo->SpriteCaracter->h/NuevoEnemigo->FrameY;
	NuevoEnemigo->PosY = 0 - NuevoEnemigo->AltoDividido;
	NuevoEnemigo->Ancho = NuevoEnemigo->SpriteCaracter->w;
	NuevoEnemigo->Alto = NuevoEnemigo->SpriteCaracter->h;
	if(NuevoEnemigo->IdSprite != Nave)
	{
		if((rand() % 3) == 0)
			NuevoEnemigo->PosX = Juego->PosActualBuffer - SCREEN_W/2 - NuevoEnemigo->AnchoDividido;
		else
			NuevoEnemigo->PosX = Juego->PosActualBuffer + SCREEN_W + SCREEN_W/2;
	}
	NuevoEnemigo->PosYSalto = NuevoEnemigo->PosY;
	NuevoEnemigo->VelocidadX = NuevoEnemigo->VelocidadY = 0;
	//NuevoEnemigo->IdSprite = 1;
	NuevoEnemigo->TimepoUltimoCalculadoPosY = 0;
	NuevoEnemigo->CurrentFrame[0] = 0;
	NuevoEnemigo->CurrentFrame[1] = 0;
	NuevoEnemigo->FrameCounter = 0;
	NuevoEnemigo->SwitchFrame = 6;
	NuevoEnemigo->TiempoDisparo = 0;
	NuevoEnemigo->Arma.Id = 0;
	NuevoEnemigo->Arma.RangoAtaque = SCREEN_W/2;
	NuevoEnemigo->Moviendose = true;
	NuevoEnemigo->DisparandoMoviendose = false;
	NuevoEnemigo->Disparando = false;
	NuevoEnemigo->TimepoUltimoCalculadoPosY = clock();

	CrearNodo(&Juego->Enemigos, NuevoEnemigo, true);


}

bool ExisteColision(TJUEGO* Juego, TCARACTER *primero, TCARACTER *segundo, eDireccionColision direccionColision, float tiempoActual, int idJugador)
{
	// En las siguientes líneas se implementa la lógica de colisiones entre
	// dos o más objetos.
	if(direccionColision == Todos)
	{
		int AltoActual = primero->AltoDividido;
		int PosYActual = primero->PosY;

		if(primero->IdSprite == Jugador)
		{
			if(Juego->Jugador[idJugador].EnElPiso == true)
			{
				AltoActual = 42;
				PosYActual = primero->PosY + 40;
			}
		}

		if((primero->PosX < (segundo->PosX + segundo->AnchoDividido)) &&
			(PosYActual < (segundo->PosY + segundo->AltoDividido)) &&
			(segundo->PosX < (primero->PosX + primero->AnchoDividido)) &&
			(segundo->PosY < (PosYActual + AltoActual)))
		{
			return true;
		}
	}
	else if (direccionColision == DesdeAbajo)
	{
		float tiempoAlturaMaxima = (Juego->Jugador[idJugador].VelocidadYSalto*2.5*-1)/ACEL_GRAVEDAD;

		if(tiempoActual >= tiempoAlturaMaxima && (primero->PosY + primero->AltoDividido >= segundo->PosY && primero->PosY + primero->AltoDividido <= segundo->PosY + 50) && (primero->PosX + primero->AnchoDividido >= segundo->PosX && primero->PosX <= segundo->PosX + segundo->AnchoDividido))/*
																																																																								 &&primero->PosY + primero->AltoDividido <= segundo->PosY + segundo->Alto/2 + (segundo->Alto/2)/2)
																																																																								 /*- 30 && primero->PosY <= segundo->PosY - 20
																																																																								 && primero->PosX <= segundo->PosX + segundo->Ancho && primero->PosX >= segundo->PosX)*/
																																																																								 //CarreteraActual->PosY + CarreteraActual->Alto/2 + (CarreteraActual->Alto/2)/2 - Caracter->AltoDividido;
		{			
			return true;
		}
	}
	else if(direccionColision == DesdeDerecha)
	{
		//if(primero->PosX + primero->AnchoDividido >= segundo->PosX && segundo->PosX > (primero->PosX + primero->AnchoDividido) 
		//&& primero->PosY + primero->AltoDividido > segundo->PosY-5)
		if(primero->PosX < segundo->PosX + segundo->AnchoDividido && segundo->PosX < (primero->PosX + primero->AnchoDividido) 
			&& primero->PosY + primero->AltoDividido > segundo->PosY)	
			return true;
	}
	else if(direccionColision == DesdeIzquierda)
	{
		if(	primero->PosX <= segundo->PosX + segundo->AnchoDividido && segundo->PosX + segundo->AnchoDividido > (primero->PosX - 5) 
			&& primero->PosY + primero->AltoDividido > segundo->PosY)
			return true;
	}

	return false;

}

void ActualizarFondo(TJUEGO* Juego)
{

	if(Juego->PosActualBuffer%SCREEN_W == 0 && (Juego->PosActualBuffer != Juego->PosActualBufferFondo))
	{
		Juego->PosActualBufferFondo = Juego->PosActualBuffer;
		TCARACTER* Fondo = new TCARACTER();
		Fondo->SpriteCaracter = load_png("CityBackground.png", NULL);
		Fondo->Ancho = Fondo->SpriteCaracter->w;
		Fondo->Alto = Fondo->SpriteCaracter->h;
		Fondo->PosX = Juego->PosActualBuffer + SCREEN_W;
		Fondo->PosY = 0 ;

		CrearNodo(&Juego->Fondo, Fondo, true);
	}

	//Eliminar cada sprite del fondo que se quedó atrás.
	TCARACTER* PrimerFondo = (TCARACTER*)(BuscarNodoIndice(&(Juego->Fondo), 0)->data);
	if(PrimerFondo->PosX + PrimerFondo->SpriteCaracter->w < Juego->PosActualFondo)
		EliminarNodo(&Juego->Fondo, PrimerFondo);
}

void ActualizarCarretera(TJUEGO* Juego)
{
	/*for(int i=0; i<Juego->Carretera.cantidad; i++)
	{
	TCARACTER* CarreteraActual = (TCARACTER*)(BuscarNodoIndice(&(Juego->Carretera), i)->data);
	if(Juego->PosActualBuffer + CarreteraActual->SpriteCaracter->w >= CarreteraActual->PosX + CarreteraActual->SpriteCaracter->w && Juego->PosActualBuffer + CarreteraActual->SpriteCaracter->w <= CarreteraActual->PosX + CarreteraActual->SpriteCaracter->w + MoveSpeed)
	{
	TCARACTER* CarreteraNueva = new TCARACTER();
	CarreteraNueva->SpriteCaracter = load_png("Calle2.png", NULL);
	CarreteraNueva->Ancho = CarreteraNueva->SpriteCaracter->w;
	CarreteraNueva->Alto = CarreteraNueva->SpriteCaracter->h;
	CarreteraNueva->PosX = CarreteraActual->PosX + CarreteraActual->SpriteCaracter->w;
	CarreteraNueva->PosY = SCREEN_H - CarreteraNueva->SpriteCaracter->h;

	CrearNodo(&Juego->Carretera, CarreteraNueva, true);
	}
	}*/

	//Eliminar las carreteras que ya no estan en la pantalla, las que se quedaron atras.
	TCARACTER* PrimeraCarretera = (TCARACTER*)(BuscarNodoIndice(&(Juego->Carretera), 0)->data);
	if(PrimeraCarretera->PosX + PrimeraCarretera->SpriteCaracter->w < Juego->PosActualBuffer)
		EliminarNodo(&Juego->Carretera, PrimeraCarretera);
}

void RestarHP(TJUEGO* Juego, TCARACTER* Caracter, TCARACTER* Proyectil, int idJugador)
{
	Caracter->HP = (Caracter->HP - Proyectil->FactorAtaque) + Caracter->FactorDefensa;

	//Cuando al caracter ya no le queda hp.
	if(Caracter->HP <= 0)
	{
		if(Caracter->IdSprite == Jugador)
		{//Cuando es el jugador principal.
			Caracter->Vidas--;
			if((Juego->CantidadJugadores == 2 && Juego->Jugador[0].Vidas<= 0 && Juego->Jugador[1].Vidas<= 0 )|| (Juego->CantidadJugadores == 1 && Juego->Jugador[0].Vidas<= 0))
				Juego->GameOver=true;
			Juego->PerdioVida=true;
			Juego->TiempoPerdioVida=clock();
			if(Caracter->Vidas <= 0)
			{
				Caracter->HP=0;
			}
			if(Caracter->Vidas > 0)
			{//Si todavia le quedan vidas.
				Caracter->HP = HP_TOTAL;
				Caracter->TimepoUltimoCalculadoPosY = clock();
				Caracter->PosY = 0;
				Caracter->VelocidadY = 0;
				Caracter->Saltando = true;
			}

		}
		else if(Caracter->IdSprite == Item)
		{//Cuando es un item se determina cual es para realizar la función que hace dicho item.
			TCARACTER* ItemInfo = (TCARACTER*)(BuscarNodoIndice(&(Juego->Items), 0)->data);
			ItemInfo->TiempoDisparo = clock();
			play_sample(Caracter->Arma.EfectoSonido, 400, 128, 1000, false);
			//play_sample(Caracter->Arma.EfectoSonido, 250, 128, 1000, false); 	
			switch(Caracter->Id)
			{
			case AumentaAtaque:
				Juego->Jugador[idJugador].FactorAtaque += 1;
				ItemInfo->CurrentFrame[1] = AumentaAtaque;
				ItemInfo->FrameX = AumentaAtaque;
				break;
			case AumentaDefensa:
				ItemInfo->CurrentFrame[1] = AumentaDefensa;
				ItemInfo->FrameX = AumentaDefensa;
				Juego->Jugador[idJugador].FactorDefensa += 1;
				break;
			case AumentaHP:
				ItemInfo->CurrentFrame[1] = AumentaHP;
				ItemInfo->FrameX = AumentaHP;
				if(Juego->Jugador[idJugador].HP < HP_TOTAL && Juego->Jugador[idJugador].HP >= HP_TOTAL-20)
					Juego->Jugador[idJugador].HP = HP_TOTAL;
				else
					Juego->Jugador[idJugador].HP += 20;
				break;
			case Bomba:
				for(int i=0; i<Juego->Enemigos.cantidad;)
				{
					TCARACTER* EnemigoActual = (TCARACTER*)BuscarNodoIndice(&Juego->Enemigos, i)->data;
					EliminarNodo(&Juego->Enemigos, EnemigoActual);
					Juego->EnemigosEnJuego --;
					Juego->EnemigosEliminados ++;
				}
				ItemInfo->CurrentFrame[1] = Bomba;
				ItemInfo->FrameX = Bomba;
				Juego->Jugador[idJugador].Saltando = true;
				Juego->Jugador[idJugador].VelocidadYSalto = 0;
				Juego->Jugador[idJugador].TimepoUltimoCalculadoPosY = clock();
				break;
			}
			EliminarNodo(&Juego->Items, Caracter);
		}
		else 
		{
			for(int ju=0; ju < Juego->CantidadJugadores; ju++)
			{
				if(Juego->Jugador[ju].Vidas <=0)
					continue;
				if(Caracter->IdSprite == Tanque && ExisteColision(Juego, &(Juego->Jugador[ju]), Caracter, DesdeAbajo, 0, ju))
				{//Cuando está encima de un taque y se destruye el jugador debe de caer al piso. Se asigna el tiempo.
					Juego->Jugador[ju].TimepoUltimoCalculadoPosY = clock();
					Juego->Jugador[ju].VelocidadYSalto = 0;
				}
			}
			EliminarNodo(&Juego->Enemigos, Caracter);
			Juego->Jugador[Proyectil->IdJugador].ScoreJugador += Caracter->ScoreCaracter;
			Juego->EnemigosEliminados++;
			Juego->EnemigosEnJuego--;
			if(Caracter->Id == Jefe)
				Juego->Win = true;
		}
	}
}

void ActualizarItems(TJUEGO* Juego)
{
	float TiempoPorItem = (clock() - Juego->TiempoSalidaItem)/CLOCKS_PER_SEC;

	//Aparición de los items:
	if(TiempoPorItem > SALIDA_ITEM && !Juego->ContraElJefe)//Si el tiempo transcurrido entre un item y otro es 40 saldrá otro item.
	{
		Juego->TiempoSalidaItem = clock();
		int ItemASalir = rand() % 10;

		if(ItemASalir >= 8 && ItemASalir <= 9)// 2/10 oportunidad
		{
			//Item es un aumenta defensa:
			//Creando el item:
			TCARACTER* ItemNuevo = new TCARACTER();

			ItemNuevo->HP = 3;
			ItemNuevo->Id = AumentaDefensa;
			ItemNuevo->IdSprite = Item;
			ItemNuevo->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 27))->data;
			ItemNuevo->Alto = ItemNuevo->SpriteCaracter->h;
			ItemNuevo->Ancho = ItemNuevo->SpriteCaracter->w;
			ItemNuevo->FrameX = 4;
			ItemNuevo->FrameY = 2;
			ItemNuevo->AnchoDividido = ItemNuevo->Ancho/ItemNuevo->FrameX;
			ItemNuevo->AltoDividido = ItemNuevo->Alto/ItemNuevo->FrameY;
			ItemNuevo->PosXInicial = Juego->PosActualBuffer - ItemNuevo->AnchoDividido;
			ItemNuevo->PosX = Juego->PosActualBuffer - ItemNuevo->AnchoDividido;
			ItemNuevo->PosYInicial = 50;
			ItemNuevo->PosY = ItemNuevo->PosYInicial;
			ItemNuevo->VelocidadX = 70*PPM;
			ItemNuevo->TiempoCalculadoVelocidadX = clock();
			ItemNuevo->TiempoCalculadoVelocidadY = clock();
			ItemNuevo->VelocidadY = 5*PPM;
			ItemNuevo->SwitchFrame = 5;
			ItemNuevo->CurrentFrame[1] = 0;
			ItemNuevo->FrameCounter = 0;
			ItemNuevo->Arma.EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 0))->data;

			CrearNodo(&Juego->Items, ItemNuevo, true);
		}
		else if(ItemASalir >= 1 && ItemASalir <= 4)// 4/10 oportunidad.
		{
			//Item es un aumenta HP:
			TCARACTER* ItemNuevo = new TCARACTER();

			ItemNuevo->HP = 3;
			ItemNuevo->Id = AumentaHP;
			ItemNuevo->IdSprite = Item;
			ItemNuevo->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 27))->data;
			ItemNuevo->Alto = ItemNuevo->SpriteCaracter->h;
			ItemNuevo->Ancho = ItemNuevo->SpriteCaracter->w;
			ItemNuevo->FrameX = 4;
			ItemNuevo->FrameY = 2;
			ItemNuevo->AnchoDividido = ItemNuevo->Ancho/ItemNuevo->FrameX;
			ItemNuevo->AltoDividido = ItemNuevo->Alto/ItemNuevo->FrameY;
			ItemNuevo->PosXInicial = Juego->PosActualBuffer - ItemNuevo->AnchoDividido;
			ItemNuevo->PosX = Juego->PosActualBuffer - ItemNuevo->AnchoDividido;
			ItemNuevo->PosYInicial = 50;
			ItemNuevo->PosY = ItemNuevo->PosYInicial;
			ItemNuevo->VelocidadX = 90*PPM;
			ItemNuevo->TiempoCalculadoVelocidadX = clock();
			ItemNuevo->TiempoCalculadoVelocidadY = clock();
			ItemNuevo->VelocidadY = 5*PPM;
			ItemNuevo->SwitchFrame = 5;
			ItemNuevo->CurrentFrame[1] = 0;
			ItemNuevo->FrameCounter = 0;
			ItemNuevo->Arma.EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 0))->data;

			CrearNodo(&Juego->Items, ItemNuevo, true);
		}
		else if(ItemASalir == 0)// 1/10 oportunidad.
		{
			//Item es un aumenta ataque:
			TCARACTER* ItemNuevo = new TCARACTER();

			ItemNuevo->HP = 3;
			ItemNuevo->Id = AumentaAtaque;
			ItemNuevo->IdSprite = Item;
			ItemNuevo->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 27))->data;
			ItemNuevo->Alto = ItemNuevo->SpriteCaracter->h;
			ItemNuevo->Ancho = ItemNuevo->SpriteCaracter->w;
			ItemNuevo->FrameX = 4;
			ItemNuevo->FrameY = 2;
			ItemNuevo->AnchoDividido = ItemNuevo->Ancho/ItemNuevo->FrameX;
			ItemNuevo->AltoDividido = ItemNuevo->Alto/ItemNuevo->FrameY;
			ItemNuevo->PosXInicial = Juego->PosActualBuffer - ItemNuevo->AnchoDividido;
			ItemNuevo->PosX = Juego->PosActualBuffer - ItemNuevo->AnchoDividido;
			ItemNuevo->PosYInicial = 50;
			ItemNuevo->PosY = ItemNuevo->PosYInicial;
			ItemNuevo->VelocidadX = 90*PPM;
			ItemNuevo->TiempoCalculadoVelocidadX = clock();
			ItemNuevo->TiempoCalculadoVelocidadY = clock();
			ItemNuevo->VelocidadY = 5*PPM;
			ItemNuevo->SwitchFrame = 5;
			ItemNuevo->CurrentFrame[1] = 0;
			ItemNuevo->FrameCounter = 0;
			ItemNuevo->Arma.EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 0))->data;

			CrearNodo(&Juego->Items, ItemNuevo, true);
		}
		else if(ItemASalir >= 5 && ItemASalir <= 7)// 3/10 oportunidad.
		{
			//Item es una bomba que destruye a todos los enemigos a la vista.
			TCARACTER* ItemNuevo = new TCARACTER();

			ItemNuevo->HP = 3;
			ItemNuevo->Id = Bomba;
			ItemNuevo->IdSprite = Item;
			ItemNuevo->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 27))->data;
			ItemNuevo->Alto = ItemNuevo->SpriteCaracter->h;
			ItemNuevo->Ancho = ItemNuevo->SpriteCaracter->w;
			ItemNuevo->FrameX = 4;
			ItemNuevo->FrameY = 2;
			ItemNuevo->AnchoDividido = ItemNuevo->Ancho/ItemNuevo->FrameX;
			ItemNuevo->AltoDividido = ItemNuevo->Alto/ItemNuevo->FrameY;
			ItemNuevo->PosXInicial = Juego->PosActualBuffer - ItemNuevo->AnchoDividido;
			ItemNuevo->PosX = Juego->PosActualBuffer - ItemNuevo->AnchoDividido;
			ItemNuevo->PosYInicial = 50;
			ItemNuevo->PosY = ItemNuevo->PosYInicial;
			ItemNuevo->VelocidadX = 90*PPM;
			ItemNuevo->TiempoCalculadoVelocidadX = clock();
			ItemNuevo->TiempoCalculadoVelocidadY = clock();
			ItemNuevo->VelocidadY = 5*PPM;
			ItemNuevo->SwitchFrame = 5;
			ItemNuevo->CurrentFrame[1] = 0;
			ItemNuevo->FrameCounter = 0;
			ItemNuevo->Arma.EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 1))->data;

			CrearNodo(&Juego->Items, ItemNuevo, true);

		}
	}

	//Darle movimiento a los items:
	for(int i=0; i<Juego->Items.cantidad; i++)
	{
		TCARACTER* ItemActual = (TCARACTER*)(BuscarNodoIndice(&(Juego->Items), i)->data);
		float tiempoActual = (clock() - ItemActual->TiempoCalculadoVelocidadX) / CLOCKS_PER_SEC;

	//	if(i!=0)
		{
			int PosYMinima = 100, PosYMaxima = 50;
			//ItemActual->CurrentFrame[1] = 0;
			//ItemActual->FrameX = 0;

			if(ItemActual->PosY >= PosYMinima)//Los mas abajo que puede estar.
			{
				ItemActual->VelocidadY = -10*PPM;
				ItemActual->TiempoCalculadoVelocidadY = clock();
				ItemActual->PosYInicial = PosYMinima-1;
			}
			else if(ItemActual->PosY <= PosYMaxima)//Lo mas alto que puede estar.
			{
				ItemActual->TiempoCalculadoVelocidadY = clock();
				ItemActual->PosYInicial = PosYMaxima+1;
				ItemActual->VelocidadY = 10*PPM;
			}

			ItemActual->PosX = ItemActual->PosXInicial + ItemActual->VelocidadX*tiempoActual;// + 0.5*3*tiempoActual*tiempoActual;

			tiempoActual = (clock() - ItemActual->TiempoCalculadoVelocidadY) / CLOCKS_PER_SEC;
			ItemActual->PosY = ItemActual->PosYInicial + ItemActual->VelocidadY*tiempoActual;// + 0.5*3*tiempoActual*tiempoActual;

			//Animación del item:
			ItemActual->FrameCounter++;
			if(ItemActual->FrameCounter >= ItemActual->SwitchFrame)
			{
				if(ItemActual->CurrentFrame[0]  >= ItemActual->SpriteCaracter->w)
					ItemActual->CurrentFrame[0] = 0;
				else
					ItemActual->CurrentFrame[0] += ItemActual->AnchoDividido;
				ItemActual->FrameCounter = 0;
			}
			if(ItemActual->CurrentFrame[0] >= ItemActual->SpriteCaracter->w)
				ItemActual->CurrentFrame[0] = 0;

			if(ItemActual->PosX > Juego->PosActualBuffer + SCREEN_W)
				EliminarNodo(&Juego->Items, ItemActual);
		}

		TiempoPorItem = (clock() - ItemActual->TiempoDisparo)/CLOCKS_PER_SEC;//Este tiempo es para la duracion del mensaje en la pantalla. Reutilización de variable.

		if(ItemActual->CurrentFrame[1] != -1 && i==0)
		{//Cuando se debe de presentar la información del item seleccionado:
			ItemActual->PosX = SCREEN_W/2 - ItemActual->AnchoDividido/2 + Juego->PosActualBuffer;
			ItemActual->FrameCounter++;
			if(ItemActual->FrameCounter >= ItemActual->SwitchFrame)
			{
				if(ItemActual->CurrentFrame[0]  >= ItemActual->SpriteCaracter->w)
					ItemActual->CurrentFrame[0] = 0;
				else
					ItemActual->CurrentFrame[0] += ItemActual->AnchoDividido;
				ItemActual->FrameCounter = 0;
			}
			if(ItemActual->CurrentFrame[0] >= ItemActual->SpriteCaracter->w)
				ItemActual->CurrentFrame[0] = 0;
		}
		if(ItemActual->CurrentFrame[1] != -1 && TiempoPorItem > 2 && i==0)
		{
			ItemActual->CurrentFrame[0] = 0;
			ItemActual->CurrentFrame[1] = -1;
			ItemActual->FrameCounter = 0;
		} 
	}
}

void CaidaConGravedad(TJUEGO* Juego, TCARACTER* Caracter, float TiempoDelSalto, int idJugador)
{
	for(int i=0; i<3; i++)
	{
		TCARACTER* CarreteraActual = (TCARACTER*)(BuscarNodoIndice(&(Juego->Carretera), i)->data);
		if(Caracter->PosY + Caracter->AltoDividido > CarreteraActual->PosY)
			//if(ExisteColision(Juego, &(Juego->Jugador), CarreteraActual, DesdeAbajo, TiempoDelSalto) == true)
		{
			Caracter->PosY = CarreteraActual->PosY - Caracter->AltoDividido;
			Caracter->TimepoUltimoCalculadoPosY = 0;
			Caracter->VelocidadYSalto = 0;
			if(Caracter->Id == ArmaACoger)
				Caracter->AcelaracionY = -ACEL_GRAVEDAD;
			else if(Caracter->Id == Tapa)
				Caracter->Exploto = false;
			break;
		}
		else if(i+1 == 3)
		{
			if(Caracter->IdSprite == Nave && Caracter->HP>0)//Cuando es la nave desciende y se ve el sprite completo en la pantalla. La aceleración será contraria a la gravedad y con misma magnitud para que se quede en  un mismo sitio.
				if(Caracter->PosY > 0)
					Caracter->AcelaracionY = ACEL_GRAVEDAD*-1;
			Caracter->PosY = Caracter->PosY + 0.5*(ACEL_GRAVEDAD+Caracter->AcelaracionY)*pow(TiempoDelSalto, 2) + Caracter->VelocidadYSalto*TiempoDelSalto;
			break;
		}
	}
	if(Caracter->IdSprite == Jugador)
	{
		for(int i=0; i<Juego->Enemigos.cantidad; i++)
		{
			TCARACTER* EnemigoActual = (TCARACTER*)(BuscarNodoIndice(&(Juego->Enemigos), i)->data);
			if(EnemigoActual->IdSprite == Tanque)
			{
				if(ExisteColision(Juego, Caracter, EnemigoActual, DesdeAbajo, TiempoDelSalto,idJugador) && TiempoDelSalto >=  (Juego->Jugador[idJugador].VelocidadYSalto * -1)/ACEL_GRAVEDAD)
				{
					Caracter->PosY = EnemigoActual->PosY - Caracter->AltoDividido;
					Caracter->TimepoUltimoCalculadoPosY = 0;
					Caracter->VelocidadYSalto = 0;
					break;
				}
			}
		}

		if(Juego->ContraElJefe == true)
		{
			for(int i=0; i<=1; i++)
			{
				if(ExisteColision(Juego, Caracter, &Juego->Plataformas[i], DesdeAbajo, TiempoDelSalto, idJugador) && TiempoDelSalto >=  (Juego->Jugador[idJugador].VelocidadYSalto * -1)/ACEL_GRAVEDAD)
				{
					Caracter->PosY =  Juego->Plataformas[i].PosY - Caracter->AltoDividido;
					Caracter->TimepoUltimoCalculadoPosY = 0;
					Caracter->VelocidadYSalto = 0;
					break;
				}
			}
		}
	}
}

void AnguloDeDisparo(TJUEGO* Juego, int idJugador)
{
	for(int j=0; j<=TOTAL_ANGULOS; j++)
	{
		if(Juego->Jugador[idJugador].AnguloDisparo == j)
		{
			if(j>ANGULO_SUP && j<ANGULO_INF) 
			{
				Juego->Jugador[idJugador].CurrentFrame[1] = (j+DIF_ANGULOS)/DIF_ANGULOS;
				Juego->Jugador[idJugador].FrameX = (j+DIF_ANGULOS)/DIF_ANGULOS;
			}
			else if(j>=270)
			{
				Juego->Jugador[idJugador].CurrentFrame[1] = (j+30)/DIF_ANGULOS;
				Juego->Jugador[idJugador].FrameX = (j+DIF_ANGULOS*2)/DIF_ANGULOS;
			}
			else
			{
				Juego->Jugador[idJugador].CurrentFrame[1] = j/DIF_ANGULOS;
				Juego->Jugador[idJugador].FrameX = j/DIF_ANGULOS;
			}
			break;
		}
	}
}

void ActualizarNave(TJUEGO* Juego, TCARACTER* EnemigoActual, float TiempoEntreDisparos)
{
	float TiempoActual;

	if(EnemigoActual->PosY > 0)
	{
		//Cuando la nave desciende:
		if(EnemigoActual->TiempoCalculadoVelocidadX == 0)
			EnemigoActual->TiempoCalculadoVelocidadX = clock();

		if(EnemigoActual->PosX <= Juego->PosActualBuffer - EnemigoActual->AnchoDividido/2)
		{//Cuando la nave llega al límite izquierdo de la pantalla:
			EnemigoActual->TiempoCalculadoVelocidadX = clock();
			EnemigoActual->PosXInicial = Juego->PosActualBuffer - EnemigoActual->AnchoDividido/2 + 6;
			EnemigoActual->VelocidadXInicial = VELOCIDAD_X_NAVE;
		}
		else if(EnemigoActual->PosX + EnemigoActual->AnchoDividido >= Juego->PosActualBuffer + SCREEN_W)
		{//Cuando la nave llega al límite derecho de la pantalla:
			EnemigoActual->TiempoCalculadoVelocidadX = clock();
			EnemigoActual->PosXInicial = Juego->PosActualBuffer + SCREEN_W - EnemigoActual->AnchoDividido -1;
			EnemigoActual->VelocidadXInicial = -VELOCIDAD_X_NAVE;
		}

		if(TiempoEntreDisparos > EnemigoActual->Arma.TiempoDisparar && EnemigoActual->BombasLanzadas < 10)
		{
			Disparar(Juego, EnemigoActual);
			EnemigoActual->BombasLanzadas++;
			if(EnemigoActual->CurrentFrame[1] == SoloVolar)
				EnemigoActual->CurrentFrame[1] = AbrirCompuerta;
		}
		else if(EnemigoActual->CurrentFrame[1] == Atacar)
			EnemigoActual->CurrentFrame[1] = CerrarCompuerta;

		if(TiempoEntreDisparos > 3 && EnemigoActual->BombasLanzadas == 10)
			EnemigoActual->BombasLanzadas = 0;

		TiempoActual = (clock() - EnemigoActual->TiempoCalculadoVelocidadX)/CLOCKS_PER_SEC;

		//Calcular la posción de la nave de acuerdo con el tiempo:
		EnemigoActual->PosX = EnemigoActual->PosXInicial + EnemigoActual->VelocidadXInicial*TiempoActual;

	}
	if(EnemigoActual->CurrentFrame[1] > Atacar)
	{//Esto se cumple cuando una bala colisiona con la nave, ahí se muestra la nave roja. Aquí vuelvo a ponerla del color normal:
		EnemigoActual->CurrentFrame[1] -= EnemigoActual->FrameY/2; 
		EnemigoActual->FrameX -= EnemigoActual->FrameY/2;
	}

	EnemigoActual->SwitchFrame = 3;
	EnemigoActual->FrameCounter++;

	//Hacer la animación del sprite sheet:
	if(EnemigoActual->FrameCounter >= EnemigoActual->SwitchFrame)
	{
		if(EnemigoActual->CurrentFrame[0] >= EnemigoActual->SpriteCaracter->w)
			EnemigoActual->CurrentFrame[0] = 0;
		else
			EnemigoActual->CurrentFrame[0] += EnemigoActual->AnchoDividido;
		EnemigoActual->FrameCounter = 0;
	}
	if(EnemigoActual->CurrentFrame[0] >= EnemigoActual->SpriteCaracter->w)
	{
		EnemigoActual->CurrentFrame[0] = 0;
		if(EnemigoActual->CurrentFrame[1] == AbrirCompuerta)
			EnemigoActual->CurrentFrame[1] = Atacar;
		else if(EnemigoActual->CurrentFrame[1] == CerrarCompuerta)
			EnemigoActual->CurrentFrame[1] = SoloVolar;
	}
}

void PantallaInicio(TJUEGO* Juego)
{
	float tiempo=clock();
	float posX=-600;

	// PALETTE pal;

	//get_palette(pal);

	//save_bitmap("dump.bmp", Juego->BufferPantalla, pal);


	
	BITMAP * _fondo= (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites),7)->data);

	
	int seleccionado=0;
	float tecla_press=0;
	int color;
	char *opciones[] = {"1 Player","2 Player",NULL};
	Juego->EstadoJuego=EnOpcion;
	while(!key[KEY_ESC] && Juego->EstadoJuego == EnOpcion)
	{
		poll_joystick();
		

		draw_sprite(Juego->BufferPantalla,_fondo,0,0);
		
		textprintf_centre_ex(Juego->BufferPantalla, Juego->LetraDeJuego, SCREEN_W/2,544,  makecol(255, 250, 250), -1, "Select an Option to Continue");
		for (int i = 0; opciones[i]; i++)
		{
			if(seleccionado==i)
				color= makecol(82, 165, 63);
			else
				color= -1;
			textprintf_centre_ex(Juego->BufferPantalla, Juego->LetraDeJuego, SCREEN_W/2, 544+(Juego->LetraDeJuego->height*(i+1)),  makecol(255, 250, 250), color, opciones[i]);
		}

		if(((key[KEY_UP] || key[KEY_W] || joy[0].stick[4].axis[1].d1 == -1  || joy[1].stick[4].axis[1].d1 == -1 || joy[0].stick[0].axis[1].d1 == -1  || joy[1].stick[0].axis[1].d1 == -1) && seleccionado >0) && clock() - tecla_press > 500)
			seleccionado--, tecla_press=clock();
		else if (((key[KEY_DOWN] || key[KEY_S] || joy[0].stick[4].axis[1].d2 == -1 || joy[1].stick[4].axis[1].d2 == -1 || joy[0].stick[0].axis[1].d2 == -1  || joy[1].stick[0].axis[1].d2 == -1) && seleccionado <=0) && clock() - tecla_press > 500)
			seleccionado++, tecla_press=clock();

		if(key[KEY_ENTER] || joy[0].button[2].b || joy[1].button[2].b || joy[0].button[11].b || joy[1].button[11].b)
		{
			if(seleccionado==0)
				Juego->CantidadJugadores=1;
			else if(seleccionado==1)
				Juego->CantidadJugadores=2;
			Juego->EstadoJuego = EnProceso;
		}

		acquire_screen();
		//renderizo el buffer
		draw_sprite(screen, Juego->BufferPantalla, 0, 0);
		//limpio el buffer
		clear(Juego->BufferPantalla);
		//suelto la pantalla
		release_screen();
		rest(16);
	}
	//if(Juego->Enemigos.cantidad > 0)
	//	VaciarLista(&Juego->Enemigos);

	////if(Juego->Tapas.cantidad > 0)
	//	VaciarLista(&Juego->Tapas);

	////if(Juego->Proyectiles.cantidad > 0)
	//  VaciarLista(&Juego->Proyectiles);


	////if(Juego->Explosiones.cantidad > 0)
	////	VaciarLista(&Juego->Explosiones);

	////if(Juego->ArmasACoger.cantidad > 0)
	////	VaciarLista(&Juego->ArmasACoger);

	////if(Juego->Items.cantidad > 0)
	////	VaciarLista(&Juego->Items);

	////if(Juego->Fondo.cantidad > 0)
	//	VaciarLista(&Juego->Fondo);

	for(int i=0; i<Juego->Enemigos.cantidad;)
		EliminarNodo(&Juego->Enemigos, (TCARACTER*)BuscarNodoIndice(&Juego->Enemigos, i)->data);
	for(int i=0; i<Juego->Carretera.cantidad;)
		EliminarNodo(&Juego->Carretera, (TCARACTER*)BuscarNodoIndice(&Juego->Carretera, i)->data);	

	Juego->TiempoInicioPartida = clock();
	Juego->TiempoSalidaItem = clock();
	Juego->TiempoSalidaVillano1 = clock();
	Juego->TiempoSalidaVillano2 = clock();
	Juego->TiempoSalidaVillano3 = clock();
	Juego->TiempoSalidaVillano4 = clock();
	Juego->TiempoInicioPartida = clock();

	Juego->EnemigosEliminados = 0;
	Juego->TeclaPresionada=0;
	Juego->PosActualBuffer = 0;
	Juego->PosActualBufferFondo = -1;//Para que se imprima el segundo sprite del fondo.
	Juego->PosActualFondo = 0;

	InicializarJugadores(Juego);
}

void CrearExplosion(TJUEGO* Juego, TCARACTER* NuevaExplosion, TCARACTER* ProyectilActual)
{
	NuevaExplosion->PosY = ProyectilActual->PosY;
	if(ProyectilActual->Id == Jugador)
	{
		if(Juego->Jugador[ProyectilActual->IdJugador].Arma.Id == LanzadorDeGranadas)
		{
			NuevaExplosion->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 17))->data;
			NuevaExplosion->PosY = ProyectilActual->PosY-20;
		}
		else
			NuevaExplosion->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 14))->data;
	}
	else if(ProyectilActual->Id == Villano)
		NuevaExplosion->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 14))->data;
	else if(ProyectilActual->Id == VillanoRodante)
		NuevaExplosion->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 15))->data;
	else if(ProyectilActual->Id == Tanque)
		NuevaExplosion->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 16))->data;
	else if(ProyectilActual->Id == Nave)
	{
		NuevaExplosion->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 17))->data;
		NuevaExplosion->PosX -= 15;
		NuevaExplosion->PosY -= 30;
	}
	else if(ProyectilActual->Id == Jefe)
		NuevaExplosion->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 17))->data;

	NuevaExplosion->Ancho = NuevaExplosion->SpriteCaracter->w;
	NuevaExplosion->Alto = NuevaExplosion->SpriteCaracter->h;
	NuevaExplosion->CurrentFrame[0] = 0;
	NuevaExplosion->CurrentFrame[1] = 0;
	NuevaExplosion->FrameX = 16;
	NuevaExplosion->FrameY = 1;
	NuevaExplosion->AnchoDividido = NuevaExplosion->SpriteCaracter->w/NuevaExplosion->FrameX;
	NuevaExplosion->AltoDividido = NuevaExplosion->SpriteCaracter->h/NuevaExplosion->FrameY;
	NuevaExplosion->FrameCounter = 0;
	NuevaExplosion->SwitchFrame = 1;
	CrearNodo(&Juego->Explosiones, NuevaExplosion, true);
}

void ActualizarArmas(TJUEGO* Juego)
{
	for(int ju=0; ju<Juego->CantidadJugadores; ju++)
	{
		if(Juego->Jugador[ju].Vidas <=0)
			continue;

		if(Juego->Jugador[ju].ScoreJugador>=SALIDA_ARMA1 && Juego->ArmasACoger.cantidad <= 0 && Juego->Jugador[ju].Armas.cantidad <= 1)
		{
			TCARACTER* NuevaArmaACoger = new TCARACTER();

			NuevaArmaACoger->Id = ArmaACoger;
			NuevaArmaACoger->IdSprite = LanzadorDeGranadas;
			NuevaArmaACoger->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 43))->data;
			NuevaArmaACoger->Ancho = NuevaArmaACoger->SpriteCaracter->w;
			NuevaArmaACoger->Alto = NuevaArmaACoger->SpriteCaracter->h;
			NuevaArmaACoger->PosXInicial = Juego->Jugador[ju].PosX + SCREEN_W/3;
			NuevaArmaACoger->PosX = Juego->Jugador[ju].PosX + SCREEN_W/3;
			NuevaArmaACoger->PosY = -NuevaArmaACoger->SpriteCaracter->h;
			NuevaArmaACoger->PosYInicial = 0;
			NuevaArmaACoger->CurrentFrame[0] = 0;
			NuevaArmaACoger->CurrentFrame[1] = 0;
			NuevaArmaACoger->FrameX = 1;
			NuevaArmaACoger->FrameY = 1;
			NuevaArmaACoger->AnchoDividido = NuevaArmaACoger->SpriteCaracter->w/NuevaArmaACoger->FrameX;
			NuevaArmaACoger->AltoDividido = NuevaArmaACoger->SpriteCaracter->h/NuevaArmaACoger->FrameY;
			NuevaArmaACoger->FrameCounter = 0;
			NuevaArmaACoger->SwitchFrame = 6;
			NuevaArmaACoger->AcelaracionY = -595;
			NuevaArmaACoger->Arma.VelocidadAtaqueEscalar = 250;
			NuevaArmaACoger->FactorAtaque = 4;
			NuevaArmaACoger->TiempoDisparo = 0.50;
			NuevaArmaACoger->TimepoUltimoCalculadoPosY = clock();
			NuevaArmaACoger->Arma.EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 0))->data;

			CrearNodo(&Juego->ArmasACoger, NuevaArmaACoger, true);
		}
		else if(Juego->Jugador[ju].ScoreJugador>=SALIDA_ARMA2 && Juego->ArmasACoger.cantidad <= 0 && Juego->Jugador[ju].Armas.cantidad <= 2)
		{
			TCARACTER* NuevaArmaACoger = new TCARACTER();

			NuevaArmaACoger->Id = ArmaACoger;
			NuevaArmaACoger->IdSprite = MultiplesDisparos;
			NuevaArmaACoger->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 44))->data;
			NuevaArmaACoger->Ancho = NuevaArmaACoger->SpriteCaracter->w;
			NuevaArmaACoger->Alto = NuevaArmaACoger->SpriteCaracter->h;
			NuevaArmaACoger->PosXInicial = Juego->Jugador[ju].PosX + SCREEN_W/3;
			NuevaArmaACoger->PosX = Juego->Jugador[ju].PosX + SCREEN_W/3;
			NuevaArmaACoger->PosY = -NuevaArmaACoger->SpriteCaracter->h;;
			NuevaArmaACoger->PosYInicial = 0;
			NuevaArmaACoger->CurrentFrame[0] = 0;
			NuevaArmaACoger->CurrentFrame[1] = 0;
			NuevaArmaACoger->FrameX = 1;
			NuevaArmaACoger->FrameY = 1;
			NuevaArmaACoger->AnchoDividido = NuevaArmaACoger->SpriteCaracter->w/NuevaArmaACoger->FrameX;
			NuevaArmaACoger->AltoDividido = NuevaArmaACoger->SpriteCaracter->h/NuevaArmaACoger->FrameY;
			NuevaArmaACoger->FrameCounter = 0;
			NuevaArmaACoger->SwitchFrame = 6;
			NuevaArmaACoger->AcelaracionY = -595;
			NuevaArmaACoger->Arma.VelocidadAtaqueEscalar = 450;
			NuevaArmaACoger->FactorAtaque = 1;
			NuevaArmaACoger->TiempoDisparo = 0.20;
			NuevaArmaACoger->TimepoUltimoCalculadoPosY = clock();
			NuevaArmaACoger->Arma.EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 0))->data;

			CrearNodo(&Juego->ArmasACoger, NuevaArmaACoger, true);
		}

		for(int i=0; i<Juego->ArmasACoger.cantidad; i++)
		{
			TCARACTER* NuevaArmaACoger = (TCARACTER*)(BuscarNodoIndice(&(Juego->ArmasACoger), i)->data);

			float TiempoDelSalto = (clock() - NuevaArmaACoger->TimepoUltimoCalculadoPosY)/CLOCKS_PER_SEC;
			CaidaConGravedad(Juego, NuevaArmaACoger, TiempoDelSalto, 0);

			if(ExisteColision(Juego, &Juego->Jugador[ju], NuevaArmaACoger, Todos, 0, 0))
			{	
				play_sample(NuevaArmaACoger->Arma.EfectoSonido, 400, 128, 1000, false);
				if(NuevaArmaACoger->IdSprite == LanzadorDeGranadas)
				{
					if(Juego->Jugador[ju].ScoreJugador>=SALIDA_ARMA1 && Juego->Jugador[ju].Armas.cantidad <= 1)
						AsignarArma(Juego, NuevaArmaACoger, ju, &i);
				}
				else if(NuevaArmaACoger->IdSprite == MultiplesDisparos)
				{
					if(Juego->Jugador[ju].ScoreJugador>=SALIDA_ARMA2 && Juego->Jugador[ju].Armas.cantidad <= 2)
						AsignarArma(Juego, NuevaArmaACoger, ju, &i);
				}
			}
		}

		if(joy[ju].button[0].b && (clock() - Juego->Jugador[ju].CambioArma)/CLOCKS_PER_SEC > 1)
		{
			Juego->Jugador[ju].CambioArma = clock();
			if(Juego->Jugador[ju].Arma.Id == DisparoSimple && Juego->Jugador[ju].Armas.cantidad>1)
				Juego->Jugador[ju].Arma = *(TARMA*)BuscarNodoIndice(&Juego->Jugador[ju].Armas, LanzadorDeGranadas)->data;
			else if(Juego->Jugador[ju].Arma.Id == LanzadorDeGranadas)
			{
				if(Juego->Jugador[ju].Armas.cantidad>2)
					Juego->Jugador[ju].Arma = *(TARMA*)BuscarNodoIndice(&Juego->Jugador[ju].Armas, MultiplesDisparos)->data;
				else
					Juego->Jugador[ju].Arma = *(TARMA*)BuscarNodoIndice(&Juego->Jugador[ju].Armas, DisparoSimple)->data;
			}
			else if(Juego->Jugador[ju].Arma.Id == MultiplesDisparos)
			{
				if(Juego->Jugador[ju].Armas.cantidad>3)
					Juego->Jugador[ju].Arma = *(TARMA*)BuscarNodoIndice(&Juego->Jugador[ju].Armas, DisparoLargo)->data;
				else
					Juego->Jugador[ju].Arma = *(TARMA*)BuscarNodoIndice(&Juego->Jugador[ju].Armas, DisparoSimple)->data;
			}
			else if(Juego->Jugador[ju].Arma.Id == DisparoLargo)
				Juego->Jugador[ju].Arma = *(TARMA*)BuscarNodoIndice(&Juego->Jugador[ju].Armas, LanzadorDeGranadas)->data;

		}
	}
}

void AsignarArma(TJUEGO* Juego, TCARACTER* NuevaArmaACoger,  int ju, int* i)
{
	TARMA* NuevaArma = new TARMA(); 

	if(ju==0)
	{
		if(NuevaArmaACoger->IdSprite == MultiplesDisparos)
		{
			NuevaArma->BalaSprite = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 36))->data;
			NuevaArma->EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 4))->data;
		}
		else if(NuevaArmaACoger->IdSprite == LanzadorDeGranadas)
		{
			NuevaArma->BalaSprite = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 37))->data;
			NuevaArma->EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 5))->data;
		}
		else if(NuevaArmaACoger->IdSprite == LanzadorDeGranadas)
		{
			NuevaArma->BalaSprite = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 38))->data;
			NuevaArma->EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 5))->data;
		}
		Juego->Jugador[ju].Avatar = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites),25))->data;
	}
	else
	{
		if(NuevaArmaACoger->IdSprite == MultiplesDisparos)
		{
			NuevaArma->BalaSprite = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 40))->data;
			NuevaArma->EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 4))->data;
		}
		else if(NuevaArmaACoger->IdSprite == LanzadorDeGranadas)
		{
			NuevaArma->BalaSprite = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 41))->data;
			NuevaArma->EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 5))->data;
		}
		else if(NuevaArmaACoger->IdSprite == LanzadorDeGranadas)
		{
			NuevaArma->BalaSprite = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 42))->data;
			NuevaArma->EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 6))->data;
		}
		Juego->Jugador[ju].Avatar = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 26))->data;
	}


	NuevaArma->Id = NuevaArmaACoger->IdSprite;
	NuevaArma->FactorAtaque = NuevaArmaACoger->FactorAtaque;
	NuevaArma->VelocidadAtaqueEscalar = NuevaArmaACoger->Arma.VelocidadAtaqueEscalar;
	NuevaArma->RangoAtaque = SCREEN_W/2;
	NuevaArma->TiempoDisparar = NuevaArmaACoger->TiempoDisparo;
	CrearNodo(&Juego->Jugador[ju].Armas, NuevaArma, true);

	Juego->Jugador[ju].Arma = *(TARMA*)BuscarNodoIndice(&Juego->Jugador[ju].Armas, Juego->Jugador[ju].Armas.cantidad-1)->data;

	EliminarNodo(&Juego->ArmasACoger, NuevaArmaACoger);
	*i--;
}

void ActualizarJefe(TJUEGO* Juego)
{
	if(Juego->PosActualBuffer > SALIDA_BOSS)
	{
		if(Juego->ContraElJefe == false)
		{
			Juego->Jefe.Id = Jefe;
			Juego->Jefe.IdSprite = Jefe;
			Juego->Jefe.Vidas = 1;
			Juego->Jefe.HP = 300;
			Juego->Jefe.SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 46))->data;
			Juego->Jefe.FactorAtaque = 20;
			Juego->Jefe.FactorDefensa = 5;
			Juego->Jefe.ScoreCaracter = 100;
			Juego->Jefe.Ancho = Juego->Jefe.SpriteCaracter->w;
			Juego->Jefe.Alto = Juego->Jefe.SpriteCaracter->h;
			Juego->Jefe.CurrentFrame[0] = 0;
			Juego->Jefe.CurrentFrame[1] = 0;
			Juego->Jefe.FrameX = 8;
			Juego->Jefe.FrameY = 2;
			Juego->Jefe.AnchoDividido = Juego->Jefe.SpriteCaracter->w/Juego->Jefe.FrameX;
			Juego->Jefe.AltoDividido = Juego->Jefe.SpriteCaracter->h/Juego->Jefe.FrameY;
			Juego->Jefe.PosX = Juego->PosActualBuffer + SCREEN_W + SCREEN_W/2 - Juego->Jefe.AnchoDividido/2;
			Juego->Jefe.PosY = 0;
			Juego->Jefe.FrameCounter = 0;
			Juego->Jefe.SwitchFrame = 6;
			Juego->Jefe.TiempoDisparo = clock()-6000;
			Juego->Jefe.Arma.BalaSprite = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 49))->data;
			Juego->Jefe.Arma.EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 3))->data;
			Juego->Jefe.Arma.FactorAtaque = 200;
			Juego->Jefe.Arma.Id = 0;
			Juego->Jefe.Arma.VelocidadAtaqueEscalar = 100;
			Juego->Jefe.Arma.RangoAtaque = SCREEN_W/2;
			Juego->Jefe.Moviendose = true;
			Juego->Jefe.DisparandoMoviendose = false;
			Juego->Jefe.Disparando = false;
			Juego->Jefe.AnguloDisparo = 270;
			Juego->Jefe.Arma.TiempoDisparar = 10;
			Juego->Jefe.Arma.AceleracionBalaY = 0;
			Juego->ContraElJefe = true;

			for(int i=0; i<=1; i++)
			{
				Juego->Manos[i].Id = Jefe;
				Juego->Manos[i].IdSprite = Jefe;
				Juego->Manos[i].Vidas = 1;
				Juego->Manos[i].HP = 300;
				Juego->Manos[i].SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 47))->data;
				Juego->Manos[i].FactorAtaque = 50;
				Juego->Manos[i].FactorDefensa = 5;
				Juego->Manos[i].ScoreCaracter = 100;
				Juego->Manos[i].Ancho = Juego->Manos[0].SpriteCaracter->w;
				Juego->Manos[i].Alto = Juego->Manos[0].SpriteCaracter->h;
				Juego->Manos[i].FrameX = 1;
				Juego->Manos[i].FrameY = 2;
				Juego->Manos[i].AnchoDividido = Juego->Manos[i].SpriteCaracter->w/Juego->Manos[i].FrameX;
				Juego->Manos[i].AltoDividido = Juego->Manos[i].SpriteCaracter->h/Juego->Manos[i].FrameY;
				if(i==0)
					Juego->Manos[i].PosX = Juego->PosActualBuffer + SCREEN_W;//SALIDA_BOSS + SCREEN_W;
				else
					Juego->Manos[i].PosX = Juego->PosActualBuffer + SCREEN_W*2 - Juego->Manos[i].AnchoDividido;
				Juego->Manos[i].PosY = 70;
				Juego->Manos[i].CurrentFrame[0] = 0;
				Juego->Manos[i].CurrentFrame[1] = 0;
				Juego->Manos[i].FrameCounter = 0;
				Juego->Manos[i].SwitchFrame = 6;
				Juego->Manos[i].TiempoDisparo = 0;
				Juego->Manos[i].AcelaracionY = -ACEL_GRAVEDAD;
				Juego->Manos[i].Arma.BalaSprite = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 10))->data;
				Juego->Manos[i].Arma.EfectoSonido = (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 3))->data;
				Juego->Manos[i].Arma.FactorAtaque = 1;
				Juego->Manos[i].Arma.Id = 0;
				Juego->Manos[i].Arma.VelocidadAtaqueEscalar = 100;
				Juego->Manos[i].Arma.RangoAtaque = SCREEN_W/2;
				Juego->Manos[i].Moviendose = true;
				Juego->Manos[i].DisparandoMoviendose = false;
				Juego->Manos[i].Disparando = false;
				Juego->Manos[i].Arma.TiempoDisparar = 0.7;
				Juego->Manos[i].Arma.AceleracionBalaY = 0;
				Juego->Manos[i].TiempoCalculadoVelocidadY = 0;

				Juego->Plataformas[i].Id = 8;
				Juego->Plataformas[i].IdSprite = 8;
				Juego->Plataformas[i].Vidas = 1;
				Juego->Plataformas[i].HP = 200;
				Juego->Plataformas[i].SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 48))->data;
				Juego->Plataformas[i].FactorAtaque = 20;
				Juego->Plataformas[i].FactorDefensa = 5;
				Juego->Plataformas[i].ScoreCaracter = 100;
				Juego->Plataformas[i].Ancho = Juego->Plataformas[i].SpriteCaracter->w;
				Juego->Plataformas[i].Alto = Juego->Plataformas[i].SpriteCaracter->h;
				Juego->Plataformas[i].FrameX = 1;
				Juego->Plataformas[i].FrameY = 2;
				Juego->Plataformas[i].AnchoDividido = Juego->Plataformas[i].SpriteCaracter->w/Juego->Plataformas[i].FrameX;
				Juego->Plataformas[i].AltoDividido = Juego->Plataformas[i].SpriteCaracter->h/Juego->Plataformas[i].FrameY;
				if(i==0)
					Juego->Plataformas[i].PosX = SALIDA_BOSS + SCREEN_W;
				else
					Juego->Plataformas[i].PosX = SALIDA_BOSS + SCREEN_W*2 - Juego->Plataformas[i].AnchoDividido;
				Juego->Plataformas[i].PosY = 450;
				Juego->Plataformas[i].CurrentFrame[0] = 0;
				Juego->Plataformas[i].CurrentFrame[1] = 0;
				Juego->Plataformas[i].FrameCounter = 0;
				Juego->Plataformas[i].SwitchFrame = 6;
				Juego->Golpeado = false;
				Juego->TiempoCaidaManos = clock();
			}
		}

		Juego->ShowStats = false;
		Juego->Jefe.CurrentFrame[1] = 0;
		float TiempoActual = (clock() - Juego->Jefe.TiempoDisparo) / CLOCKS_PER_SEC;
		
		if(TiempoActual > Juego->Jefe.Arma.TiempoDisparar)
			Disparar(Juego, &Juego->Jefe);

		int PosYMinima = 400, PosYMaxima = 70;
		
		if(Juego->ManosBoss && (clock() - Juego->TiempoCaidaManos)/CLOCKS_PER_SEC > 0.5)
		{
			if(Juego->TiempoMano)
				for(int i = 0; i < 2; i++)
					Juego->Manos[i].TiempoCalculadoVelocidadY = clock(), Juego->TiempoMano = false;
			
			for(int i = 0; i < 2; i++)
			{				
				float tiempoActual = (clock() - Juego->Manos[i].TiempoCalculadoVelocidadY) / CLOCKS_PER_SEC;

				if(Juego->Manos[i].PosY <= PosYMaxima)//Lo mas alto que puede estar.
				{
					Juego->Manos[i].TiempoCalculadoVelocidadY = clock();
					Juego->Manos[i].PosYInicial = PosYMaxima+1;
					Juego->Manos[i].VelocidadY = 150*PPM;
					Juego->ManosBoss = false;
					Juego->Golpeado = false;
				}
				tiempoActual = (clock() - Juego->Manos[i].TiempoCalculadoVelocidadY) / CLOCKS_PER_SEC;
				Juego->Manos[i].PosY = Juego->Manos[i].PosYInicial + Juego->Manos[i].VelocidadY*tiempoActual;// + 0.5*3*tiempoActual*tiempoActual;
			}
		}			
		for(int i = 0; i < 2; i++)
		{
			if(Juego->Manos[i].PosY >= PosYMinima)//Los mas abajo que puede estar.
			{
				Juego->Manos[i].VelocidadY = -300*PPM;
				Juego->Manos[i].TiempoCalculadoVelocidadY = clock();
				Juego->Manos[i].PosYInicial = PosYMinima-1;
			}
		}

		if(Juego->ManosBoss)
		{
			for(int i = 0; i < 2; i++)
				for(int ju = 0; ju < Juego->CantidadJugadores; ju++)
					if(ExisteColision(Juego, &Juego->Manos[i], &Juego->Jugador[ju], DesdeAbajo, 0, 0))
						RestarHP(Juego, &Juego->Jugador[ju], Juego->Manos, 0);
		}
		
		
		Juego->Jefe.FrameCounter++;
		if(Juego->Jefe.FrameCounter >= Juego->Jefe.SwitchFrame)
		{
			Juego->Jefe.CurrentFrame[0] += Juego->Jefe.AnchoDividido;
			Juego->Jefe.FrameCounter = 0;
		}
		if(Juego->Jefe.CurrentFrame[0] >= Juego->Jefe.SpriteCaracter->w)
			Juego->Jefe.CurrentFrame[0] = 0;

		if(Juego->CrearExplosionesBoss == true)
			CrearExplosionBoss(Juego);
	}
}

void CrearExplosionBoss(TJUEGO* Juego)
{
	float TiempoActual = (clock() - Juego->TiempoDeExplosionesBoss)/CLOCKS_PER_SEC;
	if(TiempoActual > 0.2)
	{
		for(int i = Juego->PosActualBuffer; i < Juego->PosActualBuffer + SCREEN_W; i += 50)
		{
			TCARACTER* NuevaExplosion = new TCARACTER();
			Juego->TiempoDeExplosionesBoss = clock();

			NuevaExplosion->PosY = 500;
			NuevaExplosion->PosX = i;
			NuevaExplosion->SpriteCaracter = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 17))->data;
			NuevaExplosion->Ancho = NuevaExplosion->SpriteCaracter->w;
			NuevaExplosion->Alto = NuevaExplosion->SpriteCaracter->h;
			NuevaExplosion->CurrentFrame[0] = 0;
			NuevaExplosion->CurrentFrame[1] = 0;
			NuevaExplosion->FrameX = 16;
			NuevaExplosion->FrameY = 1;
			NuevaExplosion->AnchoDividido = NuevaExplosion->SpriteCaracter->w/NuevaExplosion->FrameX;
			NuevaExplosion->AltoDividido = NuevaExplosion->SpriteCaracter->h/NuevaExplosion->FrameY;
			NuevaExplosion->FrameCounter = 0;
			NuevaExplosion->SwitchFrame = 1;
			NuevaExplosion->FactorAtaque = Juego->Jugador[0].FactorDefensa + 1 ;
			CrearNodo(&Juego->Explosiones, NuevaExplosion, true);
		}
	}
	int TiempoExplosion = rand() % 10 + 4;
	Juego->Jefe.Arma.TiempoDisparar = TiempoExplosion + 2;
	if((clock() - Juego->TiempoDetenerExplosionesBoss)/CLOCKS_PER_SEC > TiempoExplosion){
		Juego->CrearExplosionesBoss = false;
		Juego->TiempoCaidaManos = clock();
		Juego->ManosBoss = true;
		Juego->TiempoMano = true;		
	}
	//float TiempoActual = (clock() - Juego->TiempoEncimaPlataforma)/CLOCK_PER_SEC;

	/*for(int ju=0; ju<Juego->CantidadJugadores; ju++)
	{
		if(Juego->Jugador[ju].Vidas <= 0)
			continue;
		for(int pl=0; pl<=1; pl++)
		{
			if(ExisteColision(Juego, &Juego->Jugador[ju], &Juego->Plataformas[pt], DesdeAbajo, TiempoActual, ju)
				TiempoEncimaPlataforma = clock();
		}
	}*/

	//if(TiempoActual > 2);
		//DejarCaerMano(Juego);
}

/*void DejarCaerMano(TJUEGO* Juego)
{
	for(int i=0; i<=2; i++)
	{
		Juego->Manos[i].TimepoUltimoCalculadoPosX = clock();
		Juego->Manos[i].

		Juego->Manos[->PosY = Caracter->PosY + 0.5*(ACEL_GRAVEDAD+Caracter->AcelaracionY)*pow(TiempoDelSalto, 2) + Caracter->VelocidadYSalto*TiempoDelSalto;
	}
}*/