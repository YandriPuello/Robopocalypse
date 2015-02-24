#include "Main.h"

TJUEGO *Juego = new TJUEGO();

int main()
{
	InicializarJuego(Juego);

	while(!key[KEY_ESC] && Juego->EstadoJuego != Finalizado)
	{
		ActualizarJuego(Juego);
		RenderizarJuego(Juego);
		rest(16);
		if(Juego->EstadoJuego == Reiniciar)
			ReinicializarJuego(Juego, Reiniciar);
		else if(Juego->EstadoJuego == EnInicio)
			ReinicializarJuego(Juego, EnInicio);
	}

	return 0;
}
END_OF_MAIN();