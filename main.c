#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#include <windows.h>
#include<string.h>

//--------------------------------------------------------------------------------------------declaration de functions------------------------------------------------------------------------------------------------
void affichageDeMenu();
void affichageDesTaches();
void ajoutDeslesTaches();
void ModificationDesTaches();
void supprissionDeslesTaches();
void rechercheDeslesTaches();
void statistiques();
//--------------------------------------------------------------------------------------------declaration de structure-------------------------------------------------------------------------------------------------
typedef struct
{
    int annes;
    int mois;
    int jour;
} temp;
typedef struct
{
    int ID;
    char titre[25];
    //int deadLine;
    temp deadLine ;
    char statut[40];
    char description[50];
} Tache;
Tache lesTaches[100];


//--------------------------------------------------------------------------------------------------global variables---------------------------------------------------------------------------------------------------
int numTache=0;
char reutour;
int lesModifs=0;
int realiser,finalisee;
int id=0;

//--------------------------------------------------------------------------------------------------main functions---------------------------------------------------------------------------------------------------
int main()
{
    // declaration des locals variables.
    char choix[25];

    do
    {
        system("cls");
        affichageDeMenu();
        printf("\t\t le Choix : ");
m:
        scanf(" %s", &choix[1]);

        switch (choix[1])
        {
        case '1':
            ajoutDeslesTaches();
            break;
        case '2':
            affichageDesTaches();
            break;
        case '3':
            ModificationDesTaches();
            break;
        case '4':
            rechercheDeslesTaches();

            break;
        case '5':
            supprissionDeslesTaches();
            break;
        case '6':
            statistiques();
            break;
        case '0':
            printf("\t\t Au revoir ;)\n");
            exit(0);
            break;
        default:
            printf("Choix invalide. Veuillez ressayer :");
            goto m;
            break;
        }
    }
    while (choix!=0);

    return 0;
}

