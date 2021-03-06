#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FUNCTION_H_INCLUDED
#ifndef STRUCTURE_H_INCLUDED
#include "structure.h"
#endif


/**
 * cette fonction prends en parametre un ensemble
 * d'elements et retourne la liste des elements unique
 * 
 */
FeatureLine get_unique_element(MyString elts[],int nbelements)
{

    MyString bonjour={"ui454bbfkabvslklfiusabkla"};
    MyString uniqueelt[nbelements];
    FeatureLine *feature;
    //MyString *uniqueelt;
    
    for (int i=0;i<nbelements;i++){
        strcpy(uniqueelt[i].value," ");
    }
   /*
    for (int i=0;i<nbelements;i++){
        printf("la val modifier est %d %s \n",i,uniqueelt[i].value);
    }
    */
    //MyString *uniqueelt;
    //*uniqueelt=bonjour;
    int nb_unique=0;
    int trouve=0;
    for(int i=0;i<nbelements;i++){
        for(int j=0;j<=i;j++){
            if (strcmp(elts[i].value,uniqueelt[j].value)==0){
                //printf("%s == %s \n",elts[i].value,uniqueelt[j].value);
                trouve=1;
            }
        }
        if(trouve==0){
                //printf("an unique %s ->\n",elts[i].value);
                strcpy(uniqueelt[nb_unique].value,elts[i].value);
                nb_unique++;
        }
        trouve=0;
    }
    
    FeatureLine features;
   
    //FeatureLine* unique2=(FeatureLine*)malloc(nb_unique*sizeof(FeatureLine));
    features.feature=uniqueelt;
    features.id=nb_unique;
    /*printf("***bonjour la fin****\n");
    
    printf("Le nombre d'elt unique est %d \n",nb_unique);
    //printf("--------\n");
    for(int i=0;i<nb_unique;i++){
        //unique2[i]=uniqueelt[2];
        printf("hu->%s -- ",features.feature[i].value);
    }
    printf("\n");
    */
    //features.feature=unique2;
    return features;
}

/**
 * Fonction qui prend en prametre un elet et renvois le 
 * nombre de fois qui'il apparait dans la liste
 */
FeatureLine* get_feature_column(FeatureLine *feature,int col_index,int rows){
    FeatureLine *features;
    features=malloc(rows*sizeof(*features));
    for(int i=0;i<rows;i++){
        //strcpy((*(features+i)).feature[0].value,feature[i].feature[col_index].value);
        features[i].id=feature[i].id;
        features[i].feature=&feature[i].feature[col_index];
        //printf("hello %s\n",features[i].feature[0].value);
    }
    return features;
}

/**
 * Retroune le nom de fois que elt apparait dans list
 * 
 * @param char elt
 * @param MyString list
 * @param int nb_elt
 */ 
int nb_times_in(char elt[],MyString list[],int nb_elt){
    int nb=0;
    for(int i=0;i<nb_elt;i++){
        if(strcasecmp(elt,list[i].value)==0){
            nb++;
        }
    }
    return nb;
}
 