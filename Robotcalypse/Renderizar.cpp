#include "main.h"
void RenderizarBlitTransparente(BITMAP * BufferPantalla, BITMAP * _sprite, int blitPosX, int blitPosY, int posX, int posY, int ancho, int alto)
{
	//creo un buffer temporal para mantener la transparencia del sprite
	//la idea es pintar el sprite bliteado en el temporal para luego con draw_trans_sprite mostrar su transparencia
	BITMAP * tmp_bitmap = create_bitmap(ancho, alto);
	//Limpio al color 0
 	clear_to_color(tmp_bitmap, 0);
 	masked_blit(_sprite, tmp_bitmap, blitPosX, blitPosY, 0,0, ancho, alto);
	//Renderizo el sprite con su debida transparencia.
	draw_trans_sprite(BufferPantalla, tmp_bitmap, posX, posY);
	destroy_bitmap(tmp_bitmap);
}

void RenderizarSpriteInvertido(TJUEGO* Juego, BITMAP* Sprite, int PosX, int PosY)
{	
			BITMAP * Tmp = create_bitmap(Sprite->w,Sprite->h);
			clear_to_color(Tmp,0);
			draw_sprite_h_flip(Tmp,Sprite, 0,0);
			draw_trans_sprite(Juego->BufferPantalla,Tmp, PosX, PosY);
			destroy_bitmap(Tmp);
}

