#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "source.h"
#include "tests.h"

/*
ELEMENT
*/

int test_init_element(elt_t *element, int age, char prenom[])
{
    int retour = 0;
    init_element(element, age, prenom);
    if (element->age == age && strcmp(element->prenom, prenom) == 0)
    {
        retour = 1;
    }
    return retour;
}

/*
PILE
*/

int test_init_pile(int taille)
{
    int retour = 0;
    pile_t pile;
    pile = init_pile(taille);
    if(pile.taille == taille && pile.sommet == -1){
        retour = 1;
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

    printf("\nPartie de tests : 1 = RAS, 0 = ERR\n");

    retour_des_tests = test_init_pile(10);
    printf("-> init pile : %d\n", retour_des_tests);

    retour_des_tests = test_init_element(&element_de_test, 22, "Antoine");
    printf("-> init element : %d\n", retour_des_tests);

}