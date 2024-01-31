#include <stdio.h>
#include <string.h>

//Global Variables
int NMBR_T = 0;
enum Priorite{
	 HAUTE ,
	 MOYENNE ,
	 BASSE ,

};

//Les stricture
struct date {
    int day;
    int month;
    int year;
};
typedef struct {
	char tache_name[50];
	char description[100];
	enum Priorite  priority;
	struct date tacheDate;
}Taches;

//founction de ajouter Une taches 
void AjouterUnTache( Taches tache[]) {
    printf("Le nom de tache:\n ");
    scanf(" %[^\n]s", tache[NMBR_T].tache_name);

    printf("+ La Description :\n");
    scanf(" %[^\n]s", tache[NMBR_T].description);

    printf("La Priorite (0: HAUTE, 1: MOYENNE, 2: BASSE) : ");
    scanf("%d", &tache[NMBR_T].priority);

    printf("+ La Date (format: day/month/year) :\n");
    scanf("%d/%d/%d", &tache[NMBR_T].tacheDate.day, &tache[NMBR_T].tacheDate.month, &tache[NMBR_T].tacheDate.year);


    while (getchar() != '\n');

	// pour incrementer la valeur de Nombre des taches
    NMBR_T++;
}
//founction de ajouter des taches 
void AjouterPlusieurs(Taches tache[], int nombreTaches) {
    if (NMBR_T + nombreTaches > 50) {
        printf("Il n'y a pas assez d'espace pour ajouter autant de taches.\n");
    } else {
        for (int i = 0; i < nombreTaches; i++) {
            printf("Tache %d\n",i+1);
            printf("Le nom de la tache :\n ");
            scanf(" %[^\n]s", tache[NMBR_T + i].tache_name);

            printf("+ La Description :\n");
            scanf(" %[^\n]s", tache[NMBR_T + i].description);

            printf("La Priorite (0: HAUTE, 1: MOYENNE, 2: BASSE) : ");
            scanf("%d", &tache[NMBR_T + i].priority);
            
            printf("+ La Date (format: day/month/year) :\n");
            scanf("%d/%d/%d", &tache[NMBR_T + i].tacheDate.day, &tache[NMBR_T + i].tacheDate.month, &tache[NMBR_T + i].tacheDate.year);


            while (getchar() != '\n');
        }

        NMBR_T += nombreTaches;
    }
}


//La fonction de Affichage 
void Affichage( Taches tache[]) {
    if (NMBR_T < 1) {
        printf("Pas des taches a afficher\n");
    } else {
        printf("\n\t\t\t\t\t\t:::::::::::::::::::::::::");
        printf("\n\t\t\t\t\t\t\tTO DO LIST");
        printf("\n\t\t\t\t\t\t:::::::::::::::::::::::::\n");

        printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
        printf("| ID |     Nom de la tache     |          Description          |     Priorite     |   Date d'echeance    |\n");
        printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");

        for (int i = 0; i < NMBR_T; i++) {
            printf("| %-2d | %-23s | %-29s | %-16s | %02d/%02d/%04d           |\n",i + 1, tache[i].tache_name, tache[i].description,
            (tache[i].priority == HAUTE) ? "HAUTE" : (tache[i].priority == MOYENNE) ? "MOYENNE" : "BASSE",
            tache[i].tacheDate.day, tache[i].tacheDate.month, tache[i].tacheDate.year);
        printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
        }
    }
}
void Modifier( Taches tache[], int N) {
    int choix;
    char Newname[50];
    char NewDescription[100];
    int priorite;
    struct date newDate;
  if (N >= 1 && N <= NMBR_T) {
        printf("::::::::: Que voulez vous modifier :::::::\t\n");
        printf(":: < 1 >  Le nom de tache               ::\n");
        printf(":: < 2 >  La description                ::\n");
        printf(":: < 3 >  La priorite.                  ::\n");
        printf(":: < 4 >  La date                       ::\n");
        printf(":: < 0 >  Retour/Menu precedent         ::\n");
        printf("::::::::::::::::::::::::::::::::::::::::::\t\n");
        printf("\n");

        printf("Entrer Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
                case 0:
                printf("Vous avez quitte !\n");
                break;

            case 1:
                printf("Entrer le nouveau nom de la tache : ");
                scanf(" %[^\n]s", Newname);
                strcpy(tache[N - 1].tache_name, Newname);
                printf("Le nom de la tache %d a ete modifie avec succes.\n", N);
                break;

            case 2:
                printf("Entrer la nouvelle description : ");
                scanf(" %[^\n]s", NewDescription);
                strcpy(tache[N - 1].description, NewDescription);
                printf("La description de la tache %d a ete modifiee avec succes.\n", N);
                break;

            case 3:
                printf("Entrer la nouvelle priorite (0: HAUTE, 1: MOYENNE, 2: BASSE) : ");
                scanf("%d", &priorite);
                tache[N - 1].priority = priorite;
                printf("La priorite de la tache %d a ete modifiee avec succes.\n", N);
                break;

            case 4:
                printf("Entrer la nouvelle date (format: day/month/year) : ");
                scanf("%d/%d/%d", &newDate.day, &newDate.month, &newDate.year);
                tache[N - 1].tacheDate = newDate;
                printf("La date de la tache %d a ete modifiee avec succes.\n", N);
                break;

            default:
                printf("Choix invalide.\n");
                break;
        }while (choix!=0);
        
    } 
    else {
        printf("Numero de tache invalide.\n");
    }
}

