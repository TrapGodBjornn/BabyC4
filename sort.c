#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void usage();
int is_valid_num(char *word);
void swap(double *x, double *y);
void sort(double *a, int length);

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

int main(int argc, char *argv[])
{
    return 0;
}
