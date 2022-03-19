#define TAILLE_PRENOM 255

/*
STRUCTURE
*/

typedef struct elt
{
    int age;
    char prenom[TAILLE_PRENOM];
} elt_t;

typedef struct pile
{
    int taille;
    int sommet;
    elt_t *tetepile;
} pile_t;

typedef struct file
{
    int taille_max;
    int nb;
    int deb;
    int fin;
    int *base;
} file_t;

/*
ELEMENT
*/

void afficher_element(elt_t);
void init_element(elt_t *, int, char[]);

/*
PILE
*/

pile_t init_pile(int);
void afficher_pile(pile_t);
void empiler_pile(pile_t *, elt_t);
int est_vide_pile(pile_t);
void depiler_pile(pile_t *);
elt_t depiler_avec_retour_pile(pile_t *);
elt_t sommet_pile(pile_t);
void liberer_pile(pile_t *);

/*
FILE
*/

file_t init_file(int);
void afficher_file(file_t);
void entree_file(file_t *, int);
void sortie_file(file_t *);
int est_vide_file(file_t);
int est_pleine_file(file_t);
void liberer_file(file_t *);