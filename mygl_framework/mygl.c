#include "mygl.h"

//
// >>> Defina aqui as funções que você implementar <<<
//


//A função PutPixel recebe a coordenada do pixel e sua determinada cor, e então escreve o pixel em seu determinador
void PutPixel(int x, int y, struct RGBA color){

	fb_ptr[4*x + 4*y*IMAGE_WIDTH + 0] = color.red;
	fb_ptr[4*x + 4*y*IMAGE_WIDTH + 1] = color.green;
	fb_ptr[4*x + 4*y*IMAGE_WIDTH + 2] = color.blue;
	fb_ptr[4*x + 4*y*IMAGE_WIDTH + 3] = color.alpha; 


//Os valores de red, green, blue e alpha devem ser entre 0-255
}

int CheckLine(struct Point pontoA, struct Point pontoB){

	float m;
	float dx, dy;
	
	dx = pontoB.x - pontoA.x;
	dy = pontoB.y - pontoA.y;
	
	m =  dy/dx;
	
	//Parâmetros para possibilitar a criação de retas verticais.
	if(dx == 0 && pontoA.y < pontoB.y){
		return 2;
		//caso não tenha variação no x será desenhado uma linha verticalmente, assim basta o resolvedor do 2º octante resolver.
	}else if( dx == 0 && pontoA.y > pontoB.y){
		return 6;
	}
	
	//Parâmetros para possibilitar a criação de retas horizontais.
	if(dy == 0 && pontoA.x < pontoB.x){
		return 1;
	}else if(dy == 0 && pontoA.x > pontoB.x){
		return 5;	
	}
	
	//Condições para descobrir em que octante a reta está localizada.
	if(m>=0 && m<=1 && pontoA.x < pontoB.x){
		//Faz parte do primeiro octante. Nenhuma alteração será feita.
		return 1;
	}else if(m>1 && m< 100000 && pontoA.y <pontoB.y){

		return 2;
	}else if(m<-1 && m> -100000 && pontoA.y < pontoB.y){
	
		return 3;
	}else if(m<=0 && m>=-1 && pontoB.x < pontoA.x){
		//faz parte do quarto octante.
		return 4;	
	}else if(m>0 && m<=1 && pontoB.x < pontoA.x){
		
		return 5;
	}else if(m>1 && m < 100000 && pontoB.y < pontoA.y){

		return 6;	
	}else if(m<-1 && m> -100000 && pontoB.y < pontoA.y){
		
		return 7;
	}else if(m<0 && m >=-1 && pontoA.x < pontoB.x){

		return 8;
	}
	

	return -1;
	
}


void DrawLine(struct Point pontoA, struct Point pontoB, struct RGBA color){
	
	int x,y;
	int dx,dy;
	int aux1,aux2;
	
	int decisao, inc_NE, inc_L;
	int octante = -1;
	
	
	octante = CheckLine(pontoA, pontoB);
	
	if(octante == 1){
		PutPixel(pontoA.x, pontoA.y, color);
	}else if(octante == 2){
		//Para resolver retas no segundo octante é necessário colocar o x em função do y.
		aux1 = pontoA.x;
		aux2 = pontoB.x;
		pontoA.x = pontoA.y;
		pontoB.x = pontoB.y;
		
		pontoA.y = aux1;
		pontoB.y = aux2;
		
		PutPixel(pontoA.y, pontoA.x, color);
	}else if(octante == 3){
				
		aux1 = pontoA.x;
		aux2 = pontoB.x;
		pontoA.x = pontoA.y;
		pontoB.x = pontoB.y;
		
		pontoA.y = aux2;
		pontoB.y = aux1;
		
		PutPixel(pontoB.y, pontoA.x, color);

	}else if(octante == 4){

		aux1 = pontoB.x;
		
		pontoB.x = pontoA.x;
		pontoA.x = aux1;
		
		PutPixel(pontoA.x, pontoB.y, color);
	}else if(octante == 5){
		
		/*Troca os valores do ponto inicial com o final, assim vice-versa. Com isso é possível utilizar esses valores
		  no formato do 1º octante.
		*/
		aux1 = pontoA.x;
		pontoA.x = pontoB.x;
		pontoB.x = aux1;
		
		aux2 = pontoA.y;
		pontoA.y = pontoB.y;
		pontoB.y = aux2;
		
		PutPixel(pontoA.x, pontoA.y, color);
	}else if(octante == 6){
		/*Troca os valores do ponto inicial com o final, assim vice-versa. Com isso é possível utilizar esses valores
		  no formato do 2º octante.
		*/
		aux1 = pontoB.x;
		aux2 = pontoB.y;
		
		pontoB.x = pontoA.y;
		pontoB.y = pontoA.x;
		
		pontoA.y = aux1;
		pontoA.x = aux2;
		
		PutPixel(pontoA.y, pontoA.x, color);
	}else if (octante == 7){

		aux1 = pontoA.x;
		aux2 = pontoB.x;
		pontoA.x = pontoB.y;
		pontoB.x = pontoA.y;
		
		pontoA.y = aux1;
		pontoB.y = aux2;
		
		PutPixel(pontoB.y, pontoA.x, color);
	}else if (octante == 8){

		aux1 = pontoB.y;
		
		pontoB.y = pontoA.y;
		pontoA.y = aux1;
	}

	dx = pontoB.x - pontoA.x;
	dy = pontoB.y - pontoA.y;

	decisao = (2*dy) - dx;	
	
	inc_L = 2*dy;
	inc_NE = 2*(dy - dx);
	
	if(octante == 4 || octante == 8 || octante == 3 || octante == 7){
		x = pontoA.x;
		y = pontoB.y;
	}else{
		x = pontoA.x;
		y = pontoA.y;	
	}

	
	while(x < pontoB.x){
		if(decisao<=0){
			decisao += inc_L;
			x++;
		}else{
			decisao += inc_NE;
			x++;
	
			if(octante != 4 && octante !=8 && octante !=3 && octante !=7){
				y++;
			}else{
				y--;			
			}		
				
		}
		
		if(octante == 1 || octante == 5 || octante == 4 || octante == 8){
			PutPixel(x, y, color);	//Caso seja o primeiro quadrante, nada será feito.
		}else if(octante == 2 || octante == 6 || octante == 3|| octante == 7){
			PutPixel(y, x, color);
		}
	}

}

void DrawTriangle(struct Point pontoA, struct Point pontoB, struct Point pontoC, struct RGBA color){

	DrawLine(pontoA, pontoB, color);
	DrawLine(pontoB, pontoC, color);
	DrawLine(pontoC, pontoA, color);

}
// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {
    //
    // >>> Chame aqui as funções que você implementou <<<
    //
	struct RGBA color;
	struct Point pontoA, pontoB, pontoC;

	int xA,xB,xC,yA,yB,yC;

	color.red = 255;
	color.green = 0;
	color.blue = 0;
	color.alpha = 255;
	
	xA = 123;
	yA = 121;

	xB = 45;
	yB = 65;

	xC = 345;
	yC = 100;
	
	pontoA.x = xA;
	pontoA.y = yA;

	pontoB.x = xB;
	pontoB.y = yB;

	pontoC.x = xC;
	pontoC.y = yC;
	
	DrawTriangle(pontoA, pontoB, pontoC, color);

	// Debug
	color.red = 0;
	color.green = 0;
	color.blue = 255;
	color.alpha = 255;
	
	// Debug
	PutPixel(xA,yA, color);
	PutPixel(xB,yB, color);
	PutPixel(xC,yC, color);
}
