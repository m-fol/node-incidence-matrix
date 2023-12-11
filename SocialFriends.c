#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main(){

// hello

    bool comes_to_party[13];

    char names[13][15]= {"Nikos","Lydia","Giannis","Eua","Manos","Petros","Akis","Eleni","Maria","Dimitris","Zoi","Alexandros","Anna"};
    int like_dislike[13][13] = {0,1,0,0,0,0,1,0,0,0,0,0,0,
                                1,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,1,0,0,0,0,0,0,
                                0,0,0,0,1,0,0,0,0,0,0,0,0,
                                0,0,0,1,0,0,1,1,0,0,0,0,0,
                                0,0,0,0,0,0,0,1,0,0,0,0,0,
                                1,0,1,0,1,0,0,0,0,0,0,0,0,
                                0,0,0,0,1,1,0,0,1,1,0,0,0,
                                0,0,0,0,0,0,0,1,0,1,0,1,0,
                                0,0,0,0,0,0,0,1,1,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,1,0,0,0,1,
                                0,0,0,0,0,0,0,0,0,0,0,1,0};

    int i,j;
    int max=13, sum[13];


    for(i=0;i<14;i++){
        sum[i] = 0;
        comes_to_party[i]=TRUE;
        for(j=0;j<14;j++){
            if(like_dislike[i][j]==1){
                sum[i] = sum[i] + 1;
            }
        }
    }

    int counter, k;

    for(i=0;i<14;i++){
        for(j=0;j<14;j++){
            if(sum[i]==2 && like_dislike[i][j]==1){
                counter = 0;
                for(k=0;k<14;k++){
                    if(like_dislike[k][j]==1){
                        counter = counter + 1;
                    }
                }
                if(counter<2){
                    comes_to_party[i] = FALSE;
                }
            }
            else if(sum[i]>2){
                comes_to_party[i] = FALSE;
            }
        }
    }

    for(i=0;i<14;i++){
        if(comes_to_party[i]==FALSE){
            max--;
        }
    }


    printf("Tha erthoun %d atoma sto party\n", max);

    for(i=0;i<14;i++){
        if(comes_to_party[i]==TRUE){
            printf("%s\n", names[i]);
        }
    }




    return 0;


}

