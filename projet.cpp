#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
#include <conio.h>
#include <unistd.h>
#include<windows.h>
using namespace std;


//les structures--------------------
typedef	struct
{
	int jj;
	int mm;
	int aa;
}dates;

struct clients
{
	int num;
	char nom[50];
	char prenom[50];
	char cin[50];
};

struct location
{
int voiture;
int nbr_jrs;
float prix;
dates date;
};

struct voiture
{
	int num;
    char nom[50];
	char mark[50];
    int puis;
};

struct clients client;
struct voiture vot;
struct location loc;
//appel procedures voitures---------
int rech_ch_v (int num_rech);
void ajouter_une_voiture();
void recherche_voiture ();
void supprimer_voiture();
void modifier_voiture();
void afficher();
//appel procedures clients-----------
int rech_c (int num_rech);
void ajouter_un_client();
void recherche ();
void supprimer_client();
void modifier_client();
void afficher_tt();
//appel procedures locations----------
int rech_l(int NumRech);
void ajouter_loc();
void recherche_loc();
void supprimer_loc();
void modifier_loc();
void afficher_loc();
//appel procedure de cryptage--------- 
 int getnombre()
{
        int c;
        int n=0;
        do
        {
                c=getch();      
                if (c>='0' && c<='9')  
                {
                	Beep(3000,100);
                        n*=10;  
                        n+=(c-'0');          
                        cout << "*";
                        cout.flush();   
                }
        }
        while(c!=13);   
        cout << endl;   
        return n;
}
 
 int main (int argc, char *argv[])
 //main----------------------------------
{
int	code=792017;
int code1;
//bienvenue------------------------

do{
puts(" ******************************************************************************************************************");
puts(" *   Med Elyes abidi *      >>>>>>>>>>>>>>>    I.S.E.T sidi bouzid       <<<<<<<<<<<<<<<<<<<          * TI12      *");
puts(" ******************************************************************************************************************");
puts("                                          GESTION DE LOCATION VOITURES                             ");
puts("                                                  *  BIENVENUE *                                                                    ");
puts("                                                    ***********                                                                     ");

	printf("                                              saisir le code de securite :    \n\n"                            );
	printf("                                 ==============>>>>"                                                           );    
	Beep(3000,100);
	code1 =getnombre();
	Beep(3000,100);
system("cls");// vider la fenetre
}
while(code1!=code);
goto menu_principale; //sauter vers une partie precie du programme


	int choix; char rep;
	
	menu_principale:
	do
	{
	system ("cls");
	//menu principal---------------------------------------
puts(" ***********************************************************************************************************************************");
puts(" *   Med Elyes abidi *                                                                                                 * TI12      *");
puts(" ***********************************************************************************************************************************");
	puts("                                                  -----------------                                            ");
	puts("                                               * | MENU PRINCIPALE | *                                         ");
	puts("                                                  -----------------                                            ");
	puts(" **************************************************************************************************************");
	puts(" *                                                                                                            *");
	puts(" *                >1 gestion des cliens................................................................1      *");
	puts(" *                                                                                                            *");
	puts(" *                >2 gestion des locations.............................................................2      *");
	puts(" *                                                                                                            *");
	puts(" *                >3 gestion des Voitures..............................................................3      *");
	puts(" *                                                                                                            *");
	puts(" *                >4 quitter le programme..............................................................4      *");
	puts(" *                                                                                                            *");
	puts(" *                                                                                                            *");
	puts(" **************************************************************************************************************");

	printf("\n\n");
	printf("                                            choisir l'action  :                                                    \n\n");
    printf("                                 ==============>>>>");
	scanf("%d",&choix);
		
		
		switch(choix)
		{
		  case 1: goto menu_client;
		     break;
		  case 2: goto menu_loc;
		     break;
		  case 3: goto menu_voiture;
		     break;	
		  case 4: return 0;
		     break;	 	  	
		  
		 default : 
		 printf("votre choix est compris entre (1..4)\a");	 	
		    }
	
	printf("\n voulez-vous continuez O/N:\n ===> \t");
	scanf("%s",&rep);
	fflush(stdin);
	}
	while (rep=='o' || rep=='O');
  
  
//menu clients---------------------------------
	menu_client:
	int choix1; char rep1;	
	do
	{
	system ("cls");
puts(" ***********************************************************************************************************************************");
puts(" *   Med Elyes abidi *                                                                                                 * TI12      *");
puts(" ***********************************************************************************************************************************");	
	puts("                                                -----------                                                   ");
	puts("                                              *|menu client|*                                                 ");
	puts("                                                -----------                                                   ");
	puts("*************************************************************************************************************");
	puts("*                                                                                                           *");
	puts("* >ajout.................................................................................................1  *");
	puts("*                                                                                                           *");
	puts("* >recherche.............................................................................................2  *");
	puts("*                                                                                                           *");
	puts("* >supprission...........................................................................................3  *");
	puts("*                                                                                                           *");
	puts("* >modification..........................................................................................4  *");
	puts("*                                                                                                           *");
	puts("* >affichage.............................................................................................5  *");
	puts("*                                                                                                           *");
	puts("* >retour vers le menu pricipale.........................................................................6  *");
	puts("*                                                                                                           *");
	puts("*************************************************************************************************************");
	printf(" choisir l'action :\n ===>\t");
	Beep(3000,100);
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
		 printf("votre choix est compris entre (1..6)\a");	 	
		    }
	
	printf("\n voulez-vous continuez O/N:\n===>\t");
	scanf("%s",&rep1);
	fflush(stdin);
	}
	while (rep1=='o' || rep1=='O');
