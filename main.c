#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <SDL2/SDL.h>//libreria para interfas grafica
#include <SDL2/SDL_mixer.h> //Libreria para agregar sonido
#include <pthread.h>//Libreria para crear hilos de ejecucion en segundo plano
#define dim 39
void* musica();//funcion para musica en bucle
void titulo();
void limtab();
void rand_Psig();
void imptab();
void colp();
void baja();
char psig[4][10];
char tab1[39][39];//tablero
clock_t ml;
char esp=176,blc=219;
int pzran,seg=0,pos=0;
int main(int argc, char *argv[])//modificado para que la libreria SDL funcione correctamente
{

    pthread_t mloop;//Crea una variable de tipo pthread con nombre mloop, el loop de la musica; (similar a la creacion de variables normales)
    pthread_create(&mloop, NULL, musica, NULL);//Crea el hilo de ejecucion sin atributos especiales y sin enviar nu¡ingunvalor a la funcion
    system("color 0A");
    titulo();
    getch();
    limtab();
    rand_Psig();
    imptab();
    getch();
    colp();
    imptab();
    baja();
    pthread_join(mloop,NULL);//Espera a que la funcion sin necedidad de obtener ningun tipo de dato

    return 0;
}
void* musica(){
   // Inicializar SDL
    SDL_Init(SDL_INIT_AUDIO);

    // Inicializar SDL_mixer
    Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    // Cargar la canción
    Mix_Music *music = Mix_LoadMUS("C:/Users/rayos/Music/Cancion_Tetris.wav");
   /* if (music == NULL) {
        printf("No se pudo cargar la canción: %s\n", Mix_GetError());

    }*/

    // Reproducir la canción en bucle
    int rep = -1;  // Valor -1 para repetir indefinidamente
    Mix_PlayMusic(music, rep);

    // Detener y liberar recursos
    /*Mix_FreeMusic(music);
    Mix_CloseAudio();
    Mix_Quit();
    SDL_Quit();*/

    return NULL;
}
void titulo(){
    printf("\n\n\n\n\n\n\t\t\t\t[][][][][][][][][]  [][][][][][][][][]  [][][][][][][][][]  [][][][][][][][][]  [][][]  [][][][][][][][][]\n");
    printf("\t\t\t\t[][][][][][][][][]  [][][][][][][][][]  [][][][][][][][][]  [][][][][][][][][]  [][][]  [][][][][][][][][]\n");
    printf("\t\t\t\t      [][][]        [][][]                    [][][]        [][][]      [][][]  [][][]  [][][]            \n");
    printf("\t\t\t\t      [][][]        [][][]                    [][][]        [][][]      [][][]  [][][]  [][][]            \n");
    printf("\t\t\t\t      [][][]        [][][][][][]              [][][]        [][][][][][]        [][][]  [][][][][][][][][]\n");
    printf("\t\t\t\t      [][][]        [][][][][][]              [][][]        [][][][][][]        [][][]  [][][][][][][][][]\n");
    printf("\t\t\t\t      [][][]        [][][]                    [][][]        [][][]      [][][]  [][][]              [][][]\n");
    printf("\t\t\t\t      [][][]        [][][]                    [][][]        [][][]      [][][]  [][][]              [][][]\n");
    printf("\t\t\t\t      [][][]        [][][][][][][][][]        [][][]        [][][]      [][][]  [][][]  [][][][][][][][][]\n");
    printf("\t\t\t\t      [][][]        [][][][][][][][][]        [][][]        [][][]      [][][]  [][][]  [][][][][][][][][]\n\n");
    printf("\t\t\t\t\t\t\t\t     %c",218);
    for(int i=0;i<30;i++){
        printf("%c",196);
    }
    printf("%c\n",191);
    printf("\t\t\t\t\t\t\t\t     %c\t      %c%c%c %c   %c%c%c %c%c%c\t    %c\n",179,219,223,219,219,220,223,220,223,220,223,179);
    printf("\t\t\t\t\t\t\t\t     %c\t      %c%c%c %c%c%c %c%c%c  %c\t    %c\n",179,219,223,223,219,220,220,219,223,219,219,179);
    printf("\t\t\t\t\t\t\t\t     %c",192);
    for(int i=0;i<30;i++){
        printf("%c",196);
    }
    printf("%c\n",217);
    printf("> WELCOME USER DIANA B.\n");
    printf("> WELCOME USER JUAN M.\n");
    printf(">\n");
    printf("> TETRIS %c & %c 2023 TETRIS HOLDING.\n",169,184);
    printf("> TETRIS LOGOS AND TETRIMINOS ARE TRADEMARKS OF TERIS HOLDING.\n");
    printf("> LICENSED TO THE TETRIS COMPANY.\n");
    printf("> TETRIS GAME DESIGN BY DIANA BAUTISTA AND JUAN MOLINA.\n");
    printf("> ALL RIGHTS RESERVED.\n");
}
void limtab(){
    for(int i=0;i<dim-1;i++){
            tab1[i][0]='<';
            tab1[i][1]='!';
            tab1[i][dim-1]='>';
            tab1[i][dim-2]='!';
        for(int j=2;j<dim-2;j++){
            if(j%2 == 0)
                tab1[i][j]=' ';
            else
                tab1[i][j]='.';
        }
    }
    for(int i=2;i<dim-2;i++){
        tab1[dim-2][i]='=';
    }
    for(int i=0;i<dim;i++){
        if(i%2 == 0)
            tab1[dim-1][i]=92;
        else
            tab1[dim-1][i]='/';
    }
}
void rand_Psig(){
    for(int i=0;i<4;i++){
        for(int j=0;j<10;j++){
                psig[i][j]=esp;
        }
    }
    srand(time(NULL));
    pzran=rand()%7;
    //formas
    switch(pzran){
        case 0://linea
            for(int i=1;i<9;i++){
                psig[2][i]=blc;
            }
            break;
        case 1://T
            psig[1][4]=blc;
            psig[1][5]=blc;
            for(int i=2;i<8;i++){
                psig[2][i]=blc;
            }
            break;
        case 2://cuadrado
            for(int i=1;i<3;i++){
                for(int j=3;j<7;j++){
                    psig[i][j]=blc;
                }
            }
            break;
        case 3://z izquierda
            for(int j=2;j<6;j++){
                psig[1][j]=blc;
            }
            for(int j=4;j<8;j++){
                psig[2][j]=blc;
            }
            break;
        case 4://z derecha
            for(int j=2;j<6;j++){
                psig[2][j]=blc;
            }
            for(int j=4;j<8;j++){
                psig[1][j]=blc;
            }
            break;
        case 5://L derecha
            psig[1][6]=blc;
            psig[1][7]=blc;
            for(int i=2;i<8;i++){
                psig[2][i]=blc;
            }
            break;
        case 6://L izquierda
            psig[1][2]=blc;
            psig[1][3]=blc;
            for(int i=2;i<8;i++){
                psig[2][i]=blc;
            }
            break;
    }
}
void imptab(){
    system("cls");
    for(int i=0;i<dim;i++){
        switch(i){
        case 1:
            printf("Nivel: 1\t\t\t");
            break;
        case 2:
            printf("Puntos: 1\t\t\t");
            break;
        case 3:
            printf("Nivel: 1\t\t\t");
            break;
        default:
            printf("\t\t\t\t");
            break;
        }
        for(int j=0;j<dim;j++){
            printf("%c",tab1[i][j]);
        }
        switch(i){
        case 1:
            printf("\t\t");
            for(int i=0;i<10;i++){
                printf("%c",psig[0][i]);
            }
            break;
        case 2:
            printf("\t\t");
            for(int i=0;i<10;i++){
                printf("%c",psig[1][i]);
            }
            break;
        case 3:
            printf("\t\t");
            for(int i=0;i<10;i++){
                printf("%c",psig[2][i]);
            }
            break;
        case 4:
            printf("\t\t");
            for(int i=0;i<10;i++){
                printf("%c",psig[3][i]);
            }
            break;
            default:
            break;
        }
        printf("\n");
    }
}
void colp(){
    for(int i=pos;i<pos+4;i++){
        for(int j=0;j<10;j++){
            if(psig[i-pos][j]!=esp){
                tab1[i][j+13]=blc;
            }
        }
    }
}
void baja(){
    for(int i=0;i<dim-5;i++){
        ml=clock();
        if(ml>seg*1000+1000){
            limtab();
            pos++;
            colp();
            imptab();
        }
    }
}
