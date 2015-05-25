/*  File:   main.cpp
 * Author: Jonathan Sepulveda Nuñez
 *         17563886-5
 *         Roberto Esparza
 *         17754205-9
 *         Joaquin Astudillo
 *  
 * Created on 23 de abril de 2015, 12:32
 */
#include <cstdlib>
#include <string>
#include <iostream>
#define T 10

using namespace std;

char tablero[T][T];//DEFINE TABLERO
string blanco="░";//REPRESENTA  LOS CUADROS BLANCO DEL TABLERO
string negro="█";//REPRESENTA LSO CUADROS NEGROS DEL TABLERO
int i, j;// J E I SIRVE PARA RELLENAR TABLERO E IMPRIMIRLO ADEMAS DE SERVIR TAMBIEN EN VOID PRESENTACION
int z; //  ESP PARA COORDENADAS VERTICALES
int turno=1;//TURNO PARA FICHAS X CUADNO CUANDO UN SUARIO MUEVE UNA FICHA EL TURNO CAMBIA A 0 Y PROSIGUE EL SIGUIENTE JUGADOR
int direccion ;//INDICA HACIA DODNE QUIERE MOVER LA FICAH EL USUARIO
int error ; //VALIDACION DE CUANDO COMES UNA FICHA EN DIAGONAL DE LA QUE VAS A COMER
int contador=1; //SIRVE PARA VOID PRESENTACION
int fichao=12;
int fichax=12;// SIRVE PARA DETERMINAR CUANDO SE GANA O PIERDE UN JUEGO
int terminar=1;
int contador_fichas_x= 9;//CINTADOR POR DEFAULT SI NO SE CAMBIA OPCIONE EN MODO ESPECIAL
int contador_fichas_o= 9;
int x,y ;// PARA MOVER FICHAS
int contadorcpu;

/*
 *
 */

void rellenar(){
    for(i=0;i<T;i++){
        for(j=0;j<T;j++){
            if(i<=2&&((j+i)%2==0)){
                tablero[i][j] = 'O' ;
            } // ESTE IF PONE FICHAS CONTRARIAS CUANDO ARREGLO VALGA 0
            else if (i>=7&&((j+i)%2==0) ){
                tablero[i][j] = 'X' ;
            }//
            else {
                tablero[i][j] = ' ' ;}
        }/*FIN FOR J */  //SALTO DE LINEA
    }//FIN FOR I
}// FIN DEL VOID RELLENAR E IMPRIMIR

void imprimir(){
    for(z=0;z<T;z++){//INICIO DEL FOR Z QUE SIRVE PARA INDICAR LAS CORDENADAS HORIZONTALES
        cout << z <<"    ";}//FIN DEL FOR Z
    cout<<endl;
    for(i=0;i<T;i++){
        cout<<"\t\t       ";
        cout<<i;//ESTA I SIRVE PARA INDICAR COORDENADAS VERTICALES
        for(j=0;j<T;j++){
            if((tablero[i][j]=='X'||tablero[i][j]=='O'||tablero[i][j]=='C'||tablero[i][j]=='D')&&((j+i)%2==0)){
                cout<<blanco<<blanco<<tablero[i][j]<<blanco<<blanco; }
            else if (tablero[i][j]==' ' && (j+i)%2!=0){
                cout<<negro<<negro<<negro<<negro<<negro;}
            else if (tablero[i][j]==' ' &&(j+i)%2==0){
                cout<<blanco<<blanco<<blanco<<blanco<<blanco; ;}
        }/*FIN FOR J */cout<<endl;  //SALTO DE LINEA
    }//FIN FOR I
}

void imprimir2(){
    cout<<"\t\t\t";
    for(z=0;z<T;z++){//INICIO DEL FOR Z QUE SIRVE PARA INDICAR LAS CORDENADAS HORIZONTALES
        cout << z <<"    ";}//FIN DEL FOR Z
    cout<<endl;
    for(i=0;i<T;i++){
        cout<<"\t\t       ";
        cout<<i;//ESTA I SIRVE PARA INDICAR COORDENADAS VERTICALES
        for(j=0;j<T;j++){
            if((tablero[i][j]=='X'||tablero[i][j]=='O'||tablero[i][j]=='C'||tablero[i][j]=='D')&&((j+i)%2==0)){
                cout<<blanco<<blanco<<tablero[i][j]<<blanco<<blanco; }
            else if (tablero[i][j]==' ' && (j+i)%2!=0){
                cout<<negro<<negro<<negro<<negro<<negro;}
            else if (tablero[i][j]==' ' &&(j+i)%2==0){
                cout<<blanco<<blanco<<blanco<<blanco<<blanco; ;}
        }/*FIN FOR J */cout<<endl;  //SALTO DE LINEA
    }//FIN FOR I
}