int RenderizarJuego(TJUEGO* Juego)
{
	
	BITMAP* _SpriteCalle = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 3)->data);
	BITMAP* BarraDeVida = (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 5)->data);
	//creo un buffer temporal para mantener la transparencia del sprite
	//la idea es pintar el sprite bliteado en el temporal para luego con draw_trans_sprite mostrar su transparencia

	//Imprimir el fondo:
	for(int i=0; i<Juego->Fondo.cantidad; i++)
	{
		TCARACTER* Fondo = (TCARACTER*)BuscarNodoIndice(&Juego->Fondo, i)->data;
		draw_sprite(Juego->BufferPantalla, Fondo->SpriteCaracter, Fondo->PosX - Juego->PosActualFondo, Fondo->PosY);
	}

	//Imprimir la carretara:
	for(int i=0; i<Juego->Carretera.cantidad; i++)
	{
		TCARACTER* Carretera = (TCARACTER*)BuscarNodoIndice(&Juego->Carretera, i)->data;
		draw_sprite(Juego->BufferPantalla, Carretera->SpriteCaracter, Carretera->PosX - Juego->PosActualBuffer, Carretera->PosYReal);

	}

	for(int i=0; i < Juego->Tapas.cantidad; i++)
	{
		//TCARACTER* Tapa= (TCARACTER*)(BuscarNodoIndice(&(Juego->Tapas),i))->data;
		TCARACTER* TapaAlcantarilla = (TCARACTER*)BuscarNodoIndice(&Juego->Tapas, i)->data;
		BITMAP * Hoyo = (BITMAP*)BuscarNodoIndice(&Juego->Sprites,30)->data;
		draw_trans_sprite(Juego->BufferPantalla, Hoyo,(Juego->Fuego.PosX - Juego->PosActualBuffer), Juego->Fuego.PosY-5);
		

		RenderizarBlitTransparente(Juego->BufferPantalla, 
		Juego->Fuego.SpriteCaracter,
		Juego->Fuego.CurrentFrame[0], 
		Juego->Fuego.CurrentFrame[1] * Juego->Fuego.AltoDividido,
		(Juego->Fuego.PosX - Juego->PosActualBuffer)-4, 
		Juego->Fuego.PosY-5,
		Juego->Fuego.AnchoDividido, 
		Juego->Fuego.AltoDividido);
		
		RenderizarBlitTransparente(Juego->BufferPantalla, 
		TapaAlcantarilla->SpriteCaracter,
		TapaAlcantarilla->CurrentFrame[0], 
		TapaAlcantarilla->CurrentFrame[1] * TapaAlcantarilla->AltoDividido,
		(TapaAlcantarilla->PosX - Juego->PosActualBuffer)-4, 
		TapaAlcantarilla->PosY,
		TapaAlcantarilla->AnchoDividido, 
		TapaAlcantarilla->AltoDividido);
	}

	//Imprimir la plataforma:
	if(Juego->ContraElJefe == true)
	{
		for(int i=0; i<=1; i++)
  			draw_sprite(Juego->BufferPantalla, Juego->Plataformas[i].SpriteCaracter, Juego->Plataformas[i].PosX - Juego->PosActualBuffer, Juego->Plataformas[i].PosY);
	}

	//Imprimir el jefe:
	if(Juego->ContraElJefe == true)
	{
		RenderizarBlitTransparente(Juego->BufferPantalla, 
			Juego->Jefe.SpriteCaracter,
			Juego->Jefe.CurrentFrame[0], 
			Juego->Jefe.CurrentFrame[1] * Juego->Jefe.AltoDividido,
			Juego->Jefe.PosX - Juego->PosActualBuffer, 
			Juego->Jefe.PosY,
			Juego->Jefe.AnchoDividido, 
			Juego->Jefe.AltoDividido);
	}


	//Imprimir enemigos:
	for(int i=0; i<Juego->Enemigos.cantidad; i++)
	{
		TCARACTER* EnemigoActual = (TCARACTER*)BuscarNodoIndice(&Juego->Enemigos, i)->data;

		RenderizarBlitTransparente(Juego->BufferPantalla,  
			EnemigoActual->SpriteCaracter, 
			EnemigoActual->CurrentFrame[0], 
			EnemigoActual->CurrentFrame[1] * EnemigoActual->AltoDividido,
			EnemigoActual->PosX - Juego->PosActualBuffer, 
			EnemigoActual->PosY,
			EnemigoActual->AnchoDividido, 
			EnemigoActual->AltoDividido);
	}

	//Imprimir las armas a coger:
	for(int i=0; i<Juego->ArmasACoger.cantidad; i++)
	{
		TCARACTER* ArmaActual = (TCARACTER*)BuscarNodoIndice(&Juego->ArmasACoger, i)->data;
		RenderizarBlitTransparente(Juego->BufferPantalla, 
			ArmaActual->SpriteCaracter,
			ArmaActual->CurrentFrame[0], 
			ArmaActual->CurrentFrame[1] * ArmaActual->AltoDividido,
			ArmaActual->PosX - Juego->PosActualBuffer, 
			ArmaActual->PosY,
			ArmaActual->AnchoDividido, 
			ArmaActual->AltoDividido);
	}


	//Imprimir los items:
	for(int i=0; i<Juego->Items.cantidad; i++)
	{
		TCARACTER* ItemActual = (TCARACTER*)BuscarNodoIndice(&Juego->Items, i)->data;
		RenderizarBlitTransparente(Juego->BufferPantalla, 
			ItemActual->SpriteCaracter,
			ItemActual->CurrentFrame[0], 
			ItemActual->CurrentFrame[1] * ItemActual->AltoDividido,
			ItemActual->PosX - Juego->PosActualBuffer, 
			ItemActual->PosY,
			ItemActual->AnchoDividido, 
			ItemActual->AltoDividido);
	}

	//Imprimir la barra de vida:
	BITMAP * _spriteBarra=(BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 4)->data);
	for(int ju=0; ju < Juego->CantidadJugadores; ju++)
	{

		//draw_sprite_h_flip(
			//draw_trans_h_sprite
		if(ju == 0)
		{
			//si es el jugador 1 lo muestro normal
			draw_trans_sprite(Juego->BufferPantalla, _spriteBarra, 2+(ju*_spriteBarra->w), 10);
			RenderizarBlitTransparente(Juego->BufferPantalla, BarraDeVida, 0,0,4+(_spriteBarra->w*ju),30, BarraDeVida->w*((float)Juego->Jugador[ju].HP/100), BarraDeVida->h);

			draw_trans_sprite(Juego->BufferPantalla, Juego->Jugador[ju].Avatar, 20,0);
			textprintf_ex(Juego->BufferPantalla, Juego->LetraDeJuego, 4+(_spriteBarra->w - _spriteBarra->w/2) + 33, 13, makecol(255, 250, 250), -1, "x%d", Juego->Jugador[ju].Vidas);
		}
		else
		{
			//si es el jugador 2 lo muestro pero invertido

			RenderizarSpriteInvertido(Juego,_spriteBarra,   SCREEN_W -_spriteBarra->w-4 , 10);
			RenderizarBlitTransparente(Juego->BufferPantalla, BarraDeVida, BarraDeVida->w - (BarraDeVida->w*((float)Juego->Jugador[ju].HP/100))-4,0,((SCREEN_W-_spriteBarra->w)-(_spriteBarra->w*(float)Juego->Jugador[ju].HP/100))+_spriteBarra->w-4,30, BarraDeVida->w, BarraDeVida->h);
			RenderizarSpriteInvertido(Juego,Juego->Jugador[ju].Avatar,  SCREEN_W-45,0);
			textprintf_ex(Juego->BufferPantalla, Juego->LetraDeJuego, SCREEN_W - (_spriteBarra->w - _spriteBarra->w/2) - 65, 13, makecol(255, 250, 250), -1, "%dx", Juego->Jugador[ju].Vidas);
			//draw_trans_sprite(Juego->BufferPantalla, Juego->Jugador[ju].Avatar, SCREEN_W-40,0);
		}		
	}
	if(Juego->ShowStats)
	{
	//int ju=0;
	int posX;
	int posY=15;
	int posXfondo=4;
//	int posX=15;
	for(int ju=0; ju < Juego->CantidadJugadores; ju++)
	{
	//Imprimir las barras de información:
		BITMAP * _fondoData=(BITMAP*)(BuscarNodoIndice(&(Juego->Sprites), 6)->data);
		if(ju ==0)
			posX=15;
		else if(ju == 1)
			posX=SCREEN_W-_fondoData->w+8,posXfondo=SCREEN_W-_fondoData->w-4;
		//	posx
	
	draw_sprite(Juego->BufferPantalla, _fondoData, posXfondo, _spriteBarra->h+posY);
	draw_sprite(Juego->BufferPantalla, _fondoData, posXfondo, _spriteBarra->h+posY+((1*_fondoData->h)+5));
	draw_sprite(Juego->BufferPantalla, _fondoData, posXfondo, _spriteBarra->h+posY+((2*_fondoData->h)+10));
	
	textprintf_ex(Juego->BufferPantalla, Juego->LetraDeJuego, posX-9, _spriteBarra->h+posY + Juego->LetraDeJuego->height/2, makecol(255, 250, 250), -1, "Score %d", Juego->Jugador[ju].ScoreJugador);
	
	textprintf_ex(Juego->BufferPantalla, Juego->LetraDeJuego, posX, _spriteBarra->h+posY+((1*_fondoData->h)+5)+ Juego->LetraDeJuego->height/2, makecol(255, 250, 250), -1, "ATK  %d", Juego->Jugador[ju].FactorAtaque);
	textprintf_ex(Juego->BufferPantalla, Juego->LetraDeJuego,  posX, _spriteBarra->h+posY+((2*_fondoData->h)+10)+ Juego->LetraDeJuego->height/2, makecol(255, 250, 250), -1, "DEF  %d", Juego->Jugador[ju].FactorDefensa);

	}
	}
	//Imprimir el tiempo del juego:
	textprintf_centre_ex(Juego->BufferPantalla, Juego->LetraDeJuego, SCREEN_W/2, 10, makecol(255, 250, 250), -1, "%.0f", (clock() - Juego->TiempoInicioPartida)/CLOCKS_PER_SEC);
	



	//Imprimir el jugador:
	for(int ju=0; ju < Juego->CantidadJugadores; ju++)
	{
			if(Juego->Jugador[ju].Vidas <=0)
				continue;
		//textprintf_ex(Juego->BufferPantalla, Juego->LetraDeJuego, SCREEN_W/2, 400, makecol(255, 250, 250), -1, "%.0f - %d", 	0,joy[ju].stick[1].axis[0].pos);
			RenderizarBlitTransparente(Juego->BufferPantalla, 
			Juego->Jugador[ju].SpriteCaracter, 
			Juego->Jugador[ju].CurrentFrame[0], 
			Juego->Jugador[ju].CurrentFrame[1] * Juego->Jugador[ju].AltoDividido,
			Juego->Jugador[ju].PosX - Juego->PosActualBuffer, Juego->Jugador[ju].PosY,
			Juego->Jugador[ju].AnchoDividido, Juego->Jugador[ju].AltoDividido);
	}

	//Imprimir manos de Jefe
	if(Juego->ContraElJefe)
	{
		for(int i=0; i<=1; i++)
		{
			RenderizarBlitTransparente(Juego->BufferPantalla, 
				Juego->Manos[i].SpriteCaracter,
				Juego->Manos[i].CurrentFrame[0], 
				Juego->Manos[i].CurrentFrame[1] * Juego->Manos[i].AltoDividido,
				Juego->Manos[i].PosX - Juego->PosActualBuffer, 
				Juego->Manos[i].PosY,
				Juego->Manos[i].AnchoDividido, 
				Juego->Manos[i].AltoDividido);
		}
	}
	//Imprimir los proyectiles:
	for(int i=0; i<Juego->Proyectiles.cantidad; i++)
	{
		TCARACTER* ProyectilActual = (TCARACTER*)(BuscarNodoIndice(&(Juego->Proyectiles), i)->data);
		draw_trans_sprite(Juego->BufferPantalla, ProyectilActual->Arma.BalaSprite, ProyectilActual->PosX - Juego->PosActualBuffer, ProyectilActual->PosY);
	}

	//Imprimir las explosiones:
	for(int i=0; i<Juego->Explosiones.cantidad; i++)
	{
		TCARACTER* ExplosionActual = (TCARACTER*)BuscarNodoIndice(&Juego->Explosiones, i)->data;
		RenderizarBlitTransparente(Juego->BufferPantalla, 
			ExplosionActual->SpriteCaracter,
			ExplosionActual->CurrentFrame[0], 
			ExplosionActual->CurrentFrame[1] * ExplosionActual->AltoDividido,
			ExplosionActual->PosX - Juego->PosActualBuffer, 
			ExplosionActual->PosY,
			ExplosionActual->AnchoDividido, 
			ExplosionActual->AltoDividido);
	}

	if(Juego->PerdioVida)
		draw_trans_sprite(Juego->BufferPantalla, (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites),33)->data),0,0);

	//Mostar mouse:
	if(Juego->GameOver)
		RenderizarGameOver(Juego);
	if(Juego->Win)
		RenderizarWin(Juego);
	if(Juego->EstadoJuego==EnPausa)
		PausarJuego(Juego);
	show_mouse(Juego->BufferPantalla);
	//adquiero la pantalla para renderizar todo
	acquire_screen();
	//renderizo el buffer
	draw_sprite(screen, Juego->BufferPantalla, 0, 0);
	//limpio el buffer
	clear(Juego->BufferPantalla);
	//suelto la pantalla
	release_screen();

	return 0;
}

