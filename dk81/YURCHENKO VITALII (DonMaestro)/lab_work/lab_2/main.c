#include <stdio.h>
#include <time.h>

#include <header.h>



void read_file(int max_char, char masiv[max_char]);
void write_file(int max_char, char masiv[max_char]);


int main()
{
    clock_t start_time;
    clock_t end_time;

    int max_char = 300;

    char masiv[max_char];




    read_file(max_char, masiv);
    printf("%s\n", masiv);

    start_time = clock();
    bubble(max_char, masiv);
    end_time = clock();

    printf("BUBBLE: %f\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    printf("%s\n", masiv);



    printf("\n");


    read_file(max_char, masiv);
    printf("%s\n", masiv);

    start_time = clock();
    insert(max_char, masiv);
    end_time = clock();

    printf("INSERT: %f\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    printf("%s\n", masiv);



    printf("\n");


    read_file(max_char, masiv);
    printf("%s\n", masiv);

    start_time = clock();
    selection(max_char, masiv);
    end_time = clock();

    printf("SELECTION: %f\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    printf("%s\n", masiv);



    write_file(max_char, masiv);


    return 0;

}






void read_file(int max_char, char masiv[max_char])
{
    FILE *fmasiv;

    if((fmasiv = fopen("masiv.txt", "rt")) == NULL)
        printf("ERROR:\n");


    fgets(masiv, max_char, fmasiv);

    fclose(fmasiv);
}



void write_file(int max_char, char masiv[max_char])
{
    FILE *fmasiv;

    if((fmasiv = fopen("sorted_masiv.txt", "w+t")) == NULL)
        printf("ERROR:\n");

    fprintf(fmasiv, "%s", masiv);


    //fwrite(masiv, sizeof(char), max_char, fmasiv);

    fclose(fmasiv);

}