//menu location----------------------------------------	
	menu_loc:
	do
	{
	system ("cls");
puts(" ***********************************************************************************************************************************");
puts(" *   Med Elyes abidi *                                                                                                 * TI12      *");
puts(" ***********************************************************************************************************************************");
   	puts("                                                -------------                                                   ");
	puts("                                              *|menu location|*                                                 ");
	puts("                                                -------------                                                   ");
	puts("*************************************************************************************************************");
	puts("*                                                                                                           *");
	puts("* >ajout.................................................................................................1  *");
	puts("*                                                                                                           *");
	puts("* >recherche.............................................................................................2  *");
	puts("*                                                                                                           *");
	puts("* >supprission...........................................................................................3  *");
	puts("*                                                                                                           *");
	puts("* >modification..........................................................................................4  *");
	puts("*                                                                                                           *");
	puts("* >affichage.............................................................................................5  *");
	puts("*                                                                                                           *");
	puts("* >retour vers le menu pricipale.........................................................................6  *");
	puts("*                                                                                                           *");
	puts("*************************************************************************************************************");
	printf(" choisir l'action :\n ===>\t");
	Beep(3000,100);
	scanf("%d",&choix);
		
		switch(choix)
		{
		  case 1:ajouter_loc();
		     break;
		  case 2:recherche_loc ();
		     break;	
		  case 3: supprimer_loc();
		     break;
		  case 4:modifier_loc();
		     break;	 	  	
		  case 5:afficher_loc();
		     break;
		  case 6: goto menu_principale;
		     break;
		 default : 
		 printf("votre choix est compris entre (1..6)\a");	 	
		    }
	
	printf("\n voulez-vous continuez O/N? :\n===>\t");
	scanf("%s",&rep);
	fflush(stdin);
	}
	while (rep=='o' || rep=='O');
	
	

//menu voitures-----------------------------------	 
	  menu_voiture:
	  	
	do
	{
	system ("cls");
puts(" ***********************************************************************************************************************************");
puts(" *   Med Elyes abidi *                                                                                                 * TI12      *");
puts(" ***********************************************************************************************************************************");
	puts("                                                -------------                                                   ");
	puts("                                              *|menu voitures|*                                                 ");
	puts("                                                -------------                                                   ");
	puts("*************************************************************************************************************");
	puts("*                                                                                                           *");
	puts("* >ajout.................................................................................................1  *");
	puts("*                                                                                                           *");
	puts("* >recherche.............................................................................................2  *");
	puts("*                                                                                                           *");
	puts("* >supprission...........................................................................................3  *");
	puts("*                                                                                                           *");
	puts("* >modification..........................................................................................4  *");
	puts("*                                                                                                           *");
	puts("* >affichage.............................................................................................5  *");
	puts("*                                                                                                           *");
	puts("* >retour vers le menu pricipale.........................................................................6  *");
	puts("*                                                                                                           *");
	puts("*************************************************************************************************************");
	printf("  choisir l'action :\n===>\t");
   	Beep(3000,100);
	scanf("%d",&choix);
	  
	
		
		
		switch(choix)
		{
		  case 1:ajouter_une_voiture();
		     break;
		  case 2:recherche_voiture ();
		     break;	
		  case 3: supprimer_voiture();
		     break;
		  case 4:modifier_voiture();
		     break;	 	  	
		  case 5:afficher();
		     break;
		  case 6: goto menu_principale;
		     break;
		 default : 
		 printf("votre choix est compris entre (1..6)\a");	 	
		    }
	
	printf("\n voulez-vous continuez O/N:\n===>\t");
	scanf("%s",&rep);
	fflush(stdin);
	}
	while (rep=='o' || rep=='O');
	
	
}

