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
int indice=0;
int Isuop;
int i;
int result=0;
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
    printf("prenom: ");
    scanf("%99s",list.prenome[indice]);
    printf("Date de naissance: ");
    scanf("%99s",list.Date_nai[indice]);
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
        strcpy(list.Departement[indice],"informatique");
        break;
    case 2:
        strcpy(list.Departement[indice],"physique");
        break;
    case 3:
        strcpy(list.Departement[indice],"Biologie");
        break;
    case 4:
        strcpy(list.Departement[indice],"mathematiques");
        break;
    case 5:
        strcpy(list.Departement[indice],"geologie");
        break;
    case 6:
        strcpy(list.Departement[indice],"chemie");
        break;
    default:
        printf("option unvalid!!\n");
        goto Again;
    }
    printf("Note generale: ");
    scanf("%f",&list.Note_generale[indice]);
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
        }
    }
}
void Afficher(int i){
    for (int i= 0;i<indice;i++){
        printf("================================\n");
        printf("nom: %s\n",list.Nom[i]);
        printf("prenome: %s\n",list.prenome[i]);
        printf("Date de naissance: %s\n",list.Date_nai[i]);
        printf("Departement: %s\n",list.Departement[i]);
        printf("Note generale: %f\n",list.Note_generale[i]);
        printf("================================\n");
    }
}
float moyenne_Departement(int result){
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
    printf("%f",result);
}
float moyenne_generale(){
    int result=0;
    for(int i=0;i<indice;i++){
        printf("%d",i);
        result += list.Note_generale[i];
    }
    result = result/indice;
    printf("%f",result);
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
            default:
                printf("se choix ne pas valider rentrer auter choix.\n");
                break;
            }
            break;
        case 3:
            Afficher(i);
            break;
        case 4:
            moyenne_generale(result);
            moyenne_Departement(result);
            break;
        }
    }

    return 0;
}
