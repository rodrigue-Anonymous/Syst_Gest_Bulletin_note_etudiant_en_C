
#include <stdio.h>
#include <string.h>

#define NB_ETUDIANTS 2
#define NB_MATIERES 5

int main() {
    char prenom[NB_ETUDIANTS][20];//tableu pour stoker les prenoms dse etudiants
    char noms[NB_ETUDIANTS][20];  // tableau pour stocker les noms des étudiants
    float notes[NB_ETUDIANTS][NB_MATIERES];  // tableau pour stocker les notes
    float moyennes[NB_ETUDIANTS];  // tableau pour stocker les moyennes des étudiants
    float moyennesMatieres[NB_MATIERES];  // tableau pour stocker les moyennes des matières
    float moyenneClasse = 0;  // variable pour stocker la moyenne de la classe
    float plusForteMoyenne = 0;  // variable pour stocker la plus forte moyenne
    float plusFaibleMoyenne = 100;  // variable pour stocker la plus faible moyenne
    char* mentions[NB_ETUDIANTS];
    int i, j;
    int rang[NB_ETUDIANTS] ;
    char information1[20];
    char information2[20];
    FILE *fichier = fopen("resultats.txt", "w");

    // saisie des noms et des notes
    for (i = 0; i < NB_ETUDIANTS; i++) {
        printf("Entrez le nom de l'etudiant %d:", i + 1);
        scanf("%s", noms[i]);
        printf("Entrez le prenom de l'etudiant %d:", i + 1);
        scanf( "%s",prenom[i]);
        for (j = 0; j < NB_MATIERES; j++) {
            printf("Entrez la note %d de l'etudiant %d : ", j + 1, i + 1);
            scanf("%f", &notes[i][j]);
        }
        printf("\n");
    }

    // calcul des moyennes
    for (i = 0; i < NB_ETUDIANTS; i++) {
        float somme = 0;
        for (j = 0; j < NB_MATIERES; j++) {
            somme += notes[i][j];
            moyennesMatieres[j] += notes[i][j];
        }
        moyennes[i] = somme / NB_MATIERES;
        moyenneClasse += moyennes[i];


         // Attribution des mentions
         {

        if (moyennes[i] >= 18) {
            printf (" Vous avez mal entrez les notes\n");
        }else if (moyennes[i] >= 18) {
            mentions[i] = "excelent";
        }else if (moyennes[i] >= 16) {
            mentions[i] = "tres bien";
        } else if (moyennes[i] >= 14) {
            mentions[i] = "bien";
        } else if (moyennes[i] >= 12) {
            mentions[i] = "assez bien";
        } else if (moyennes[i] >= 10) {
            mentions[i] = "passable";
        } else {
            mentions[i] = "echec";
        } }


        if (moyennes[i] > plusForteMoyenne) {
            plusForteMoyenne = moyennes[i];
        }
        if (moyennes[i] < plusFaibleMoyenne) {
            plusFaibleMoyenne = moyennes[i];
        }
    }
    for (j = 0; j < NB_MATIERES; j++) {
        moyennesMatieres[j] /= NB_ETUDIANTS;
    }
    moyenneClasse /= NB_ETUDIANTS;

         // Calcul du rang de chaque étudiant
    for (int i = 0; i < NB_ETUDIANTS; i++) {
           rang[i] = 0;
        for (int j = 0; j < NB_ETUDIANTS; j++) {
            if (moyennes[j] > moyennes[i]) {
                rang[i]++;
            }
        }
        rang[i]= rang[i]+1;
    }


    // affichage des résultats
    printf("Moyennes par matiere :\n");
    for (j = 0; j < NB_MATIERES; j++) {
        printf("Matiere %d : %.2f\n", j + 1, moyennesMatieres[j]);
    }
    printf("...................................................\n");

    printf("Moyennes generales :\n");
    for (i = 0; i < NB_ETUDIANTS; i++) {
        printf("%s : %.2f\n", noms[i], moyennes[i]);
        printf("votre Mention est %s\n",mentions[i]);
        printf("votre rang est %d\n",rang[i]);
        printf(".........................................\n");

    }
    printf("\n");

    printf("Moyenne de la classe : %.2f\n", moyenneClasse);
    printf("Plus forte moyenne : %.2f\n", plusForteMoyenne);
    printf("Plus faible moyenne : %.2f\n", plusFaibleMoyenne);

      // Écriture des résultats dans le fichier
    for (int i = 0; i < NB_ETUDIANTS; i++) {
        fprintf(fichier, " B  U   L  L  E  T  T  I  N  de %s\n",noms[i]);

        fprintf(fichier, "  L'ETUDIANT %s %s a %.2f, %.2f, %.2f, %.2f, %.2f pour moyennes de ses cinq matière\n. De meme sa moyenne general est de %.2f avec une mention %s. Ce qui lui attribut le %d rang de la salle .\n",noms[i],prenom[i],notes[0][0],notes[0][1],notes[0][2],notes[0][3],notes[0][4],moyennes[i], mentions[i],rang[i]);
        fprintf(fichier,"   **********************************************************************************************************************************************\n");
        fprintf(fichier,"   *                              B U L L E T I N     DE        F I N        D'A N N E E     S C O L A I R E  2022/2003                         *\n");
        fprintf(fichier,"   **********************************************************************************************************************************************\n");
        fprintf(fichier,"   * NOM ET PRENOM             |Matière 1     |Matière 2     | Matière 3     | Matière 4       | Matière 5      | Moyenne      | Mention   *\n");
        fprintf(fichier,"   **********************************************************************************************************************************************\n");
        fprintf(fichier,"                                                                                                                                                *\n");
        fprintf(fichier,"   * %s                                                                                                                                     \n",noms[i]);
        fprintf(fichier,"   * %s                   |  Mat1=%.2f  |  Mat2=%.2f  |  Mat3=%.2f |  Mat4=%.2f  |  Mat5=%.2f          | Moy=%.2f       |Ment= %s       \n",prenom[i],notes[0][0],notes[0][1],notes[0][2],notes[0][3],notes[0][4],moyennes[i], mentions[i]);
        fprintf(fichier,"   **********************************************************************************************************************************************\n");
        fprintf(fichier,"                                                                                                                     |      Rang     *    %d     |\n",rang[i]);
        fprintf(fichier,"                                                                                                                     ****************************|\n");
        fprintf(fichier,"                                                                                                                     |     PEUT MIEUX FAIRE      |\n");
        fprintf(fichier,"                                                                                                                     *****************************\n");
        fprintf(fichier,"\n");
        fprintf(fichier,"\n");

    }


    // Nom de l'etudiant pour affichez son bulletin


    printf("Nom de l'étudiant dont vous voulez le bulletiin : ");
    scanf("%s",information1);
    printf("Prenom de l'étudiant dont vous voulez le bulletin : ");
    scanf("%s",information2);
    for (i = 0; i < NB_ETUDIANTS; i++) {
        if(strcmp(information1,noms[i])==0 && strcmp(information2,prenom[i])==0 ) {
             printf("%s %s: %.2f\n", noms[i], prenom[i],moyennes[i]);
             printf("votre Mention est %s\n",mentions[i]);
             printf("votre rang est %d\n",rang[i]);
             printf("   **********************************************************************************************************************************************\n");
             printf("   *                              B U L L E T I N     DE        F I N        D'A N N E E     S C O L A I R E  2022/2003                         *\n");
             printf("   **********************************************************************************************************************************************\n");
             printf("   * NOM ET PRENOM             |Matière 1     |Matière 2     | Matière 3     | Matière 4       | Matière 5      | Moyenne      | Mention   *\n");
             printf("   **********************************************************************************************************************************************\n");
             printf("   *                                                                                                                                            *\n");
             printf("   * %s                                                                                                                                     \n",noms[i]);
             printf("   * %s                   |  Mat1=%.2f  |  Mat2=%.2f  |  Mat3=%.2f |  Mat4=%.2f  |  Mat5=%.2f          | Moy=%.2f       |Ment= %s       \n",prenom[i],notes[0][0],notes[0][1],notes[0][2],notes[0][3],notes[0][4],moyennes[i], mentions[i]);
             printf("   **********************************************************************************************************************************************\n");
             printf("                                                                                                                     |      Rang     *    %d     |\n",rang[i]);
             printf("                                                                                                                     ****************************|\n");
             printf("                                                                                                                     |     PEUT MIEUX FAIRE      |\n");
             printf("                                                                                                                     *****************************\n");
         }
    }










    // recherche d'un étudiant
    //char nomRecherche[20]


    return 0;
}
