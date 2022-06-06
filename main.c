#include <stdio.h>
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
	printf("%d %d", *nl, *nc);
	img = malloc(size * sizeof(int));
	for(int i =0; i<size; i++){
		fscanf (arq, "%d", img + 1);
	}
	return img;
}


void salvaImage(char *nome, image *img, int nl, int nc, int mn){
	FILE *arq;
	int conta;
	arq = fopen(nome, "wt");
	fprintf(arq, "P2\n");
	fprintf(arq, "%d %d\n", nc, nl);
	fprintf(arq, "%d\n", mn);
	for(int i =0; i<nl*nc; i++){
		fprintf(arq, "%3d", *img[i]);
		conta++;
		if((conta % 20)==0){
			fprintf(arq, "\n");
		}
	}
}

void operacao (image img, int nl, int nc, int mn){
	for (int i =0; i< nl*nc; i++){
		img[i]= mn - img[i];
	}
}

int main(void) {
  image in;
	int nl, nc, mn;
	in=leImage("img.txt", &nl, &nc, &mn);
	operacao(in, nl, nc, mn);
	salvaImage("img-operacao", &in, nl, nc, mn);
  return 0;
}