/***********************************************************************************************************************************************************************************
                                                                      procedures et fonctions 
***********************************************************************************************************************************************************************************/

// procedures et fonctions des clients:.......................................................1

/*__________fonction de recherche des clients_____________________*/
int rech_c (int num_rech)
{
	FILE *C;
	C=fopen("clients.txt","r");
	do
	{
		fscanf(C,"%d ;%s ;%s ;%s \n",&client.num,&client.nom,&client.prenom,&client.cin);
		fflush(stdin); 
		if (client.num == num_rech)
		{
			fclose(C);
			return 1;
			
		}
		
	
	}
	while (!feof(C));
	fclose(C);
	return -1;
}
/*___________*procedure d'ajout d'un client*_______________*/
void ajouter_un_client()
{
	system("cls");
	FILE *C;
	int num;
	C=fopen("clients.txt","a");
	printf("\n entre le numero du nouveau client: ");
	scanf("%d",&num);
	fflush(stdin);
		
	while (rech_c(num)==1)
	 // verifiecation de l'existance du nnumero ajouté 
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
		
		fprintf(C,"%d ;%s ;%s ;%s \n",client.num,client.nom,client.prenom,client.cin);
		fflush(stdin);
		
		fclose(C);
}

/*_____________*fonction de recherche et d'affichage*___________*/

void recherche ()
{
system("cls");
int num_r;
printf("saisir le numero de client a rechercher\n");
scanf("%d",&num_r);
FILE *C;
C=fopen("clients.txt","r");
do
{
	fscanf(C,"%d ;%s ;%s ;%s \n",&client.num,&client.nom,&client.prenom,&client.cin);
	if (num_r==client.num)
	{
	printf("-----------INFORMATION SUR CE CLIENT : ----------\n\n");
		printf("numero\t: %d \n",client.num);
		printf("nom\t: %s \n",client.nom);
		printf("prenom\t: %s \n",client.prenom);
		printf("CIN\t: %s \n",client.cin);
		
	}
}while(!feof(C));
fclose(C);
}

