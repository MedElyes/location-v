typedef	struct
{
	int jj;
	int mm;
	int aa;
}dates;

struct location
{
int voiture;
int nbr_jrs;
float prix;
dates date;
};
 struct location loc;
 
 
 
 
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
		
	while (rech(num)==1)
	 // verification sur l'existance du numero ajouté------------
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
	if(rech(num_rech)==1)
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
	int num_rec;
	printf("entrez le numero de location à modifie:");
	scanf("%d",&num_rec);
	fflush(stdin);
	if(rech(num_loc)==1)
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
			 fclose(A);
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
printf("                                  La Liste Des Locations :  \n\n");
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


