#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
//#include"menu.h"
//#include"head.h"
typedef struct
{
    int identifiant;
    char titre[25];
    int deadline;
    char statut[40];
    char description[50];
} Tache;
//array
Tache taches[100];
// global variables :
int numTache;
char back;


int main()
{
    // declaration des variable.
    int choix;

    do
    {
        system("cls");
        afficherMenu();
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            ajouterTache();
            break;
        case 2:
            AfficherLesTaches();
            break;
        case 3:
            ModifierUneTache();
            break;
        case 4:
            //RechercherUneTache();

            break;
        case 5:
            // SupprimerUneTache();
            break;
        case 6:
            // Statistiques();
            break;
        case 0:
            printf("\t\t Au revoir ;)\n");
            break;
        default:
            printf("Choix invalide. Veuillez ressayer :\n");
            break;
        }
    }
    while (choix!=0);

    return 0;
}
void afficherMenu()
{
    printf("                 *************************************************************************************\n");
    printf("                 *                                     ToDo list                                     *\n");
    printf("                 *************************************************************************************\n");
    printf("                 *                              [1] l'ajout d'une tache.                             *\n");
    printf("                 *                                   [2] afficher.                                   *\n");
    printf("                 *                           [3] l'ajout d'une tache.                                *\n");
    printf("                 *                            [4] l'ajout d'une tache.                               *\n");
    printf("                 *                           [5] l'ajout d'une tache.                                *\n");
    printf("                 *                           [6] l'ajout d'une tache.                                *\n");
    printf("                 ************************************[0] Exit.****************************************\n");
    printf("\t\t le Choix : ");
}

void ajouterTache()
{
    int NombreDajout;
    printf("====>Combien de taches voulez-vous entrer : ");
    scanf("%d", &NombreDajout);

    for (int i = 0; i<NombreDajout; i++)
    {
        printf("                 *****************************l'ajout de tache numero %d*******************************\n",i+1);
        //printf("\tEntrer l'identifiant de la tache : ");
        // scanf("%d",&taches[i].identifiant);
        taches[i].identifiant=i+1;

        printf("----> Entrer le titre de la tache : ");
        getchar();
        gets(taches[i].titre);
        printf("\n");

        printf("----> Entrer le statut de la tache : ");
        getchar();
        gets(taches[i].statut);
        printf("\n");

        printf("----> Entrer le deadline de la tache : ");
        scanf("%d",&taches[i].deadline);
        printf("\n");

        printf("----> Entrer la description de la tache : ");
        getchar();
        gets(taches[i].description);
        printf("\n");

        printf("--------> BRAVO,Cette tache est ajoutee ;)\n");
        printf("\n");
        numTache ++;
    }
    printf("-->Appuyez sur n'importe quelle touche pour revenir au menu : ");
    scanf("%s",&back);
}
void AfficherLesTaches()
{
    int i,j;
    int TypeAffichage;
  if (numTache<=0)
    {
        printf("\n\t\tajouter une tache avant d'afficher :'(\n");
        printf("\n");
        printf("\tAppuyez n'importe quelle touche pour revenir au menu : ");
        scanf("%s",&back);
    }
    else
    {
        do
        {
            printf("\t[1] affichage normale .\n");
            printf("\t[2] affichage par tri alphabetique .\n");
            printf("\t[3] affichage par tri de deadline .\n");
            printf("\t\t le choix : ");
            scanf("%d",&TypeAffichage);
            switch(TypeAffichage)
            {

            case 1 :
                for(i=0; i<numTache; i++)
                {
                    printf("                 ===================================tache numero %d=====================================\n",i+1);
                    printf("\tl'dentifiant est : %d\n",taches[i].identifiant);
                    printf("\tle titre est : %s\n",taches[i].titre);
                    printf("\tla status est : %s\n",taches[i].statut);
                    printf("\tle description est : %s\n",taches[i].description);
                    printf("                 --------------------------------------------------------------------------------------\n");
                }
                printf("Appuyez n'importe quelle touche pour revenir au menu : ");
                scanf("%s",&back);
                break;
            case 2:
                for (i = 0; i < numTache - 1; i++)
                {
                    for (j = i + 1; j < numTache; j++)
                    {
                        if (strcmp(taches[i].titre, taches[j].titre) > 0)
                        {
                            // Swap the tasks
                            Tache temp = taches[i];
                            taches[i] = taches[j];
                            taches[j] = temp;
                        }
                    }
                }
                for (i = 0; i < numTache; i++)
                {
                    printf("=================================== Tache numero %d =====================================\n", i + 1);
                    printf("L'identifiant est : %d\n", taches[i].identifiant);
                    printf("Le titre est : %s\n", taches[i].titre);
                    printf("Le statut est : %s\n", taches[i].statut);
                    printf("La description est : %s\n", taches[i].description);
                    printf("-----------------------------------------------------------------------------------------\n");
                }
                printf("Appuyez n'importe quelle touche pour revenir au menu : ");
                scanf("%s",&back);
                break;


            }
        }

        while(TypeAffichage<0&&TypeAffichage>3);
    }
}
ModifierUneTache()
{
    if (numTache<=0)
    {
        printf("\n\t\tajouter une tache avant de modifier :'(\n");
        printf("\n");
        printf("\tAppuyez n'importe quelle touche pour revenir au menu : ");
        scanf("%s",&back);
    }
    else
    {
        int mod=0;
        for (int i = 0; i < numTache; i++)
        {
            printf("=================================== Tache numero %d =====================================\n", i + 1);
            printf("L'identifiant est : %d\n", taches[i].identifiant);
            printf("Le titre est : %s\n", taches[i].titre);
            printf("-----------------------------------------------------------------------------------------\n");

        }
        printf("entrer le numero de la tache qui vous vouler modifier : ");
        scanf("%d",&mod);

        printf("----> Entrer le nouveau titre de la tache : ");
        getchar();
        gets(taches[mod-1].titre);
        printf("\n");

        printf("----> Entrer la nouvelle statut de la tache : ");
        getchar();
        gets(taches[mod-1].statut);
        printf("\n");

        printf("----> Entrer le nouveua deadline de la tache : ");
        scanf("%d",&taches[mod-1].deadline);
        printf("\n");

        printf("----> Entrer la nouvelle description de la tache : ");
        getchar();
        gets(taches[mod-1].description);
        printf("\n");

        printf("--------> BRAVO,Cette tache est modifier ;)\n");
        printf("\n");
    }
}