//La function supprimer
void Supprimer( Taches tache[]) {  
    int pos;
    printf("Entrez le ID de la tache a supprimer : ");
    scanf("%d", &pos);
    // Validation 
    if (pos >= 1 && pos <= NMBR_T) {
        for (int i = pos - 1; i < NMBR_T - 1; i++) {
            tache[i] = tache[i + 1];
        }
        NMBR_T--;
		
        printf("La tache %d a ete supprimee avec succes.\n", pos);

    } else {
        printf("Numero de tache invalide.\n");	
    }
}

//La function de triee croissant
void trieeCroissant( Taches tache[]) {
    if (NMBR_T > 0) {
        for (int i = 0; i < NMBR_T; i++) {
            for (int j = i + 1; j < NMBR_T; j++) {
                // Comparer les annee et le moins et le jours

                if (tache[i].tacheDate.year > tache[j].tacheDate.year || (tache[i].tacheDate.year == tache[j].tacheDate.year && tache[i].tacheDate.month > tache[j].tacheDate.month) 
                || (tache[i].tacheDate.year == tache[j].tacheDate.year && tache[i].tacheDate.month == tache[j].tacheDate.month && tache[i].tacheDate.day > tache[j].tacheDate.day))
                 {
                    // changer les elements
                    Taches temp = tache[i];
                    tache[i] = tache[j];
                    tache[j] = temp;
                }
            }
        }
    }Affichage(tache);
}

//La function de triee decroissant
void trieeDecroissant(Taches tache[]) {
    if (NMBR_T > 0) {
        for (int i = 0; i < NMBR_T; i++) {
            for (int j = i + 1; j < NMBR_T; j++) {
                // Comparer les annee et le mois et le jour
                if (tache[i].tacheDate.year < tache[j].tacheDate.year || 
                    (tache[i].tacheDate.year == tache[j].tacheDate.year && tache[i].tacheDate.month < tache[j].tacheDate.month) ||
                    (tache[i].tacheDate.year == tache[j].tacheDate.year && tache[i].tacheDate.month == tache[j].tacheDate.month && tache[i].tacheDate.day < tache[j].tacheDate.day)) {
                    // changer les elements
                    Taches temp = tache[i];
                    tache[i] = tache[j];
                    tache[j] = temp;
                }
            }
        }
    }
    Affichage(tache);
}