void RenderizarGameOver(TJUEGO *Juego)
{
	
	float tiempo=clock();
	float posX=-600;

	// PALETTE pal;

	//get_palette(pal);

	//save_bitmap("dump.bmp", Juego->BufferPantalla, pal);


	BITMAP *BufferAnterior = create_bitmap(SCREEN_W,SCREEN_H);
	draw_sprite(BufferAnterior, Juego->BufferPantalla,0,0);
	BITMAP * _fondo= (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites),32)->data);
	BITMAP * _gameover= (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites),34)->data);
	SAMPLE * _oversound= (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 12))->data;
	int seleccionado=0;
	float tecla_press=0;
	int color;
	char *opciones[] = {"NEW GAME","EXIT",NULL};
	play_sample(_oversound, 2000, 128, 1000,false);
	bool salir=false;
	while(!key[KEY_ESC] && Juego->EstadoJuego != Finalizado && Juego->GameOver==true)
	{
		poll_joystick();
		if(posX < SCREEN_H/2 - _gameover->h/2 - 50)
			posX= posX+( 0.5*(605*((tiempo-clock())/1000)*(tiempo-clock())/1000));

		draw_sprite(Juego->BufferPantalla,BufferAnterior,0,0);
		draw_trans_sprite(Juego->BufferPantalla, _fondo, 0,0);

		draw_trans_sprite(Juego->BufferPantalla, _gameover, SCREEN_W/2 - _gameover->w/2,posX);

		textprintf_centre_ex(Juego->BufferPantalla, Juego->LetraDeJuego, SCREEN_W/2, _gameover->h+posX-5,  makecol(255, 250, 250), -1, "Select an Option to Continue");
		for (int i = 0; opciones[i]; i++)
		{
			if(seleccionado==i)
				color= makecol(82, 165, 63);
			else
				color= -1;
			textprintf_centre_ex(Juego->BufferPantalla, Juego->LetraDeJuego, SCREEN_W/2, _gameover->h+posX+20+(Juego->LetraDeJuego->height * i),  makecol(255, 250, 250), color, opciones[i]);
		}

		if(key[KEY_N])
			seleccionado=0;
		else if (key[KEY_E])
			seleccionado=1;


		if(((key[KEY_UP] || key[KEY_W] || joy[0].stick[4].axis[1].d1 == -1  || joy[1].stick[4].axis[1].d1 == -1 || joy[0].stick[0].axis[1].d1 == -1  || joy[1].stick[0].axis[1].d1 == -1) && seleccionado >0) && clock() - tecla_press > 500)
			seleccionado--, tecla_press=clock();
		else if (((key[KEY_DOWN] || key[KEY_S] || joy[0].stick[4].axis[1].d2 == -1 || joy[1].stick[4].axis[1].d2 == -1 || joy[0].stick[0].axis[1].d2 == -1  || joy[1].stick[0].axis[1].d2 == -1) && seleccionado <=0) && clock() - tecla_press > 500)
			seleccionado++, tecla_press=clock();

		if(key[KEY_ENTER] || joy[0].button[2].b || joy[1].button[2].b || joy[0].button[11].b || joy[1].button[11].b)
		{
			if(seleccionado==0)
				Juego->GameOver=false, Juego->EstadoJuego = Reiniciar;
			else if(seleccionado==1)
				Juego->EstadoJuego = Finalizado;
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
	destroy_bitmap(BufferAnterior);


}

void PausarJuego(TJUEGO* Juego)
{
	BITMAP *BufferAnterior = create_bitmap(SCREEN_W,SCREEN_H);
	draw_sprite(BufferAnterior, Juego->BufferPantalla,0,0);
	BITMAP * _fondo= (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites),32)->data);
	float tiempoPausa=clock();
	int seleccionado=0;
	float tecla_press=0;
	int color;
	char *opciones[] = {"Resume", "Restart", "Main Menu", "Exit", NULL};
	while(Juego->EstadoJuego ==EnPausa)
	{
		poll_joystick();
		draw_sprite(Juego->BufferPantalla,BufferAnterior,0,0);
		draw_trans_sprite(Juego->BufferPantalla, _fondo, 0,0);
		
		
		textprintf_centre_ex(Juego->BufferPantalla, Juego->LetraDeJuego, SCREEN_W/2, 500,  makecol(255, 250, 250), makecol(0, 0, 0), "Select an Option to Continue");
		for (int i = 0; opciones[i]; i++)
		{
			if(seleccionado==i)
				color= makecol(82, 165, 63);
			else
				color= -1;
			textprintf_centre_ex(Juego->BufferPantalla, Juego->LetraDeJuego, SCREEN_W/2, 500+(Juego->LetraDeJuego->height*(i+1)),  makecol(255, 250, 250), color, opciones[i]);
		}

		if(((key[KEY_UP] || key[KEY_W] || joy[0].stick[4].axis[1].d1 == -1  || joy[1].stick[4].axis[1].d1 == -1 || joy[0].stick[0].axis[1].d1 == -1  || joy[1].stick[0].axis[1].d1 == -1) && seleccionado > 0) && clock() - tecla_press > 300)
			seleccionado--, tecla_press=clock();
		else if (((key[KEY_DOWN] || key[KEY_S] || joy[0].stick[4].axis[1].d2 == -1 || joy[1].stick[4].axis[1].d2 == -1 || joy[0].stick[0].axis[1].d2 == -1  || joy[1].stick[0].axis[1].d2 == -1) && seleccionado < 3) && clock() - tecla_press > 300)
			seleccionado++, tecla_press=clock();
		
		if(key[KEY_ENTER] || joy[0].button[2].b || joy[1].button[0].b )//|| joy[0].button[11].b || joy[1].button[11].b)
		{
			if(seleccionado == 0)
				Juego->EstadoJuego = EnProceso;
			else if(seleccionado == 1)
				Juego->EstadoJuego = Reiniciar;
			else if(seleccionado == 2)
				Juego->EstadoJuego = EnInicio;
			else if(seleccionado == 3)
				Juego->EstadoJuego = Finalizado;
		}
		if((key[KEY_P] || joy[0].button[11].b || joy[1].button[11].b) && clock() - Juego->TeclaPresionada > 500)
			Juego->EstadoJuego=EnProceso, Juego->TeclaPresionada=clock();
		
		textprintf_centre_ex(Juego->BufferPantalla, Juego->LetraDeJuego, SCREEN_W/2, SCREEN_H/2,  makecol(255, 250, 250), makecol(0, 0, 0), "Game Paused");
		acquire_screen();
		//renderizo el buffer
		draw_sprite(screen, Juego->BufferPantalla, 0, 0);
		//limpio el buffer
		clear(Juego->BufferPantalla);
		//suelto la pantalla
		release_screen();
		rest(16);
		//Juego->EstadoJuego = EnPausa;
	}
	float DuracionPausa=clock()-tiempoPausa;

	for(int i=0; i < Juego->Items.cantidad; i++)
	{
		TCARACTER* ItemActual = (TCARACTER*)(BuscarNodoIndice(&(Juego->Items), i)->data);
		if(ItemActual->TiempoCalculadoVelocidadX > 0)
			ItemActual->TiempoCalculadoVelocidadX +=DuracionPausa;
		if(ItemActual->TiempoCalculadoVelocidadY > 0)
			ItemActual->TiempoCalculadoVelocidadY +=DuracionPausa;
	}


	for(int i=0; i<Juego->Proyectiles.cantidad && i>=0; i++)
	{
		TCARACTER* ProyectilActual = (TCARACTER*)BuscarNodoIndice(&(Juego->Proyectiles), i)->data;
		if(ProyectilActual->TiempoDisparo > 0)
		ProyectilActual->TiempoDisparo +=DuracionPausa;
	}

	for(int i=0; i< Juego->CantidadJugadores; i++)
	{
		if(Juego->Jugador[i].TimepoUltimoCalculadoPosY >0)
		Juego->Jugador[i].TimepoUltimoCalculadoPosY += DuracionPausa;
	}

	for(int i=0; i < Juego->Enemigos.cantidad; i++)
	{
		TCARACTER* EnemigoActual = (TCARACTER*)BuscarNodoIndice(&(Juego->Enemigos), i)->data;
		if(EnemigoActual->TiempoCalculadoVelocidadX > 0)
		EnemigoActual->TiempoCalculadoVelocidadX+=DuracionPausa;

		if(EnemigoActual->TimepoUltimoCalculadoPosY > 0)
		EnemigoActual->TimepoUltimoCalculadoPosY+=DuracionPausa;	
	}

		
	Juego->TiempoSalidaVillano1+=DuracionPausa;
	Juego->TiempoSalidaVillano2+=DuracionPausa;
	Juego->TiempoSalidaVillano3+=DuracionPausa;
	Juego->TiempoSalidaVillano4+=DuracionPausa;
	Juego->TiempoSalidaItem+=DuracionPausa;

	//Juego->Enemigos


}

