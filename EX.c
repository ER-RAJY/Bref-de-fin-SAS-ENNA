#include <stdio.h>

int taille = 2;

struct date{
	int day;
	int month;
	int year;
};
struct Taches{
	char tache_name[50];
	char description[100];
	char priority[50];
	struct date tacheDate;
};

void add_tache(struct Taches tache[]){
	
	 for (int i = 0; i < taille; i++) {
	 	
		printf("++ Votre tache:\n ");
        scanf(" %[^\n]s",tache[i].tache_name);
		//gets(tache[i].tache_name);

        printf("+ Description :\n");
        scanf(" %[^\n]s",tache[i].description);
        //gets(tache[i].description);

        printf("+ Priorite:\n");
        scanf(" %[^\n]s",tache[i].priority);
        //gets(tache[i].priority);

        printf("+ Date :\n");
        scanf("%d/%d/%d", &tache[i].tacheDate.day, &tache[i].tacheDate.month, &tache[i].tacheDate.year);
        printf("\n");
        
        // declared to avoid issues with the next task bcs it could skip '\n',
        while (getchar() != '\n');
	}
}

void Affichage(struct Taches tache[]){
	for(int i=0; i<taille;i++){ 
		printf("Task %d: %s\n", i + 1, tache[i].tache_name);
		printf("\t-Description :%s\n",tache[i].description);
		printf("\t-Priorite :%s\n",tache[i].priority);
		printf("\t-Date :%d/%d/%d\n",tache[i].tacheDate.day,tache[i].tacheDate.month,tache[i].tacheDate.year);
		printf("\n");
	}
		
}

void Menu(struct Taches tache[]) {
    int  choix;
	do{
		printf("\t:::: Menu ::::\t\n");
		printf("< 1 > Ajouter une Tache \n");
		printf("< 2 > Afficher la Liste des Taches \n");
		printf("< 3 > Supprimer une Tache \n");
		printf("< 4 > Modifier une Tache \n");
		printf("< 5 > Ordonne les Tache \n");
		printf("< 6 > filtrer les Tache \n");
		printf("< 7 > Quitter \n");
		printf("==============choix : ");
		scanf("%d",&choix);
		
		
		switch(choix){
			case 1:
				add_tache(tache);
				break;
				
			case 2:
				Affichage(tache);
				break;
			default:
				printf("Choix invalide. Entrer un choix entre 1 et 7!\n");
				
		}
	} while( choix != '7');
			
}
		



int main(){
	struct Taches tache[50];
	char choix;
	
	Menu(tache);	
		
}