void FiltrerParPriorite( Taches tache[]) {
    int N;
    printf("Choisir une priorite (0: HAUTE, 1: MOYENNE, 2: BASSE) : ");
    scanf("%d", &N);

    int found = 0;

    printf("\n\t\t\t\t\t\t:::::::::::::::::::::::::");
    printf("\n\t\t\t\t\t\t\tTO DO LIST");
    printf("\n\t\t\t\t\t\t:::::::::::::::::::::::::\n");

    printf("+----+-------------------------+-------------------------------+------------------+------------------+\n");
    printf("| ID |     Nom de la tache     |          Description          |  Date d'echeance |     Priorite     |\n");
    printf("+----+-------------------------+-------------------------------+------------------+------------------+\n");

    for (int i = 0; i < NMBR_T; i++) {
        if (tache[i].priority == N) {
            printf("| %-2d | %-23s | %-29s |", i + 1, tache[i].tache_name, tache[i].description);
            printf(" %02d/%02d/%04d       |", tache[i].tacheDate.day, tache[i].tacheDate.month, tache[i].tacheDate.year);

            switch (N) {
                case HAUTE:
                    printf(" HAUTE            |\n");
                    break;
                case MOYENNE:
                    printf(" MOYENNE          |\n");
                    break;
                case BASSE:!
                    printf(" BASSE            |\n");
                    break;
                default:
                    printf(" Inconnue         |\n");
            }

    printf("+----+-------------------------+-------------------------------+------------------+------------------+\n");

            found = 1;
        }
    }

    if (!found) {
        printf("Aucune tache avec la priorite %d n'a ete trouvee.\n", N);
    }
}

//La function de Menu
void Menu( Taches tache[]) {

    int  choix;
	printf("\n");
	do{
		printf(":::::::::::::::::< Menu >:::::::::::::::::\t\n");
		printf(":: < 1 >  Ajouter une Tache.            ::\n");
		printf(":: < 2 >  Afficher la Liste des Taches. ::\n");
		printf(":: < 3 >  Modifier une Tache.           ::\n");
		printf(":: < 4 >  Supprimer une Tache.          ::\n");
		printf(":: < 5 >  Ordonne les Tache.            ::\n");
		printf(":: < 6 >  filtrer les Tache.            ::\n");
		printf(":: < 7 >  Quitter.                      ::\n");
		printf("::::::::::::::::::::::::::::::::::::::::::\t\n");
		printf("\n");
		printf("==> Saisir Votre Choix : ");
		scanf("%d",&choix);
		
		switch(choix){
         int nombreTaches;
int nbr;

case 1:
    // Ajouter
    printf("(1) Ajouter une tache.\n");
    printf("(2) Ajouter plusieurs taches.\n");
    printf("==> Saisir Votre Choix : ");
    scanf("%d", &nbr);

    switch (nbr) {
        case 1:
            AjouterUnTache(tache);
            break;
        case 2:
            printf("Entrez le nombre de taches a ajouter : ");
            scanf("%d", &nombreTaches);

            // Call AjouterPlusieurs
            AjouterPlusieurs(tache, nombreTaches);
            break;

        default:
            printf("Choix invalide. Entrer un choix entre 1 et 2!\n");
            break;
    }
    break;

			case 2:
            //Affichage 
				Affichage(tache);
				break;
		    case 3: {
                // Modifier
                if (NMBR_T < 1) {
                    printf("\t\"Pas des taches pour modifier!!\"\n");
                    break;
                }
                else{int N;
                Affichage(tache);
                printf("Entrer le ID de la tache : ");
                scanf("%d", &N);
                Modifier(tache, N);
                break;}
            }
				 break;
			case 4:{
            //Supprimer
            if (NMBR_T < 1) {
                    printf("\t\"Pas des taches pour Supprimer!!\"\n");
                    break;
                }else
                Affichage(tache);
				Supprimer(tache);
				 break;
            }     

			case 5:{
            //Triee
              if (NMBR_T < 1) {
                    printf("\t\"Pas des taches a Ordoner!!\"\n");
                    break;
                }else{
                    int Triee ; 
                printf("croissant (1) \t decroissant (2) \n");
                printf("=> Saisir Votre Choix : ");
                scanf("%d",&Triee);
                switch (Triee)
                {
                case 1:
                    trieeCroissant(tache);
                    break;
                
                case 2:
                    trieeDecroissant(tache);
                    break;
                default:

                printf("Choix invalide. Entrer un choix entre 1 et 2!\n");
                    break;
                }
				 break;
                }  
            } 
            case 6:    
                //Filtrer Par Priorite
                if (NMBR_T < 1) {
                    printf("\t\"Pas des taches a filtrer!!\"\n");
                    break;
                }else
                FiltrerParPriorite(tache);
                break;	  
            case 7:
                printf("Programme termine.\n");
                break;	
			default:
				printf("Choix invalide. Entrer un choix entre 1 et 7!\n");
		
		}
	} while( choix != 7);
}

int main(){	
	char choix;
	Taches task[50];
	Menu(task);	
}
