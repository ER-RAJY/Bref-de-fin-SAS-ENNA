#include <stdio.h>
#include <stdlib.h>
int main()
{
    int pos, Val ;
    int T[8]= {1,2,3,4,5,6,7,8};
    int taille =8;
    printf("entre le elements :");
    scanf("%d",&pos);
    printf("entre la valeur :");
    scanf("%d",&Val);

    if (pos <= 1 && pos>taille)
        {
            printf("posision invalid");
        }
    else{     
        for (int i = pos - 1; i < taille; i++)
            {
                T[i]=T[i-1];
            }
        taille++;
        }




        //affichege
    for (int i = 0; i < taille; i++)
    {
        printf("T[%d]= %d\n",i+1,T[i]);
    }

}