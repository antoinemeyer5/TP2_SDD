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
    return (pile.sommet == -1); // si vide 1, sinon 0
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

elt_t sommet_pile(pile_t pile)
{
    return pile.tetepile[pile.sommet];
}

void liberer_pile(pile_t *pile)
{
    while (pile->sommet != -1)
    {
        free(pile->tetepile);
        pile->tetepile = NULL;
        pile->sommet = pile->sommet - 1;
    }
}

/*
FILE
*/

file_t init_file(int taille)
{
    file_t file;
    file.taille_max = taille;
    file.nb = 0;
    file.base = malloc(file.taille_max * sizeof(int));
    if (file.base == NULL)
    {
        free(file.base);
        file.base = NULL;
    }
    else
    {
        file.deb = 0;
        file.fin = file.taille_max - 1;
    }
    return file;
}

void afficher_file(file_t file)
{
    int i = 0;
    if (file.nb == 0)
    {
        printf("La file est vide.\n");
    }
    else
    {
        printf("La file a une taille max de %d. ", file.taille_max);
        printf("La file a %d élément(s).\n", file.nb);
        while (i <= file.taille_max - 1)
        {
            printf("élément n°%d : %d", i + 1, file.base[i]);
            if (i == file.deb)
            {
                printf(" -> deb");
            }
            if (i == file.fin)
            {
                printf(" -> fin");
            }
            i = i + 1;
            printf("\n");
        }
    }
}

void entree_file(file_t *file, int valeur)
{
    if (est_pleine_file(*file))
    {
        printf("file pleine, impossible d'entrer\n");
    }
    else
    {
        file->base[(file->deb + file->nb) % file->taille_max] = valeur;
        file->fin = (file->fin + 1) % file->taille_max;
        file->nb = file->nb + 1;
    }
}

void sortie_file(file_t *file)
{
    if (est_vide_file(*file))
    {
        printf("file vide, impossible de sortir\n");
    }
    else
    {
        file->base[file->deb] = 0; // remise à zéro, pas forcément opti mais cool visuellement
        file->deb = (file->deb + 1) % file->taille_max;
        file->nb = file->nb - 1;
    }
}

int est_vide_file(file_t file)
{
    return (file.nb == 0);
}

int est_pleine_file(file_t file)
{
    return (file.nb == file.taille_max);
}

void liberer_file(file_t *file)
{
}