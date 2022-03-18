#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "source.h"

/*
ELEMENT
*/

void afficher_element(elt_t element)
{
    printf("%s a %d ans.\n", element.prenom, element.age);
}

void init_element(elt_t *element, int age, char prenom[])
{
    element->age = age;
    strcpy(element->prenom, prenom);
}

/*
PILE
*/

pile_t init_pile(int taille)
{
    pile_t pile;
    pile.taille = taille;
    pile.sommet = -1;
    pile.tetepile = malloc(taille * sizeof(elt_t));
    if (pile.tetepile == NULL)
    {
        free(pile.tetepile);
        pile.tetepile = NULL;
    }
    return pile;
}

void afficher_pile(pile_t pile)
{
    int i;
    if (pile.sommet == -1)
    {
        printf("La pile est vide.\n");
    }
    else
    {
        for (i = pile.sommet; i >= 0; i--)
        {
            printf("%d : ", i + 1);
            afficher_element(pile.tetepile[i]);
        }
        printf("Bas de la pile\n");
    }
}

void empiler_pile(pile_t *pile, elt_t element)
{
    pile->sommet = pile->sommet + 1;
    pile->tetepile[pile->sommet] = element;
}

int est_vide_pile(pile_t pile)
{
    return (pile.sommet == -1); // Si vide 1, sinon 0
}

void depiler_pile(pile_t *pile)
{
    pile->sommet = pile->sommet - 1;
}

elt_t depiler_avec_retour_pile(pile_t *pile)
{
    elt_t element = pile->tetepile[pile->sommet];
    pile->sommet = pile->sommet - 1;
    return element;
}

/*
FILE
*/

// TODO