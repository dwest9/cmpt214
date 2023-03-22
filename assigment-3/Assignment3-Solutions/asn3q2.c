#include <stdio.h>
#include <err.h>

int main() {

    FILE* infile = fopen("sales.dat", "r");
    if( infile == NULL ) {
        perror("sales.dat");
        errx(1, "Unable to open sales.dat for reading.");
    }

    float sale = 0.0;
    float total = 0.0;
    int count=0;
    int result;
    while( (result = fscanf(infile, "%f", &sale)) != EOF) {
        // if fscanf() failed for some reason *other* than reaching end-of-file...
        if( result != 1) {
            errx(1, "Error reading a dollar amount from sales.dat.");
        }
        total += sale;
        count++;
    }
    fclose(infile);

    printf("The average sales transaction was valued at: $%.2f.\n", total/count);
}
