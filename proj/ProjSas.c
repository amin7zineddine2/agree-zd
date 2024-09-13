#include<stdio.h>
#include<string.h>

typedef struct {
    int jours;
    int mois;
    int annee;
}DATE;



typedef struct {
    char nom[20];
    char prenom[20];
    char departement[100];
    float note;
    DATE date ;
    int nombre;
}Student;
Student student[100] = {
    {"chaima", "elomrani", "PC", 19.00, {2004/20/10},1},
    {"Anass", "Boutaib", "SVT", 19.99, {2001/03/06}, 2},
    {"yasser", "aboufaris", "ECO", 19.50, {2005/18/05}, 3},
    {"hamza", "alhdouchi", "SM", 16.2, {2002/9/10}, 4},
    {"achraf", "hamouda", "ECO", 7.7, {2003/6/2}, 5},
    {"ayoub", "ahnaou", "SVT", 18.5, {2001/10/7}, 6},
    {"haitam", "abod", "PC", 9.4, {2002/19/1}, 7},
    {"hatim", "blghiti", "SM", 17.99, {2005/12/2}, 8},
    {"salma", "hasson", "PC", 8.3, {2003/21/9}, 9},
    {"sanaa", "mallali", "ECO", 3.6, {2008/30/8}, 10}};


int i;
int compteur=11;
int total_etudient=10;
void affichage_menu (){
        printf("===============================================\n");
        printf("1-ajouter un eleve\n");
        printf("2-afficher les details des eleves\n");
        printf("3-modifier les details d'un eleve\n");
        printf("4-supprimer\n");
        printf("5-recherche\n");
        printf("6-calcule de moyenne generale\n");
        printf("7-trier\n");
        printf("8-statistique\n");
        printf("===============================================\n");


  }

void ajout_eleve(){

    student[total_etudient].nombre=compteur;
      printf("nom:");
        scanf("%s",student[total_etudient].nom);

        printf("prenom:");
        scanf("%s",student[total_etudient].prenom);

        printf("date de naissance:\n");
        printf("Jour:");
        scanf("%d",&student[total_etudient].date.jours);  
        printf("mois:");
        scanf("%d",&student[total_etudient].date.mois);
        printf("annee:");
        scanf("%d",&student[total_etudient].date.annee);


        printf("departement:\n");
        printf("1-PC\t 2-SVT\t 3-ECO\t 4-SM\n");
        scanf("%s",student[total_etudient].departement);


        printf("note generale:\n");
        scanf("%f",&student[total_etudient].note);



     total_etudient++;
    printf("=====================================================\n");
     printf("eleve ajoute avec succes!\n");
    printf("=====================================================\n");
}

void affichage(){
     for(i=0;i<total_etudient;i++){
        printf("nom: %s \n",student[i].nom);
        printf("prenom: %s \n",student[i].prenom);
        printf("date de naissance: %02d/%02d/%04d \n",student[i].date.jours,student[i].date.mois,student[i].date.annee);
        printf("departement: %s\n",student[i].departement);
        printf("note generale: %f \n",student[i].note); 
        printf("nombre unique: %d\n", student[i].nombre);
        printf("######################################\n\n");      
        }
}

void modification(){
    int n_recherche;
     printf("entrer le numero unique d'eleve:");
        scanf("%d",&n_recherche);

        for(i=0;i<total_etudient;i++){
           if(student[i].nombre==n_recherche ){
                printf("entrer les nouvelles informations:\n");

                printf("entrer le nouveau nom:");
                scanf("%s",student[i].nom);

                  printf("entrer le nouveau prenom:");
                scanf("%s",student[i].prenom);

                printf("choisissez le nouveau departement:\n");
                printf("1-PC\t 2-SVT\t 3-ECO\t 4-SM\n");
                scanf("%s",student[total_etudient].departement);


                printf("date de naissance:\n");
                printf("nouvelle Jour:");
                scanf("%d",&student[total_etudient].date.jours);
                printf("nouveau mois:");
                scanf("%d",&student[total_etudient].date.mois);
                printf("nouvelle annee:");
                scanf("%d",&student[total_etudient].date.annee);


                printf("entrer la nouvelle note generale:");
                scanf("%f",&student[i].note);

               printf("======================================================================\n");
               printf("information modifier avec succee!\n");
               printf("======================================================================\n\n");
           }
        }
}