/*_____________*procedure de suppression*___________*/
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
		printf("\n voulez-vous continuez O/N? :\n===>\t");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep=='o'|| rep=='O')
		{
			FILE *FICH, *C;
			C=fopen("clients.txt","r");
			FICH=fopen("temp_client.txt","a");
		   do
		     { 
		     fscanf(C,"%d ;%s ;%s ;%s \n",&client.num,&client.nom,&client.prenom,&client.cin);
		     if (num_rech != client.num)
		     {
		     	fprintf(FICH,"%d ;%s ;%s ;%s \n",client.num,client.nom,client.prenom,client.cin);
			 }
			
			 }while (!feof(C));
			 fclose(FICH);
			 fclose(C);
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
		FILE *FICH, *C;
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
		
			C=fopen("clients.txt","r");
			FICH=fopen("temp_client.txt","a");
		   do
		     { 
		     fscanf(C,"%d ;%s ;%s ;%s \n",&client.num,&client.nom,&client.prenom,&client.cin);
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
			 }while (!feof(C));
			 
			 fclose(FICH);
			 fclose(C);
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

/*_____________*procedure d'affichage*___________*/
void afficher_tt()
{
system("cls");
FILE *C;
C=fopen("clients.txt","r");
printf("la liste des clients est : \n\n");
printf("NUMERO\t NOM\t PRENOM\t NUMERO CIN\n");
do
{
	fscanf(C,"%d ;%s ;%s ;%s \n",&client.num,&client.nom,&client.prenom,&client.cin);
	fflush(stdin);
	printf("%d\t",client.num);
	printf("%s\t",client.nom);
	printf("%s\t",client.prenom);
	printf("%s\n",client.cin);
} while (!feof(C));
fclose(C);
}

// procedures et fonctions des locations:.......................................................2

/*_____________________*Fonction recherche*____________*/
int rech_l(int NumRech)
{
	FILE*F;
	F=fopen("location.txt","r");
	do
	{
		fscanf(F,"%d ;%d ;%f ;%d%d%d \n",&loc.voiture,&loc.nbr_jrs,&loc.prix,&loc.date.jj,&loc.date.mm,&loc.date.aa);
		fflush(stdin);
		if(loc.voiture==NumRech)
		{
			fclose(F);
			return 1;
		}
	}
   while(!feof(F));
   fclose(F);
    return -1;
}
/*_________________*procedure ajout du location*__________________*/
void ajouter_loc()
{
	system("cls");
	FILE *F;
	int num;
	F=fopen("location.txt","a");
	printf("\n entre le numero du nouveau locatin: \n");
	scanf("%d",&num);
	fflush(stdin);
		
	while (rech_l(num)==1)
	{
		printf("\n ce numero existe deja !!");
		printf("\n entrer le numero du nouveau location : \n");
		scanf("%d",&num);
	}
	   loc.voiture=num;
	   
		printf("\n entrer le numero du locateur :");
		scanf("%d",&client.num);
		fflush(stdin);
		
		printf("\n entrer la date du location : \n");
		printf("le jour :\t");
		scanf("%d",&loc.date.jj);
		printf("le mois :\t");
		scanf("%d",&loc.date.mm);
		printf("l'annee' :\t");
		scanf("%d",&loc.date.aa);
		fflush(stdin);
		
		printf("\n entre le nombre de jours :");
		scanf("%d",&loc.nbr_jrs);
		fflush(stdin);
		
		printf("\n entre le prix du locatin :");
		scanf("%f",&loc.prix);
		fflush(stdin);
		
	
		
		fprintf(F,"%d ;%d/%d/%d ;%d ;%d ;%f \n",loc.voiture,loc.date.jj,loc.date.mm,loc.date.aa,loc.nbr_jrs,loc.prix);
		fflush(stdin);
		
		fclose(F);
}
/*________________*procedure de recherche et d'affichage des locations*_________________*/
void recherche_loc()
{
system("cls");
int num_l;
printf("saisir le numero de location a recherche\n");
scanf("%d",&num_l);
FILE *F;
F=fopen("location.txt","r");
do
{
	fscanf(F,"%d ;%d/%d/%d ;%d ;%d ;%f \n",&loc.voiture,&loc.date.jj,&loc.date.mm,&loc.date.aa,&loc.nbr_jrs,&loc.prix);
	if (num_l==loc.voiture)
	{
	printf("\t\t-----------Information Sur Cet Reservation : ----------\n\n");
		printf("\t\t numero\t: %d \n",loc.voiture);
		printf("\t\t date\t: %d/%d/%d \n",loc.date.jj,loc.date.mm,loc.date.aa);
		printf("\t\t nombre des jours\t: %d \n",loc.nbr_jrs);
		printf("\t\t le prix \t: %f \n",loc.prix);
		
	}
}while(!feof(F));
fclose(F);
}
/*________________*procedure de suppression des locations*_______________*/
void supprimer_loc()
{
	system("cls");
	char rep;
	int num_rech;
	printf("entrez le numero de location a supprimer:");
	scanf("%d",&num_rech);
	fflush(stdin);
	if(rech_l(num_rech)==1)
	{
		printf("\n voulez vous vraiment supprimer O/n ? : \n====>\t ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep=='o'|| rep=='O')
		{
			FILE *FICH2, *F;
			F=fopen("location.txt","r");
			FICH2=fopen("loc.txt","a");
		   do
		     { 
		     fscanf(F,"%d ;%d/%d/%d ;%d ;%d ;%f \n",&loc.voiture,&loc.date.jj,&loc.date.mm,&loc.date.aa,&loc.nbr_jrs,&loc.prix);
		     if (num_rech != loc.voiture)
		     {
		     	fprintf(FICH2,"%d ;%d/%d/%d ;%d ;%d ;%f \n",loc.voiture,loc.date.jj,loc.date.mm,loc.date.aa,loc.nbr_jrs,loc.prix);
			 }
			
			 }while (!feof(F));
			 fclose(FICH2);
			 fclose(F);
			 remove ("location.txt");
			 rename("loc.txt","location.txt");
			 printf("supression effectue avec succee");
			 	
		}	
	}
	else
	{
		printf("\n ce numero ne correspand pas à un location");
	}
		
}
/*________________*procedure de modification des locations*___________________*/

void modifier_loc()
{
	system("cls");
		FILE *FICH2, *F;
	char rep='n';
	int num_loc;
	printf("entrez le numero de location à modifie:");
	scanf("%d",&num_loc);
	fflush(stdin);
	if(rech_l(num_loc)==1)
	{
		printf("\n voulez vous vraiment modifier ce client O/n \n ===>\t?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep=='o'|| rep=='O')
		{
		
			F=fopen("location.txt","r");
			FICH2=fopen("loc.txt","a");
		   do
		     { 
		     fscanf(F,"%d ;%d/%d/%d ;%d ;%d ;%f \n",&loc.voiture,&loc.date.jj,&loc.date.mm,&loc.date.aa,&loc.nbr_jrs,&loc.prix);
		     if (num_loc == loc.voiture)
		     {
		     	loc.voiture=num_loc;
		     printf("\n entrer la nouvelle date de location :\n ");
	    	 printf("le jour :\t");
	    	 scanf("%d",&loc.date.jj);
	    	 printf("le mois :\t");
	    	 scanf("%d",&loc.date.mm);
	    	 printf("l'annee' :\t");
	    	 scanf("%d",&loc.date.aa);
	    	  fflush(stdin);
	    	  
		
		     printf("\n saisir le nouveau nombre des jours  :");
		     scanf("%d",&loc.nbr_jrs);
		     fflush(stdin);
		
		     printf("\n saisir le nouveau prix :");
		     scanf("%f",&loc.prix);
		     fflush(stdin);
		     
			 }
			 fprintf(FICH2,"%d ;%d/%d/%d ;%d ;%d ;%f \n",loc.voiture,loc.date.jj,loc.date.mm,loc.date.aa,loc.nbr_jrs,loc.prix);
			 }while (!feof(F));
			 
			 fclose(FICH2);
			 fclose(F);
			 remove ("location.txt");
			 rename("loc.txt","location.txt");
			 printf("la modification a reussi");
		      
	
		}	
	}
	else
	{
	printf("\n la modification a ete annule");	
		
	}
		
}
/*_____________*procedure d'affichage des locations*________________*/
void afficher_loc()
{
system("cls");
FILE *F;
F=fopen("location.txt","r");
puts("                                  La Liste Des Locations :  \n\n");
printf("*************************************************************************************************\n");

do
{
	fscanf(F,"%d ;%d/%d/%d ;%d ;%d ;%f \n",&loc.voiture,&loc.date.jj,&loc.date.mm,&loc.date.aa,&loc.nbr_jrs,&loc.prix);
	fflush(stdin);
	printf("> nuemro du location : %d \n",loc.voiture);
	printf("> date du location : %d/%d/%d \n",loc.date.jj,loc.date.mm,loc.date.aa);
	printf("> nombre de jours : %d ",loc.nbr_jrs);
	printf("> le prix :  %f\n",loc.prix);
printf("*************************************************************************************************\n");
} while (!feof(F));

fclose(F);
}

// procedures et fonctions des voitures:.......................................................3                                                                    

/*__________________*fonction de recherche des voitures*_____________________*/
int rech_ch_v (int num_rech)
{
	FILE *V;
	V=fopen("voiture.txt","r");
	do
	{
		fscanf(V,"%d ;%s ;%s ;%d\n",&vot.num,&vot.nom,&vot.mark,&vot.puis);
		fflush(stdin); //liberation la memoire 
		if (vot.num == num_rech)
		{
			fclose(V);
			return 1;
			
		}
		
	
	}
	while (!feof(V));
	fclose(V);
	return -1;
}
/*_________________________*procedure d'ajout des voitures*___________________*/
void ajouter_une_voiture()
{
	system("cls");
	FILE *V;
	int num;
	V=fopen("voiture.txt","a");
	printf("\n entrez le numero de la voiture à ajouter : ");
	scanf("%d",&num);
	fflush(stdin);
		
	while (rech_ch_v(num)==1)
	{
		printf("\n ce numero existe deja !!");
		printf("\n entrez a nouveau le numero du la voiture à ajouter : \n");
		scanf("%d",&num);
	}
	   vot.num=num;
	   
		printf("\n entrer le nom de la voiture :\n");
		gets(vot.nom);
		fflush(stdin);
		
		printf("\n entrer la marque de la voiture :\n");
		gets(vot.mark);
	    fflush(stdin);
		
		printf("\n saisir la puissance de la voiture (cv) :\n");
		scanf("%d",&vot.puis);
        fflush(stdin);
		
		fprintf(V,"%d ;%s ;%s ;%d \n",vot.num,vot.nom,vot.mark,vot.puis);
		fflush(stdin);
		
		fclose(V);
}
/*_____________________*procedure de recherche et d'affichage des voitures*________________________*/

void recherche_voiture ()
{
system("cls");
int num_r;
printf("saisir le numero de la voiture a rechercher\n");
scanf("%d",&num_r);
FILE *V;
V=fopen("voiture.txt","r");
do
{
	fprintf(V,"%d ;%s ;%s ;%d\n",vot.num,vot.nom,vot.mark,vot.puis);
	if (num_r==vot.num)
	{
	printf("-----------Informations Sur Cette Voiture : ----------\n\n");
		printf("numero\t: %d \n",vot.num);
		printf("nom\t: %s \n",vot.nom);
		printf("marque\t: %s \n",vot.mark);
		printf("puissance (cv)\t: %d \n",vot.puis);
	
		
	}
}while(!feof(V));
fclose(V);
}
/*_______________________*procedure de suppression des voitures*___________________________*/
void supprimer_voiture()
{
	system("cls");
	char rep;
	int num_rech;
	printf("entrez le numero de la voiture a supprime:");
	scanf("%d",&num_rech);
	fflush(stdin);
	if(rech_ch_v(num_rech)==1)
	{
		printf("\n voulez vous vraiment supprimer O/N ? : \n \===>t");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep=='o'|| rep=='O')
		{
			FILE *FICH1, *V;
			V=fopen("voiture.txt","r");
			FICH1=fopen("vol.txt","a");
		   do
		     { 
		         fscanf(V,"%d ;%s ;%s ;%d \n",&vot.num,&vot.nom,&vot.mark,&vot.puis);
		     if (num_rech != client.num)
		     {
		     	 fprintf(FICH1,"%d ;%s ;%s ;%d \n",vot.num,vot.nom,vot.mark,vot.puis);
			 }
			
			 }while (!feof(V));
			 fclose(FICH1);
			 fclose(V);
			 remove ("voiture.txt");
			 rename("vol.txt","voiture.txt");
			 printf("supression effectuer avec succees");
			 	
		}	
	}
	else
	{
		printf("\n ce numero ne correspand a aucune voiture");
	}
		
}
/*___________________*procedure de modification des voitures*___________________*/

void modifier_voiture()
{
	system("cls");
		FILE *FICH1, *V;
	char rep='n';
	int num_rec;
	printf("\n entre le numero de la voiture a modifie:");
	scanf("%d",&num_rec);
	fflush(stdin);
	if(rech_c(num_rec)==1)
	{
		printf("\n voulez vous vraiment modifier  O/n ? : \n ===>\t");
		scanf("%c",&rep);
		fflush(stdin);
		
		if(rep=='o'|| rep=='O')
		{
		
			V=fopen("voiture.txt","r");
			FICH1=fopen("vol.txt","a");
		   do
		     { 
		     fscanf(V,"%d ;%s ;%s ;%d \n",&vot.num,&vot.nom,&vot.mark,&vot.puis);
		     if (num_rec == vot.num)
		     {
		     	vot.num=num_rec;
		     	
		     printf("\n entrer le nouveau nom de la voiture :");
		     gets(vot.nom);
		     fflush(stdin);	
		
		     printf("\n entre la nouvelle marque  de la voiture :");
		     scanf("%c",&vot.mark);
		     fflush(stdin);
		     
		     printf("\n entre la nouvelle puissance (cv)  de la voiture :");
		     scanf("%d",&vot.puis);
		     fflush(stdin);
		     
			 }
			 fprintf(FICH1,"%d ;%s ;%s ;%d\n",vot.num,vot.nom,vot.mark,vot.puis);
			 }while (!feof(V));
			 
			 fclose(FICH1);
			 fclose(V);
			 remove("voiture.txt");
			 rename("vol.txt","voiture.txt");
			 printf("la modification a reussi");
		      
			 	
		}	
	}
	else
	{
	
		printf("\n ce numero n'existe pas");
	}
	
}

/*____________________*procedure d'affichage des voitures*_________________*/
void afficher()
{
system("cls");
FILE *V;
V=fopen("voiture.txt","r");
printf("la liste des voitures : \n\n");
printf("***************************************************\n");
do
{
	fscanf(V,"%d ;%s ;%s ;%d ;%d%d \n",&vot.num,&vot.nom,&vot.mark,&vot.puis);
	fflush(stdin);
	printf(">le numero :\t %d\n",vot.num);
	printf(">le nom :\t %s\n",vot.nom);
	printf(">la marque : \t %s\n",vot.mark);
	printf(">la puissance : \t %d \n",vot.puis);
printf("***************************************************\n");
} while (!feof(V));

fclose(V);
}

