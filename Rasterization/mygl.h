#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <stdio.h>
#include <math.h>

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************
typedef struct
{	
	int R,G,B,A;	
}t_cor;

void putPixel(const int x, const int y, const t_cor cor){
	int posicao = x*4 + y*4*IMAGE_WIDTH;

	FBptr[posicao] = cor.R;
	FBptr[posicao + 1] = cor.G;
	FBptr[posicao + 2] = cor.B;
	FBptr[posicao + 3] = cor.A;
}

float tamanhoReta(int x1, int y1, int x2, int y2){
	return pow((pow((x2-x1),2) + pow((y2-y1), 2.0)), 0.5);
}

void interpolar(t_cor *cores, t_cor cor0, t_cor cor1,float tamanhoTotal, float tamanhoParcial){

	double t = tamanhoParcial/tamanhoTotal;

	cores->R = cor0.R * (1 -t) + cor1.R * t;
	cores->G = cor0.G * (1 -t) + cor1.G * t;
	cores->B = cor0.B * (1 -t) + cor1.B * t;
}



void drawLine(int x1,int y1,int x2,int y2, const t_cor cor){
	int x = x1;
	int y = y1;
	int dx = x2 - x1;
	int dy = y2 - y1;
	float tamanhoTotal = 0, tamanhoParcial = 0;
	bool decrex = false, decrey = false;
	t_cor cor_final;
	t_cor cor_inicial;
	cor_final.R = 0;
	cor_final.G = 200;
	cor_final.B = 0;
	cor_final.A = 255;

	x2 < x1 ? decrex = true : decrex = false;
	y2 < y1 ? decrey = true : decrey = false;

	tamanhoTotal = tamanhoReta(x1,y1,x2,y2); 

	if(dx == 0){
		while(y <= y2){
			tamanhoParcial = tamanhoReta(x,y,x2,y2);
			interpolar(&cor_inicial,cor,cor_final,tamanhoTotal, tamanhoParcial);
			putPixel(x, y,cor_inicial);
			decrey == true ? y-- : y++;
		}
	}else if(dy > dx){
		if(dx < 0){
			dx = -dx;
		}

		int p = 2*dx - dy;
		

		while(y <= y2){
			decrey == true ? y-- : y++;
			//decrex == true ? x-- : x++;

			if(p <= 0){
				p += 2 *dx;
			}else{
				p += 2 *(dx - dy);
				decrex == true ? x-- : x++;
				//decrey == true ? y-- : y++;
				//y++;
			}
			tamanhoParcial = tamanhoReta(x,y,x2,y2);
			interpolar(&cor_inicial,cor,cor_final,tamanhoTotal, tamanhoParcial);
			putPixel(x, y,cor_inicial);
		}
	}else{
		if(dy < 0){
			dy = -dy;
		}

		int p = 2*dy - dx;

		while(x <= x2){
			tamanhoParcial = tamanhoReta(x,y,x2,y2);
			interpolar(&cor_inicial,cor,cor_final,tamanhoTotal, tamanhoParcial);
			putPixel(x, y,cor_inicial);
			
			decrex == true ? x-- : x++;

			if(p < 0){
				p += 2 *dy;
			}else{
				p += 2 *(dy - dx);
				decrey == true ? y-- : y++;
			}
		}		
	}
}

void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, t_cor cor1, t_cor cor2, t_cor cor3){
	drawLine(x0, y0, x1, y1, cor1);
	drawLine(x1, y1, x2, y2, cor2);
	drawLine(x0, y0,x2, y2, cor3);
}



#endif // _MYGL_H_

