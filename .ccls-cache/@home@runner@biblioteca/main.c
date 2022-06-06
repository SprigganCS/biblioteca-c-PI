#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef int *image;

image leImage(char *nome, int *nl, int *nc, int *mn){
	FILE *arq;
	char line[100];
	int size;
	image img;
	arq = fopen(nome, "rt");
	fgets(line, 100, arq);
	fscanf(arq, "%d %d", nc, nl);
	fscanf(arq, "%d", mn);
	size = (*nc)*(*nl);
	//printf("%d %d", *nl, *nc);
	img = malloc(size * sizeof(int));
	for(int i =0; i<size; i++){
		fscanf (arq, "%d", img + 1);
	}
	return img;
}


void salvaImage(char *nome, image img, int nl, int nc, int mn){
	FILE *arq;
	int conta;
	arq = fopen(nome, "wt");
	fprintf(arq, "P2\n");
	fprintf(arq, "%d %d\n", nc, nl);
	fprintf(arq, "%d\n", mn);
	for(int i =0; i<nl*nc; i++){
		fprintf(arq, "%3d", img[i]);
		conta++;
		if((conta % 20)==0){
			fprintf(arq, "\n");
		}
	}
}

void operacao (image img, int nl, int nc, int mn){
	float T[mn+1];

	for(int i=0; i<=mn; i++){
		T[i]=log(i+1) / log (mn +1) *mn;
	}
	for (int i =0; i< nl*nc; i++){
		//img[i]= pow(img[i], 2) / pow(mn,2)*mn;
		//img[i]=T[img[i]];
		if(img[i] <=100){
			img[i] = 0;
		}else{
			img[i] = 255;
		}
	}
	
}

int main(int argc, char *argv[]) {
	char nome[100] = "img.pgm";
	char cmd[100]="eog ";
  image in;
	int nl, nc, mn;
	if(argc>1){
		strcpy (nome, argv[1]);
	}
	in=leImage(nome, &nl, &nc, &mn);
	operacao(in, nl, nc, mn);
	strcat (nome, "-saida.pgm");
	salvaImage(nome, in, nl, nc, mn);
	strcat(cmd, nome);
	//system("eog img-operacao.pgm"); //ao executar ja abre o visualizador
}