#include <stdio.h>
#define ukuran 5

void inputMatrix(int matrix[ukuran][ukuran]){
    for(int baris = 0; baris < ukuran; baris ++){
        for(int kolom = 0; kolom < ukuran; kolom ++){
            scanf("%d", &matrix[baris][kolom]);
        }
    }
}

int HapusBarisSama(int matrix[ukuran][ukuran]){
    int ElemenSama,BarisTerakhirHilangkan = 0;

    for(int baris = 0; baris < ukuran; baris ++){
        ElemenSama = 1;

        for(int kolom = 1; kolom < ukuran; kolom ++){
            if(matrix[baris][kolom] !=  matrix[baris][0]){
                ElemenSama = 0;
                break;
            }
        }
        if(ElemenSama){
            for(int kolom = 0; kolom < ukuran; kolom ++){
                matrix[baris][kolom] = 0;
            }
            BarisTerakhirHilangkan = baris;
        }
    }
    return BarisTerakhirHilangkan;
}

void turunkanBaris(int  matrix[ukuran][ukuran],int BarisTerakhirHilangkan){
    int barisTurun;

    for(int kolom = 0; kolom <ukuran; kolom ++){
        barisTurun = BarisTerakhirHilangkan;

        for(int baris = BarisTerakhirHilangkan + 1; baris < ukuran; baris ++){
            if(matrix[baris][kolom] == 0){
                barisTurun += 1;
            }else{
                break;
            }
        }

        if(matrix[barisTurun][kolom] == 0){
            for(int baris = barisTurun; baris > 0; baris --){
                matrix[baris][kolom] = matrix[baris - 1][kolom];
                if(baris == 1){
                    matrix[baris - 1][kolom] = 0;
                }
            }
        }

        for(int baris = barisTurun; baris > 0; baris --){
            if(matrix[barisTurun][kolom] == 0){
                for(int i = barisTurun; i > 0; i --){
                    matrix[i][kolom] = matrix[i - 1][kolom];
                    if(i == 1){
                        matrix[i - 1][kolom] = 0;
                    }
                }
            }else if(matrix[baris][kolom] == 0){
                for(int i = baris; i > 0; i --){
                    matrix[i][kolom] = matrix[i - 1][kolom];
                    if (i == 1){
                        matrix[i - 1][kolom] = 0;
                    }
                }
            }
        }
    }
}

void cetakTetris(int matrix[ukuran][ukuran]){
    for(int baris = 0; baris < ukuran; baris++){
        for(int kolom = 0; kolom < ukuran; kolom ++){
            printf("%d ", matrix[baris][kolom]);
        }
        printf("\n");
    }
}

int main(){
    int matrix[ukuran][ukuran];
    int BarisTerakhirDihilangkan;

    inputMatrix(matrix);

    BarisTerakhirDihilangkan = HapusBarisSama(matrix);

    turunkanBaris(matrix, BarisTerakhirDihilangkan);
    cetakTetris(matrix);
}