//--------------------------------------------------------------------------------------------------functions responsable d'afficher le menu---------------------------------------------------------------------------------------------------
void affichageDeMenu()
{
    printf("             *************************************************************************************\n");
    printf("             ************************************* ToDo list *************************************\n");
    printf("             *************************************************************************************\n");
    printf("             *                               [1] L'ajout des lesTaches.                          *\n");
    printf("             *                                   [2] Afficher.                                   *\n");
    printf("             *                            [3] Modifification d'une tache.                        *\n");
    printf("             *                              [4] Recherche d'une tache.                           *\n");
    printf("             *                             [5] supression d'une tache.                           *\n");
    printf("             *                                 [6] statistiques                                  *\n");
    printf("             **************************************[0] Exit.**************************************\n");
}
//--------------------------------------------------------------------------------------------------functions responsable d'ajouter les taches---------------------------------------------------------------------------------------------------
void ajoutDeslesTaches()
{
    int NombreDajout;
    int status;
    printf("====>Combien des taches voulez-vous entrer : ");
    scanf("%d", &NombreDajout);
    NombreDajout+=numTache;

    for (int i = numTache; i<NombreDajout; i++)
    {
        printf("                 *****************************l'ajout de tache numero %d*******************************\n",i+1);
        //printf("\tEntrer l'ID de la tache : ");
        // scanf("%d",&lesTaches[i].ID);
        lesTaches[i].ID=id+1;
        id++;

        printf("----> Entrer le titre de la tache %d : ",i+1);
        getchar();
        gets(lesTaches[i].titre);
        printf("\n");

        printf("----> Entrer la description de la tache %d: ",i+1);
        gets(lesTaches[i].description);
        printf("\n");


        do
        {
            printf("----> Entrer le nombre de statut de la tache %d: \n",i+1);
            printf("---------> [1] realiser                 \n");
            printf("---------> [2] en cours de realisation  \n");
            printf("---------> [3] finalisee                \n");
            printf("---------> ");
            scanf("%d",&status);
            switch(status)
            {
            case 1 :
                strcpy(lesTaches[i].statut,"realiser");
                realiser++;
                break;
            case 2 :
                strcpy(lesTaches[i].statut,"en cours de realisation");
                break;
            case 3 :
                strcpy(lesTaches[i].statut,"finalisee");
                finalisee++;
                break;
            }
        }
        while(status !=1 && status != 2 && status !=3);

        printf("---->le deadLine de la tache %d.\n",i+1);
        do
        {
            printf("--------->entrer le jour : ");
            scanf("%d",&lesTaches[i].deadLine.jour);
        }
        while(lesTaches[i].deadLine.jour<0 || lesTaches[i].deadLine.jour>31);
        do
        {
            printf("--------->entrer le mois : ");
            scanf("%d",&lesTaches[i].deadLine.mois);
        }
        while(lesTaches[i].deadLine.mois<0 || lesTaches[i].deadLine.mois>12);

        do
        {
            printf("--------->entrer l'annes : ");
            scanf("%d",&lesTaches[i].deadLine.annes);
            printf("\n");
        }
        while(lesTaches[i].deadLine.annes<2023);


        printf("--------> BRAVO,Cette tache %d est ajoutee ;)\n",i+1);
        printf("\n");
        numTache ++;

    }
    printf("-->Appuyez sur n'importe quelle touche pour revenir au menu : ");
    scanf("%s",&reutour);
}
//--------------------------------------------------------------------------------------------------functions responsable d'afficher les taches---------------------------------------------------------------------------------------------------
void affichageDesTaches()
{
    //----------------time.h lib----------------
    time_t date=time(NULL);


    struct tm temp=*localtime(&date);

    //-----------------------------------------
    int i,j;
    int TypeAffichage;
    if (numTache<=0)
    {
        printf("\n\t\tajouter une tache avant d'afficher :'(\n");
        printf("\n");
        printf("\tAppuyez n'importe quelle touche pour revenir au menu : ");
        scanf("%s",&reutour);
    }
    else
    {
        do
        {
            printf("\t[1] affichage normale .\n");
            printf("\t[2] affichage par tri alphabetique .\n");
            printf("\t[3] affichage par tri de deadLine .\n");
            printf("\t[4] Afficher les tâches dont le deadLine est dans 3 jours ou moins. \n");
            printf("\t\t le choix : ");
            scanf("%d",&TypeAffichage);
            switch(TypeAffichage)
            {

            case 1 :
                for(i=0; i<numTache; i++)
                {
                    printf("                 ===================================tache numero %d=====================================\n",i+1);
                    printf("\tl'dentifiant est : %d\n",lesTaches[i].ID);
                    printf("\tle titre est : %s\n",lesTaches[i].titre);
                    printf("\tla status est : %s\n",lesTaches[i].statut);
                    printf("\tle description est : %s\n",lesTaches[i].description);
                    printf("\tle deadLine est : %d/%d/%d\n",lesTaches[i].deadLine.annes,lesTaches[i].deadLine.mois,lesTaches[i].deadLine.jour);
                    printf("                 --------------------------------------------------------------------------------------\n");
                }
                printf("Appuyez n'importe quelle touche pour revenir au menu : ");
                scanf("%s",&reutour);
                break;
            case 2:
                for (i = 0; i < numTache - 1; i++)
                {
                    for (j = i + 1; j < numTache; j++)
                    {
                        if (strcmp(lesTaches[i].titre, lesTaches[j].titre) > 0)
                        {
                            Tache temp = lesTaches[i];
                            lesTaches[i] = lesTaches[j];
                            lesTaches[j] = temp;
                        }
                    }
                }
                for (i = 0; i < numTache; i++)
                {
                    printf("=================================== Tache numero %d =====================================\n", i + 1);
                    printf("L'Identifiant est : %d\n", lesTaches[i].ID);
                    printf("Le titre est : %s\n", lesTaches[i].titre);
                    printf("La statut est : %s\n", lesTaches[i].statut);
                    printf("La description est : %s\n", lesTaches[i].description);
                    printf("\tle deadLine est : %d/%d/%d\n",lesTaches[i].deadLine.annes,lesTaches[i].deadLine.mois,lesTaches[i].deadLine.jour);
                    printf("-----------------------------------------------------------------------------------------\n");
                }
                printf("Appuyez n'importe quelle touche pour revenir au menu : ");
                scanf("%s",&reutour);
                break;
            case 3:
                for (i = 0; i < numTache - 1; i++)
                {
                    for (j = i + 1; j < numTache; j++)
                    {
                        if (lesTaches[i].deadLine.mois*30+lesTaches[i].deadLine.jour+lesTaches[i].deadLine.annes*365>lesTaches[j].deadLine.mois*30+lesTaches[j].deadLine.jour+lesTaches[j].deadLine.annes*365)
                        {
                            // Swap the tasks
                            Tache temp = lesTaches[i];
                            lesTaches[i] = lesTaches[j];
                            lesTaches[j] = temp;
                        }
                    }
                }
                for (i = 0; i < numTache; i++)
                {
                    printf("=================================== Tache numero %d =====================================\n", i + 1);
                    printf("L'Identifiant est : %d\n", lesTaches[i].ID);
                    printf("Le titre est : %s\n", lesTaches[i].titre);
                    printf("Le statut est : %s\n", lesTaches[i].statut);
                    printf("La description est : %s\n", lesTaches[i].description);
                    printf("\tle deadLine est : %d/%d/%d\n",lesTaches[i].deadLine.annes,lesTaches[i].deadLine.mois,lesTaches[i].deadLine.jour);
                    printf("-----------------------------------------------------------------------------------------\n");
                }
                printf("Appuyez n'importe quelle touche pour revenir au menu : ");
                scanf("%s",&reutour);
                break;

            case 4:
                for (int i = 0; i < numTache; i++)
                {
                    if ((lesTaches[i].deadLine.mois - (temp.tm_mon+1)) * 30 + (lesTaches[i].deadLine.jour - temp.tm_mday )+ (lesTaches[i].deadLine.annes -1900 - temp.tm_year) * 365 <= 3)
                    {
                        printf("=================================== Tache numero %d =====================================\n", i + 1);
                        printf("L'Identifiant est : %d\n", lesTaches[i].ID);
                        printf("Le titre est : %s\n", lesTaches[i].titre);
                        printf("\tle deadLine est : %d/%d/%d\n", lesTaches[i].deadLine.annes, lesTaches[i].deadLine.mois, lesTaches[i].deadLine.jour);
                        printf("-----------------------------------------------------------------------------------------\n");
                    }
                    if((lesTaches[i].deadLine.mois - (temp.tm_mon+1)) * 30 + (lesTaches[i].deadLine.jour - temp.tm_mday )+ (lesTaches[i].deadLine.annes -1900 - temp.tm_year) > 3)
                    {
                        printf("\t\t !!! Il n'y a pas des Taches moins de 3 jours :( \n\n");
                    }

                }

                printf("\tAppuyez n'importe quelle touche pour revenir au menu : ");
                scanf("%s",&reutour);
                break;


            }
        }

        while(TypeAffichage<0&&TypeAffichage>3);
    }
}
//--------------------------------------------------------------------------------------------------functions responsable de modifier les taches---------------------------------------------------------------------------------------------------
void ModificationDesTaches()
{
    int typeDeModifs;
    int status;
    if (numTache<=0)
    {
        printf("\n\t\tajouter une tache avant de Modifier :'(\n");
        printf("\n");
        printf("\tAppuyez n'importe quelle touche pour revenir au menu : ");
        scanf("%s",&reutour);
    }
    else
    {
        for (int i = 0; i < numTache; i++)
        {
            printf("=================================== Tache numero %d =====================================\n", i + 1);
            printf("L'Identifiant est : %d\n", lesTaches[i].ID);
            printf("Le titre est : %s\n", lesTaches[i].titre);
            printf("-----------------------------------------------------------------------------------------\n");

        }
        printf("entrer le numero de la tache qui vous vouler Modifier : ");
        scanf("%d",&lesModifs);
        system("cls");
        affichageDeMenu();
        printf("----> quelle partie vous voullez modifier : \n");
        printf("------------------> [1] la description               \n");
        printf("------------------> [2] la status \n");
        printf("------------------> [3] le deadline       \n");
        printf("\t\t le choix : ");
        scanf("%d",&typeDeModifs);
        switch(typeDeModifs)
        {
        case 1:

            printf("----> Entrer la nouvelle description de la tache : ");
            getchar();
            gets(lesTaches[lesModifs-1].description);
            printf("\n");
            break;

        case 2:

            do
            {
                printf("----> Entrer le nombre de la nouvelle statut de votre tache : \n");
                printf("---------> [1] realiser                 \n");
                printf("---------> [2] en cours de realisation  \n");
                printf("---------> [3] finalisee                \n");
                printf("---------> ");
                scanf("%d",&status);
                switch(status)
                {
                case 1 :
                    strcpy(lesTaches[lesModifs-1].statut,"realiser");
                    break;
                case 2 :
                    strcpy(lesTaches[lesModifs-1].statut,"en cours de realisation");
                    break;
                case 3 :
                    strcpy(lesTaches[lesModifs-1].statut,"finalisee");
                    break;
                }
            }
            while(status !=1 && status != 2 && status !=3);

            break;

        case 3 :
            printf("----> Entrer le nouveua deadLine de la tache. \n ");
            do
            {
                printf("--------->entrer le jour : ");
                scanf("%d",&lesTaches[lesModifs-1].deadLine.jour);
            }
            while(lesTaches[lesModifs-1].deadLine.jour<0 || lesTaches[lesModifs-1].deadLine.jour>31);
            do
            {
                printf("--------->entrer le mois : ");
                scanf("%d",&lesTaches[lesModifs-1].deadLine.mois);
            }
            while(lesTaches[lesModifs-1].deadLine.mois<0 || lesTaches[lesModifs-1].deadLine.mois>12);
            do
            {
                printf("--------->entrer l'annes : ");
                scanf("%d",&lesTaches[lesModifs-1].deadLine.annes);
            }
            while(lesTaches[lesModifs-1].deadLine.mois<0 || lesTaches[lesModifs-1].deadLine.mois>12);
            printf("\n");
            break;
        }
        printf("--------> BRAVO,Cette tache est modifier ;)\n");
        printf("\n");
        printf("\tAppuyez n'importe quelle touche pour revenir au menu : ");
        scanf("%s",&reutour);
    }
}
//--------------------------------------------------------------------------------------------------functions responsable de rechercher a une tache---------------------------------------------------------------------------------------------------
void rechercheDeslesTaches()
{
    int recherche=0;
    int Typerecherche=1;
    char titre[25];
    int RechercheResultat;
    int counteur=0;
    if (numTache<=0)
    {
        printf("\n\t\tajouter une tache avant de rechercher :'(\n");
        printf("\n");
        printf("\tAppuyez n'importe quelle touche pour revenir au menu : ");
        scanf("%s",&reutour);
    }
    else
    {
        printf("\t[1] recherche par Identicateur .\n");
        printf("\t[2] recherche par titre .\n");
        printf("\t\t le choix : ");
        scanf("%d",&Typerecherche);
        switch(Typerecherche)
        {
        case 1 :
            for (int i = 0; i < numTache; i++)
            {
                printf("=================================== Tache numero %d =====================================\n", i + 1);
                printf("L'ID est : %d\n", lesTaches[i].ID);
                printf("Le titre est : %s\n", lesTaches[i].titre);
                printf("-----------------------------------------------------------------------------------------\n");

            }
            printf("entrer l'identicateur de la tache qui vous vouler rechercher: ");
            scanf("%d",&recherche);
            system("cls");
            affichageDeMenu();
            printf("\n");
            printf("=================================== Tache numero %d =====================================\n", recherche);
            printf("L'ID est : %d\n", lesTaches[recherche-1].ID);
            printf("Le titre est : %s\n", lesTaches[recherche-1].titre);
            printf("Le statut est : %s\n", lesTaches[recherche-1].statut);
            printf("La description est : %s\n", lesTaches[recherche-1].description);
            printf("\tle deadLine est : %d/%d/%d\n",lesTaches[recherche-1].deadLine.annes,lesTaches[recherche-1].deadLine.mois,lesTaches[recherche-1].deadLine.jour);
            printf("-----------------------------------------------------------------------------------------\n");
            printf("\tAppuyez n'importe quelle touche pour revenir au menu : ");
            scanf("%s",&reutour);
            break;
        case 2 :
            for (int i = 0; i < numTache; i++)
            {
                printf("=================================== Tache numero %d =====================================\n", i + 1);
                printf("L'ID est : %d\n", lesTaches[i].ID);
                printf("Le titre est : %s\n", lesTaches[i].titre);
                printf("-----------------------------------------------------------------------------------------\n");

            }
            printf("entrer le titre de la tache qui vous vouler rechercher: ");
            scanf("%s",&titre);
            printf("\n");
            for (int i=0; i<numTache; i++)
            {
                RechercheResultat=strcmp(lesTaches[i].titre,titre);
                if(RechercheResultat==0)
                {
                    printf("=================================== Tache numero %d =====================================\n",i+1);
                    printf("L'ID est : %d\n", lesTaches[i].ID);
                    printf("Le titre est : %s\n", lesTaches[i].titre);
                    printf("Le statut est : %s\n", lesTaches[i].statut);
                    printf("La description est : %s\n", lesTaches[i].description);
                    printf("\tle deadLine est : %d/%d/%d\n",lesTaches[i].deadLine.annes,lesTaches[i].deadLine.mois,lesTaches[i].deadLine.jour);
                    printf("-----------------------------------------------------------------------------------------\n");
                    printf("\tAppuyez n'importe quelle touche pour revenir au menu : ");
                    scanf("%s",&reutour);
                    counteur++;
                }
            }
            if(counteur!=0)
            {
                printf("\tpas de tache avec ce nom .");
                printf("\n\tAppuyez n'importe quelle touche pour revenir au menu : ");
                scanf("%s",&reutour);
            }
            break;
        }
    }

}
//--------------------------------------------------------------------------------------------------functions responsable de supprimer une tache---------------------------------------------------------------------------------------------------
void supprissionDeslesTaches()
{
    int sup;
    int i,j;
    printf("veuiller emtrer l'identicateur de la tache qui vous voullez supprimer : ");
    scanf("%d",&sup);
    for (i=0; i<numTache; i++)
    {
        if(sup==lesTaches[i].ID)
        {
            for(j=i+1; j<numTache; j++)
            {
                lesTaches[i]=lesTaches[j];
            }
            numTache--;
        }

    }
    printf("\n");
    printf("--------> Dit au revoir a cette tache :^(\n");
    printf("\tAppuyez n'importe quelle touche pour revenir au menu : ");
    scanf("%s",&reutour);
}
//--------------------------------------------------------------------------------------------------functions responsable de statistiques---------------------------------------------------------------------------------------------------
void statistiques()
{
    //---------------tim.h lib-----------------
    time_t date=time(NULL);


    struct tm temp=*localtime(&date);
    //------------------------------------------
    int TypeStat;
    if (numTache<=0)
    {
        printf("\n\t\tajouter une tache avant de voir les statistiques :'(\n");
        printf("\n");
        printf("\tAppuyez n'importe quelle touche pour revenir au menu : ");
        scanf("%s",&reutour);
    }
    else
    {
        printf("\t[1] afficher le nombre total des lesTaches .\n");
        printf("\t[2] afficher le nombre de lesTaches complete et incomplete .\n");
        printf("\t[3] afficher le nombre de jours restants jusqu'au delai de chaque tache .\n");
        printf("\t\t le choix : ");
        scanf("%d",&TypeStat);
    }
    switch(TypeStat)
    {
    case 1 :
        printf("\t---->le nombre total des lesTaches est : %d\n\n",numTache);
        printf("\tAppuyez n'importe quelle touche pour revenir au menu : ");
        scanf("%s",&reutour);
        break;
    case 2 :
        printf("\t---->le nombre total des lesTaches realiser est : %d\n\n",realiser);
        printf("\t---->le nombre total des lesTaches finalisee est : %d\n\n",finalisee);
        printf("\tAppuyez n'importe quelle touche pour revenir au menu : ");
        scanf("%s",&reutour);
        break;
    case 3 :
        for (int i = 0; i < numTache; i++)
        {
            if( ((lesTaches[i].deadLine.mois - (temp.tm_mon+1)) * 30 + (lesTaches[i].deadLine.jour - temp.tm_mday )+ (lesTaches[i].deadLine.annes -1900 - temp.tm_year) * 365)>=0)
            {
                printf("=================================== Tache numero %d =====================================\n", i + 1);
                printf("L'ID est : %d\n", lesTaches[i].ID);
                printf("Le titre est : %s\n", lesTaches[i].titre);
                printf("les jours restees sont : %d\n", (lesTaches[i].deadLine.mois - (temp.tm_mon+1)) * 30 + (lesTaches[i].deadLine.jour - temp.tm_mday )+ (lesTaches[i].deadLine.annes -1900 - temp.tm_year) * 365 );
                printf("-----------------------------------------------------------------------------------------\n");
            }
        }
        printf("\tAppuyez n'importe quelle touche pour revenir au menu : ");
        scanf("%s",&reutour);
        break;
    }


}


