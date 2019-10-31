#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxchar 15
#define maxtel 10
#define maxrep 3

typedef struct Date{
    int joure;
    int mois;
    int annee;
}Date;
typedef struct Adress{
    char NomVille[maxchar];
    char Rue[maxchar];
    int NumeroMaison;
}Adress;
typedef struct Personne{
    char Nom[maxchar];
    Date date;
    int NumTel;
    char E_Mail[maxchar];
    int CodeDep;
    Adress Adress;
}Personne;

Personne Repertoire[maxrep];

void Ajouter(int indice){
    printf("Entrez le nom :");
    scanf("%s",&Repertoire[indice].Nom);
    printf("Entrez le numero de telephone :");
    scanf("%d",&Repertoire[indice].NumTel);
    printf("\n");
    printf("Entrez le joure de naissance :");
    scanf("%d",&Repertoire[indice].date.joure);
    printf("Entrez le mois de naissance :");
    scanf("%d",&Repertoire[indice].date.mois);
    printf("Entrez l'annee de naissance :");
    scanf("%d",&Repertoire[indice].date.annee);
    printf("\n");
    printf("Entrez le code de departement:");
    scanf("%d",&Repertoire[indice].CodeDep);
    printf("\n");
    printf("Entrez le nom de la ville :");
    scanf("%s",&Repertoire[indice].Adress.NomVille);
    printf("\n");
    printf("Entrez le nom de la rue :");
    scanf("%s",&Repertoire[indice].Adress.Rue);
    printf("\n");
    printf("Entrez le numero de la maison :");
    scanf("%d",&Repertoire[indice].Adress.NumeroMaison);
    printf("\n");
    printf("Entrez le E-mail :");
    scanf("%s",&Repertoire[indice].E_Mail);
}

int ENLEVER (char tele[maxtel],int indice){
    int b=0;
    char num[maxtel] ;
    int c;
    for(c=0;c<indice;c++){
        itoa(Repertoire[c].NumTel,num,maxtel);
        if(strcmp(tele,num)==0){
            b=1;
            if(c==indice-1){
                indice-=1;
                break;
                           }
                                }
		if(b==1)Repertoire[c] = Repertoire[c+1];
                                                      
                         }
		return b;
    }

void SUPPRIMER(int *pointeurSurIndice){
    char tele[maxtel];
	printf("Entrer le numero de telephone :");
    scanf("%s",&tele);
    printf("\n");
    if(ENLEVER(tele,*pointeurSurIndice)==1){
        printf("Le contact est enleve!!\n");
        *pointeurSurIndice-=1;
        }
    else printf("Le contact n'est pas enleve!!\n");	
}

void AfficherRep(int indice){
    int i;
        printf(" +-----------------------------------------------------------------\n");
		printf(" |                     LE REPERTOIRE TELEPHONIQUE                  \n");
		printf(" +-----------------------+-----------------------------------------\n");
    for(i=0;i<indice;i++){
		printf(" |         INDICE        |   %d \n",i);
		printf(" +-----------------------+-----------------------------------------\n");
		printf(" |         LE NOM        |   %s \n",Repertoire[i].Nom);
		printf(" +-----------------------+-----------------------------------------\n");
		printf(" |LE NUMERO DE TELlEPHONE|   %d \n",Repertoire[i].NumTel);
		printf(" +-----------------------+-----------------------------------------\n");
		printf(" |    DATE DE NAISSANCE  |   %d/%d/%d \n",Repertoire[i].date.joure,Repertoire[i].date.mois,Repertoire[i].date.annee);
		printf(" +-----------------------+-----------------------------------------\n");
		printf(" |LE CODE DE DEPARTEMENT |   %d \n",Repertoire[i].CodeDep);
		printf(" +-----------------------+-----------------------------------------\n");
		printf(" |       L'ADRESS        |   %s. %s. N%d \n",Repertoire[i].Adress.NomVille,Repertoire[i].Adress.Rue,Repertoire[i].Adress.NumeroMaison);
		printf(" +-----------------------+-----------------------------------------\n");
		printf(" |       LE E-mail       |   %s\n",Repertoire[i].E_Mail);
		printf(" +-----------------------+-----------------------------------------\n");
		printf(" ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    }
}

void main(){
    int code=12 ;
    int indice=0;
    int *pointeurSurIndice = &indice;
        printf("\n");
        printf(" +---------------------------------------------------+\n");
		printf(" |             LE REPERTOIRE TELEPHONIQUE            |\n");
		printf(" +-------+-------------------------------------------+\n");
		printf(" |  Code |             LA FONCTION                   |\n");
		printf(" +-------+-------------------------------------------+\n");
		printf(" |   1   |        AJOUTER UNE PERSONNE               |\n");
		printf(" |       |                                           |\n");
		printf(" |   2   |        SUPPRIMER UNE PERSONNE             |\n");
		printf(" |       |                                           |\n");
		printf(" |   3   |        AFFICHER LE REPERTOIRE             |\n");
		printf(" |       |                                           |\n");
		printf(" |   4   |        QUITTER LE REPERTOIRE              |\n");
		printf(" +-------+-------------------------------------------+\n");
		do{
            printf("\n       Entrez un code : ");
		scanf("%d",&code);
		switch(code){
		case 1:
				Ajouter(indice);
				indice++;
			break;
		case 2:
				SUPPRIMER(&indice);
			break;
        case 3:
				AfficherRep(indice);
			break;
		case 4:
				return EXIT_SUCCESS;
			break;
		default:
			printf("\n	Code Introuvable!");
		}
		}while(1);
}
