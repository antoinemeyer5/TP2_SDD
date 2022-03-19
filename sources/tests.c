#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "source.h"
#include "tests.h"

/*
ELEMENT
*/

int test_init_element()
{
    int retour = 0;
    elt_t element_test;
    int age_test = 22;
    char prenom_test[] = "Antoine";
    init_element(&element_test, age_test, prenom_test);
    if (element_test.age == age_test && strcmp(element_test.prenom, prenom_test) == 0)
    {
        retour = 1;
    }
    return retour;
}

/*
PILE
*/

int test_init_pile()
{
    int retour = 0;
    pile_t pile;
    int taille = 10;
    pile = init_pile(taille);
    if (pile.taille == taille && pile.sommet == -1)
    {
        retour = 1;
    }
    return retour;
}

int test_empiler_pile()
{
    elt_t element_test;
    pile_t pile;
    int retour = 0;
    char prenom_test[] = "Antoine";
    int age_test = 22;
    pile = init_pile(2);
    init_element(&element_test, age_test, prenom_test);
    empiler_pile(&pile, element_test);
    if (pile.sommet == 0 && pile.tetepile[pile.sommet].age == age_test)
    {
        if (strcmp(pile.tetepile[pile.sommet].prenom, prenom_test) == 0)
        {
            retour = 1;
        }
    }
    return retour;
}

/*
GENERAL
*/

void tous_les_tests()
{
    int retour_des_tests = -1;
    elt_t element_de_test;
    pile_t pile_de_test;

    printf("\nPartie de tests : 1 = RAS, 0 = ERR\n");

    retour_des_tests = test_init_pile();
    printf("-> init pile : %d\n", retour_des_tests);

    retour_des_tests = test_init_element();
    printf("-> init element : %d\n", retour_des_tests);

    retour_des_tests = test_empiler_pile();
    printf("-> empiler pile : %d\n", retour_des_tests);
}