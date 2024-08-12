// https://omegaup.com/arena/problem/Entrando-al-supermercado/#problems

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){

    int n, m;
    int i, c, ct = 0;

    scanf("%d %d", &n, &m);

        if(1 <= n <= pow(10, 5) && 1 <= m <= pow(10, 5)){

            for(i = 1; i <= n; i++){

                printf("");
                scanf("%d", &c);
                ct = ct + c;

                    if(1 <= ct <= m){

                        if (ct >= 1 && ct <= m){

                    printf("pasa\n");
                }else{
                    printf("espera\n");
                    ct = ct - c;
                }
            }else{
                printf("No se respetaron los limites de OmegaUp");
            }
        }

    }else{
        printf("No se respetaron los limites de OmegaUp");
    }

    return 0;

}
