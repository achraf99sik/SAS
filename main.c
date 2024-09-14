#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_etud 255
#define max_len 255

struct list_etudiants{
    int Numero_unique[max_etud];
    char Nom[max_etud][max_len];
    char prenome[max_etud][max_len];
    char Date_nai[max_etud][max_len];
    char Departement[max_etud][max_len];
    float Note_generale[max_etud];
    int moyenne[max_etud];
};
int info=0,inforu=0;
int IVsuop;
int phy=0,phyru=0;
int bio=0,bioru=0;
int math=0,mathru=0;
int co = 0;
int geo=0,georu=0;
int chem=0,chemru=0;
char temp_nom[max_etud][max_len];
char temp_pren[max_etud][max_len];
char temp_date[max_etud][max_len];
char temp_depa[max_etud][max_len];
int temp_numun;
float temp;
int indice=0;
int Isuop;
int IIIsuop;
int i;
int seuil =14;
float result;
int num_uni;
struct list_etudiants list;
int menu(int choix){
    printf("==============================Bienvenu==============================\n");
    printf("*                                                                  *\n");
    printf("* choisissez une option de list suivent:                           *\n");
    printf("*                                                                  *\n");
    printf("* 1) Ajouter un etudiant.                                          *\n");
    printf("* 2) Modifier ou supprimer un etudiant.                            *\n");
    printf("* 3) Afficher les details d'un etudiant.                           *\n");
    printf("* 4) Calculer la moyenne generale.                                 *\n");
    printf("* 5) Statistiques.                                                 *\n");
    printf("* 6) Rechercher un etudiant.                                       *\n");
    printf("* 7) Trier un etudiant par.                                        *\n");
    printf("* 8) quitrer.                                                      *\n");
    printf("*                                                                  *\n");
    printf("====================================================================\n");
    printf("choisissez un option (1-8): ");
    scanf("%d",&choix);
    printf("====================================================================\n");
    return choix;
}
int ajout(int indice){
    printf("Ajouter un etudiant:\n");
    printf("Nom: ");
    scanf("%99s",list.Nom[indice]);
    printf("---------------------------------------------------------\n");
    printf("prenom: ");
    scanf("%99s",list.prenome[indice]);
    printf("---------------------------------------------------------\n");
    printf("Date de naissance: ");
    scanf("%99s",list.Date_nai[indice]);
    printf("---------------------------------------------------------\n");
    printf("================Departement================\n");
    printf("*                                         *\n");
    printf("* choisissez une option de list suivent:  *\n");
    printf("*                                         *\n");
    printf("* 1) informatique.                        *\n");
    printf("* 2) physique.                            *\n");
    printf("* 3) Biologie.                            *\n");
    printf("* 4) mathematiques.                       *\n");
    printf("* 5) geologie.                            *\n");
    printf("* 6) chemie.                              *\n");
    printf("*                                         *\n");
    printf("===========================================\n");
    Again:
    printf("choisesser un departement (1-6): ");
    scanf("%d",&Isuop);
    printf("---------------------------------------------------------\n");
    switch(Isuop){
    case 1:
        strcpy(list.Departement[indice],"informatique");
        info++;
        break;
    case 2:
        strcpy(list.Departement[indice],"physique");
        phy++;
        break;
    case 3:
        strcpy(list.Departement[indice],"Biologie");
        bio++;
        break;
    case 4:
        strcpy(list.Departement[indice],"mathematiques");
        math++;
        break;
    case 5:
        strcpy(list.Departement[indice],"geologie");
        geo++;
        break;
    case 6:
        strcpy(list.Departement[indice],"chemie");
        chem++;
        break;
    default:
        printf("option unvalid!!\n");
        goto Again;
    }
    printf("Note generale: ");
    scanf("%f",&list.Note_generale[indice]);
    printf("---------------------------------------------------------\n");
    list.Numero_unique[indice]=indice+1;
    indice++;
    return indice;
}
void Modifier(int num_uni){
    printf("entre le numero unique de l'etudiant que tu pe modifier: ");
    scanf("%d",&num_uni);
    printf("Nouveau Nom: ");
    scanf("%99s",list.Nom[num_uni-1]);
    printf("Nouveau prenom: ");
    scanf("%99s",list.prenome[num_uni-1]);
    printf("Nouveau Date de naissance: ");
    scanf("%99s",list.Date_nai[num_uni-1]);
    printf("================Departement================\n");
    printf("*                                         *\n");
    printf("* choisissez une option de list suivent:  *\n");
    printf("*                                         *\n");
    printf("* 1) informatique.                        *\n");
    printf("* 2) physique.                            *\n");
    printf("* 3) Biologie.                            *\n");
    printf("* 4) mathematiques.                       *\n");
    printf("* 5) geologie.                            *\n");
    printf("* 6) chemie.                              *\n");
    printf("*                                         *\n");
    printf("===========================================\n");
    Again:
    printf("choisesser un nouveau departement (1-6): ");
    scanf("%d",&Isuop);
    switch(Isuop){
    case 1:
        strcpy(list.Departement[num_uni-1],"informatique");
        break;
    case 2:
        strcpy(list.Departement[num_uni-1],"physique");
        break;
    case 3:
        strcpy(list.Departement[num_uni-1],"Biologie");
        break;
    case 4:
        strcpy(list.Departement[num_uni-1],"mathematiques");
        break;
    case 5:
        strcpy(list.Departement[num_uni-1],"geologie");
        break;
    case 6:
        strcpy(list.Departement[num_uni-1],"chemie");
        break;
    default:
        printf("option unvalid!!\n");
        goto Again;
    }
    printf("Nouveau Note generale: ");
    scanf("%f",&list.Note_generale[num_uni-1]);
}
void supprimer(int num_uni){
    printf("entre le numero unique de l'etudiant que tu pe supprimer: ");
    scanf("%d",&num_uni);
    int count = num_uni-1;
    if (list.Nom[count]=='\0'){
        printf("le numero unique que vous entrez est ne pas exist dans la list d'etudiants");
        abort();
    }
    else{
        for (int count;count<indice;count++){
            strcpy(list.Nom[count],list.Nom[count+1]);
            strcpy(list.prenome[count],list.prenome[count+1]);
            strcpy(list.Date_nai[count],list.Date_nai[count+1]);
            strcpy(list.Departement[count],list.Departement[count+1]);
            list.Note_generale[count]=list.Note_generale[count+1];
            list.Numero_unique[count]=list.Numero_unique[count+1];
        }
    }
    indice--;
}
void Afficher(int i){
    for (int i= 0;i<indice;i++){
        printf("================================\n");
        printf("num unique: %d\n",list.Numero_unique[i]);
        printf("nom: %s\n",list.Nom[i]);
        printf("prenome: %s\n",list.prenome[i]);
        printf("Date de naissance: %s\n",list.Date_nai[i]);
        printf("Departement: %s\n",list.Departement[i]);
        printf("Note generale: %.2f\n",list.Note_generale[i]);
        printf("================================\n");
    }
}
float moyenne_Departement(float result){
    int c=0;
    printf("================Departement================\n");
    printf("*                                         *\n");
    printf("* choisissez une option de list suivent:  *\n");
    printf("*                                         *\n");
    printf("* 1) informatique.                        *\n");
    printf("* 2) physique.                            *\n");
    printf("* 3) Biologie.                            *\n");
    printf("* 4) mathematiques.                       *\n");
    printf("* 5) geologie.                            *\n");
    printf("* 6) chemie.                              *\n");
    printf("*                                         *\n");
    printf("===========================================\n");
    Again:
    printf("choisesser un departement pour afficher la moyenne generale(1-6): ");
    scanf("%d",&Isuop);
    for(int i=0;i<indice;i++ ){
        switch(Isuop){
        case 1:
            if(strcmp(list.Departement[i],"informatique")==0){
                list.moyenne[c]=list.Note_generale[i];
                c++;
            }
            break;
        case 2:
            if(strcmp(list.Departement[i],"physique")==0){
                list.moyenne[c]=list.Note_generale[i];
                c++;
            }
            break;
        case 3:
            if(strcmp(list.Departement[i],"Biologie")==0){
                list.moyenne[c]=list.Note_generale[i];
                c++;
            }
            break;
        case 4:
            if(strcmp(list.Departement[i],"mathematiques")==0){
                list.moyenne[c]=list.Note_generale[i];
                c++;
            }
            break;
        case 5:
            if(strcmp(list.Departement[i],"geologie")==0){
                list.moyenne[c]=list.Note_generale[i];
                c++;
            }
            break;
        case 6:
            if(strcmp(list.Departement[i],"chemie")==0){
                list.moyenne[c]=list.Note_generale[i];
                c++;
            }
            break;
        default:
            printf("option unvalid!!\n");
            goto Again;
        }
    }
    for(int i=0;i<c;i++){
        result += list.moyenne[i];
    }
    result = result/c;
    printf("la moyenne generale de set departement est: %.2f\n",result);
}
float moyenne_generale(float result){
    result=0;
    for(int i=0;i<indice;i++){
        result += list.Note_generale[i];
    }
    result = result/indice;
    printf("la moyenne generale de l'universite: %.2f\n",result);
}
void statestique(){
    printf("=====================================Statistiques=====================================\n");
    printf("*                                                                                    *\n");
    printf("* choisissez une option de list suivent:                                             *\n");
    printf("*                                                                                    *\n");
    printf("* 1) Afficher le nombre total d'etudiants inscrits.                                  *\n");
    printf("* 2) Afficher le nombre d'etudiants dans chaque departement.                         *\n");
    printf("* 3) Afficher les etudiants ayant une moyenne generale superieure à un certain seuil.*\n");
    printf("* 4) Afficher les 3 etudiants ayant les meilleures notes.                            *\n");
    printf("* 5) Afficher le nombre d'etudiants ayant reussi dans chaque departement.            *\n");
    printf("======================================================================================\n");
    printf("choisesser un option pour afficher le Statistiques(1-5): ");
    scanf("%d",&IIIsuop);
    switch (IIIsuop){
    case 1:
        printf("le nombre total d'etudiants inscrits est: %d\n",indice);
        break;
    case 2:
        printf("le nombre d'etudiants dans le departement informatique est: %d\n",info);
        printf("le nombre d'etudiants dans le departement physique est: %d\n",phy);
        printf("le nombre d'etudiants dans le departement biologie est: %d\n",bio);
        printf("le nombre d'etudiants dans le departement mathematiques est: %d\n",math);
        printf("le nombre d'etudiants dans le departement geologie est: %d\n",geo);
        printf("le nombre d'etudiants dans le departement chemie est: %d\n",chem);
        break;
    case 3:
        for (i=0;i<indice;i++){
            if (list.Note_generale[i]>seuil){
                printf("Numero unique: %d\n",i+1);
                printf("nom: %s\n",list.Nom[i]);
                printf("prenom: %s",list.prenome[i]);
                printf("Date de naissance (jj/mm/aaaa): %s\n",list.Date_nai[i]);
                printf("Departement: %s\n",list.Departement[i]);
                printf("Note generale: %.2f\n",list.Note_generale[i]);
                printf("le Numero unique: %d\n",list.Numero_unique[i]);
            }
        }
        break;
    case 4:
        for (i=0;i<3;i++){
            for(int j = i+1;j<indice;j++){
                if (list.Note_generale[i]<list.Note_generale[j]){
                    temp=list.Note_generale[i];
                    list.Note_generale[i]=list.Note_generale[j];
                    list.Note_generale[j]=temp;

                    strcpy(temp_nom,list.Nom[i]);
                    strcpy(list.Nom[i],list.Nom[j]);
                    strcpy(list.Nom[j],temp_nom);

                    temp_numun=list.Numero_unique[i];
                    list.Numero_unique[i]=list.Numero_unique[j];
                    list.Numero_unique[j]=temp_numun;

                    strcpy(temp_pren,list.prenome[i]);
                    strcpy(list.prenome[i],list.prenome[j]);
                    strcpy(list.prenome[j],temp_pren);

                    strcpy(temp_date,list.Date_nai[i]);
                    strcpy(list.Date_nai[i],list.Date_nai[j]);
                    strcpy(list.Date_nai[j],temp_date);

                    strcpy(temp_depa,list.Departement[i]);
                    strcpy(list.Departement[i],list.Departement[j]);
                    strcpy(list.Departement[j],temp_depa);
                }
            }

        }
        for(i=0;i<3;i++){
            printf("================================\n");
            printf("nom: %s\n",list.Nom[i]);
            printf("prenome: %s\n",list.prenome[i]);
            printf("Date de naissance  (jj/mm/aaaa): %s\n",list.Date_nai[i]);
            printf("Departement: %s\n",list.Departement[i]);
            printf("Note generale: %.2f\n",list.Note_generale[i]);
            printf("Note generale: %d\n",list.Numero_unique[i]);
            printf("================================\n");
        }
        break;
    case 5:
        for(i=0;i<info;i++){
            if(strcmp(list.Departement[i],"informatique")==0){
                    if (list.Note_generale[i]<=10){
                        inforu++;
                    }
            }
        }
        printf("Afficher le nombre d'etudiants ayant reussi dans departement informatique est: %d\n",inforu);
        printf("%s\n%s\n",list.Departement[i],"informatique");
        printf("%d\n",list.Note_generale[i]);
        for(i=0;i<phy;i++){
            if(strcmp(list.Departement[i],"physique")==0){
                    if (list.Note_generale[i]<=10){
                        phyru++;
                    }
            }
        }
        printf("Afficher le nombre d'etudiants ayant reussi dans departement physique est: %d\n",phyru);
        for(i=0;i<bio;i++){
            if(strcmp(list.Departement[i],"Biologie")==0){
                    if (list.Note_generale[i]<=10){
                        bioru++;
                    }
            }
        }
        printf("Afficher le nombre d'etudiants ayant reussi dans departement Biologie est: %d\n",bio);
        for(i=0;i<math;i++){
            if(strcmp(list.Departement[i],"mathematiques")==0){
                    if (list.Note_generale[i]<=10){
                        mathru++;
                    }
            }
        }
        printf("Afficher le nombre d'etudiants ayant reussi dans departement mathematiques est: %d\n",mathru);
        for(i=0;i<geo;i++){
            if(strcmp(list.Departement[i],"geologie")==0){
                    if (list.Note_generale[i]<=10){
                        georu++;
                    }
            }
        }
        printf("Afficher le nombre d'etudiants ayant reussi dans departement geologie est: %d\n",georu);
        for(i=0;i<chem;i++){
            if(strcmp(list.Departement[i],"chemie")==0){
                    if (list.Note_generale[i]<=10){
                        chemru++;
                    }
            }
        }
        printf("Afficher le nombre d'etudiants ayant reussi dans departement chemie est: %d\n",chemru);
        break;


    }
}
void rechercher(){
    int optin;
    char a[max_etud][max_len]={"informatique","physique","Biologie","mathematiques","geologie","chemie"};
    char sear[50];
    printf("===================================================================================\n");
    printf("* 1) Rechercher un etudiant par son nom.                                          *\n");
    printf("* 2) Afficher la liste des etudiants inscrits dans un departement specifique.     *\n");
    printf("* 3) annuler.                                                                     *\n");
    printf("===================================================================================\n");
    printf("choisissez une option (1-3): ");
    scanf("%d",&optin);
    switch(optin){
    case 1:
        printf("entrez le nom que vous recherchez: ");
        scanf("%49s",&sear);
        for(i=0;i<indice;i++){
            if (strcmp(list.Nom[i],sear)==0){
                printf("================================\n");
                printf("nom: %s\n",list.Nom[i]);
                printf("prenome: %s\n",list.prenome[i]);
                printf("Date de naissance  (jj/mm/aaaa): %s\n",list.Date_nai[i]);
                printf("Departement: %s\n",list.Departement[i]);
                printf("Note generale: %.2f\n",list.Note_generale[i]);
                printf("le Numero unique: %d\n",list.Numero_unique[i]);
                printf("================================\n");
            }
        }
        break;
    case 2:
        printf("================Departement================\n");
        printf("*                                         *\n");
        printf("* choisissez une option de list suivent:  *\n");
        printf("*                                         *\n");
        printf("* 1) informatique.                        *\n");
        printf("* 2) physique.                            *\n");
        printf("* 3) Biologie.                            *\n");
        printf("* 4) mathematiques.                       *\n");
        printf("* 5) geologie.                            *\n");
        printf("* 6) chemie.                              *\n");
        printf("*                                         *\n");
        printf("===========================================\n");
        Again:
        printf("choisesser un departement (1-6): ");
        scanf("%d",&Isuop);
        switch(Isuop){
        case 1:
            for(i=0;i<indice;i++){
                if (strcmp(list.Departement[i],a[Isuop-1])==0){
                    printf("================================\n");
                    printf("nom: %s\n",list.Nom[i]);
                    printf("prenome: %s\n",list.prenome[i]);
                    printf("Date de naissance  (jj/mm/aaaa): %s\n",list.Date_nai[i]);
                    printf("Departement: %s\n",list.Departement[i]);
                    printf("Note generale: %.2f\n",list.Note_generale[i]);
                    printf("le Numero unique: %d\n",list.Numero_unique[i]);
                    printf("================================\n");
                    }
            }
            break;
        case 2:
            for(i=0;i<indice;i++){
                if (strcmp(list.Departement[i],a[Isuop-1])==0){
                    printf("================================\n");
                    printf("nom: %s\n",list.Nom[i]);
                    printf("prenome: %s\n",list.prenome[i]);
                    printf("Date de naissance  (jj/mm/aaaa): %s\n",list.Date_nai[i]);
                    printf("Departement: %s\n",list.Departement[i]);
                    printf("Note generale: %.2f\n",list.Note_generale[i]);
                    printf("le Numero unique: %d\n",list.Numero_unique[i]);
                    printf("================================\n");
                    }
            }
            break;
        case 3:
            for(i=0;i<indice;i++){
                if (strcmp(list.Departement[i],a[Isuop-1])==0){
                    printf("================================\n");
                    printf("nom: %s\n",list.Nom[i]);
                    printf("prenome: %s\n",list.prenome[i]);
                    printf("Date de naissance  (jj/mm/aaaa): %s\n",list.Date_nai[i]);
                    printf("Departement: %s\n",list.Departement[i]);
                    printf("Note generale: %.2f\n",list.Note_generale[i]);
                    printf("le Numero unique: %d\n",list.Numero_unique[i]);
                    printf("================================\n");
                    }
            }
            break;
        case 4:
            for(i=0;i<indice;i++){
                if (strcmp(list.Departement[i],a[Isuop-1])==0){
                    printf("================================\n");
                    printf("nom: %s\n",list.Nom[i]);
                    printf("prenome: %s\n",list.prenome[i]);
                    printf("Date de naissance  (jj/mm/aaaa): %s\n",list.Date_nai[i]);
                    printf("Departement: %s\n",list.Departement[i]);
                    printf("Note generale: %.2f\n",list.Note_generale[i]);
                    printf("le Numero unique: %d\n",list.Numero_unique[i]);
                    printf("================================\n");
                    }
            }
            break;
        case 5:
            for(i=0;i<indice;i++){
                if (strcmp(list.Departement[i],a[Isuop-1])==0){
                    printf("================================\n");
                    printf("nom: %s\n",list.Nom[i]);
                    printf("prenome: %s\n",list.prenome[i]);
                    printf("Date de naissance  (jj/mm/aaaa): %s\n",list.Date_nai[i]);
                    printf("Departement: %s\n",list.Departement[i]);
                    printf("Note generale: %.2f\n",list.Note_generale[i]);
                    printf("le Numero unique: %d\n",list.Numero_unique[i]);
                    printf("================================\n");
                    }
            }
            break;
        case 6:
            for(i=0;i<indice;i++){
                if (strcmp(list.Departement[i],a[Isuop-1])==0){
                    printf("================================\n");
                    printf("nom: %s\n",list.Nom[i]);
                    printf("prenome: %s\n",list.prenome[i]);
                    printf("Date de naissance  (jj/mm/aaaa): %s\n",list.Date_nai[i]);
                    printf("Departement: %s\n",list.Departement[i]);
                    printf("Note generale: %.2f\n",list.Note_generale[i]);
                    printf("le Numero unique: %d\n",list.Numero_unique[i]);
                    printf("================================\n");
                    }
            }
            break;
        default:
            printf("option unvalid!!\n");
            goto Again;
        }
        break;
    }
}
char char_swap(x,y,z){
    strcpy(z,x);
    strcpy(x,y);
    strcpy(y,z);
}
void trier(){
    int optin;
    printf("===================================================================================\n");
    printf("* 1) trier de(A-Z).                                                               *\n");
    printf("* 2) trier de(Z-A).                                                               *\n");
    printf("* 3) Tri des etudiants par moyenne generale, du plus eleve au plus faible.        *\n");
    printf("* 4) Tri des etudiants par moyenne generale, du plus faible au plus eleve.        *\n");
    printf("* 5) Tri des etudiants selon leur statut de reussite.                             *\n");
    printf("* 6) quitter                                                                      *\n");
    printf("===================================================================================\n");
    printf("choisissez une option (1-3): ");
    scanf("%d",&optin);
    switch(optin){
        case 1:
            for (i=0;i<indice;i++){
                int j=i+1;
                for(j ;j<indice;j++){
                    if (strcmp(list.Nom[j],list.Nom[i])<0){
                        temp=list.Note_generale[i];
                        list.Note_generale[i]=list.Note_generale[j];
                        list.Note_generale[j]=temp;

                        char_swap(list.Nom[i],list.Nom[j],temp_nom[0]);

                        temp_numun=list.Numero_unique[i];
                        list.Numero_unique[i]=list.Numero_unique[j];
                        list.Numero_unique[j]=temp_numun;

                        char_swap(list.prenome[i],list.prenome[j],temp_pren[0]);

                        char_swap(list.Date_nai[i],list.Date_nai[j],temp_date[0]);

                        char_swap(list.Departement[i],list.Departement[j],temp_depa[0]);
                    }
                }

            }
            for(i=0;i<indice;i++){
                printf("================================\n");
                printf("nom: %s\n",list.Nom[i]);
                printf("prenome: %s\n",list.prenome[i]);
                printf("Date de naissance  (jj/mm/aaaa): %s\n",list.Date_nai[i]);
                printf("Departement: %s\n",list.Departement[i]);
                printf("Note generale: %.2f\n",list.Note_generale[i]);
                printf("le Numero unique: %d\n",list.Numero_unique[i]);
                printf("================================\n");
            }
            break;
        case 2:
            for (i=0;i<indice;i++){
                int j=i+1;
                for(j ;j<indice;j++){
                    if (strcmp(list.Nom[j],list.Nom[i])>0){
                        temp=list.Note_generale[i];
                        list.Note_generale[i]=list.Note_generale[j];
                        list.Note_generale[j]=temp;

                        char_swap(list.Nom[i],list.Nom[j],temp_nom[0]);

                        temp_numun=list.Numero_unique[i];
                        list.Numero_unique[i]=list.Numero_unique[j];
                        list.Numero_unique[j]=temp_numun;

                        char_swap(list.prenome[i],list.prenome[j],temp_pren[0]);

                        char_swap(list.Date_nai[i],list.Date_nai[j],temp_date[0]);

                        char_swap(list.Departement[i],list.Departement[j],temp_depa[0]);
                    }
                }

            }
            for(i=0;i<indice;i++){
                printf("================================\n");
                printf("nom: %s\n",list.Nom[i]);
                printf("prenome: %s\n",list.prenome[i]);
                printf("Date de naissance  (jj/mm/aaaa): %s\n",list.Date_nai[i]);
                printf("Departement: %s\n",list.Departement[i]);
                printf("Note generale: %.2f\n",list.Note_generale[i]);
                printf("le Numero unique: %d\n",list.Numero_unique[i]);
                printf("================================\n");
            }
            break;
        case 3:
            for (i=0;i<indice;i++){
                for(int j = i+1;j<indice;j++){
                    if (list.Note_generale[i]<list.Note_generale[j]){
                        temp=list.Note_generale[i];
                        list.Note_generale[i]=list.Note_generale[j];
                        list.Note_generale[j]=temp;

                        strcpy(temp_nom,list.Nom[i]);
                        strcpy(list.Nom[i],list.Nom[j]);
                        strcpy(list.Nom[j],temp_nom);

                        temp_numun=list.Numero_unique[i];
                        list.Numero_unique[i]=list.Numero_unique[j];
                        list.Numero_unique[j]=temp_numun;

                        strcpy(temp_pren,list.prenome[i]);
                        strcpy(list.prenome[i],list.prenome[j]);
                        strcpy(list.prenome[j],temp_pren);

                        strcpy(temp_date,list.Date_nai[i]);
                        strcpy(list.Date_nai[i],list.Date_nai[j]);
                        strcpy(list.Date_nai[j],temp_date);

                        strcpy(temp_depa,list.Departement[i]);
                        strcpy(list.Departement[i],list.Departement[j]);
                        strcpy(list.Departement[j],temp_depa);
                    }
                }

            }
            for(i=0;i<indice;i++){
                printf("================================\n");
                printf("nom: %s\n",list.Nom[i]);
                printf("prenome: %s\n",list.prenome[i]);
                printf("Date de naissance  (jj/mm/aaaa): %s\n",list.Date_nai[i]);
                printf("Departement: %s\n",list.Departement[i]);
                printf("Note generale: %.2f\n",list.Note_generale[i]);
                printf("Numero unique: %d\n",list.Numero_unique[i]);
                printf("================================\n");
            }
            break;
        case 4:
            for (i=0;i<indice;i++){
                for(int j = i+1;j<indice;j++){
                    if (list.Note_generale[i]>list.Note_generale[j]){
                        temp=list.Note_generale[i];
                        list.Note_generale[i]=list.Note_generale[j];
                        list.Note_generale[j]=temp;

                        strcpy(temp_nom,list.Nom[i]);
                        strcpy(list.Nom[i],list.Nom[j]);
                        strcpy(list.Nom[j],temp_nom);

                        temp_numun=list.Numero_unique[i];
                        list.Numero_unique[i]=list.Numero_unique[j];
                        list.Numero_unique[j]=temp_numun;

                        strcpy(temp_pren,list.prenome[i]);
                        strcpy(list.prenome[i],list.prenome[j]);
                        strcpy(list.prenome[j],temp_pren);

                        strcpy(temp_date,list.Date_nai[i]);
                        strcpy(list.Date_nai[i],list.Date_nai[j]);
                        strcpy(list.Date_nai[j],temp_date);

                        strcpy(temp_depa,list.Departement[i]);
                        strcpy(list.Departement[i],list.Departement[j]);
                        strcpy(list.Departement[j],temp_depa);
                    }
                }

            }
            for(i=0;i<indice;i++){
                printf("================================\n");
                printf("nom: %s\n",list.Nom[i]);
                printf("prenome: %s\n",list.prenome[i]);
                printf("Date de naissance  (jj/mm/aaaa): %s\n",list.Date_nai[i]);
                printf("Departement: %s\n",list.Departement[i]);
                printf("Note generale: %.2f\n",list.Note_generale[i]);
                printf("Numero unique: %d\n",list.Numero_unique[i]);
                printf("================================\n");
            }
            break;
        case 5:
            for (i=0;i<indice;i++){
                for(int j = i+1;j<indice;j++){
                    if (list.Note_generale[i]<list.Note_generale[j]){
                        temp=list.Note_generale[i];
                        list.Note_generale[i]=list.Note_generale[j];
                        list.Note_generale[j]=temp;

                        strcpy(temp_nom,list.Nom[i]);
                        strcpy(list.Nom[i],list.Nom[j]);
                        strcpy(list.Nom[j],temp_nom);

                        temp_numun=list.Numero_unique[i];
                        list.Numero_unique[i]=list.Numero_unique[j];
                        list.Numero_unique[j]=temp_numun;

                        strcpy(temp_pren,list.prenome[i]);
                        strcpy(list.prenome[i],list.prenome[j]);
                        strcpy(list.prenome[j],temp_pren);

                        strcpy(temp_date,list.Date_nai[i]);
                        strcpy(list.Date_nai[i],list.Date_nai[j]);
                        strcpy(list.Date_nai[j],temp_date);

                        strcpy(temp_depa,list.Departement[i]);
                        strcpy(list.Departement[i],list.Departement[j]);
                        strcpy(list.Departement[j],temp_depa);
                    }
                }

            }
            for(i=0;i<indice;i++){
                if (list.Note_generale[i]>=10){
                    printf("================================\n");
                    printf("nom: %s\n",list.Nom[i]);
                    printf("prenome: %s\n",list.prenome[i]);
                    printf("Date de naissance  (jj/mm/aaaa): %s\n",list.Date_nai[i]);
                    printf("Departement: %s\n",list.Departement[i]);
                    printf("Note generale: %.2f\n",list.Note_generale[i]);
                    printf("Numero unique: %d\n",list.Numero_unique[i]);
                    printf("================================\n");
                }
            }
            break;
        case 6:
            break;
    }
}
int main()
{
    int IIsuop;
    int choix;
    while(choix!=8){
        int choix = menu(choix);
        switch(choix){
        case 1:
            indice = ajout(indice);
            printf("%d",indice);
            break;
        case 2:
            printf("====================================================================\n");
            printf("* 1) Modifier un etudiant.                                         *\n");
            printf("* 2) supprimer un etudiant.                                        *\n");
            printf("* 3) annuler.                                                      *\n");
            printf("====================================================================\n");
            printf("choisissez une option (1-3): ");
            scanf("%d",&IIsuop);
            switch(IIsuop){
            case 1:
                Modifier(num_uni);
                break;
            case 2:
                supprimer(num_uni);
                break;
            case 3:
                break;
            }
            break;
        case 3:
            Afficher(i);
            break;
        case 4:
            printf("====================================================================\n");
            printf("* 1) moyenne generale de unviversity.                              *\n");
            printf("* 2) moyenne d'un Departement.                                     *\n");
            printf("* 3) annuler.                                                      *\n");
            printf("====================================================================\n");
            printf("choisissez une option (1-3): ");
            scanf("%d",&IIsuop);
            switch(IIsuop){
                case 1:
                    moyenne_generale(result);
                    break;
                case 2:
                    moyenne_Departement(result);
                    break;
                case 3:
                    break;

            }
            break;
        case 5:
            statestique();
            break;
        case 6:
            rechercher();
            break;
        case 7:
            trier();
            break;
        case 9:
            exit(0);
        }
    }

    return 0;
}
