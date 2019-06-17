#ifndef __Jogo__
#define __Jogo__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "GL/glut.h"
#include "GL/freeglut_ext.h" //callback da wheel do mouse.

// Fun��o Principal que inicia o jogo quando solicitado
int Iniciar(int x);

// Fun��o que busca em todo o tabuleiro por combina��es
int Combinar(void);

// Fun��o que desce cada pe�a para baixo caso houver espa�os livres
int ShiftDown(void);

// Fun��o que reconhece a posi��o do mouse e marca a jogada
void Marcar(int mx, int my);

// Fun��o que Desenha cada figura conforme a numera��o
void IMG(int num, int posx, int posy, int *pos);

// Fun��o que troca duas posi��es selecioandas
void troca(int posy1, int posx1, int posx2, int posy2);

// Fun��o que implementa a pe�a especial de alinhar 5 doces da mesma cor
void Bolacha(int explos);

// Fun��o que exibe mensagens conforme a combina��o efetuada
void Comemoracao(int valor);

// Fun��o que emprime na tela os Pontos do Usu�rio
void MarcaPonto(int pontos);

#endif
