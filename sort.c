#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void usage(){	
	printf("sort [-r] num1 num2 ...\n");

}
	
void swap(double *x, double *y){
	if (x == NULL || y == NULL){
		printf("sort [-r] num1 num2 ...\n");
		
	}
	if (x!= y){
		double stuf = *x;
		*x = *y;
		*y = stuf;
	}
}

void sort(double *a, int length){
	if (a == NULL) {
		printf("sort [-r] num1 num2 ...\n");	
		
	}	
	int i =1;
	while (i<length){
		int j=i;
		while (j>0 && a[j-1] >a[j]){
			swap(&a[j], &a[j-1]);
			j = j-1;
		}
		i = i+1;
	}
}

int is_valid_num(char *word)
{
    int found_dot = 0;

    for (int i=0; i<strlen(word); ++i)
    {
        if (word[i] == '-')
        {
            if (i != 0)
            {
                return 0;
            }
            continue;
        }

        if (word[i] == '.')
        {
            if (found_dot == 1)
            {
                return 0;
            }
            found_dot = 1;
            continue;
        }

        if (!isdigit(word[i]))
        {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char *argv[]){
	if (argc < 2){
		usage();
	}

	int reverse = 0;
	int beginn = 1;

	if (argc > 2 && strcmp(argv[1], "-r") == 0){
		reverse = 1;
		beginn = 2; 
	}
	if (argc - beginn < 1) {
		usage();
	}
	int numboli = argc - beginn;
	double *numbers = malloc(numboli * sizeof(double));

	for (int i = 0; i < numboli; i++){
		char *endptr;
		numbers[i] = strtod(argv[beginn + i], &endptr);

	if (*endptr != '\0'){
		free(numbers);
		usage();
		}
	}
	sort(numbers, numboli);

	if (reverse) {
		for (int i = numboli - 1; i>=0; i--){
			printf("%g\n", numbers [i]);
		}
	}
	else {
		for (int i=0; i< numboli; i++){
			printf("%g\n",numbers[i]);
		}
	}
	free(numbers);
    	return 0;
}
