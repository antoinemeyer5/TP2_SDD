#include <stdio.h>
#include "source.h"

int main()
{
    elt_t antoine;
    elt_t julie;
    elt_t fahd;

    pile_t pile;

    int vide = 0;

    pile = init_pile(15);

    init_element(&antoine, 22, "Antoine");
    init_element(&julie, 20, "Julie");
    init_element(&fahd, 35, "Monsieur Aazi");

    empiler_pile(&pile, antoine);
    empiler_pile(&pile, julie);
    empiler_pile(&pile, fahd);

    afficher_pile(pile);

    /*vide = est_vide_pile(pile);
    printf("Pile vide ? : %d\n", vide);*/

    // depiler_pile(&pile);

    // antoine = depiler_avec_retour_pile(&pile);

    return 0;
}