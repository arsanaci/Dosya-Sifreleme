#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *myfile, *yazdosya;
	yazdosya = fopen("d:\\resim\\sifreli.jpg", "wb");
	if ((myfile = fopen("d:\\resim\\ornek.jpg", "rb")) == NULL)
		printf("dosya acilamadi");

	unsigned int key = 237;
	char c;

	while (!feof(myfile)) {

		fread(&c, sizeof(c), 1, myfile);
		c = c ^ key;
		fwrite(&c, sizeof(c), 1, yazdosya);
	}
	fclose(myfile);
	fclose(yazdosya);

	return EXIT_SUCCESS;
}
