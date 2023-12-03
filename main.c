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
#include <string.h>
#include <aio.h>

/* Grosses variable globales */
static int first_digit = 0xFF;
static int last_digit = 0xFF;
static int position_first_digit = 0x800000FF;
static int position_last_digit = 0xFF;

static int find_alphabet_digit(char* line, char* alphabetToFind, char* digitToFind, int digit);

int main() {
    printf("Elves! Day 1 of collecting Stars\r\n");

    FILE* file = NULL;
    char* line = NULL;
    size_t len = 0;
    ssize_t nb_char = 0;

    int compteur = 0;
    int somme = 0;

    file = fopen("./Day1_input.txt", "r");
    if(file == NULL) {
        printf("Erreur : Le fichier ne s'ouvre pas!\r\n");
        exit(EXIT_FAILURE);
    }

    nb_char = getline(&line, &len, file);
    while(nb_char != -1) {
        /* Pour chaque ligne on verifie la position du premier chiffre en lettre ou en chiffre */
        if(find_alphabet_digit(line, "one", "1", 1)) {
            // printf("One or 1 have been found\tfirst Posi %d\t last posi %d\r\n", position_first_digit, position_last_digit);
        }

        if(find_alphabet_digit(line, "two", "2", 2)) {
            // printf("Two or 2 have been found\tfirst Posi %d\t last posi %d\r\n", position_first_digit, position_last_digit);
        }

        if(find_alphabet_digit(line, "three", "3", 3)) {
            // printf("three or 3 have been found\tfirst Posi %d\t last posi %d\r\n", position_first_digit, position_last_digit);
        }

        if(find_alphabet_digit(line, "four", "4", 4)) {
            // printf("Four or 4 have been found\tfirst Posi %d\t last posi %d\r\n", position_first_digit, position_last_digit);
        }

        if(find_alphabet_digit(line, "five", "5", 5)) {
            // printf("Five or 5 have been found\tfirst Posi %d\t last posi %d\r\n", position_first_digit, position_last_digit);
        }

        if(find_alphabet_digit(line, "six", "6", 6)) {
            // printf("Six or 6 have been found\tfirst Posi %d\t last posi %d\r\n", position_first_digit, position_last_digit);
        }

        if(find_alphabet_digit(line, "seven", "7", 7)) {
            // printf("Seven or 7 have been found\tfirst Posi %d\t last posi %d\r\n", position_first_digit, position_last_digit);
        }

        if(find_alphabet_digit(line, "eight", "8", 8)) {
            // printf("Eight or 8 have been found\tfirst Posi %d\t last posi %d\r\n", position_first_digit, position_last_digit);
        }

        if(find_alphabet_digit(line, "nine", "9", 9)) {
            // printf("Nine or 9 have been found\tfirst Posi %d\t last posi %d\r\n", position_first_digit, position_last_digit);
        }

        compteur++;
        /* On va chercher la prochaine ligne */
        nb_char = getline(&line, &len, file);
        /* On ajoute la somme du nombre de la ligne */
        printf("first Digit: %d\tLast Digit: %d\r\n", first_digit, last_digit);
        somme += ((first_digit*10) + last_digit);
        printf("somme : %d\r\n", somme);
        /* On reset les valeurs pour trouver le prochaine nombre de la prochaine ligne */
        first_digit = 0xFF;
        last_digit = 0xFF;
        position_first_digit = 0x800000FF;
        position_last_digit = 0xFF;
    }

    printf("Nb de ligne : %d\r\n", compteur);
    printf("Somme : %d\r\n", somme);
    fclose(file);

    return 0;
}

static int find_alphabet_digit(char* line, char* alphabetToFind, char* digitToFind, int digitToSet) {
    char* alphabet_digit = NULL;
    char* digit = NULL;
    int test = 0;
    int position_current_digit = 0xFF;

    alphabet_digit = strstr(line, alphabetToFind);
    digit = strstr(line, digitToFind);

    if(alphabet_digit != NULL) {
        while(alphabet_digit != NULL) {
            test++;
            if(test >= 10) {
                test = 0;
                // printf("ALPHA test first posi: %d\tdigit: %d\r\n", position_first_digit, first_digit);
                // printf("ALPHA test last posi: %d\tdigit: %d\r\n", position_last_digit, last_digit);
                break;
            }
            // printf("nb de fois que je fais la boucle : %d\r\n", test);
            position_current_digit = strlen(alphabet_digit);
            // printf("Substring trouvée : %s\r\n", alphabet_digit);
            // printf("strlen sur le chiffre trouvé : %d\r\n", strlen(alphabet_digit));
            if(position_current_digit > position_first_digit) {
                first_digit = digitToSet;
                position_first_digit = position_current_digit;
            }
            if(position_current_digit < position_last_digit) {
                last_digit = digitToSet;
                position_last_digit = position_current_digit;
            }
            alphabet_digit++;
            alphabet_digit = strstr(alphabet_digit, alphabetToFind);
        }
        // printf("Alphabet %s have been found\r\n", alphabetToFind);
    }

    if(digit != NULL) {
        test = 0;
        while(digit != NULL) {
            test++;
            if(test >= 10) {
                test = 0;
                // printf("DIGIT test first posi: %d\tdigit: %d\r\n", position_first_digit, first_digit);
                // printf("DIGIT test last posi: %d\tdigit: %d\r\n", position_last_digit, last_digit);
                break;
            }
            // printf("nb de fois que je fais la boucle : %d\r\n", test);
            position_current_digit = strlen(digit);
            // printf("Substring trouvée : %s\r\n", alphabet_digit);
            // printf("strlen sur le chiffre trouvé : %d\r\n", strlen(alphabet_digit));
            if(position_current_digit > position_first_digit) {
                first_digit = digitToSet;
                position_first_digit = position_current_digit;
            }
            if(position_current_digit < position_last_digit) {
                last_digit = digitToSet;
                position_last_digit = position_current_digit;
            }
            digit++;
            digit = strstr(digit, digitToFind);
        }
        // printf("Digit %s have been found\r\n", digitToFind);
        return 1;
    } else {
        // printf("No\r\n");
        return 0;
    }
}
