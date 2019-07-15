#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	t_cor cor1;
	cor1.R = 255;
	cor1.G = 0;
	cor1.B = 200;
	cor1.A = 255;

	t_cor cor2;
	cor2.R = 125;
	cor2.G = 0;
	cor2.B = 200;
	cor2.A = 255;

	t_cor cor3;
	cor3.R =125;
	cor3.G = 0;
	cor3.B =255;
	cor3.A = 255;
	
	/*Funaão para exemplificar o put pixel com duas cores
	for(int i = 0; i < 512; i+=10){
		for(int j = 512; j >= 0; j-=10){
			
			if(i <= 256){
				putPixel(i,j, cor);
			}else{
				cor.R = 0;
				cor.G = 255;
				cor.B = 0;
				cor.A = 150;
				putPixel(i,j, cor);
			}
		}
	}*/
/*
	drawLine(256, 0, 256, 256, cor);
	drawLine(256, 256, 256, 512, cor);
	drawLine(0, 256, 256, 256, cor);
	drawLine(256, 256, 512, 256, cor);
	drawLine(0, 0, 256, 256, cor);
	drawLine(256, 256, 512, 512, cor);
	drawLine(256, 256,0, 512, cor);
	drawLine(512, 0, 256, 256, cor);
	drawLine();
*/

	drawTriangle(256, 106, 106, 406, 406, 406, cor1, cor2, cor3);

}


//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

