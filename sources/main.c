#include <stdio.h>
#include "source.h"
#include "tests.h"

int main()
{
    /*elt_t element_exemple;
    pile_t pile;
    pile = init_pile(15);
    init_element(&element_exemple, 22, "Antoine");
    empiler_pile(&pile, element_exemple);
    init_element(&element_exemple, 20, "Julie");
    empiler_pile(&pile, element_exemple);
    init_element(&element_exemple, 35, "Monsieur Aazi");
    empiler_pile(&pile, element_exemple);
    afficher_pile(pile);*/

    tous_les_tests();

    // METTRE CELA DANS LES TESTS //
    /*int vide = 0;
    vide = est_vide_pile(pile);
    printf("Pile vide ? : %d\n", vide);*/
    // depiler_pile(&pile);
    // element_exemple = depiler_avec_retour_pile(&pile);
    // element_exemple = sommet_pile(pile);
    // liberer_pile(&pile);

    file_t file;
    file = init_file(5);
    entree_file(&file, 4);
    entree_file(&file, 15);
    entree_file(&file, -23);
    entree_file(&file, 502);
    sortie_file(&file);
    afficher_file(file);
    printf("========\n");
    liberer_file(&file);
    afficher_file(file);

    return 0;
}