void suppression(){
    int n_recherche;
        printf("entrer le numero unique d'eleve a supprimer:");
        scanf("%d",&n_recherche);

        for(i=0;i<total_etudient;i++){
        if(student[i].nombre == n_recherche){
        for(int j=i;j<total_etudient-1;j++){
        student[j] = student[j+1];
        }
        total_etudient--;
        printf("======================================================================\n");
        printf("eleve supprimer avec succes!!\n");
        printf("======================================================================\n");
       }
   }
}

 void recherche_nom(){
        char a_recherche[100];
        printf("entrer le nom d'eleve :");
        scanf("%s",&a_recherche);
        for(i=0;i<total_etudient;i++){
        if(strcmp(student[i].nom , a_recherche) == 0){
            printf("nombre: %d\n",student[i].nombre);
            printf("nom: %s\n",student[i].nom);
            printf("prenom: %s\n",student[i].prenom);
            printf("date de naissance: %02d/%02d/%04d \n",student[i].date.jours,student[i].date.mois,student[i].date.annee);
            printf("departement %s\n",student[i].departement);
            printf("note generale: %f\n",student[i].note);
        }
       }
}

void recherche_departement(){
    char departement[100];
    printf("Entrer un choix :");
    scanf("%s",departement);
    for(i=0;i<total_etudient;i++){
        if(strcmp(student[i].departement,departement)==0){
            printf("nom: %s \n",student[i].nom);
            printf("prenom: %s \n",student[i].prenom);
            printf("date de naissance: %02d/%02d/%04d \n",student[i].date.jours,student[i].date.mois,student[i].date.annee);
            printf("departement: %s\n",student[i].departement);
            printf("nombre unique: %d\n", student[i].nombre);
            printf("note generale: %f \n",student[i].note);         
        
        }
    }
}

void recherche(){
    int choix;
  printf("voullez-vous rechercher avec :\n");
  printf("1-nom\n");
  printf("2-departement\n");
  printf("entrer votre choix:");
  scanf("%d",&choix);
  
  if(choix==1){
    recherche_nom();
    return;
  
  }else if (choix==2){
     recherche_departement();
     return;
  }
}

void moyenne_generale(){
        int choix ;
        float somme1=0,somme2=0,somme3=0,somme4=0;
        float moyenne1,moyenne2,moyenne3,moyenne4;
        int compteur_pc=0;
        int compteur_svt=0;
        int compteur_sm=0;
        int compteur_eco=0;
        
        printf("1-moyenne generale de chaque departement\n");
        printf("2-moyenne generale universitaire\n ");
        printf("entrer votre choix:\n");
        scanf("%d",&choix);

     if(choix==1){
        for(i=0;i<total_etudient;i++){
           if(strcmp(student[i].departement,"PC")==0){
            somme1+=total_etudient;
            compteur_pc++;
            }  

         else if(strcmp(student[i].departement,"SVT")==0){
            somme2+=total_etudient;
            compteur_svt++;
            }

         else if(strcmp(student[i].departement,"ECO")==0){
            somme3+=total_etudient;
            compteur_eco++;
            }

         else if(strcmp(student[i].departement,"SM")==0){
            somme4+=total_etudient;
            compteur_sm++;
            }
            }
            moyenne1 = somme1 / compteur_pc;
            moyenne2 = somme2 / compteur_svt;
            moyenne3 = somme3 / compteur_eco;
            moyenne4 = somme4 / compteur_sm;
            printf("la moyenne de departement PC est: %f \n",moyenne1);
            printf("la moyenne de departement SVT est: %f \n",moyenne2);
            printf("la moyenne de departement ECO est: %f \n",moyenne3);
            printf("la moyenne de departement SM est: %f \n",moyenne4);

         }else if(choix==2){
             for(i=0;i<total_etudient;i++){
                somme1+=student[i].note ;
                }
                moyenne1=somme1/total_etudient;
                printf("la myenne generale d'universite est:%f",moyenne1);

            }

     


}


void menu_choix ()
{
 int choix;
   do
   { 
        affichage_menu();

        int choix ;
        printf("entrer votre choix:");
        scanf("%d",&choix);
    
        switch(choix)
        {
            case 1:
                ajout_eleve();
                
            break;

            case 2:
                affichage();
                
            break;

            case 3:
                modification();
                
            break;
            case 4 :
                suppression();
            break;
            case 5:
                recherche();
            break;
            case 6:
                moyenne_generale();
            break;
        }

   }while(choix != 0);
}
int main (){
    menu_choix ();

}