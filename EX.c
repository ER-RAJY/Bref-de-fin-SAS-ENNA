#include <stdio.h>
#include <stdlib.h>

struct tache_date
{
    int jour;
    int mois;
    int anne;
};

struct Taches
{
    char Nom_de_tache[50];
    struct tache_date date;
    char description[255];
    char priorite[50];
};

void Ajouter(struct Taches tach[], int *size)
{
    for (int i = 0; i < *size; i++)
    {
        printf("Entrer Le nom de tache : ");
        fgets(tach[i].Nom_de_tache, sizeof(tach[i].Nom_de_tache), stdin);

        printf("Entrer Une description : ");
        fgets(tach[i].description, sizeof(tach[i].description), stdin);

        printf("Entrer La priorite : ");
        fgets(tach[i].priorite, sizeof(tach[i].priorite), stdin);

        printf("Entrer La date de tache (jour mois annee) : ");
        scanf("%d %d %d", &tach[i].date.jour, &tach[i].date.mois, &tach[i].date.anne);

        // Clear input buffer
        while (getchar() != '\n');
    }
}

void Affichier(struct Taches tach[], int *size)
{
    printf("\nAdded Tasks:\n");
    for (int i = 0; i < *size; i++)
    {
        printf("La tache : %d:\n", i + 1);
        printf("Nom de tache: %s", tach[i].Nom_de_tache);
        printf("Date de tache: %d/%d/%d\n", tach[i].date.jour, tach[i].date.mois, tach[i].date.anne);
        printf("Description: %s", tach[i].description);
        printf("Priorite: %s", tach[i].priorite);
        printf("\n");
    }
}

int main()
{
    struct Taches Task[50];

    int size;
    printf("Entrer le nombre des taches : ");
    scanf("%d", &size);

    // Check if the size is within bounds
    if (size > 50 || size <= 0)
    {
        printf("Invalid size. Please enter a number between 1 and 50.\n");
        return 1; // Return an error code
    }

    Ajouter(Task, &size);
    Affichier(Task, &size);

    return 0;
}