void mover1(){
    do{
        do{
            do{
                do{
                    cout<<"TURNO JUGADOR 2 FICHAS O" <<endl ;
                    cout<<"INGRESE CORDENADA VERTICAL "<<endl ;
                    cin>> x ;
                    cout<<"INGRESE COORDENADA HORIZONTAL "<<endl ;
                    cin>> y;
                    if  (tablero[x][y]!='O'&&tablero[x][y]!='C'){
                        cout<<"ERROR VUELVA A TIRAR NO HAY FICHA EN LA CASILLA "<<x<<"-"<<y<<endl ;}
                }while (tablero[x][y]!='O'&&tablero[x][y]!='C');//VALIDACION PARA EL TIRO DE MOVIMIENTO
                do{
                    if (tablero[x][y] == 'O'){
                        cout<<"SELECCIONE LA NUEVA POSICION DE LA FICHA [1]IZQUIERDA-ABAJO [2] DERECHA-ABAJO "<<endl ;
                        cin>>direccion ;
                        error=0;
                        if(direccion>2||direccion<1){
                            cout<<"ERROR ESCOGA UNA OPCION VALIDA EN DIRECCION "<<endl;
                        }
                        if((y==0&&direccion==1)||(y==9&&direccion==2)){
                            cout<<"ERROR LA PIEZA SALE DEL TABLERO "<<endl ;
                        }
                    }//FIN IF DE MOVIMIENTO
                    if (tablero[x][y]=='C'){
                        cout<<"SELECCIONE [1]IZQ-ABAJO [2]DER-ABAJO [3]IZQ-ARRIBA [4]DER-ARRIBA "<<endl ;
                        cin>>direccion ;
                        error=0;
                        if(direccion>4||direccion<1){
                            cout<<"ERROR ESCOGA UNA OPCION VALIDA EN DIRECCION "<<endl;}
                        if((y==9&&direccion==2)||(y==0&&direccion==1)||(y==9&&direccion==4)||(y==0&&direccion==3)||(x==0&&direccion==4)||(x==0&&direccion==3)||(x==9&&direccion==1)||(x==9&&direccion==2)){
                            cout<<"ERROR NO PUEDES SALIRTE DEL TABLERO "<<endl ;
                        }
                    }//FIN IF DE MOVIMIENTO
                }while (direccion>4||direccion<1);
            }while ((y==9&&direccion==2)||(y==0&&direccion==1)||(y==9&&direccion==4)||(y==0&&direccion==3)||(x==0&&direccion==4)||(x==0&&direccion==3)||(x==9&&direccion==1)||(x==9&&direccion==2));
            if (direccion == 1 &&( tablero[x+1][y-1]== 'O'||tablero[x+1][y-1]== 'C') ){
                cout<<"ERROR LA CASILLA ESTA OCUPADA POR UNA FICHA AMIGA  "<<endl ;
            }
            if (direccion == 2 && (tablero[x+1][y+1]== 'O' || tablero[x+1][y+1]== 'C') ){
                cout<<"ERROR LA CASILLA ESTA OCUPADA POR UNA FICHA AMIGA "<<endl ;
            }
            if (direccion == 3 && (tablero[x-1][y-1]== 'O' || tablero[x-1][y-1]== 'C') ){
                cout<<"ERROR LA CASILLA ESTA OCUPADA POR UNA FICHA AMIGA "<<endl ;
            }
            if (direccion == 4 && (tablero[x-1][y+1]== 'O' || tablero[x-1][y+1]== 'C') ){
                cout<<"ERROR LA CASILLA ESTA OCUPADA POR UNA FICHA AMIGA "<<endl ;
            }
        }while((direccion == 1 &&( tablero[x+1][y-1]== 'O'||tablero[x+1][y-1]== 'C') )||(direccion == 2 && (tablero[x+1][y+1]== 'O' || tablero[x+1][y+1]== 'C') )|| (direccion == 3 && (tablero[x-1][y-1]== 'O' || tablero[x-1][y-1]== 'C') )||(direccion == 4 && (tablero[x-1][y+1]== 'O' || tablero[x-1][y+1]== 'C') ));//VALIDACION PARA CASILLA OCUPADA POR UNA AMIGA
        if (direccion==1 &&( tablero[x+1][y-1] == 'X' || tablero[x+1][y-1] == 'D') ){
            if(y==1){
                cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                error=1;
            }
            if(x==6){
                cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                error=1;
            }
            if(tablero[x+2][y-2] == 'X'){
                cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<x+2<<"-"<<y-2<<endl;
                error=1;
            }
            if(tablero[x+2][y-2] == 'O'){
                cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<x+2<<"-"<<y-2<<endl;
                error=1;
            }
            if(tablero[x+2][y-2] == 'C'){
                cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<x+2<<"-"<<y-2<<endl;
                error=1;
            }
            if(tablero[x+2][y-2] == 'D'){
                cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<x+2<<"-"<<y-2<<endl;
                error=1;
            }
        }
        if (direccion==2 && (tablero[x+1][y+1] == 'X'||tablero[x+1][y+1] == 'D'))
        {
            if(y==6)
            {cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                error=1;
            }
            if(x==6)
            {cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                error=1;
            }
            if(tablero[x+2][y+2] == 'X')
            {
                cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                error=1;}
            if( tablero[x+2][y+2] == 'O')
            {
                cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                error=1;}
            if( tablero[x+2][y+2] == 'C')
            {
                cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                error=1;}
            if( tablero[x+2][y+2] == 'D')
            {
                cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                error=1;}
        }
        if (direccion==3 && (tablero[x-1][y-1] == 'X'||tablero[x-1][y-1] == 'D'))
        {
            if(y==1)
            {cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                error=1;
            }
            if(x==1)
            {cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                error=1;
            }
            if(tablero[x-2][y-2] == 'X')
            {
                cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                error=1;}
            if( tablero[x-2][y-2] == 'O')
            {
                cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                error=1;}
            if( tablero[x-2][y-2] == 'C')
            {
                cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                error=1;}
            if( tablero[x-2][y-2] == 'D')
            {
                cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                error=1;}
        }
        if (direccion==4 && (tablero[x-1][y+1] == 'X'||tablero[x-1][y+1] == 'D'))
        {
            if(y==6)
            {cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                error=1;
            }
            if(x==1)
            {cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                error=1;
            }
            if(tablero[x-2][y+2] == 'X')
            {
                cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                error=1;}
            if( tablero[x-2][y+2] == 'O')
            {
                cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                error=1;}
            if( tablero[x-2][y+2] == 'D')
            {
                cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                error=1;}
            if( tablero[x-2][y+2] == 'C')
            {
                cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                error=1;}
        }
    }while(error==1);
    //VALIDACION DE MOVIMIENTO PARA ESPACION OCUPADOS
    
    if (tablero[x][y]=='C' && direccion == 1 && tablero[x+1][y-1]== ' ' ){
        tablero[x][y]=' ' ;
        tablero[x+1][y-1] = 'C' ;
    }
    else if (tablero[x][y]=='C' && direccion == 2 && tablero[x+1][y+1]== ' '  ){
        tablero[x][y]=' ' ;
        tablero[x+1][y+1] = 'C' ;
    }
    else if (tablero[x][y]=='C' && direccion == 3 && tablero[x-1][y-1]== ' '  ){
        tablero[x][y]=' ' ;
        tablero[x-1][y-1] = 'C' ;
    }
    else if (tablero[x][y]=='C' && direccion == 4 && tablero[x-1][y+1]== ' '  ){
        tablero[x][y]=' ' ;
        tablero[x-1][y+1] = 'C' ;
    }
    else if(tablero[x][y]=='C' && direccion== 1 && (tablero [x+1][y-1] == 'X'||tablero [x+1][y-1] == 'D'))
    {
        tablero[x][y]=' ' ;
        tablero[x+1][y-1]=' ' ;
        tablero[x+2][y-2]= 'C' ;
        cout<<"\a";
        cout<<"HAS COMIDO A LA FICHA CONTRARIA 'X' EN LA CASILLA   "<<x+1<<"-"<<y-1 ;
        fichax=fichax-1;
        contador_fichas_o= contador_fichas_o+3;
        
    }
    else if(tablero[x][y]=='C' && direccion== 2 && (tablero [x+1][y+1] == 'X'||tablero [x+1][y+1] == 'D'))
    {
        tablero[x][y]=' ' ;
        tablero[x+1][y+1]=' ' ;
        tablero[x+2][y+2]= 'C' ;
        cout<<"\a";
        cout<<"HAS COMIDO A LA FICHA CONTRARIA 'X' EN LA CASILLA   "<<x+1<<"-"<<y+1 ;
        fichax=fichax-1;
        contador_fichas_o= contador_fichas_o+3;
        
    }
    else if(tablero[x][y]=='C' && direccion== 3 && (tablero [x-1][y-1] == 'X'||tablero [x-1][y-1] == 'D'))
    {
        tablero[x][y]=' ' ;
        tablero[x-1][y-1]=' ' ;
        tablero[x-2][y-2]= 'C' ;
        cout<<"\a";
        cout<<"HAS COMIDO A LA FICHA CONTRARIA 'X' EN LA CASILLA   "<<x-1<<"-"<<y-1 ;
        fichax=fichax-1;
        contador_fichas_o= contador_fichas_o+3;
        
    }
    else if(tablero[x][y]=='C' && direccion== 4 && (tablero [x-1][y+1] == 'X'||tablero [x-1][y+1] == 'D'))
    {
        tablero[x][y]=' ' ;
        tablero[x-1][y+1]=' ' ;
        tablero[x-2][y+2]= 'C' ;
        cout<<"\a";
        cout<<"HAS COMIDO A LA FICHA CONTRARIA 'X' EN LA CASILLA   "<<x-1<<"-"<<y+1 ;
        fichax=fichax-1;
        contador_fichas_o= contador_fichas_o+3;
        
    }
    else if (tablero[x][y]=='O' && direccion == 1 && tablero[x+1][y-1]== ' ' ){
        tablero[x][y]=' ' ;
        tablero[x+1][y-1] = 'O' ;
    }
    if (tablero[x][y]=='O' && direccion == 2 && tablero[x+1][y+1]== ' ' ){
        tablero[x][y]=' ' ;
        tablero[x+1][y+1] = 'O' ;
    }
    else if(tablero[x][y]=='O'&& direccion== 1 && (tablero [x+1][y-1] == 'X'||tablero [x+1][y-1] == 'D'))
    {
        tablero[x][y]=' ' ;
        tablero [x+1][y-1]= ' ' ;
        tablero[x+2][y-2]= 'O' ;
        cout<<"\a";
        cout<<"HAS COMIDO A LA FICHA CONTRARIA 'X' EN LA CASILLA  "<<x+1<<"-"<<y-1 ;
        fichax=fichax-1;
        contador_fichas_o= contador_fichas_o+3;
        
    }
    else if(tablero[x][y]=='O'&& direccion== 2 && ( tablero [x+1][y+1] == 'X'|| tablero [x+1][y+1] == 'D'))
    {
        tablero[x][y]=' ' ;
        tablero[x+1][y+1]=' ' ;
        tablero[x+2][y+2]= 'O' ;
        cout<<"\a";
        cout<<"HAS COMIDO A LA FICHA CONTRARIA 'X' EN LA CASILLA   "<<x+1<<"-"<<y+1 ;
        fichax=fichax-1;
        contador_fichas_o= contador_fichas_o+3;
        
    }
    turno = 1 ;
    
}// FIN VOID MOVER **********

