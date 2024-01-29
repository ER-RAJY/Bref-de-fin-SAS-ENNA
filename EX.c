#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

//Global Variables
int NMBR_T = 0;
enum priority{
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
struct Taches{
	char tache_name[50];
	char description[100];
	int  priority;
	struct date tacheDate;
};



// // Function to validate the date format
// int isValidDate(int day, int month, int year) {
//     if (year < 1900) {
//         return 0; // Year should be greater than or equal to 1900
//     }

//     if (month < 1 || month > 12) {
//         return 0; // Month should be between 1 and 12
//     }

//     int daysInMonth;

//     // Determine the number of days in the given month
//     switch (month) {
//         case 1:
//         case 3:
//         case 5:
//         case 7:
//         case 8:
//         case 10:
//         case 12:
//             daysInMonth = 31;
//             break;
//         case 4:
//         case 6:
//         case 9:
//         case 11:
//             daysInMonth = 30;
//             break;
//         case 2:
            
//                 daysInMonth = 29;
            
//             break;
//         default:
//             return 0; // Invalid month
//     }

//     return (day >= 1 && day <= daysInMonth);
// }







//founction de ajouter des taches 
void Ajouter(struct Taches tache[]) {
    printf("Le nom de tache:\n ");
    scanf(" %[^\n]s", tache[NMBR_T].tache_name);

    printf("+ La Description :\n");
    scanf(" %[^\n]s", tache[NMBR_T].description);

    printf("La Priorite (0: HAUTE, 1: MOYENNE, 2: BASSE) : ");
    scanf("%d", &tache[NMBR_T].priority);

    printf("+ La Date (format: day/month/year) :\n");
    scanf("%d/%d/%d", &tache[NMBR_T].tacheDate.day, &tache[NMBR_T].tacheDate.month, &tache[NMBR_T].tacheDate.year);

// la condition de verifier la date 


    // if (!isValidDate(tache[NMBR_T].tacheDate.day, tache[NMBR_T].tacheDate.month, tache[NMBR_T].tacheDate.year)) {
    //     printf("Format de date invalide. Veuillez entrer une date valide.\n");
    //     return;
    // }



    // Clear the input buffer
    while (getchar() != '\n');

	// pour incrementer la valeur de Nombre des taches
    NMBR_T++;
}
	

//La fonction de Affichage 
void Affichage(struct Taches tache[]) {
    if (NMBR_T < 1) {
        printf("There are no tasks to display.\n");
    } else {
        printf("\n\t\t\t\t\t\t:::::::::::::::::::::::::");
        printf("\n\t\t\t\t\t\t\tTO DO LIST");
        printf("\n\t\t\t\t\t\t:::::::::::::::::::::::::\n");

        printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
        printf("| ID |     Nom de la tache     |          Description          |     Priorite     |   Date d'echeance    |\n");
        printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");

        for (int i = 0; i < NMBR_T; i++) {
            printf("| %-2d | %-23s | %-29s | %-16s | %02d/%02d/%04d           |\n",
                   i + 1, tache[i].tache_name, tache[i].description,
                   (tache[i].priority == HAUTE) ? "HAUTE" : (tache[i].priority == MOYENNE) ? "MOYENNE" : "BASSE",
                   tache[i].tacheDate.day, tache[i].tacheDate.month, tache[i].tacheDate.year);
        printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
        }
    }
}

#include <stdio.h>
#include <string.h>

void Modifier(struct Taches tache[], int N) {
    int choix;
    char Newname[50];
    char NewDescription[100];
    int priorite;
    struct date newDate;

    if (N >= 1 && N <= NMBR_T) {
        printf("::::::::: Que voulez vous modifier :::::::\t\n");
        printf(":: < 1 >  Le nom de tache              ::\n");
        printf(":: < 2 >  La description                ::\n");
        printf(":: < 3 >  La priorite.                  ::\n");
        printf(":: < 4 >  La date                       ::\n");
        printf("::::::::::::::::::::::::::::::::::::::::::\t\n");
        printf("\n");

        printf("Entrer Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
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
        }
    } else {
        printf("Numero de tache invalide.\n");
    }
}


//La function supprimer
void Supprimer(struct Taches tache[]) {
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

//La function de Menu
void Menu(struct Taches tache[]) {
    int  choix;

	// printf("Entrer le nombre de tache :\n");
    // scanf("")

    
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
			case 1:
            //Ajouter 
				Ajouter(tache);
				break;
				
			case 2:
            //Affichage 
				Affichage(tache);
				break;
		    case 3: {
                // Modifier
                int N;
                Affichage(tache);
                printf("Entrer le ID de la tache : ");
                scanf("%d", &N);
                Modifier(tache, N);
                break;
            }
				 break;
			case 4:
            //Supprimer
                Affichage(tache);
				Supprimer(tache);
				 break;
			default:
				printf("Choix invalide. Entrer un choix entre 1 et 7!\n");
			case 7:
                printf("Programme terminé.\n");
                break;	
		}
	} while( choix != '7');
	
			

}


int main(){
	struct Taches tache[50];
	char choix;
	
	Menu(tache);	
		
}