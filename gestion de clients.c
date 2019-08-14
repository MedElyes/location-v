struct clients
{
	int num;
	char nom[50];
	char prenom[50];
	char cin[50];
	dates permis;	
};

/*__________fonction de recherche des clients_____________________*/
int rech_c (int num_rech)
{
	FILE *C;
	F=fopen("clients.txt","r");
	do
	{
		fscanf(C,"%d ;%c ;%c ;%s ;%d%d%d \n",&client.num,&client.nom,&client.prenom,&client.cin,&client.permis.jj,&client.permis.mm,&client.permis.aa);
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
/*_______________*procedure pour ajouter un client*_______________*/
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
	 // verification sur l'existance du numero ajouté------------
	{
		printf("\n ce numero existe deja !!");
		printf("\n entrer le numero du client :\n");
		scanf("%d",&num);
	}
	   client.num=num;
	   
		printf("\n entrer le nom du client :\n");
		gets(client.nom);
		fflush(stdin);
		
		printf("\n entrer le prenom du client :\n");
		gets(client.prenom);
		fflush(stdin);
		
		printf("\n entrer le numero de la carte d'identite (CIN) :\n");
		gets(client.cin);
		fflush(stdin);
		
		printf("\n entrer la date du permis :");
		gets(client.permis.jj,client.permis.mm,client.permis.aa);
		fflush(stdin);
		
		fprintf(C,"%d ;%s ;%s ;%s ;%d%d%d \n",client.num,client.nom,client.prenom,client.cin,&client.permis.jj,&client.permis.mm,&client.permis.aa);
		fflush(stdin);
		
		fclose(C);
}

/*__________________*procedure de recherche et d'affichage des clients*____________________*/

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
	fscanf(F,"%d ;%s ;%s ;%s \n",&client.num,&client.nom,&client.prenom,&client.cin,&client.permis.jj,&client.permis.mm,&client.permis.aa);
	if (num_r==client.num)
	{
	printf("-----------Le Client : ----------\n\n");
		printf("numero\t: %d \n",client.num);
		printf("nom et prenom\t: %s %s \n",client.nom,client.prenom);
		printf("CIN\t: %s \n",client.cin);
		printf("date du permis : \t %d/%d/%d",client.permis.jj,client.permis.mm,client.permis.aa);
		
	}
}while(!feof(C));
fclose(C);
}

/*______________*procedure de la suppression du cliens*_______________*/
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
			FILE *FICH, *C;
			C=fopen("clients.txt","r");
			FICH=fopen("temp_client.txt","a");
		   do
		     { 
		     fscanf(C,"%d ;%s ;%s ;%s ;%d%d%d \n",&client.num,&client.nom,&client.prenom,&client.cin,&client.permis.jj,&client.permis.mm,&client.permis.aa);
		     if (num_rech != client.num)
		     {
		     	fprintf(FICH,"%d ;%s ;%s ;%s ;%d%d%d \n",client.num,client.nom,client.prenom,client.cin,&client.permis.jj,&client.permis.mm,&client.permis.aa);
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


/*_____________*procedure de modification des clients*___________*/

void modifier_client()
{
	system("cls");
		FILE *FICH, *C;
	char rep='n';
	int num_rec;
	printf("entrez le numero de client a modifie:");
	scanf("%d",&num_rec);
	fflush(stdin);
	if(rech_c(num_rec)==1)
	{
		printf("\n voulez vous vraiment modifier ce client O/N ? : \n ===> \t ");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep=='o'|| rep=='O')
		{
		
			C=fopen("clients.txt","r");
			FICH=fopen("temp_client.txt","a");
		   do
		     { 
		     fscanf(C,"%d ;%s ;%s ;%s ;%d%d%d \n",&client.num,&client.nom,&client.prenom,&client.cin,&client.permis.jj,&client.permis.mm,&client.permis.aa);
		     if (num_rec == client.num)
		     {
		     	client.num=num_rec;
		     printf("\n entrer le nouveau nom :\n ");
	    	 gets(client.nom);
	    	 fflush(stdin);
		
		     printf("\n entrer le nouveau prenom du client :\n");
		     gets(client.prenom);
		     fflush(stdin);
		
		     printf("\n entrer le nouveau numero de la carte d'identite (CIN) :\n");
		     scanf("%s",&client.cin);
		     fflush(stdin);
		     
		     printf("\n entrer la nouvelle date du permis :\n");
		     
			 printf("entrer le jour:\n")
		     scanf("%s",&client.permis.jj);
		     fflush(stdin);
		     printf("entrer le mois:\n")
		     scanf("%s",&client.permis.mm);
		     fflush(stdin);
		     printf("entrer l'annee:\n")
		     scanf("%s",&client.permis.aa);
		     fflush(stdin);
		     
			 }
			 fprintf(FICH,"%d ;%s ;%s ;%s ;%d%d%d \n",client.num,client.nom,client.prenom,client.cin,&client.permis.jj,&client.permis.mm,&client.permis.aa);
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

/*_____________*procedure d'affichage des clients*___________*/
void afficher_tt()
{
system("cls");
FILE *C;
C=fopen("clients.txt","r");
printf("la liste des clients est : \n\n");
printf("NUMERO:\t %d\n",client.num);
printf("\nNOM:\t %s",client.nom);
printf("\nPRENOM:\t %s",client.prenom);
printf("CIN:\t %s\n",client.cin);
printf("\nLa Date Du Permis :\t%d/%d/%d:\n",client.permis.jj,client.permis.mm,client.permis.aa);
		     		    
do
{
	fscanf(C,"%d ;%s ;%s ;%s ;%d%d%d \n",&client.num,&client.nom,&client.prenom,&client.cin,&client.permis.jj,&client.permis.mm,&client.permis.aa);
	fflush(stdin);
	printf("%d\t\n",client.num);
	printf("\n%s\t",client.nom);
	printf("\n%s\t",client.prenom);
	printf("\n%s",client.cin);
	printf("\n%d%d%d",client.permis.jj,client.permis.mm,client.permis.aa);
} while (!feof(C));
fclose(C);
}
