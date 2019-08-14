typedef struct
{
	int serie;
	
	int num_v;
}matricul;
struct voiture
{
	int num;
    char nom[50];
	char mark[50];
    int puis;
    matricul ser;
};

struct voiture vot;



/*__________________*fonction de recherche des voitures*_____________________*/
int rech_ch_v (int num_rech)
{
	FILE *V;
	V=fopen("voiture.txt","r");
	do
	{
		fscanf(V,"%d ;%c ;%c ;%d ;%d%d \n",&vot.num,&vot.nom,&vot.mark,&vot.puis,&vot.ser.serie,&vot.ser.num_v);
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
	char z;
	C=fopen("voiture.txt","a");
	printf("\n entrez le numero de la voiture à ajouter : ");
	scanf("%d",&num);
	fflush(stdin);
		
	while (rech_ch(num)==1)
	 // verification sur l'existance du numero ajouté------------
	{
		printf("\n ce numero existe deja !!");
		printf("\n entrez le numero du la voiture à ajouter :");
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
		gets(vot.puis);
        fflush(stdin);
		
	    printf("\n saisir le matricul de la voiture :\n");
		scanf("%d,%d",&ovl.ser.serie,&vol.ser.num_v);
        fflush(stdin);
		
		fprintf(V,"%d ;%c ;%c ;%d ;%d%d \n",vot.num,vot.nom,vot.mark,vot.puis,vot.ser.serie,vot.ser.num_v);
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
FILE *v;
C=fopen("voiture.txt","r");
do
{
	fprintf(V,"%d ;%c ;%c ;%d ;%d%d \n",vot.num,vot.nom,vot.mark,vot.puis,vot.ser.serie,vot.ser.num_v);
	if (num_r==vot.num)
	{
	printf("-----------Informations Sur Cette Voiture : ----------\n\n");
		printf("numero\t: %d \n",vot.num);
		printf("nom\t: %s \n",vot.nom);
		printf("marque\t: %s \n",vot.mark);
		printf("puissance (cv)\t: %d \n",vot.puis);
		printf("matricul\t: %d/TN/%d \n",vot.ser.serie,vot.ser.num_v);
		
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
	if(rech_ch(num_rech)==1)
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
		     fscanf(V,"%d ;%c ;%c ;%d ;%d%d \n",&vot.num,&vot.nom,&vot.mark,&vot.pauis,&vot.ser.serie,&vot.ser.num_v);
		     if (num_rech != client.num)
		     {
		     	fprintf(FICH1,"%d ;%c ;%c ;%d ;%d%d \n",vot.num,vot.nom,vot.mark,vot.puis,&vot.ser.serie&vot.ser.num_v);
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
		printf("\n ce numero ne correspand aucun chambre");
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
		     fscanf(V,"%d ;%c ;%c ;%d ;%d%d \n",&vot.num,&vot.nom,&vot.mark,&vot.puis,&vot.ser.serie,&vot.ser.num_v);
		     if (num_rec == chambre.num)
		     {
		     	vot.num=num_rec;
		     	
		     printf("\n entrer le nouveau nom de la voiture :");
		     gets(vot.onm);
		     fflush(stdin);	
		
		     printf("\n entre la nouvelle marque  de la voiture :");
		     scanf("%c",&vot.mark);
		     fflush(stdin);
		     
		     printf("\n entre la nouvelle puissance (cv)  de la voiture :");
		     scanf("%d",&vot.puis);
		     fflush(stdin);
		     
		     printf("\n entre la nouveau matricul de la voiture :");
		     scanf("%d %d",&vot.ser.serie,&vot.ser.num_v);
		     fflush(stdin);
			 }
			 fprintf(FICH1,"%d ;%c ;%c ;%d ;%d%d \n",vot.num,vot.nom,vot.mark,vot.puis,vot.ser.serie,vot.ser.num_v);
			 }while (!feof(V));
			 
			 fclose(FICH1);
			 fclose(V)
			 remove ("voiture.txt");
			 rename("vol.txt","voiture.txt");
			 printf("la modification a reussi");
		      
			 	
		}	
	}
	else
	{
	
		printf("\n ce numero n'existe pas");
	}
	
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
	fscanf(V,"%d ;%c ;%c ;%d ;%d%d \n",&vot.num,&vot.nom,&vot.mark,&vot.puis,&vot.ser.serie,&vot.ser.num_v);
	fflush(stdin);
	printf(">le numero :\t %d\n",vot.num);
	printf(">le nom :\t %c\n",vot.nom);
	printf(">la marque : \t %c\n",vot.mark);
	printf(">le matricul : \t %d/TN/%d\n",vot.ser.serie,vot.ser.num_v);
printf("***************************************************\n");
} while (!feof(V));

fclose(V);
}




