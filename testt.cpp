#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
//changement de couleur
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
using namespace std;    // pour iostream
//structure client
struct clients
{
	int num;
	char nom[50];
	char prenom[50];
	char cin[50];
};
//structure chambre
struct chambres
{
	int num;
	char type[50];
	char categorie[50];
	char etat;
	int prix ;
	
};
//structure reservation
typedef	struct
{
	int jj;
	int mm;
	int aa;
}dates;
struct reservations
{
	int num;
	dates date;
	int nbr_nuit;
	int nbr_ch;
	int nbr_pers;
};
struct reservations res;
struct chambres chambre;
struct clients client;

//___________*********************************************
//____________*********gestionnaire de client ********
//______________*************************************


//**__________**fonction de recherche des clients**_____________________**
int rech_c (int num_rech)
{
	FILE *F;
	F=fopen("clients.txt","r");
	do
	{
		fscanf(F,"%d ;%s ;%s ;%s \n",&client.num,&client.nom,&client.prenom,&client.cin);
		fflush(stdin); //fflash(stdin); ==> pour libere la memoire et evitée les probleme aucours de compilation
		if (client.num == num_rech)
		{
			fclose(F);
			return 1;
			
		}
		
	
	}
	while (!feof(F));
	fclose(F);
	return -1;
}
//**___________**procedure pour ajouter un client**_______________**
void ajouter_un_client()
{
	system("cls");
	FILE *F;
	int num;
	F=fopen("clients.txt","a");
	printf("\n entre le numero du nouveau client: ");
	scanf("%d",&num);
	fflush(stdin);
		
	while (rech_c(num)==1)
	 //boucle while pour verifier que le numero ajoutée n'existe pas
	{
		printf("\n ce numero existe deja !!");
		printf("\n entrer le numero du client :");
		scanf("%d",&num);
	}
	   client.num=num;
	   
		printf("\n entrer le nom du client :");
		gets(client.nom);
		fflush(stdin);
		
		printf("\n entrer le prenom du client :");
		gets(client.prenom);
		fflush(stdin);
		
		printf("\n entrer le numero de la carte d'identite (CIN) :");
		gets(client.cin);
		fflush(stdin);
		
		fprintf(F,"%d ;%s ;%s ;%s \n",client.num,client.nom,client.prenom,client.cin);
		fflush(stdin);
		
		fclose(F);
}

//**_____________**fonction recherche et affichage**___________**

void recherche ()
{
system("cls");
int num_r;
printf("saisir le numero de client a rechercher\n");
scanf("%d",&num_r);
FILE *F;
F=fopen("clients.txt","r");
do
{
	fscanf(F,"%d ;%s ;%s ;%s \n",&client.num,&client.nom,&client.prenom,&client.cin);
	if (num_r==client.num)
	{
	printf("-----------INFORMATION SUR CE CLIENT : ----------\n\n");
		printf("numero\t: %d \n",client.num);
		printf("nom\t: %s \n",client.nom);
		printf("prenom\t: %s \n",client.prenom);
		printf("CIN\t: %s \n",client.cin);
		
	}
}while(!feof(F));
fclose(F);
}

