#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//---------------- STRUCTURES ----------------

typedef struct {
    float noteC;
    float noteAlgo;
    float noteArchi;
    float noteElectro;
    float noteMath;
    float noteProba;
    float noteAnglais;
    float noteCulture;
    float noteTec;
} Note;

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    int age;
    Note note;
} Etudiant;


//---------------- VERIFIER ID ----------------

int idExiste(Etudiant *t, int taille, int id)
{
    int i;

    for(i=0;i<taille;i++)
    {
        if(t[i].id==id)
        {
            return 1;
        }
    }

    return 0;
}


//---------------- AJOUTER ETUDIANT ----------------

void ajouter(Etudiant *&t,int &taille)
{
    if(taille==0)
        t=(Etudiant*)malloc(sizeof(Etudiant));
    else
        t=(Etudiant*)realloc(t,sizeof(Etudiant)*(taille+1));


    do{
        printf("veuillez saisir l'id de l'etudiant: ");
        scanf("%d",&t[taille].id);

        if(idExiste(t,taille,t[taille].id))
            printf("Erreur : ID existe deja !\n");

    }while(idExiste(t,taille,t[taille].id));


    printf("veuillez saisir le nom: ");
    scanf("%s",t[taille].nom);

    printf("veuillez saisir le prenom: ");
    scanf("%s",t[taille].prenom);

    do{
        printf("age (17-26): ");
        scanf("%d",&t[taille].age);

        if(t[taille].age<17 || t[taille].age>26)
            printf("Erreur age.\n");

    }while(t[taille].age<17 || t[taille].age>26);

    taille++;
}



//---------------- MODIFIER ----------------

void modifier_id(Etudiant *t,int taille)
{
    int idr,i,trouve=0;

    printf("donner id: ");
    scanf("%d",&idr);

    for(i=0;i<taille;i++)
    {
        if(idr==t[i].id)
        {
            trouve=1;

            printf("nouveau nom: ");
            scanf("%s",t[i].nom);

            printf("nouveau prenom: ");
            scanf("%s",t[i].prenom);

            do{
                printf("age (17-26): ");
                scanf("%d",&t[i].age);

            }while(t[i].age<17 || t[i].age>26);

            printf("modifie avec succes\n");
        }
    }

    if(!trouve)
        printf("etudiant non trouve\n");
}



//---------------- SUPPRIMER ----------------

void supprimerEtudiant(Etudiant *&t,int &taille)
{
    int ind=-1;
    int idr;

    printf("donner id: ");
    scanf("%d",&idr);

    for(int i=0;i<taille;i++)
    {
        if(idr==t[i].id)
        {
            ind=i;
            break;
        }
    }

    if(ind==-1)
    {
        printf("etudiant non trouve\n");
        return;
    }

    for(int i=ind;i<taille-1;i++)
        t[i]=t[i+1];

    taille--;

    t=(Etudiant*)realloc(t,sizeof(Etudiant)*taille);

    printf("supprime avec succes\n");
}



//---------------- RECHERCHER ----------------

void rechercherEtudiant(Etudiant *t,int taille)
{
    int idr,trouve=0;

    printf("donner id: ");
    scanf("%d",&idr);

    for(int i=0;i<taille;i++)
    {
        if(idr==t[i].id)
        {
            trouve=1;

            printf("nom: %s\n",t[i].nom);
            printf("prenom: %s\n",t[i].prenom);
            printf("age: %d\n",t[i].age);
        }
    }

    if(!trouve)
        printf("etudiant non trouve\n");
}



//---------------- LISTER ----------------

void listerEtudiants(Etudiant *t,int taille)
{
    for(int i=0;i<taille;i++)
    {
        printf("id:%d nom:%s prenom:%s age:%d\n",
               t[i].id,t[i].nom,t[i].prenom,t[i].age);
    }
}



//---------------- MOYENNE ----------------

void noteMoyenne(Etudiant *t,int taille)
{
    int idr,trouve=0;

    printf("id: ");
    scanf("%d",&idr);

    for(int i=0;i<taille;i++)
    {
        if(idr==t[i].id)
        {
            trouve=1;

            float somme=
            t[i].note.noteC+
            t[i].note.noteAlgo+
            t[i].note.noteArchi+
            t[i].note.noteElectro+
            t[i].note.noteMath+
            t[i].note.noteProba+
            t[i].note.noteAnglais+
            t[i].note.noteCulture+
            t[i].note.noteTec;

            printf("moyenne: %.2f\n",somme/9);
        }
    }

    if(!trouve)
        printf("etudiant non trouve\n");
}



//---------------- MAIN ----------------

int main()
{
    Etudiant *etudiants=NULL;
    int tailleEtudiants=0;

    int choix,sousChoix;

    do{

        system("cls");
        
		printf("========Menu==========");
        printf("1 Gestion etudiants\n");
        printf("2 Moyenne\n");
        printf("0 Quitter\n");

        scanf("%d",&choix);

        switch(choix)
        {

            case 1:

                do{

                    system("cls");
                    
					printf("======Menu=======")
                    printf("1 Ajouter\n");
                    printf("2 Modifier\n");
                    printf("3 Supprimer\n");
                    printf("4 Rechercher\n");
                    printf("5 Lister\n");
                    printf("6 Retour\n");

                    scanf("%d",&sousChoix);

                    switch(sousChoix)
                    {
                        case 1: ajouter(etudiants,tailleEtudiants); break;
                        case 2: modifier_id(etudiants,tailleEtudiants); break;
                        case 3: supprimerEtudiant(etudiants,tailleEtudiants); break;
                        case 4: rechercherEtudiant(etudiants,tailleEtudiants); break;
                        case 5: listerEtudiants(etudiants,tailleEtudiants); break;
                    }

                }while(sousChoix!=6);

                break;


            case 2:

                noteMoyenne(etudiants,tailleEtudiants);

                break;

        }

    }while(choix!=0);


    free(etudiants);

}
