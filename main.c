/** @file       main.c
 *  @brief      This file is collecting the first star of the sky.
 *
 *  @copyright  Copyright (C) 2023 by Twins & Co. - Collecting stars and coding in north pole near you!
 *  @license    This source code is proprietary and subject to the Twins Co.
 *
 *  @author     Karine
 */

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include <aio.h>

int main()
{
    printf("Elves! Day 1 of collecting Stars\r\n");

    FILE* file = NULL;
    char* line = NULL;
    size_t len = 0;
    ssize_t nb_char = 0;
    int first_digit = 0xFF;
    int last_digit = 0xFF;
    int digit;
    int compteur = 0;
    int somme = 0;

    file = fopen("./Day1_input.txt", "r");
    if(file == NULL) {
        printf("Erreur : Le fichier ne s'ouvre pas!\r\n");
        exit(EXIT_FAILURE);
    }
    
    /* Tant que ce n'est pas la fin du fichier */
    while(digit != EOF) {
        /* Get le premier char */
        digit = fgetc(file);
        // printf("%c", digit);

        /* Si c'est un chiffre */
        if((digit >= 0x30) && (digit <= 0x39)) {
            if(first_digit == 0xFF) {
                first_digit = digit - 0x30;
            } else {
                last_digit = digit - 0x30;
            }
        }

        /* Sinon si c'est la fin de la ligne, il est temps d'additionner le nombre */
        else if((digit == '\n') || (digit == EOF)) {
            if((last_digit == 0xFF) && (first_digit == 0xFF)) {
                printf("Erreur\r\n");
            } else if (last_digit == 0xFF) {
                /* Dans le cas ou il n'y a qu'un seul chiffre */
                last_digit = first_digit;
            }
            printf("Fin de ligne \t%d\t%d \r\n", first_digit, last_digit);
            /* Additionne le nombre avec la somme de tous */
            somme += ((first_digit*10) + last_digit); 
            compteur++;
            first_digit = 0xFF;
            last_digit = 0xFF;
        }
    }

    printf("Nb de ligne : %d\r\n", compteur);
    printf("Somme : %d\r\n", somme);

    fclose(file);

    return 0;
}