void RenderizarWin(TJUEGO *Juego)
{
	play_midi(Juego->BackGround, false);
	float tiempo=clock();
	float posX=-600;

	// PALETTE pal;

	//get_palette(pal);

	//save_bitmap("dump.bmp", Juego->BufferPantalla, pal);


	BITMAP *BufferAnterior = create_bitmap(SCREEN_W,SCREEN_H);
	draw_sprite(BufferAnterior, Juego->BufferPantalla,0,0);
	BITMAP * _fondo= (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites),32)->data);
	BITMAP * _gameover= (BITMAP*)(BuscarNodoIndice(&(Juego->Sprites),50)->data);
	SAMPLE * _oversound= (SAMPLE*)(BuscarNodoIndice(&(Juego->Sonidos), 13))->data;
	int seleccionado=0;
	float tecla_press=0;
	int color;
	char *opciones[] = {"NEW GAME","EXIT",NULL};
	play_sample(_oversound, 2000, 128, 1000,false);
	bool salir=false;
	while(!key[KEY_ESC] && Juego->EstadoJuego != Finalizado && Juego->Win==true)
	{
		poll_joystick();
		if(posX < SCREEN_H/2 - _gameover->h/2 - 50)
			posX= posX+( 0.5*(605*((tiempo-clock())/1000)*(tiempo-clock())/1000));

		draw_sprite(Juego->BufferPantalla,BufferAnterior,0,0);
		draw_trans_sprite(Juego->BufferPantalla, _fondo, 0,0);

		draw_trans_sprite(Juego->BufferPantalla, _gameover, SCREEN_W/2 - _gameover->w/2,posX);

		textprintf_centre_ex(Juego->BufferPantalla, Juego->LetraDeJuego, SCREEN_W/2, _gameover->h+posX-5,  makecol(255, 250, 250), -1, "Select an Option to Continue");
		for (int i = 0; opciones[i]; i++)
		{
			if(seleccionado==i)
				color= makecol(82, 165, 63);
			else
				color= -1;
			textprintf_centre_ex(Juego->BufferPantalla, Juego->LetraDeJuego, SCREEN_W/2, _gameover->h+posX+20+(Juego->LetraDeJuego->height * i),  makecol(255, 250, 250), color, opciones[i]);
		}

		if(key[KEY_N])
			seleccionado=0;
		else if (key[KEY_E])
			seleccionado=1;


		if(((key[KEY_UP] || key[KEY_W] || joy[0].stick[4].axis[1].d1 == -1  || joy[1].stick[4].axis[1].d1 == -1 || joy[0].stick[0].axis[1].d1 == -1  || joy[1].stick[0].axis[1].d1 == -1) && seleccionado >0) && clock() - tecla_press > 500)
			seleccionado--, tecla_press=clock();
		else if (((key[KEY_DOWN] || key[KEY_S] || joy[0].stick[4].axis[1].d2 == -1 || joy[1].stick[4].axis[1].d2 == -1 || joy[0].stick[0].axis[1].d2 == -1  || joy[1].stick[0].axis[1].d2 == -1) && seleccionado <=0) && clock() - tecla_press > 500)
			seleccionado++, tecla_press=clock();

		if(key[KEY_ENTER] || joy[0].button[2].b || joy[1].button[2].b || joy[0].button[11].b || joy[1].button[11].b)
		{
			if(seleccionado==0)
				Juego->Win=false, Juego->EstadoJuego = Reiniciar;
			else if(seleccionado==1)
				Juego->EstadoJuego = Finalizado;
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
	destroy_bitmap(BufferAnterior);

}