//**_____________**procedure de suppression**___________**
void supprimer_client()
{
	system("cls");
	char rep;
	int num_rech;
	printf("entrez le numero de client asupprimer:");
	scanf("%d",&num_rech);
	fflush(stdin);
	if(rech_c(num_rech)==1)
	{
		printf("\n voulez vous vraiment supprimer O/N ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep=='o'|| rep=='O')
		{
			FILE *FICH, *F;
			F=fopen("clients.txt","r");
			FICH=fopen("temp_client.txt","a");
		   do
		     { 
		     fscanf(F,"%d ;%s ;%s ;%s \n",&client.num,&client.nom,&client.prenom,&client.cin);
		     if (num_rech != client.num)
		     {
		     	fprintf(FICH,"%d ;%s ;%s ;%s \n",client.num,client.nom,client.prenom,client.cin);
			 }
			
			 }while (!feof(F));
			 fclose(FICH);
			 fclose(F);
			 remove ("clients.txt");
			 rename("temp_client.txt","clients.txt");
			 printf("supression effectuer avec succees");
			 	
		}	
	}
	else
	{
		printf("\n ce numero ne correspand aucun client");
	}
		
}


//**_____________**procedure pour la modification du client**___________**

void modifier_client()
{
	system("cls");
		FILE *FICH, *F;
	char rep='n';
	int num_rec;
	printf("entrez le numero de client a modifier:");
	scanf("%d",&num_rec);
	fflush(stdin);
	if(rech_c(num_rec)==1)
	{
		printf("\n voulez vous vraiment modifier ce client O/N ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep=='o'|| rep=='O')
		{
		
			F=fopen("clients.txt","r");
			FICH=fopen("temp_client.txt","a");
		   do
		     { 
		     fscanf(F,"%d ;%s ;%s ;%s \n",&client.num,&client.nom,&client.prenom,&client.cin);
		     if (num_rec == client.num)
		     {
		     	client.num=num_rec;
		     printf("\n entrer le nouveau nom : ");
	    	 gets(client.nom);
	    	 fflush(stdin);
		
		     printf("\n entrer le nouveau prenom du client :");
		     gets(client.prenom);
		     fflush(stdin);
		
		     printf("\n entrer le nouveau numero de la carte d'identite (CIN) :");
		     scanf("%s",&client.cin);
		     fflush(stdin);
			 }
			 fprintf(FICH,"%d ;%s ;%s ;%s \n",client.num,client.nom,client.prenom,client.cin);
			 }while (!feof(F));
			 
			 fclose(FICH);
			 fclose(F);
			 remove ("clients.txt");
			 rename("temp_client.txt","clients.txt");
			 printf("la modification a reussi");
		      
	
		}	
	}
	else
	{
	printf("\nla modification a ete annule");	
		
	}
		
}

//**_____________**procedure d'affichage**___________**
void afficher_tt()
{
system("cls");
FILE *F;
F=fopen("clients.txt","r");
printf("la liste des clients est : \n\n");
printf("NUMERO\t NOM\t PRENOM\t NUMERO CIN\n");
do
{
	fscanf(F,"%d ;%s ;%s ;%s \n",&client.num,&client.nom,&client.prenom,&client.cin);
	fflush(stdin);
	printf("%d\t",client.num);
	printf("%s\t",client.nom);
	printf("%s\t",client.prenom);
	printf("%s\n",client.cin);
} while (!feof(F));
fclose(F);
}
//___________*********************************************
//____________*********gestionnaire de reservation********
//______________*************************************


//**__________**fonction de recherche des reservations**_____________________**
int rech (int num_rech)
{
	FILE *A;
	A=fopen("reservations.txt","r");
	do
	{
		fscanf(A,"%d ;%d ;%d/%d/%d ;%d ;%d ;%d \n",&res.num,&client.num,&res.date.jj,&res.date.mm,&res.date.aa,&res.nbr_nuit,&res.nbr_ch,&res.nbr_pers);
		fflush(stdin); //fflash(stdin); ==> pour libere la memoire et evitée les probleme aucours de compilation
		if (res.num == num_rech)
		{
			fclose(A);
			return 1;
			
		}
		
	
	}
	while (!feof(A));
	fclose(A);
	return -1;
}
//**___________**procedure pour ajouter une reservation**_______________**
void ajouter_res()
{
	system("cls");
	FILE *A;
	int num;
	A=fopen("reservations.txt","a");
	printf("\n entre le numero du nouveau reservation: \n");
	scanf("%d",&num);
	fflush(stdin);
		
	while (rech(num)==1)
	 //boucle while pour verifier que le numero ajoutée n'existe pas
	{
		printf("\n ce numero existe deja !!");
		printf("\n entrer le numero du nouveau reservation : \n");
		scanf("%d",&num);
	}
	   res.num=num;
	   
		printf("\n entrer le numero de client qui reserve :");
		scanf("%d",&client.num);
		fflush(stdin);
		
		printf("\n entrer la date de reservation : \n");
		printf("le jour :\t");
		scanf("%d",&res.date.jj);
		printf("le mois :\t");
		scanf("%d",&res.date.mm);
		printf("l'annee' :\t");
		scanf("%d",&res.date.aa);
		fflush(stdin);
		
		printf("\n entre le nombre de nuit :");
		scanf("%d",&res.nbr_nuit);
		fflush(stdin);
		
		printf("\n entre le nombre des chambres :");
		scanf("%d",&res.nbr_ch);
		fflush(stdin);
		
		printf("\n entre le nombre de personne :");
		scanf("%d",&res.nbr_pers);
		fflush(stdin);
		
		fprintf(A,"%d ;%d ;%d/%d/%d ;%d ;%d ;%d \n",res.num,client.num,res.date.jj,res.date.mm,res.date.aa,res.nbr_nuit,res.nbr_ch,res.nbr_pers);
		fflush(stdin);
		
		fclose(A);
}

//**_____________**fonction recherche et affichage**___________**

void recherche_res ()
{
system("cls");
int num_r;
printf("saisir le numero de reservation a rechercher\n");
scanf("%d",&num_r);
FILE *A;
A=fopen("reservations.txt","r");
do
{
	fscanf(A,"%d ;%d ;%d/%d/%d ;%d ;%d ;%d \n",&res.num,&client.num,&res.date.jj,&res.date.mm,&res.date.aa,&res.nbr_nuit,&res.nbr_ch,&res.nbr_pers);
	if (num_r==res.num)
	{
	printf("\t\t-----------INFORMATION SUR CEtte reservation : ----------\n\n");
		printf("\t\t numero\t: %d \n",res.num);
		printf("\t\t numero de client\t: %d \n",client.num);
		printf("\t\t date\t: %d/%d/%d \n",res.date.jj,res.date.mm,res.date.aa);
		printf("\t\t nombre des nuits\t: %d \n",res.nbr_nuit);
		printf("\t\t nombre des chambres\t: %d \n",res.nbr_ch);
		printf("\t\t nombre des personnes\t: %d \n",res.nbr_pers);
		
	}
}while(!feof(A));
fclose(A);
}

//**_____________**procedure de suppression**___________**
void supprimer_res()
{
	system("cls");
	char rep;
	int num_rech;
	printf("entrez le numero de reservation a supprimer:");
	scanf("%d",&num_rech);
	fflush(stdin);
	if(rech(num_rech)==1)
	{
		printf("\n voulez vous vraiment supprimer O/N ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep=='o'|| rep=='O')
		{
			FILE *FICH2, *A;
			A=fopen("reservations.txt","r");
			FICH2=fopen("temp_res.txt","a");
		   do
		     { 
		     fscanf(A,"%d ;%d ;%d/%d/%d ;%d ;%d ;%d \n",&res.num,&client.num,&res.date.jj,&res.date.mm,&res.date.aa,&res.nbr_nuit,&res.nbr_ch,&res.nbr_pers);
		     if (num_rech != res.num)
		     {
		     	fprintf(FICH2,"%d ;%d ;%d/%d/%d ;%d ;%d ;%d \n",res.num,client.num,res.date.jj,res.date.mm,res.date.aa,res.nbr_nuit,res.nbr_ch,res.nbr_pers);
			 }
			
			 }while (!feof(A));
			 fclose(FICH2);
			 fclose(A);
			 remove ("reservations.txt");
			 rename("temp_res.txt","reservations.txt");
			 printf("supression effectuer avec succees");
			 	
		}	
	}
	else
	{
		printf("\n ce numero ne correspand aucun reservation");
	}
		
}


//**_____________**procedure pour la modification de reservation**___________**

void modifier_res()
{
	system("cls");
		FILE *FICH2, *A;
	char rep='n';
	int num_rec;
	printf("entrez le numero de reervation a modifier:");
	scanf("%d",&num_rec);
	fflush(stdin);
	if(rech(num_rec)==1)
	{
		printf("\n voulez vous vraiment modifier ce client O/N ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep=='o'|| rep=='O')
		{
		
			A=fopen("reservations.txt","r");
			FICH2=fopen("temp_res.txt","a");
		   do
		     { 
		     fscanf(A,"%d ;%d ;%d/%d/%d ;%d ;%d ;%d \n",&res.num,&res.date.jj,&res.date.mm,&res.date.aa,&res.nbr_nuit,&res.nbr_ch,&res.nbr_pers);
		     if (num_rec == res.num)
		     {
		     	res.num=num_rec;
		     	printf("saisir le nouvelle numero de client : \t");
		     printf("\n entrer la nouvelle date de reservation :\n ");
	    	 printf("le jour :\t");
	    	 scanf("%d",&res.date.jj);
	    	 printf("le mois :\t");
	    	 scanf("%d",&res.date.mm);
	    	 printf("l'annee' :\t");
	    	 scanf("%d",&res.date.aa);
	    	  fflush(stdin);
	    	  
		
		     printf("\n saisir le nouveau nombre des nuits  :");
		     scanf("%d",&res.nbr_nuit);
		     fflush(stdin);
		
		     printf("\n saisir le nouveau nombre des chambres  :");
		     scanf("%d",&res.nbr_ch);
		     fflush(stdin);
		     
		     printf("\n saisir le nouveau nombre des personnes :");
		     scanf("%d",&res.nbr_pers);
			 }
			 fprintf(FICH2,"%d ;%d ;%d/%d/%d ;%d ;%d ;%d \n",res.num,client.num,res.date.jj,res.date.mm,res.date.aa,res.nbr_nuit,res.nbr_ch,res.nbr_pers);
			 }while (!feof(A));
			 
			 fclose(FICH2);
			 fclose(A);
			 remove ("reservations.txt");
			 rename("temp_res.txt","reservations.txt");
			 printf("la modification a reussi");
		      
	
		}	
	}
	else
	{
	printf("\n la modification a ete annule");	
		
	}
		
}

//**_____________**procedure d'affichage**___________**
void afficher_res()
{
system("cls");
FILE *A;
A=fopen("reservations.txt","r");
puts("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
printf("------------------------------------------   La Liste Des Reservation  -------------------------------------------- \n");
puts("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
printf("**********************************************************************************************************************\n");
printf("NUMERO\t  numero de client\t   date\t         nombre des nuit\t nombre de personne\t nombre des chambres\n");
printf("**********************************************************************************************************************\n");
do
{
	fscanf(A,"%d ;%d ;%d/%d/%d ;%d ;%d ;%d \n",&res.num,&client.num,&res.date.jj,&res.date.mm,&res.date.aa,&res.nbr_nuit,&res.nbr_ch,&res.nbr_pers);
	fflush(stdin);
	printf("  %d\t|",res.num);
	printf("  %d\t\t  |",client.num);
	printf(" %d/%d/%d \t\t|",res.date.jj,res.date.mm,res.date.aa);
	printf("  %d\t\t      |",res.nbr_nuit);
	printf("  %d\t\t\t|",res.nbr_ch);
	printf("  %d \n",res.nbr_pers);
printf("***********************************************************************************************************************\n");
} while (!feof(A));

fclose(A);
}
//___________*****************************************
//____________*********gestionnaire chambre**********
//______________*********************************


//**__________**fonction de recherche des chambres**_____________________**
int rech_ch (int num_rech)
{
	FILE *C;
	C=fopen("chambres.txt","r");
	do
	{
		fscanf(C,"%d ;%s ;%s ;%c ;%d \n",&chambre.num,&chambre.type,&chambre.categorie,&chambre.etat,&chambre.prix);
		fflush(stdin); //fflash(stdin); ==> pour libere la memoire et evitée les probleme aucours de compilation
		if (chambre.num == num_rech)
		{
			fclose(C);
			return 1;
			
		}
		
	
	}
	while (!feof(C));
	fclose(C);
	return -1;
}
//**___________**procedure pour ajouter une chambre**_______________**
void ajouter_une_chambre()
{
	int choix;
	char x[] ="swite";
	system("cls");
	FILE *C;
	int num;
	C=fopen("chambres.txt","a");
	printf("\n entre le numero du chambre ajoute: ");
	scanf("%d",&num);
	fflush(stdin);
		
	while (rech_ch(num)==1)
	 //boucle while pour verifier que le numero ajoutée n'existe pas
	{
		printf("\n ce numero existe deja !!");
		printf("\n entrer le numero du chambre ajouter :");
		scanf("%d",&num);
	}
	   chambre.num=num;
	   
		printf("\n entrer le type de chambre\n 1:single\n 2:double\n 3:triple\n 4:suite\n :");
		scanf("%d",&choix);
		switch (choix)
		{
			case 1:
			chambre.type=="single";
			chambre.prix=50;
			break;
			case 2:
				chambre.type=="double";
				chambre.prix=80;
				break;
			case 3:
			  chambre.type=="triple";
			  chambre.prix=130;
			  break;
			case 4:
			 chambre.type=="suite";
				chambre.prix=180;
				break;
				default:
					printf("\n SVP saisir un choix entre (1..4)\a");
		}
		
		fflush(stdin);
		
		printf("\n entrer la categorie de chambre\n vue_mer\n vue_cup\n  :");
		gets(chambre.categorie);
	    fflush(stdin);
		
		printf("\n saisir l'etat de chambre\n 1:reserve\n 0:libre\n  :");
		scanf("%c",&chambre.etat);
        fflush(stdin);
		
	    
		fprintf(C,"%d ;%s ;%s ;%c ;%d \n",chambre.num,chambre.type,chambre.categorie,chambre.etat,chambre.prix);
		fflush(stdin);
		
		fclose(C);
}
//**_____________**fonction recherche et affichage**___________**

void recherche_chambre ()
{
system("cls");
int num_r;
printf("saisir le numero de la chambre a rechercher\n");
scanf("%d",&num_r);
FILE *C;
C=fopen("chambres.txt","r");
do
{
	fscanf(C,"%d ;%s ;%s ;%c ;%d \n",&chambre.num,&chambre.type,&chambre.categorie,&chambre.etat,&chambre.prix);
	if (num_r==chambre.num)
	{
	printf("-----------INFORMATION SUR CEtte CHAMBRE : ----------\n\n");
		printf("numero\t: %d \n",chambre.num);
		printf("type\t: %s \n",chambre.type);
		printf("categorie\t: %s \n",chambre.categorie);
		printf("etat\t: %c \n",chambre.etat);
		printf("prix\t: %d \n",chambre.prix);
		
	}
}while(!feof(C));
fclose(C);
}
//**_____________**procedure de suppression**___________**
void supprimer_chambre()
{
	system("cls");
	char rep;
	int num_rech;
	printf("entrez le numero de chambre a supprimer:");
	scanf("%d",&num_rech);
	fflush(stdin);
	if(rech_ch(num_rech)==1)
	{
		printf("\n voulez vous vraiment supprimer O/N ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep=='o'|| rep=='O')
		{
			FILE *FICH1, *C;
			C=fopen("chambres.txt","r");
			FICH1=fopen("temp_chambres.txt","a");
		   do
		     { 
		     fscanf(C,"%d ;%s ;%s ;%c ;%d \n",&chambre.num,&chambre.type,&chambre.categorie,&chambre.etat,&chambre.prix);
		     if (num_rech != chambre.num)
		     {
		     	fprintf(FICH1,"%d ;%s ;%s ;%c ;%d \n",chambre.num,chambre.type,chambre.categorie,chambre.etat,chambre.prix);
			 }
			
			 }while (!feof(C));
			 fclose(FICH1);
			 fclose(C);
			 remove ("chambres.txt");
			 rename("temp_chambres.txt","chambres.txt");
			 printf("supression effectuer avec succees");
			 	
		}	
	}
	else
	{
	
		printf("\n ce numero n'existe pas");
	}
}


//**_____________**procedure pour la modification du chambre**___________**

void modifier_chambre()
{
	system("cls");
		FILE *FICH1, *C;
	char rep='n';
	int num_rec;
	printf("\n entre le numero de la chambre a modifier:");
	scanf("%d",&num_rec);
	fflush(stdin);
	if(rech_c(num_rec)==1)
	{
		printf("\n voulez vous vraiment modifier  O/N ?");
		scanf("%c",&rep);
		fflush(stdin);
		
		if(rep=='o'|| rep=='O')
		{
		
			C=fopen("chambres.txt","r");
			FICH1=fopen("temp_chambres.txt","a");
		   do
		     { 
		     fscanf(C,"%d ;%s ;%s ;%c ;%d \n",&chambre.num,&chambre.type,&chambre.categorie,&chambre.etat,&chambre.prix);
		     if (num_rec == chambre.num)
		     {
		     	chambre.num=num_rec;
		     	
		     printf("\n entrer la  nouvelle etat de chambre :");
		     scanf("%c",&chambre.etat);
		     fflush(stdin);	
		
		     printf("\n entre le nouveau prix  de cette  chambre :");
		     scanf("%d",&chambre.prix);
		     fflush(stdin);
			 }
			 fprintf(FICH1,"%d ;%s ;%s ;%c ;%d \n",chambre.num,chambre.type,chambre.categorie,chambre.etat,chambre.prix);
			 }while (!feof(C));
			 
			 fclose(FICH1);
			 fclose(C);
			 remove ("chambres.txt");
			 rename("temp_chambres.txt","chambres.txt");
			 printf("la modification a reussi");
		      
			 	
		}	
	}
	else
	{
	
		printf("\n ce numero n'existe pas");
	}
	
}
//**_____________**procedure d'affichage**___________**
void afficher()
{
system("cls");
FILE *C;
C=fopen("chambres.txt","r");
printf("la liste des chambres est : \n\n");
printf("NUMERO\t type\t categorie\t etat\t prix\n");
printf("***************************************************\n");
do
{
	fscanf(C,"%d ;%s ;%s ;%s ;%d \n",&chambre.num,&chambre.type,&chambre.categorie,&chambre.etat,&chambre.prix);
	fflush(stdin);
	printf("%d\t|",chambre.num);
	printf("%s\t|",chambre.type);
	printf("%s\t|",chambre.categorie);
	printf("%c\t|",chambre.etat);
	printf("%d\n",chambre.prix);
printf("***************************************************\n");
} while (!feof(C));

fclose(C);
}
//**______________**a propos de programme**_________________**
void a_propos()
{ system("cls");
puts("                                                                                                             ");
puts("                                                                                                             ");
puts("                                                                                                             ");
puts("                                                                                                             ");
puts("                                                                                                             ");
puts("                                                                                                             ");
puts("                                                                                                             ");
puts("                                           ==============================================                    ");
puts("                                   >>>>>>>>>>>>>>>    I.S.E.T sidi bouzid       <<<<<<<<<<<<<<<<<<<          ");
puts("                                           ==============================================                    ");
puts("                                                                                                             ");
puts("                                                                                                             ");
puts("                                                GESTION DE RESERVATION HOTELIERE                             ");
puts("                                                                                                             ");
puts("                                                                                                             ");
puts("                                                             V 1.0                                           ");
puts("                                                                                                             ");
puts("                                                                                                             ");
puts("                                                           mini projet                                       ");
puts("                                                                                                             ");
puts("                                                                                                             ");
puts("                                                         programmer par :                                    ");
puts("                                                                                                             ");
puts("                                                                                                             ");
puts("                                                           MOEZ FELHI                                        ");
puts("                                                              TI 12                                          ");
puts("                                                                                                             ");
puts("                                                            2016/2017                                        ");


	
}
//-------procedure de cryptage------------//
int getnombre()
{
        int c;
        int n=0;
        do
        {
                c=getch();      // attends la prochaine touche
                if (c>='0' && c<='9')  // si c'est un chiffre uniquement
                {
                        n*=10;  
                        n+=(c-'0');          // mise a jour de n
                        cout << "*";
                        cout.flush();   // affiche une * et flush
                }
        }
        while(c!=13);   // jusqu'a entrée (code 13)
        cout << endl;   // revient a la ligne
        return n;
}
//procedure d'affectation d'une chambre//
int rech_aff (int num_rech)
{
	FILE *FF;
	FF=fopen("affectations.txt","r");
	do
	{
		fscanf(FF,"%d ;%d ;%d  \n",&chambre.num,&res.num,&client.num);
		fflush(stdin); //fflash(stdin); ==> pour libere la memoire et evitée les probleme aucours de compilation
		if (chambre.num == num_rech)
		{
			fclose(FF);
			return 1;
			
		}
		
	
	}
	while (!feof(FF));
	fclose(FF);
	return -1;
}
//**___________**procedure pour ajouter une affectation**_______________**
void ajouter_aff()
{
	system("cls");
	FILE *FF;
	int num;
	FF=fopen("affectations.txt","a");
	printf("\n entre le numero de chambre affecter: ");
	scanf("%d",&num);
	fflush(stdin);
		
	while (rech_aff(num)==1)
	 //boucle while pour verifier que le numero ajoutée n'existe pas
	{
		printf("\n ce numero existe deja !!");
		printf("\n entrer le numero de chambre affectee :");
		scanf("%d",&num);
	}
	   chambre.num=num;
	   
	   
		printf("\n entrer le num de reservation :");
		scanf("%d",&res.num);
		fflush(stdin);
		
		printf("\n entrer le numero de client :");
		scanf("%d",&client.num);
		fflush(stdin);
		
		fprintf(FF,"%d ;%d ;%d\n",chambre.num,res.num,client.num);
		fflush(stdin);
	
		fclose(FF);	 
		FILE *FICH1, *C;
			C=fopen("chambres.txt","r");
			FICH1=fopen("temp_chambres.txt","a");
		   do
		   {
		   	fscanf(C,"%d ;%s ;%s ;%c ;%d \n",&chambre.num,&chambre.type,&chambre.categorie,&chambre.etat,&chambre.prix);
		   		if	   (chambre.num==num)
                 {
                   	chambre.etat='1';
                     	fflush(stdin);
      	
	                 } 
	          fprintf(FICH1,"%d ;%s ;%s ;%c ;%d \n",chambre.num,chambre.type,chambre.categorie,chambre.etat,chambre.prix);       
		   } while (!feof(C));
           fclose(FICH1);
			 fclose(C);
			 remove ("chambres.txt");
			 rename("temp_chambres.txt","chambres.txt");
	
}

//**_____________**fonction recherche et affichage**___________**

void recherche_aff ()
{
system("cls");
int num_r;
printf("saisir le numero de chambre affectee\n");
scanf("%d",&num_r);
FILE *FF;
FF=fopen("affectations.txt","r");
do
{
	fscanf(FF,"%d ;%d ;%d\n",&chambre.num,&res.num,&client.num);
	if (num_r==chambre.num)
	{
	printf("-----------INFORMATION SUR CEet affectation : ----------\n\n");
		printf("numro de chambre affectee\t: %d \n",chambre.num);
		printf("numero de la reservation\t: %d \n",res.num);
		printf("numero de client\t: %d \n",client.num);
		
	}
}while(!feof(FF));
fclose(FF);
}

//**_____________**procedure de suppression**___________**
void supprimer_aff()
{
	system("cls");
	char rep;
	int num_rech;
	printf("entrez le numero de la chambre affectee a supprimer:");
	scanf("%d",&num_rech);
	fflush(stdin);
	if(rech_aff(num_rech)==1)
	{
		printf("\n voulez vous vraiment supprimer O/N ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep=='o'|| rep=='O')
		{
			FILE *FICHF, *FF;
			FF=fopen("affectations.txt","r");
			FICHF=fopen("temp_affectations.txt","a");
		   do
		     { 
		     fscanf(FF,"%d ;%d ;%d\n",&chambre.num,&res.num,&client.num);
		     if (num_rech != chambre.num)
		     {
		     	fprintf(FICHF,"%d ;%d ;%d\n",chambre.num,res.num,client.num);
			 }
			
			 }while (!feof(FF));
			 fclose(FICHF);
			 fclose(FF);
			 remove ("affectations.txt");
			 rename("temp_affectations.txt","affectations.txt");
			 printf("supression effectuer avec succees");
			 	
			
		
	
	FILE *FICH1, *C;
			C=fopen("chambres.txt","r");
			FICH1=fopen("temp_chambres.txt","a");
		   do
		   {
		   	fscanf(C,"%d ;%s ;%s ;%c ;%d \n",&chambre.num,&chambre.type,&chambre.categorie,&chambre.etat,&chambre.prix);
		   		if	   (chambre.num==num_rech)
                 {
                   	chambre.etat='0';
                     	fflush(stdin);
      	
	                 } 
	          fprintf(FICH1,"%d ;%s ;%s ;%c ;%d \n",chambre.num,chambre.type,chambre.categorie,chambre.etat,chambre.prix);       
		   } while (!feof(C));
           fclose(FICH1);
			 fclose(C);
			 remove ("chambres.txt");
			 rename("temp_chambres.txt","chambres.txt");
		}
	}
	else
	{
		printf("\n ce numero ne correspand aucun chambre ");
	}
		
}
//------------------------------------------//
//--------------menu pricipale-------------//
//----------------------------------------// 
 int main (int argc, char *argv[])
{
int	code=4070;
int code1;
puts("                                           =================================");
puts("                                           =          GESTION DE           =");
puts("                                           =  RESERVATION  HOTELIER        =");
puts("                                           =            V1.0               =");
puts("                                           =================================");
puts("                                                      BIENVENUE             \n\n");
do 
{
	printf("                                              saisir le code de securite     \n\n");
	printf("                                 ==============>>>>");    
	code1 =getnombre();

}
while(code1!=code);
goto menu_principale; // goto pour sauter des partie du programme vers une partie exacte


	int choix; char rep;
	
	menu_principale:
	Color(15, 5);
	do
	{
	system ("cls");// systeme (cls) pour vider la fenetre
	puts("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
	puts("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²² MENU PRINCIPALE ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
	puts("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\n\n");
	puts("                 _1_ gestion des cliens                                                                        ");
	puts("                                                                                                               ");
	puts("                                                                         _4_ a propos de programme          ");
	puts("                                                                                                               ");
	puts("                 _2_ gestion des reservations                                                                      ");
	puts("                                                                                                               ");
	puts("                                                                         _5_ quitter le programme                                     ");
	puts("                                                                                                               ");
	puts("                 _3_ gestion des chambres                                                                                              ");
	puts("                                                                                                               ");
	printf("\n\n");
	printf("                                            entre votre choix :                                                    \n\n");
printf("                                 ==============>>>>");
		scanf("%d",&choix);
		
		
		switch(choix)
		{
		  case 1: goto menu_client;
		     break;
		  case 2: goto menu_res;
		     break;
		  case 3: goto menu_chambre;
		     break;	
		  case 4:  a_propos();
		     break;
		  case 5:return 0;
		     break;	 	  	
		  
		 default : 
		 printf("svp resseyer autre option(1..5)\a");	 	
		    }
	
	printf("\n voulez-vous continuez O/N:");
	scanf("%s",&rep);
	fflush(stdin);
	}
	while (rep=='o' || rep=='O');
  
  
  
	menu_client:
	int choix1; char rep1;	
	do
	{
	system ("cls");// systeme (cls) pour vider la fenetre
	printf("  -----------gestion clients------------\n");
	printf("1- ajouter un client\n");
	printf("2- rechercher un client\n");
	printf("3- supprimer un client\n");
	printf("4- modifier un client\n");
	printf("5- afficher tous les clients \n");
	printf("6- retourner vers le menu principale\n\n");
	
	  
		printf(" - entre votre choix :");
		scanf("%d",&choix1);
		
		
		switch(choix1)
		{
		  case 1:ajouter_un_client();
		     break;
		  case 2:recherche();
		     break;	
		  case 3: supprimer_client();
		     break;
		  case 4:modifier_client();
		     break;	 	  	
		  case 5:afficher_tt();
		     break;
		  case 6: goto menu_principale; 
		     break;
		 default : 
		 printf("svp resseyer autre option(1..6)\a");	 	
		    }
	
	printf("\n voulez-vous continuez O/N:");
	scanf("%s",&rep1);
	fflush(stdin);
	}
	while (rep1=='o' || rep1=='O');
//---------------menu reservation------------	
	menu_res:
	do
	{
	system ("cls");// systeme (cls) pour vider la fenetre
	printf("  -----------menu reservation------------\n");
	printf("1- ajouter une reservation\n");
	printf("2- rechercher une reservation\n");
	printf("3- supprimer une reservation\n");
	printf("4- modifier une reservation\n");
	printf("5- afficher tous les reservation \n");
	printf("6- affectee chambre");
	printf("7- retourner vers le menu pricipale \n\n");
	
	  
		printf(" - entre votre choix :");
		scanf("%d",&choix);
		
		
		switch(choix)
		{
		  case 1:ajouter_res();
		     break;
		  case 2:recherche_res ();
		     break;	
		  case 3: supprimer_res();
		     break;
		  case 4:modifier_res();
		     break;	 	  	
		  case 5:afficher_res();
		     break;
		  case 6:goto affecte_chambre;
		     break;   
		  case 7: goto menu_principale;
		     break;
		 default : 
		 printf("svp resseyer autre option(1..6)\a");	 	
		    }
	
	printf("\n voulez-vous continuez O/N:");
	scanf("%s",&rep);
	fflush(stdin);
	}
	while (rep=='o' || rep=='O');
//menu affectation des chambres
affecte_chambre:
	do
	{
	
	system ("cls");// systeme (cls) pour vider la fenetre
	printf("  -----------menu affectation------------\n");
	printf("1- ajouter une affectation\n");
	printf("2- rechercher une affectation\n");
	printf("3- supprimer une affectation\n");
	printf("4- retourner vers le menu gestion des reservations \n\n");
	
	  
		printf(" - entre votre choix :");
		scanf("%d",&choix);
		
		
		switch(choix)
		{
		  case 1:ajouter_aff();
		     break;
		  case 2:recherche_aff ();
		     break;	
		  case 3: supprimer_aff();
		     break;
		  case 4:goto menu_res;
		     break;   
		 default : 
		 printf("svp resseyer autre option(1..4)\a");	 	
		    }
	
	printf("\n voulez-vous continuez O/N:");
	scanf("%s",&rep);
	fflush(stdin);
}
	while (rep=='o' || rep=='O');	
	
//------menu chambres---------	 
	  menu_chambre:
	  	
	do
	{
	system ("cls");// systeme (cls) pour vider la fenetre
	printf("  -----------menu chambre------------\n");
	printf("1- ajouter une chambre\n");
	printf("2- rechercher une chambre\n");
	printf("3- supprimer une chambre\n");
	printf("4- modifier une chambre\n");
	printf("5- afficher tous les chambre \n");
	printf("6- retourner vers menu pricipale \n\n");
	
	  
		printf(" - entre votre choix :");
		scanf("%d",&choix);
		
		
		switch(choix)
		{
		  case 1:ajouter_une_chambre();
		     break;
		  case 2:recherche_chambre ();
		     break;	
		  case 3: supprimer_chambre();
		     break;
		  case 4:modifier_chambre();
		     break;	 	  	
		  case 5:afficher();
		     break;
		  case 6: goto menu_principale;
		     break;
		 default : 
		 printf("svp resseyer autre option(1..6)\a");	 	
		    }
	
	printf("\n voulez-vous continuez O/N:");
	scanf("%s",&rep);
	fflush(stdin);
	}
	while (rep=='o' || rep=='O');


}
