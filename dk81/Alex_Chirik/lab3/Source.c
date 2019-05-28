#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>


int filesize(char *filename) {
	struct stat st;
	int ok;
	int res;

	ok = stat(filename, &st);

	if (ok == 0)
		res = st.st_size;
	else
		res = -1;

	return res;
}

void savetofile(char *filename, char *masiv) {
	FILE *f = fopen(filename, "ab");
	if (f != NULL)
	{
		fputs(masiv, f);
		fclose(f);
	}
}

int main() {
	char *masiv;
	int dlina;
	char alfavit_filename[] = "masiv.txt";
	char c;
	clock_t start, stop;
	dlina = filesize(alfavit_filename);

	FILE *f = fopen(alfavit_filename, "r");//открываем файл на чтение
	if (f == NULL) {
			;
		return 1;
	}
	masiv = malloc(dlina + 1);
	fread(masiv, 1, dlina, f);
	masiv[dlina] = 0;
	fclose(f);

	printf("Vedite 1 simvol ot a-z or A-Z: ");
	scanf_s("%c", &c);
	if (  !( (c >= 'a' && c <='z' ) || (c >= 'A' && c <= 'Z') )  ) {
		printf("ne vernoe znachenie simvola\n");
		return 2;
	}
	start = clock();	
	int n = linsearch(c, masiv, dlina);
	stop = clock();
	if (n == -1) {
			;
	}
	else {
		printf("simvol naiden, pozicia: %d\n", n);
		printf("Vremya %f ms\n", (double)(stop - start) / CLOCKS_PER_SEC);
	}

	printf("masiv:   %s\n", masiv);
	start = clock();
	quics(masiv, dlina);
	stop = clock();
	printf("QuickSort:       %s\n", masiv);
	printf("Vremya %f ms\n", (double)(stop - start) / CLOCKS_PER_SEC);
	savetofile("QuickSort.txt", masiv);


	free(masiv);

	system("PAUSE");
	return 0;	
}