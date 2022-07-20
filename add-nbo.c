#include <stdio.h>


int main(int argc, char *argv[]){
	FILE* f_td = fopen(argv[1], "rb");
	FILE* f_fh = fopen(argv[2], "rb");

	if(f_td == NULL && f_fh == NULL){
		printf("No file...\n");
		return 0;
	}
	
	int td;
	int fh;
	int sum;
	fread(&td, sizeof(int), 1, f_td);
	fread(&fh, sizeof(int), 1, f_fh);

	td = ntohl(td);
	fh = ntohl(fh);
	sum = td + fh;

	printf("%d(%#x) + %d(%#x) = %d(%#x)",td,td,fh,fh,sum,sum);

	fclose(f_td);
	fclose(f_fh);

	return 0;
}