void mover2()
{
    do
    {
        do
        {
            do
            {
                do
                {
                    cout<<"TURNO JUGADOR 1 FICHAS X" <<endl ;
                    if(turno==1 )
                    {
                        cout<<"INGRESE CORDENADA VERTICAL "<<endl ;
                        cin>> x ;
                        
                        cout<<"INGRESE COORDENADA HORIZONTAL "<<endl ;
                        cin>> y;
                    }//FIN IF TURNO =1
                    if  (tablero[x][y]!='X'&&tablero[x][y]!='D')
                    {
                        cout<<"ERROR VUELVA A TIRAR NO HAY FICHA EN LA CASILLA "<<x<<"-"<<y<<endl ;}
                }while (tablero[x][y]!='X'&&tablero[x][y]!='D');//VALIDACION PARA EL TIRO DE MOVIMIENTO
                do
                {
                    if (tablero[x][y] == 'X')
                    {
                        {
                            cout<<"SELECCIONE LA NUEVA POSICION DE LA FICHA [1]IZQUIERDA-ARRIBA [2] DERECHA-ARRIBA " ;
                            cin>>direccion ;
                            error=0;
                            if(direccion>2||direccion<1)
                            {cout<<"ERROR ESCOGA UNA OPCION VALIDA EN DIRECCION "<<endl;
                            }
                        }
                        if((y==9&&direccion==2)||(y==0&&direccion==1))
                        {
                            cout<<"ERROR NO PUEDES SALIRTE DEL TABLERO "<<endl ;}
                    }//FIN IF DE MOVIMIENTO
                    if (tablero[x][y]=='D')
                    {
                        cout<<"SELECCIONE [1]IZQ-ARRIBA [2]DER-ARRIBA [3]IZQ-ABAJO [4] DER-ABAJO " <<endl ;
                        cin>>direccion ;
                        error=0;
                        if(direccion>4||direccion<1)
                        {cout<<"ERROR ESCOGA UNA OPCION VALIDA EN DIRECCION "<<endl;}
                        if((y==9&&direccion==2)||(y==0&&direccion==1)||(y==9&&direccion==4)||(y==0&&direccion==3)||(x==0&&direccion==1)||(x==0&&direccion==2)||(x==9&&direccion==3)||(x==9&&direccion==4))
                        {
                            cout<<"ERROR NO PUEDES SALIRTE DEL TABLERO "<<endl ;}
                    }// fin if
                }while (direccion>4||direccion<1);//VALIDACION DE MOVIMIETNO PARA DIRECCION
            }while((y==9&&direccion==2)||(y==0&&direccion==1)||(y==9&&direccion==4)||(y==0&&direccion==3)||(x==0&&direccion==1)||(x==0&&direccion==2)||(x==9&&direccion==3)||(x==9&&direccion==4));//Vlidacion para no salirte del tablero
            if (direccion == 1 && ( tablero[x-1][y-1]== 'X'||tablero[x-1][y-1]== 'D')  ){
                cout<<"ERROR LA CASILLA ESTA OCUPADA POR UNA FICHA AMIGA  "<<endl ;
            }
            else if (direccion == 2 && (tablero[x-1][y+1]== 'X'||tablero[x-1][y+1]== 'D') ){
                cout<<"ERROR LA CASILLA ESTA OCUPADA POR UNA FICHA AMIGA "<<endl ;
            }
            else if (direccion == 3 && (tablero[x+1][y-1]== 'X'||tablero[x+1][y-1]== 'D') ){
                cout<<"ERROR LA CASILLA ESTA OCUPADA POR UNA FICHA AMIGA "<<endl ;
            }
            else if (direccion == 4 && (tablero[x+1][y+1]== 'X'||tablero[x+1][y+1]== 'D') ){
                cout<<"ERROR LA CASILLA ESTA OCUPADA POR UNA FICHA AMIGA "<<endl ;
            }
        }while((direccion==1&&(tablero[x-1][y-1]== 'X'||tablero[x-1][y-1]== 'D'))||(direccion==2&&(tablero[x-1][y+1]== 'X'||tablero[x-1][y+1]== 'D') )||(direccion == 3 && (tablero[x+1][y-1]== 'X'||tablero[x-1][y+1]== 'D') )||(direccion == 4 && (tablero[x+1][y+1]== 'X'||tablero[x+1][y+1]== 'D') ));//VALIDACION DE MOVIMIENTO PARA ESPACION OCUPADO POR
        //CASILLA AMIGA
        if (direccion==1 && (tablero[x-1][y-1] == 'O'||tablero[x-1][y-1] == 'C') )
        {
            if(y==1)
            {cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                error=1;
            }
            if(x==1)
            {cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                error=1;
            }
            if(tablero[x-2][y-2] == 'X')
            {
                cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x-2<<"-"<<y-2<<endl;
                error=1;}
            if(tablero[x-2][y-2] == 'O' )
            {
                cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x-2<<"-"<<y-2<<endl;
                error=1;}
            if(tablero[x-2][y-2] == 'D' )
            {
                cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x-2<<"-"<<y-2<<endl;
                error=1;}
            if(tablero[x-2][y-2] == 'C' )
            {
                cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x-2<<"-"<<y-2<<endl;
                error=1;}
        }
        else if (direccion==2 && (tablero[x-1][y+1] == 'O'||tablero[x-1][y+1] == 'C'))
        {
            if(y==6)
            {cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                error=1;
            }
            if(x==1)
            {cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                error=1;
            }
            if(tablero[x-2][y+2] == 'X')
            {
                cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                error=1;}
            if (tablero[x-2][y+2] == 'O')
            {
                cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                error=1;}
            if (tablero[x-2][y+2] == 'D')
            {
                cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                error=1;}
            if (tablero[x-2][y+2] == 'C')
            {
                cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                error=1;}
        }
        else if (direccion==3 && (tablero[x+1][y-1] == 'O'||tablero[x+1][y-1] == 'C'))
        {
            if(y==1)
            {cout<<"ERROR TE SALES DEL TABLERO "<<endl ;if(y==1)
            {cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                error=1;
            }
                error=1;
            }
            if(x==6)
            {cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                error=1;
            }
            if(tablero[x+2][y-2] == 'X')
            {
                cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                error=1;}
            if (tablero[x+2][y-2] == 'O')
            {
                cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                error=1;}
            if (tablero[x-2][y+2] == 'C')
            {
                cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                error=1;}
            if (tablero[x-2][y+2] == 'D')
            {
                cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                error=1;}
        }
        else if (direccion==4 && (tablero[x+1][y+1] == 'O'||tablero[x+1][y+1] == 'C'))
        {
            if(y==6)
            {cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                error=1;
            }
            if(x==6)
            {cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                error=1;
            }
            if(tablero[x+2][y+2] == 'X')
            {
                cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                error=1;}
            if (tablero[x+2][y+2] == 'O')
            {
                cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                error=1;}
            if (tablero[x+2][y+2] == 'D')
            {
                cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                error=1;}
            if (tablero[x+2][y+2] == 'C')
            {
                cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                error=1;}
        }
    }while(error==1);
    //VALIDACION DE MOVIMIENTO PARA ESPACION OCUPADOS CUANDO SE VA A COMER
    if(tablero[x][y]== 'D' && direccion==1 && tablero[x-1][y-1]== ' '  ){
        tablero[x][y]= ' ';
        tablero[x-1][y-1]= 'D';}
    else if (tablero[x][y]=='D'&& direccion == 2 && tablero[x-1][y+1]== ' ' ){
        tablero[x][y]=' ' ;
        tablero[x-1][y+1] = 'D' ;
    }
    else if (tablero[x][y]=='D'&& direccion == 3 && tablero[x+1][y-1]== ' ' ){
        tablero[x][y]=' ' ;
        tablero[x+1][y-1] = 'D' ;
    }
    else if (tablero[x][y]=='D'&& direccion == 4 && tablero[x+1][y+1]== ' ' ){
        tablero[x][y]=' ' ;
        tablero[x+1][y+1] = 'D' ;
    }
    else if(tablero[x][y]=='D'&& direccion== 1 &&( tablero [x-1][y-1] == 'O' || tablero [x-1][y-1] == 'C'))
    {
        tablero[x][y]=' ' ;
        tablero[x-1][y-1]=' ' ;
        tablero[x-2][y-2]= 'D' ;
        cout<<"\a";
        cout<<"HAS COMIDO A LA FICHA CONTRARIA 'O' EN LA CASILLA "<<x-1<<"-"<<y-1 ;
        fichao=fichao-1;
        contador_fichas_x= contador_fichas_x+3;
        
    }
    else if(tablero[x][y]=='D'&& direccion==2 && (tablero [x-1][y+1] == 'O'||tablero [x-1][y+1] == 'C'))
    {
        tablero[x][y]=' ' ;
        tablero[x-1][y+1]=' ' ;
        tablero[x-2][y+2]= 'D' ;
        cout<<"\a";
        cout<<"HAS COMIDO A LA FICHA CONTRARIA 'O' EN LA CASILLA  "<<x-1<<"-"<<y+1 ;
        fichao=fichao-1;
        contador_fichas_x= contador_fichas_x+3;
        
    }
    else if(tablero[x][y]=='D'&& direccion== 3 && (tablero [x+1][y-1] == 'O'||tablero [x+1][y-1] == 'C'))
    {
        tablero[x][y]=' ' ;
        tablero[x+1][y-1]=' ' ;
        tablero[x+2][y-2]= 'D' ;
        cout<<"\a";
        cout<<"HAS COMIDO A LA FICHA CONTRARIA 'O' EN LA CASILLA "<<x+1<<"-"<<y-1 ;
        fichao=fichao-1;
        contador_fichas_x= contador_fichas_x+3;
        
    }
    else if(tablero[x][y]=='D'&& direccion== 4 && (tablero [x+1][y+1] == 'O'||tablero [x+1][y-1] == 'C'))
    {
        tablero[x][y]=' ' ;
        tablero[x+1][y+1]=' ' ;
        tablero[x+2][y+2]= 'D' ;
        cout<<"\a";
        cout<<"HAS COMIDO A LA FICHA CONTRARIA 'O' EN LA CASILLA "<<x+1<<"-"<<y+1 ;
        fichao=fichao-1;
        contador_fichas_x= contador_fichas_x+3;
    }
    else if(tablero[x][y]== 'X' && direccion== 1 && tablero [x-1][y-1] == ' ')
    {
        tablero[x][y]=' ' ;
        tablero [x-1][y-1]= 'X' ;
    }//FIN DE ELSE IF
    else if(tablero[x][y]=='X'&& direccion== 1 && (tablero [x-1][y-1] == 'O'||tablero [x-1][y-1] == 'C'))
    {
        tablero[x][y]=' ' ;
        tablero[x-1][y-1]=' ' ;
        tablero[x-2][y-2]= 'X' ;
        cout<<"\a";
        cout<<"HAS COMIDO A LA FICHA CONTRARIA 'O' EN LA CASILLA  "<<x-1<<"-"<<y-1 ;
        fichao=fichao-1;
        contador_fichas_x= contador_fichas_x+3;
        
    }
    else if(tablero[x][y]== 'X' && direccion== 2 && tablero [x-1][y+1] == ' ')
    {
        tablero[x][y]=' ' ;
        tablero [x-1][y+1]= 'X' ;
    }//FIN DE ELSE IF
    else if(tablero[x][y]== 'X' && direccion== 2 && (tablero [x-1][y+1] == 'O'||tablero [x-1][y+1] == 'C'))
    {
        tablero[x][y]=' ' ;
        tablero [x-1][y+1]= ' ' ;
        tablero[x-2][y+2]= 'X' ;
        cout<<"\a";
        cout<<"HAS COMIDO A LA FICHA CONTRARIA 'O' EN LA CASILLA "<<x-1<<"-"<<y+1 ;
        fichao=fichao-1;
        contador_fichas_x= contador_fichas_x+3;
        
    }//FIN DE ELSE IF
    turno = 0 ;
}//FIN VOI MOVER 2  
void cpu ()
{
   cout<<"TURNO COMPUTADORA PENSANDO JUGADA...." <<endl ;    
    do{
        do{
           do{
               do{
                    srand(time(NULL));
                    x=rand() % 9+0 ;
                    y=rand() % 9+0 ;
                  }while (tablero[x][y]!='O'&&tablero[x][y]!='C');//VALIDACION PARA EL TIRO DE MOVIMIENTO
                    do
                    {
                        if (tablero[x][y]=='C')
                       {
                            direccion=rand()% 4+1 ;
                            error=0;
                          if (tablero[x][y] == 'O')
                          {
                            direccion=rand() % 2+1 ;
                            error=0;
                          }//FIN IF DE MOVIMIENTO
                        }//FIN IF DE MOVIMIENTO
                     }while (direccion>4||direccion<1);
             }while ((y==9&&direccion==2)||(y==0&&direccion==1)||(y==9&&direccion==4)||(y==0&&direccion==3)||(x==0&&direccion==4)||(x==0&&direccion==3)||(x==9&&direccion==1)||(x==9&&direccion==2));
           }while((direccion == 1 &&( tablero[x+1][y-1]== 'O'||tablero[x+1][y-1]== 'C') )||(direccion == 2 && (tablero[x+1][y+1]== 'O' || tablero[x+1][y+1]== 'C') )|| (direccion == 3 && (tablero[x-1][y-1]== 'O' || tablero[x-1][y-1]== 'C') )||(direccion == 4 && (tablero[x-1][y+1]== 'O' || tablero[x-1][y+1]== 'C') ));//VALIDACION PARA CASILLA OCUPADA POR UNA AMIGA
            if (direccion==1 &&( tablero[x+1][y-1] == 'X' || tablero[x+1][y-1] == 'D') )
             {
                if(y==1)
                {
                  error=1;
                }
                if(x==6)
                {
                  error=1;
                }
                if(tablero[x+2][y-2] == 'X')
                {
                  error=1;
                }
                if(tablero[x+2][y-2] == 'O')
                {
                  error=1;
                }
                if(tablero[x+2][y-2] == 'C')
                {
                  error=1;
                }
                if(tablero[x+2][y-2] == 'D')
                {
                 error=1;}
              }
             if (direccion==2 && (tablero[x+1][y+1] == 'X'||tablero[x+1][y+1] == 'D'))
              {
                if(y==6)
                {
                   error=1;
                }
                if(x==6)
                { 
                   error=1;
                }
                if(tablero[x+2][y+2] == 'X')
                {
                   error=1;
                }
                if( tablero[x+2][y+2] == 'O')
                {
                   error=1;
                }
                if( tablero[x+2][y+2] == 'C')
                {
                   error=1;
                }
                if( tablero[x+2][y+2] == 'D')
                {
                   error=1;
                }
              }
             if (direccion==3 && (tablero[x-1][y-1] == 'X'||tablero[x-1][y-1] == 'D'))
              {
                if(y==1)
                { error=1;
                }
                if(x==1)
                { error=1;
                }
                if(tablero[x-2][y-2] == 'X')
                {
                  error=1;}
                if( tablero[x-2][y-2] == 'O')
                {
                 error=1;}
                 if( tablero[x-2][y-2] == 'C')
                {
                 error=1;}
                if( tablero[x-2][y-2] == 'D')
                {
                 error=1;
                }
              }
             if (direccion==4 && (tablero[x-1][y+1] == 'X'||tablero[x-1][y+1] == 'D'))
              {
                if(y==6)
                {
                    error=1;
                }
                if(x==1)
                {
                    error=1;
                }
                if(tablero[x-2][y+2] == 'X')
                {
                    error=1;
                }
                if( tablero[x-2][y+2] == 'O')
                {
                    error=1;
                }
                if( tablero[x-2][y+2] == 'D')
                {
                    error=1;
                }
                 if( tablero[x-2][y+2] == 'C')
                {
                    error=1;
                }
             }
     }while(error==1);//VALIDACION DE MOVIMIENTO PARA ESPACION OCUPADOS
        if (tablero[x][y]=='C' && direccion == 1 && tablero[x+1][y-1]== ' ' ){
            tablero[x][y]=' ' ;
            tablero[x+1][y-1] = 'C' ;
            cout<<"LA COMPUTADORA A MOVIDO UNA FICHA A LA CASILLA "<<x+1<<"-"<<y-1 ;
            
          }
        else if (tablero[x][y]=='C' && direccion == 2 && tablero[x+1][y+1]== ' '  )
        {
            tablero[x][y]=' ' ;
            tablero[x+1][y+1] = 'C' ;
            cout<<"LA COMPUTADORA A MOVIDO UNA FICHA A LA CASILLA "<<x+1<<"-"<<y+1 ;
            
        }
        else if (tablero[x][y]=='C' && direccion == 3 && tablero[x-1][y-1]== ' '  )
        {
            tablero[x][y]=' ' ;
            tablero[x-1][y-1] = 'C' ;
            cout<<"LA COMPUTADORA A MOVIDO UNA FICHA A LA CASILLA "<<x-1<<"-"<<y-1 ;
          
        }
        else if (tablero[x][y]=='C' && direccion == 4 && tablero[x-1][y+1]== ' '  )
        {
            tablero[x][y]=' ' ;
            tablero[x-1][y+1] = 'C' ;
            cout<<"LA COMPUTADORA A MOVIDO UNA FICHA A LA CASILLA "<<x-1<<"-"<<y+1 ;
            
        }
        else if(tablero[x][y]=='C' && direccion== 1 && (tablero [x+1][y-1] == 'X'||tablero [x+1][y-1] == 'D'))
        {
            tablero[x][y]=' ' ;
            tablero[x+1][y-1]=' ' ;
            tablero[x+2][y-2]= 'C' ;
             cout<<"\a";
             cout<<"HAS COMIDO A LA FICHA CONTRARIA 'X' EN LA CASILLA   "<<x+1<<"-"<<y-1 ;
             fichax=fichax-1;
             contador_fichas_o= contador_fichas_o+3;
             
        }
        else if(tablero[x][y]=='C' && direccion== 2 && (tablero [x+1][y+1] == 'X'||tablero [x+1][y+1] == 'D'))
        {
                tablero[x][y]=' ' ;
                tablero[x+1][y+1]=' ' ;
                tablero[x+2][y+2]= 'C' ;
                 cout<<"\a";
                 cout<<"HAS COMIDO A LA FICHA CONTRARIA 'X' EN LA CASILLA   "<<x+1<<"-"<<y+1 ;
                 fichax=fichax-1;
                 contador_fichas_o= contador_fichas_o+3;
                
         }
        else if(tablero[x][y]=='C' && direccion== 3 && (tablero [x-1][y-1] == 'X'||tablero [x-1][y-1] == 'D'))
        {
                tablero[x][y]=' ' ;
                tablero[x-1][y-1]=' ' ;
                tablero[x-2][y-2]= 'C' ;
                 cout<<"\a";
                 cout<<"HAS COMIDO A LA FICHA CONTRARIA 'X' EN LA CASILLA   "<<x-1<<"-"<<y-1 ;
                 fichax=fichax-1;
                 contador_fichas_o= contador_fichas_o+3;
              
        }
        else if(tablero[x][y]=='C' && direccion== 4 && (tablero [x-1][y+1] == 'X'||tablero [x-1][y+1] == 'D'))
        {
                tablero[x][y]=' ' ;
                tablero[x-1][y+1]=' ' ;
                tablero[x-2][y+2]= 'C' ;
                 cout<<"\a";
                 cout<<"HAS COMIDO A LA FICHA CONTRARIA 'X' EN LA CASILLA   "<<x-1<<"-"<<y+1 ;
                 fichax=fichax-1;
                 contador_fichas_o= contador_fichas_o+3;
                 
        }
        else if (tablero[x][y]=='O' && direccion == 1 && tablero[x+1][y-1]== ' ' )
        {
            tablero[x][y]=' ' ;
            tablero[x+1][y-1] = 'O' ;
            cout<<"LA COMPUTADORA A MOVIDO UNA FICHA A LA CASILLA "<<x+1<<"-"<<y-1 ;
           
        }
        if (tablero[x][y]=='O' && direccion == 2 && tablero[x+1][y+1]== ' ' )
         {
            tablero[x][y]=' ' ;
            tablero[x+1][y+1] = 'O' ;
            cout<<"LA COMPUTADORA A MOVIDO UNA FICHA A LA CASILLA "<<x+1<<"-"<<y+1 ;
           
         }
        else if(tablero[x][y]=='O'&& direccion== 1 && (tablero [x+1][y-1] == 'X'||tablero [x+1][y-1] == 'D'))
         {
            tablero[x][y]=' ' ;
            tablero [x+1][y-1]= ' ' ;
            tablero[x+2][y-2]= 'O' ;
            cout<<"\a";
            cout<<"HAS COMIDO A LA FICHA CONTRARIA 'X' EN LA CASILLA  "<<x+1<<"-"<<y-1 ;
            fichax=fichax-1;
            contador_fichas_o= contador_fichas_o+3;
           
         }
        else if(tablero[x][y]=='O'&& direccion== 2 && ( tablero [x+1][y+1] == 'X'|| tablero [x+1][y+1] == 'D'))
        {
            tablero[x][y]=' ' ;
            tablero[x+1][y+1]=' ' ;
            tablero[x+2][y+2]= 'O' ;
            cout<<"\a";
            cout<<"HAS COMIDO A LA FICHA CONTRARIA 'X' EN LA CASILLA   "<<x+1<<"-"<<y+1 ;
            fichax=fichax-1;
            contador_fichas_o= contador_fichas_o+3;
           
         }
           turno = 1 ;  
}//FIN DEL VOID CPU 

