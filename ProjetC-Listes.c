#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef struct classe
{
    int Numero;
    char Libelle[20];
    char Professeur[20];
    int NbEleve;
    struct classe *suiv;
} classes;
classes *debut = NULL;

////////////////////////

void AjoutC(classes * C){ //Ajout a la fin de liste
    classes *Aux;
    if (debut == NULL)
    {
        debut = C;
        debut->suiv = NULL;
    }
    else
    {
        for (Aux = debut; Aux->suiv != NULL;
        Aux = Aux->suiv)
            ;
        Aux->suiv = C;
        C->suiv = NULL;
    }
}

////////////////////////

void Rechercher(int cd){
    classes *Aux;
    for (Aux = debut; Aux != NULL; Aux = Aux->suiv)
        if (Aux->Numero == cd)
        {
            printf("Numero:%d \n", Aux->Numero);
            printf("Libelle:%s \n", Aux->Libelle);
            printf("Professeur:%s \n", Aux->Professeur);
            printf("Nombre d'eleves:%d \n", Aux->NbEleve);
            break;
        }
    if (Aux == NULL)
        printf("Classe n'est pas existe\n");
}

////////////////////////
void afficher(){

    classes *Aux;
    for (Aux = debut; Aux != NULL; Aux = Aux->suiv)
    {
        Rechercher(Aux->Numero);
        printf("---------------------------------------\n");
    }
}
////////////////////////

void SupprimerC(int cd){

    classes *E;
    classes *Aux;
    if (debut == NULL)
        printf("La Liste est vide\n");
    else{
        if (debut->Numero == cd){
            E = debut;
            debut = E->suiv;
            free(E);
        }
        else
            for (Aux = debut; Aux->suiv != NULL; Aux = Aux->suiv)
                if (Aux->suiv->Numero == cd){
                    E = Aux->suiv;
                    Aux->suiv = E->suiv;
                    free(E);
                }
        printf("Classe supprime\n");
    }
}

////////////////////////

void MaxEleves(){
        int maxNbEleve = 0;
        classes *classeMax = NULL;
        classes *Aux;
        for (Aux = debut; Aux != NULL; Aux = Aux->suiv){
            if (Aux->NbEleve > maxNbEleve){
                maxNbEleve = Aux->NbEleve;
                classeMax = Aux;
            }
        }
        if (classeMax != NULL){
            printf("La classe avec le nombre maximum d'eleves est:\n");
            printf("Numero:%d \n", classeMax->Numero);
            printf("Libelle:%s \n", classeMax->Libelle);
            printf("Professeur:%s \n", classeMax->Professeur);
            printf("Nombre d'eleves:%d \n", classeMax->NbEleve);
        }
        else{
            printf("La Liste est vide\n");
        }
}

////////////////////////

void ProfMaxClasses() {
        int maxNbClasses = 0;
        char ProfMax[20] = "";
        classes *Aux1, *Aux2;
        for (Aux1 = debut; Aux1 != NULL; Aux1 = Aux1->suiv) {
            int nbClasses = 0;
            for (Aux2 = debut; Aux2 != NULL; Aux2 = Aux2->suiv) {
                if (strcmp(Aux1->Professeur, Aux2->Professeur) == 0) {
                    nbClasses++;
                }
            }
            if (nbClasses > maxNbClasses) {
                maxNbClasses = nbClasses;
                strcpy(ProfMax, Aux1->Professeur);
            }
        }
        if (maxNbClasses > 0) {
            printf("Le professeur qui encadre le plus grand nombre de classes est %s avec %d classes.\n", ProfMax, maxNbClasses);
        }
        else {
            printf("La Liste est vide\n");
        }
}

///////////////////////

void Menu(){
    printf("========= Menu =========\n");
    printf("1. Ajouter une classe\n");
    printf("2. Supprimer une classe\n");
    printf("3. Rechercher une classe\n");
    printf("4. Afficher la classe ayant le nombre max d'eleves\n");
    printf("5. Afficher la liste des classes\n");
    printf("6. Afficher le professeur qui encadre le plus grand nombre de classes\n");
    printf("0. Quitter\n");
    printf("\n ================== \n");

};

///////////////////////

int main(){
    int choix, d ,Supp;
    classes *CL;

    do{
        Menu();
        printf("\nEntrez votre choix: ");
        scanf("%d", &choix);
        switch (choix){
            case 1:
                CL = (classes *)malloc(sizeof(classes));
                printf("Numero:");
                scanf("%d", &CL->Numero);
                printf("Libelle:");
                scanf("%s", CL->Libelle);
                printf("Professeur:");
                scanf("%s", CL->Professeur);
                printf("Nombre d'Eleves:");
                scanf("%d", &CL->NbEleve);
                AjoutC(CL);
                break;

            case 2:
                printf("Numero  :");
                scanf("%d", &Supp);
                SupprimerC(Supp);
                break;

            case 3:
                printf("Numero :");
                scanf("%d", &d);
                Rechercher(d);
                break;

            case 4:
                MaxEleves();
                break;

            case 5:
                afficher();
                break;

            case 6:
                ProfMaxClasses();
                break;

            default:
                if (choix==0)
                    printf("=========FIN============\n");
                else
                    printf("=========ERREUR!!! Taper une valeur entre 0 et 6 ============\n");

        }

    } while (choix!=0);
}
