#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*************************** variables globales *************************/
char cTabmorp[3][3] ={{' ',' ', ' '},{' ', ' ', ' '},{' ', ' ',' '}}; // tableau position des pions
int iSaisie[2]; //pour contrôle erreur
int cptTour=0; // compteur pour tours
int x, y=0;
int controle=0;
int ctabvaleur[3][3]={{0,0,0},{0,0,0},{0,0,0}};
/*****************************proto*****************************/

void affichage (); // pour affichage pour le joueur
void tourj1(); // compte les tours joueur 1
void tourj2(); // compte les tours joueur 2
bool testligne(); // fonction d'erreur pour ligne
bool testcolonne(); //fonction d'erreur pour colonne
bool caseprise(); //contrôle si la case est déjà prise
void analyseresult(); //analyse du résultat
void compteurtours(); //permet de générer plusieurs tours

 /************************definitions***********************/

void affichage() {
    printf("     0            1             2      \n");
    printf("0    %c      |     %c     |       %c      \n",cTabmorp[0][0],cTabmorp[0][1],cTabmorp[0][2]);
    printf("------------|-----------|---------------\n");
    printf("1    %c      |     %c     |       %c      \n",cTabmorp[1][0],cTabmorp[1][1],cTabmorp[1][2]);
    printf("------------|-----------|---------------\n");
    printf("2    %c      |     %c     |       %c      \n",cTabmorp[2][0],cTabmorp[2][1],cTabmorp[2][2]);

   /*
     printf("     0            1             2      \n");
     printf("0    %i      |     %i     |       %i      \n",ctabvaleur[0][0],ctabvaleur[0][1],ctabvaleur[0][2]);
     printf("------------|-----------|---------------\n");
     printf("1    %i      |     %i     |       %i      \n",ctabvaleur[1][0],ctabvaleur[1][1],ctabvaleur[1][2]);
     printf("------------|-----------|---------------\n");
     printf("2    %i      |     %i     |       %i      \n",ctabvaleur[2][0],ctabvaleur[2][1],ctabvaleur[2][2]);
Tableau de valeur 3 ou 5 suivant le joueur
    */
}

void tourj1() {
    do {
        do {
            printf("Joueur 1, Veuillez saisir le numéro de la ligne\n");
            scanf("%d", &x);
        } while (testligne() == false); //test hors tableau
        do {
            printf("Joueur 1, Veuillez saisir le numéro de la colonne\n");
            scanf("%d", &y);
        } while (testcolonne() == false); //test hors tableau
    }while (caseprise() == false);
    cTabmorp[x][y] = 'X';
    ctabvaleur[x][y] = 3; //place la valeur 3 pour un X.
}
void tourj2() {
    do {
        do {
            printf("Joueur 2, Veuillez saisir le numéro de la ligne\n");
            scanf("%d", &x);
        } while (testligne() == false); //test hors tableau
        do {
            printf("Joueur 2, Veuillez saisir le numéro de la colonne\n");
            scanf("%d", &y);
        } while (testcolonne() == false); //test hors tableau
    }while (caseprise() == false);
        cTabmorp[x][y] = 'O';
        ctabvaleur[x][y] = 5;  //place la valeur 5 pour un O
}


/********************Contrôle d'erreur********************/
bool testligne(){
    if (x==0 || x==1 || x==2) {
        return true;
    } else
        printf("saisie hors tableau, Veuillez recommencer votre saisie\n");
    return false;
//Si sur la saisie du joueur est hors tableau, bool = false
}

bool testcolonne() {
    if (y == 0 || y == 1 || y == 2) {
        return true;
    } else
        printf("saisie hors tableau, Veuillez recommencer votre saisie\n");
    return false;
    //Si sur la saisie du joueur est hors tableau, bool = false
}

bool caseprise(){
    if(ctabvaleur[x][y] !=0) {
        printf("Case déjà prise, veuillez recommencer\n");
        return false;
    }else
    return true;
// si la case est déjà prise (donc différente de 0) bool = false
}

/*********************************************Analyse resultat********************************************************/

    void analyseresult() {
    int itabadd[3] = {0};

    /************analyse lignes**************/
    for (int x = 0; x < 3; x++) {
        int ligne = 0;
        for (int y = 0; y < 3; y++) {
            itabadd[x] = ctabvaleur[x][y];
            ligne = ligne + itabadd[x];
            if (ligne == 9)
                printf("Bravo joueur 1 c'est gagné!\n");
            else if (ligne == 15)
                printf("Bravo joueur 2 c'est gagné!\n");


        }
    }
/***************Analyse colonne*************/
    for (int y = 0; y < 3; y++) {
        int colonne = 0;
        for (int x = 0; x < 3; x++) {
            itabadd[x] = ctabvaleur[x][y];
            colonne = colonne + itabadd[x];
            if (colonne == 9)
                printf("\nBravo joueur 1 c'est gagné!\n");
            else if (colonne == 15)
                printf("\nBravo joueur 2 c'est gagné!\n");
        }
    }
/************Analyse diag***************/
    if (ctabvaleur[0][0] ==  ctabvaleur[1][1] && ctabvaleur[1][1]== ctabvaleur[2][2] && ctabvaleur[0][0]== ctabvaleur[2][2]) {
        if (ctabvaleur[0][0]==3){
            printf("\nBravo joueur 1 c'est gagné\n");}
            else if (ctabvaleur[0][0]==5){
                printf("\nBravo joueur 2 c'est gagné\n");

            }
    }

    else {
        if (ctabvaleur[0][2] == ctabvaleur[1][1]  && ctabvaleur[0][2]==ctabvaleur[2][0] && ctabvaleur[1][1]== ctabvaleur[2][0] ){
            if (ctabvaleur[0][2]==3){
                printf("\nBravo joueur 1 c'est gagné\n");}
            else if (ctabvaleur[0][2]==5){
                printf("\nBravo joueur 2 c'est gagné\n");

            }
    }

}
}
/****************************************compteur tours*********************************/
void compteurtours(){
    for (int i = 0; i < 10; i++) {
        tourj1();
        analyseresult();
        affichage();
        tourj2();
        analyseresult();
        affichage();
    }
}


int main() {
    affichage();
    compteurtours();
    return 0;
}

//Notre code est terminé. Malheureusement, il n'y a rien qui stoppe le jeu une fois
//qu'un joueur à gagné (au milieu de la partie)