int main(int argc, char** argv) {
    int seleccion ;//REPRESENTA LA SELECCION DEL MENU
    do{
        cout<<"\t*************  BENVENIDO AL JUEGO DE DAMAS CHILENA EN C++  **********\n\n\n";
        cout<<"\t\t\t  MODO CONTRA LA MAQUINA [1]\n";
        cin>>seleccion;
        system("clear");
        switch (seleccion){
            case 1:
            {
                rellenar();
                imprimir2();
                do{
                    for(i=0;i<T;i++){
                        for(j=0;j<T;j++){
                            if (tablero[i][j]=='D' && tablero[i+2][j+2]==' ' && (tablero[i+1][j+1]=='O'||tablero[i+1][j+1]=='C') && j!= 6){
                                cout<<"TU OPONENTE TE OBLIGO A COMER AUTOMATICAMENTE LA FICHA EN "<<i+1<<"-"<<j+1<<endl;
                                tablero[i][j]=' ';
                                tablero[i+1][j+1]= ' ';
                                tablero[i+2][j+2]='D' ;
                                
                                fichao=fichao-1;
                                turno=0;}
                            else if (tablero[i][j]=='D' && tablero[i+2][j-2]==' ' && (tablero[i+1][j-1]=='O'||tablero[i+1][j-1]=='C') && j!= 1)
                            {
                                cout<<"TU OPONENTE TE OBLIGO A COMER AUTOMATICAMENTE LA FICHA EN "<<i+1<<"-"<<j-1<<endl;
                                tablero[i][j]=' ';
                                tablero[i+1][j-1]= ' ';
                                tablero[i+2][j-2]='D' ;
                                
                                fichao=fichao-1;
                                turno=0;}
                            else if (tablero[i][j]=='D' && tablero[i-2][j+2]==' ' && (tablero[i-1][j+1]=='O'||tablero[i-1][j+1]=='C')  && j!= 6)
                            {
                                cout<<"TU OPONENTE TE OBLIGO A COMER AUTOMATICAMENTE LA FICHA EN "<<i-1<<"-"<<j+1<<endl;
                                tablero[i][j]=' ';
                                tablero[i-1][j+1]= ' ';
                                tablero[i-2][j+2]='D' ;
                                
                                fichao=fichao-1;
                                turno=0;}
                            else if(tablero[i][j]=='D'&& tablero[i-2][j-2]==' ' && (tablero[i-1][j-1]=='O'||tablero[i-1][j-1]=='C') && j!= 1 )
                            {
                                cout<<"TU OPONENTE TE OBLIGO A COMER AUTOMATICAMENTE LA FICHA EN "<<i-1<<"-"<<j-1<<endl;
                                tablero[i][j]=' ';
                                tablero[i-1][j-1]= ' ';
                                tablero[i-2][j-2]='D' ;
                                
                                fichao=fichao-1;
                                turno=0;}        
                            else if(tablero[i][j]=='X'&& tablero[i-2][j-2]==' ' && (tablero[i-1][j-1]=='O'||tablero[i-1][j-1]=='C') && j!= 1  )
                            {
                                cout<<"TU OPONENTE TE OBLIGO A COMER AUTOMATICAMENTE LA FICHA EN "<<i-1<<"-"<<j-1<<endl;
                                tablero[i][j]=' ';
                                tablero[i-1][j-1]= ' ';
                                tablero[i-2][j-2]='X' ;
                                
                                fichao=fichao-1;
                                turno=0;}
                            else if (tablero[i][j]=='X' && tablero[i-2][j+2]==' ' && (tablero[i-1][j+1]=='O'||tablero[i-1][j+1]=='C') && j!= 6 )
                            {
                                cout<<"TU OPONENTE TE OBLIGO A COMER AUTOMATICAMENTE LA FICHA EN "<<i-1<<"-"<<j+1<<endl;
                                tablero[i][j]=' ';
                                tablero[i-1][j+1]= ' ';
                                tablero[i-2][j+2]='X' ;
                                
                                fichao=fichao-1;
                                turno=0;}
                        }
                    }
                    if(turno==1)
                    {    
                        mover2();}
                    for (x=0;x<T;x++)// PARA IDENTIFICAR UNA DAMA
                    {
                        if(tablero[0][x]== 'X' )
                        {
                            tablero[0][x]='D';
                            cout<<"TU FICHA SE A CONVERTIDO EN DAMA SE USARA LA LETRA -D- PARA REPRESENTARLA "<<endl ;
                            
                        }
                    }// FIN DE DAMAS
                    system("clear");
                    cout<<"\t\t         ";
                    imprimir() ;
                    if (fichao==0)
                    {
                        cout<<"JUEGO TERMINADO JUGADOR UNO A GANADO ESTA PARTIDA  " <<endl;
                        terminar=2;
                        break;
                    }
                    for(i=0;i<T;i++)
                    {
                        for(j=0;j<T;j++)
                        {
                            if(tablero[i][j]=='C'&& tablero[i+2][j+2]==' ' && (tablero[i+1 ][j+1]=='X'||tablero[i+1 ][j+1]=='D') && j!=1)
                            {
                                cout<<"SE COMIO AUTOMATICAMENTE LA FICHA EN "<<i+1<<"-"<<j+1<<endl;
                                tablero[i][j]=' ';
                                tablero[i+1][j+1]= ' ';
                                tablero[i+2][j+2]='C' ;
                                
                                fichax=fichax-1;
                                turno=1;}
                            if (tablero[i][j]=='C' && tablero[i-2 ][j-2]==' ' && ( tablero[i-1][j-1]=='X'||tablero[i-1][j-1]=='D') && j!=1)
                            {
                                cout<<"SE COMIO AUTOMATICAMENTE LA FICHA EN "<<i-1<<"-"<<j-1<<endl;
                                tablero[i][j]=' ';
                                tablero[i-1][j-1]= ' ';
                                tablero[i-2][j-2]='C' ;
                                
                                fichax=fichax-1;
                                turno=1;}
                            else if (tablero[i][j]=='C' && tablero[i-2][j+2]==' ' && (tablero[i-1][j+1]=='X'||tablero[i-1][j+1]=='D') && j!=6  )
                            {
                                cout<<"SE COMIO AUTOMATICAMENTE LA FICHA EN "<<i-1<<"-"<<j+1<<endl;
                                tablero[i][j]=' ';
                                tablero[i-1][j+1]= ' ';
                                tablero[i-2][j+2]='C' ;
                                
                                fichax=fichao-1;
                                turno=1;}
                            else if (tablero[i][j]=='C' && tablero[i+2][j-2]==' ' && (tablero[i+1][j-1]=='X'||tablero[i+1][j-1]=='D') && j!=6)
                            {
                                cout<<"SE COMIO AUTOMATICAMENTE LA FICHA EN "<<i+1<<"-"<<j-1<<endl;
                                tablero[i][j]=' ';
                                tablero[i+1][j-1]= ' ';
                                tablero[i+2][j-2]='C' ;
                                
                                fichax=fichax-1;
                                turno=1;}
                            else if(tablero[i][j]=='O'&& tablero[i+2][j+2]==' ' &&( tablero[i+1][j+1]=='X'||tablero[i+1][j+1]=='D') && j!=6)
                            {
                                cout<<"SE COMIO AUTOMATICAMENTE LA FICHA EN "<<i+1<<"-"<<j+1<<endl;
                                tablero[i][j]=' ';
                                tablero[i+1][j+1]= ' ';
                                tablero[i+2][j+2]='O' ;
                                
                                fichax=fichax-1;
                                turno=1;}
                            else if (tablero[i][j]=='O' && tablero[i+2 ][j-2 ]==' ' && (tablero[i+1][j-1]=='X' ||tablero[i+1][j-1]=='D' ) && j!=1)
                            {            
                                cout<<"SE COMIO AUTOMATICAMENTE LA FICHA EN "<<i+1<<"-"<<j-1<<endl;
                                tablero[i][j]=' ';
                                tablero[i+1][j-1]= ' ';
                                tablero[i+2][j-2]='O' ;
                                
                                fichax=fichax-1;
                                turno=1;}
                        }
                    }
                    if(turno==0)
                    {
                       cpu();
                    }
                    for (x=0;x<T;x++)// PARA IDENTIFICAR UNA DAMA
                    {
                        if(tablero[9][x]== 'O' )
                        {
                            tablero[9][x]='C';
                            cout<<"LA COMPUTADORA SE A CORONADO -C- PARA REPRESENTARLA"<<endl ;
                            
                        }
                    }// FIN DE DAMAS
                    system("clear");
                    cout<<"\t\t         ";
                    for (x=0;x<T;x++)// PARA IDENTIFICAR UNA DAMA
                    {
                        if(tablero[9][x]== 'O' )
                        {
                            tablero[9][x]='C';
                        }
                    }// FIN DE DAMAS
                    imprimir() ;
                    if(fichax==0){
                        cout<<"JUEGO TERMINADO JUGADOR DOS A GANADO ESTA PARTIDA "<<endl;
                        terminar=2;
                        break;
                    }
                }while(terminar==1);
                break;
            }//FIN CASE MODO CONTRA LA COMPUTADORA
        }//FIN DE SWITCH
    }while (seleccion<=5&&seleccion>=1);
    return 0;
}
