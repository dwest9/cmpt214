// Name: David Emmanuel
// Student Number: 11298443
// Couse: cmpt214 section03 Assignment3 
// NSID: Doe869
// Instructor: Tony Kusalik


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <err.h>



//opening the sales.dat file for reading

int main(){
    FILE *infile;

    infile = fopen("sales.dat", "r");
    if (infile == NULL){
        perror("sales.dat");
        errx(1, "Failed to open sales.dat");

    }
    //declaration of variables
    float next_sales = 0;
    float sum = 0;
    int total = 0;
    float average;
    int result;
    

    //this reads the sales data and prints them until end of file is reached
    while ((result = fscanf(infile, "%f", &next_sales)) != EOF) {
        sum = sum + next_sales;
        total++;
        
        if(result !=1){
            errx(1, "Error reading sales.dat");
        }

    }

    // this calculate the average for the sales transaction 
    average = sum / total;
    printf("Average value of a sales transaction: %.2f\n", average);


    //this closes the file
    fclose(infile);

    return 0;
}