/*  File:   main.cpp
 * Author: Jonathan Sepulveda Nuñez
 *         17563886-5
 *         Roberto Esparza
 *         17754205-9
 *         Joaquin Astudillo
 *  
 * Created on 23 de abril de 2015, 12:32
 */
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
# define T 8

using namespace std;
char tablero[T][T];
char blanco=178;
char negro=177;
int i,j;
int z;
int turno=1;
int direccion;
int error;
int contador=1;
int fichao=12;
int fichax=12;
int terminar=1;
int contador_fichas_x=7;
int contador_fichas_o=7;
int x,y;
int contadorcpu;
void presentacion()
{
    for(int i=0;i<8;i++){
        cout<<endl;
        contador--;
        cout<<"\t\t\t     ";
        for(int j=0;j<8;j++){
            contador++;
            if(contador%2!=0){
                cout<<blanco<<blanco<<blanco<<blanco;
               }
            if(contador%2==0){
                cout<<negro<<negro<<negro<<negro;  
            }
        }
    }

}//FIN VOID PRESENTACION

void rellenar()
{
    for(i=0;i<T;i++)
    {
    for(j=0;j<T;j++)    
    {
      if(i<=2&&((j+i)%2==0))
      {
      tablero[i][j]='0';
       } //este if pone fichas contrarias cuando el arreglo valga 0   
    
        else if(i>5&&((j+i)%2==0) )  {
        tablero[i][j]='x';
                                     } 
        else{
        tablero[i][j]=' ' ;}
    }//fin for j // salto de linea
    }// fin for i
}//FIN DEL VOID LLENAR O IMPRIMIR

void mover1()//************
{
         do{
             do{
                 do{
                       do{
                            cout<<"TURNO JUGADOR 2 FICHAS O" <<endl ;
                            
                            cout<<"INGRESE CORDENADA VERTICAL "<<endl ;
                            cin>> x ;

                            cout<<"INGRESE COORDENADA HORIZONTAL "<<endl ;
                            cin>> y;

                            if (tablero[x][y]!='O'&&tablero[x][y]!='C')
                            {
                            cout<<"ERROR VUELVA A TIRAR NO HAY FICHA EN LA CASILLA "<<x<<"-"<<y<<endl ;}
                          }while (tablero[x][y]!='O'&&tablero[x][y]!='C');//VALIDACION PARA EL TIRO DE MOVIMIENTO
                              do{
                                  if (tablero[x][y] == 'O')
                                   {
                                             cout<<"SELECCIONE LA NUEVA POSICION DE LA FICHA [1]IZQUIERDA-ABAJO [2] DERECHA-ABAJO "<<endl ;
                                             cin>>direccion ;
                                             error=0;
                                             if(direccion>2||direccion<1)
                                              {
                                                cout<<"ERROR ESCOGA UNA OPCION VALIDA EN DIRECCION "<<endl;
                                              }

                                             if((y==0&&direccion==1)||(y==7&&direccion==2))
                                              {
                                                cout<<"ERROR LA PIEZA SALE DEL TABLERO "<<endl ;
                                              }
                                    }//FIN IF DE MOVIMIENTO

                                    if (tablero[x][y]=='C')
                                    {
                                         cout<<"SELECCIONE [1]IZQ-ABAJO [2]DER-ABAJO [3]IZQ-ARRIBA [4]DER-ARRIBA "<<endl ;
                                         cin>>direccion ;
                                         error=0;
                                         if(direccion>4||direccion<1)
                                           {
                                             cout<<"ERROR ESCOGA UNA OPCION VALIDA EN DIRECCION "<<endl;
                                           }
                                         if((y==7&&direccion==2)||(y==0&&direccion==1)||(y==7&&direccion==4)||(y==0&&direccion==3)||(x==0&&direccion==4)||(x==0&&direccion==3)||(x==7&&direccion==1)||(x==7&&direccion==2))
                                           {
                                             cout<<"ERROR NO PUEDES SALIRTE DEL TABLERO "<<endl ;
                                           }
                                    }//FIN IF DE MOVIMIENTO
                                 }while (direccion>4||direccion<1);
                    }while ((y==7&&direccion==2)||(y==0&&direccion==1)||(y==7&&direccion==4)||(y==0&&direccion==3)||(x==0&&direccion==4)||(x==0&&direccion==3)||(x==7&&direccion==1)||(x==7&&direccion==2));
                    if (direccion == 1 &&( tablero[x+1][y-1]== 'O'||tablero[x+1][y-1]== 'C') )
                    {
                        cout<<"ERROR LA CASILLA ESTA OCUPADA POR UNA FICHA AMIGA  "<<endl ;
                    }
                    if (direccion == 2 && (tablero[x+1][y+1]== 'O' || tablero[x+1][y+1]== 'C') )
                    {
                        cout<<"ERROR LA CASILLA ESTA OCUPADA POR UNA FICHA AMIGA "<<endl ;
                    }
                    if (direccion == 3 && (tablero[x-1][y-1]== 'O' || tablero[x-1][y-1]== 'C') )
                    {
                        cout<<"ERROR LA CASILLA ESTA OCUPADA POR UNA FICHA AMIGA "<<endl ;
                    }
                    if (direccion == 4 && (tablero[x-1][y+1]== 'O' || tablero[x-1][y+1]== 'C') )
                    {
                        cout<<"ERROR LA CASILLA ESTA OCUPADA POR UNA FICHA AMIGA "<<endl ;
                    }
                }while((direccion == 1 &&( tablero[x+1][y-1]== 'O'||tablero[x+1][y-1]== 'C') )||(direccion == 2 && (tablero[x+1][y+1]== 'O' || tablero[x+1][y+1]== 'C') )|| (direccion == 3 && (tablero[x-1][y-1]== 'O' || tablero[x-1][y-1]== 'C') )||(direccion == 4 && (tablero[x-1][y+1]== 'O' || tablero[x-1][y+1]== 'C') ));//VALIDACION PARA CASILLA OCUPADA POR UNA AMIGA
                if (direccion==1 &&( tablero[x+1][y-1] == 'X' || tablero[x+1][y-1] == 'D') )
                   {
                        if(y==1)
                           {
                            cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                            error=1;
                           }
                        if(x==6)
                           {
                            cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                            error=1;
                           }
                        if(tablero[x+2][y-2] == 'X')
                           {
                            cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<x+2<<"-"<<y-2<<endl;
                            error=1;
                           }
                        if(tablero[x+2][y-2] == 'O')
                           {
                            cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<x+2<<"-"<<y-2<<endl;
                            error=1;
                           }
                        if(tablero[x+2][y-2] == 'C')
                           {
                            cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<x+2<<"-"<<y-2<<endl;
                            error=1;
                           }
                        if(tablero[x+2][y-2] == 'D')
                           {
                            cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<x+2<<"-"<<y-2<<endl;
                            error=1;
                           }
                     }
                    if (direccion==2 && (tablero[x+1][y+1] == 'X'||tablero[x+1][y+1] == 'D'))
                    {
                        if(y==6)
                         {
                          cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                          error=1;
                         }
                        if(x==6)
                         {
                          cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                          error=1;
                         }
                        if(tablero[x+2][y+2] == 'X')
                         {
                          cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                          error=1;
                         }
                        if( tablero[x+2][y+2] == 'O')
                         {
                          cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                          error=1;
                         }
                        if( tablero[x+2][y+2] == 'C')
                         {
                          cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                          error=1;
                         }
                       if( tablero[x+2][y+2] == 'D')
                         {
                          cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                          error=1;}
                    }
                    if (direccion==3 && (tablero[x-1][y-1] == 'X'||tablero[x-1][y-1] == 'D'))
                      {
                        if(y==1)
                          {
                            cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                            error=1;
                          }
                         if(x==1)
                          {
                            cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
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
                             error=1;
                            }
                         if( tablero[x-2][y-2] == 'D')
                            {
                             cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                             error=1;}
                       }
                    if (direccion==4 && (tablero[x-1][y+1] == 'X'||tablero[x-1][y+1] == 'D'))
                       {
                            if(y==6)
                            {
                              cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                              error=1;
                            }
                            if(x==1)
                            {
                              cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                              error=1;
                            }
                          if(tablero[x-2][y+2] == 'X')
                            {
                              cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                              error=1;
                            }
                          if( tablero[x-2][y+2] == 'O')
                            {
                              cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                              error=1;}
                          if( tablero[x-2][y+2] == 'D')
                            {
                              cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                              error=1;
                            }
                          if( tablero[x-2][y+2] == 'C')
                            {
                              cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x+2<<"-"<<y+2<<endl;
                              error=1;} 
                        }
            }while(error==1); //VALIDACION DE MOVIMIENTO PARA ESPACION OCUPADOS

            if (tablero[x][y]=='C' && direccion == 1 && tablero[x+1][y-1]== ' ' )
             {
                tablero[x][y]=' ' ;
                tablero[x+1][y-1] = 'C' ;
             }
            else if (tablero[x][y]=='C' && direccion == 2 && tablero[x+1][y+1]== ' '  )
            {
                tablero[x][y]=' ' ;
                tablero[x+1][y+1] = 'C' ;
            }
            else if (tablero[x][y]=='C' && direccion == 3 && tablero[x-1][y-1]== ' '  )
            {
                tablero[x][y]=' ' ;
                tablero[x-1][y-1] = 'C' ;
            }
            else if (tablero[x][y]=='C' && direccion == 4 && tablero[x-1][y+1]== ' '  )
            {
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
               system ("pause");
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
                system ("pause");
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
                system ("pause");
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
                system ("pause");
             }
            else if (tablero[x][y]=='O' && direccion == 1 && tablero[x+1][y-1]== ' ' )
             {
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
                system ("pause");
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
                    system ("pause");
                }
                turno = 1 ;
}//FIN VOID MOVER *********************++
void mover2()
{
    do{
        do{
           do{
               do{
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
                     cout<<"ERROR VUELVA A TIRAR NO HAY FICHA EN LA CASILLA "<<x<<"-"<<y<<endl ;
                     }
                 }while (tablero[x][y]!='X'&&tablero[x][y]!='D');//VALIDACION PARA EL TIRO DE MOVIMIENTO
                   do{
                      if (tablero[x][y] == 'X')
                        {
                           {
                                cout<<"SELECCIONE LA NUEVA POSICION DE LA FICHA [1]IZQUIERDA-ARRIBA [2] DERECHA-ARRIBA " ;
                                cin>>direccion ;
                                error=0;
                                if(direccion>2||direccion<1)
                                 {
                                    cout<<"ERROR ESCOGA UNA OPCION VALIDA EN DIRECCION "<<endl;
                                 }
                           }
                           if((y==7&&direccion==2)||(y==0&&direccion==1))
                           {
                           cout<<"ERROR NO PUEDES SALIRTE DEL TABLERO "<<endl ;
                           }
                         }//FIN IF DE MOVIMIENTO
                         if (tablero[x][y]=='D')
                           {
                               cout<<"SELECCIONE [1]IZQ-ARRIBA [2]DER-ARRIBA [3]IZQ-ABAJO [4] DER-ABAJO " <<endl ;
                               cin>>direccion ;
                               error=0;
                               if(direccion>4||direccion<1)
                               {
                                 cout<<"ERROR ESCOGA UNA OPCION VALIDA EN DIRECCION "<<endl;
                               }
                               if((y==7&&direccion==2)||(y==0&&direccion==1)||(y==7&&direccion==4)||(y==0&&direccion==3)||(x==0&&direccion==1)||(x==0&&direccion==2)||(x==7&&direccion==3)||(x==7&&direccion==4))
                               {
                               cout<<"ERROR NO PUEDES SALIRTE DEL TABLERO "<<endl ;}
                            }// fin if
                      }while (direccion>4||direccion<1);//VALIDACION DE MOVIMIETNO PARA DIRECCION
               }while((y==7&&direccion==2)||(y==0&&direccion==1)||(y==7&&direccion==4)||(y==0&&direccion==3)||(x==0&&direccion==1)||(x==0&&direccion==2)||(x==7&&direccion==3)||(x==7&&direccion==4));//Vlidacion para no salirte del tablero
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
             {
                 cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                 error=1;
             }
             if(x==1)
             {
                 cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                 error=1;
             }
             if(tablero[x-2][y-2] == 'X')
             {        
               cout<<"NO SE PUEDE COMER LA FICHA YA QUE HAY OTRA FICHA EN LA CASILLA "<<x-2<<"-"<<y-2<<endl;
               error=1;
             }
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
                {
                    cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                    error=1;
                }
                if(x==1)
                {
                    cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                    error=1;
                }      
                if(tablero[x-2][y+2] == 'X')
                {
                    cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                    error=1;
                }
                if (tablero[x-2][y+2] == 'O')
                {
                   cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                   error=1;
                }
                if (tablero[x-2][y+2] == 'D')
                {
                   cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                   error=1;
                }
                if (tablero[x-2][y+2] == 'C')
                {
                   cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                   error=1;
                }
             }
             else if (direccion==3 && (tablero[x+1][y-1] == 'O'||tablero[x+1][y-1] == 'C'))
             {
                if(y==1)
                {
                  cout<<"ERROR TE SALES DEL TABLERO "<<endl ;if(y==1)
                   {
                       cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                       error=1;
                   }
                   error=1;
                }
                if(x==6)
                {
                    cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                    error=1;
                }
                if(tablero[x+2][y-2] == 'X')
                {
                   cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                   error=1;
                }
                if (tablero[x+2][y-2] == 'O')
                {
                   cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                   error=1;
                }
                if (tablero[x-2][y+2] == 'C')
                {
                   cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                   error=1;
                }
                if (tablero[x-2][y+2] == 'D')
                {
                   cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                   error=1;
                }
             }
             else if (direccion==4 && (tablero[x+1][y+1] == 'O'||tablero[x+1][y+1] == 'C'))
             {
                if(y==6)
                {
                   cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                   error=1;
                }
                if(x==6)
                { 
                    cout<<"ERROR TE SALES DEL TABLERO "<<endl ;
                    error=1;
                }
                if(tablero[x+2][y+2] == 'X')
                {
                    cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                    error=1;
                }
                if (tablero[x+2][y+2] == 'O')
                {
                    cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                    error=1;
                }
                if (tablero[x+2][y+2] == 'D')
                  {
                    cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                    error=1;
                  }
                if (tablero[x+2][y+2] == 'C')
                {
                    cout<<"ERROR NO SE PUEDE COMER UNA FICHA YA QUE LA POSICION ESTA OCUPADA "<<endl;
                    error=1;
                }
             }
      }while(error==1); //VALIDACION DE MOVIMIENTO PARA ESPACION OCUPADOS CUANDO SE VA A COMER
        if(tablero[x][y]== 'D' && direccion==1 && tablero[x-1][y-1]== ' '  )
        {
            tablero[x][y]= ' ';
            tablero[x-1][y-1]= 'D';
        }
        else if (tablero[x][y]=='D'&& direccion == 2 && tablero[x-1][y+1]== ' ' )
        {
            tablero[x][y]=' ' ;
            tablero[x-1][y+1] = 'D' ;
        }
        else if (tablero[x][y]=='D'&& direccion == 3 && tablero[x+1][y-1]== ' ' )
        {
            tablero[x][y]=' ' ;
            tablero[x+1][y-1] = 'D' ;
        }
        else if (tablero[x][y]=='D'&& direccion == 4 && tablero[x+1][y+1]== ' ' )
        {
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
            system ("pause");
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
             system ("pause");
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
             system ("pause");
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
             system (pause);}
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
             system ("pause");
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
               system ("pause");
        }//FIN DE ELSE IF
           turno = 0 ;  
}//FIN VOID MOVER 2 +********************
void imprimir()
{
   for(z=0;z<T;z++)
     {//INICIO DEL FOR Z QUE SIRVE PARA INDICAR LAS CORDENADAS HORIZONTALES
           cout<<z<<"    ";
     }//FIN DEL FOR Z
           cout<<endl;
     for(i=0;i<T;i++)
     {
        cout<<"\t\t       ";
        cout<<i;//ESTA I SIRVE PARA INDICAR COORDENADAS VERTICALES
        for(j=0;j<T;j++)
         {
            if((tablero[i][j]=='X'||tablero[i][j]=='O'||tablero[i][j]=='C'||tablero[i][j]=='D')&&((j+i)%2==0))
            {
             cout<<blanco<<blanco<<tablero[i][j]<<blanco<<blanco; 
            }
            else if (tablero[i][j]==' ' && (j+i)%2!=0)
            {
               cout<<negro<<negro<<negro<<negro<<negro;
            }
            else if (tablero[i][j]==' ' &&(j+i)%2==0)
            {
             cout<<blanco<<blanco<<blanco<<blanco<<blanco; ;
            }
         }/*FIN FOR J */cout<<endl;  //SALTO DE LINEA
     }//FIN FOR I
 }//FIN VOID RE IMPRIMIR ******************
void cpu ()
{
   cout<<"TURNO COMPUTADORA PENSANDO JUGADA...." <<endl ;    
    do{
        do{
           do{
               do{
                    srand(time(NULL));
                    x=rand() % 7+0 ;
                    y=rand() % 7+0 ;
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
             }while ((y==7&&direccion==2)||(y==0&&direccion==1)||(y==7&&direccion==4)||(y==0&&direccion==3)||(x==0&&direccion==4)||(x==0&&direccion==3)||(x==7&&direccion==1)||(x==7&&direccion==2));
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
            system ("pause");
          }
        else if (tablero[x][y]=='C' && direccion == 2 && tablero[x+1][y+1]== ' '  )
        {
            tablero[x][y]=' ' ;
            tablero[x+1][y+1] = 'C' ;
            cout<<"LA COMPUTADORA A MOVIDO UNA FICHA A LA CASILLA "<<x+1<<"-"<<y+1 ;
            system ("pause");
        }
        else if (tablero[x][y]=='C' && direccion == 3 && tablero[x-1][y-1]== ' '  )
        {
            tablero[x][y]=' ' ;
            tablero[x-1][y-1] = 'C' ;
            cout<<"LA COMPUTADORA A MOVIDO UNA FICHA A LA CASILLA "<<x-1<<"-"<<y-1 ;
            system ("pause");
        }
        else if (tablero[x][y]=='C' && direccion == 4 && tablero[x-1][y+1]== ' '  )
        {
            tablero[x][y]=' ' ;
            tablero[x-1][y+1] = 'C' ;
            cout<<"LA COMPUTADORA A MOVIDO UNA FICHA A LA CASILLA "<<x-1<<"-"<<y+1 ;
            system ("pause");
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
             system ("pause");
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
                 system ("pause");
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
                 system ("pause");
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
                 system ("pause");
        }
        else if (tablero[x][y]=='O' && direccion == 1 && tablero[x+1][y-1]== ' ' )
        {
            tablero[x][y]=' ' ;
            tablero[x+1][y-1] = 'O' ;
            cout<<"LA COMPUTADORA A MOVIDO UNA FICHA A LA CASILLA "<<x+1<<"-"<<y-1 ;
            system ("pause");
        }
        if (tablero[x][y]=='O' && direccion == 2 && tablero[x+1][y+1]== ' ' )
         {
            tablero[x][y]=' ' ;
            tablero[x+1][y+1] = 'O' ;
            cout<<"LA COMPUTADORA A MOVIDO UNA FICHA A LA CASILLA "<<x+1<<"-"<<y+1 ;
            system ("pause");
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
            system ("pause");
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
            system ("pause");
         }
           turno = 1 ;  
}//FIN DEL VOID CPU *********************

int main( )//MENU
{
    int seleccion ;//REPRESENTA LA SELECCION DEL MENU
    system("color B") ;
    cout<<"\n\n\n\n ";
       cout<<"\t     ---------BIENVENIDO AL JUEGO DE DAMAS INGLESAS EN C++--------\n\n\n";
       cout<<"\n                * * * * * * * *   PRESIONA START  * * * * * * * *\n" ;
       presentacion() ;
    cout<<"\n\n\n\n ";
    cout<<"\t\t 2011 copyright \251AsA Todos los Derechos Reservados";
    system (pause);
    system ("cls");
      do{  
            system("color 7");
               cout<<"\t***************BENVENIDO AL JUEGO DE DAMAS EN C++**************\n\n\n";
               cout<<"\t\t\t  MODO NORMAL JUEGO 2-JUGADORES  [1]\n";
               cout<<"\t\t\t  MODO ESPECIAL  [2]\n";
               cout<<"\t\t\t  CONTRA COMPUTADORA [3]\n ";
               cout<<"\t\t\t  LEER MANUAL [4]\n ";
               cout<<"\t\t\t  OPCIONES [5]\n ";
               cout<<"\t\t\t  SALIR [6]"<<endl;
               cin>>seleccion;
            system("CLS");
            switch (seleccion)
                {
                case 1://*********************
                  {
                   cout<<"\t\t         ";
                   system("color 0E") ;
                   rellenar();
                   imprimir() ;
                   do{
                      for(i=0;i<T;i++)
                        {
                            for(j=0;j<T;j++)
                            {
                                    if (tablero[i][j]=='D' && tablero[i+2][j+2]==' ' && (tablero[i+1][j+1]=='O'||tablero[i+1][j+1]=='C') && j!= 6)
                                     {
                                          cout<<"TU OPONENTE TE OBLIGO A COMER AUTOMATICAMENTE LA FICHA EN "<<i+1<<"-"<<j+1<<endl;
                                          tablero[i][j]=' ';
                                          tablero[i+1][j+1]= ' ';
                                          tablero[i+2][j+2]='D' ;
                                          system ("pause");
                                          fichao=fichao-1;
                                          turno=0;
                                    }
                                    else if (tablero[i][j]=='D' && tablero[i+2][j-2]==' ' && (tablero[i+1][j-1]=='O'||tablero[i+1][j-1]=='C') && j!= 1)
                                    {
                                          cout<<"TU OPONENTE TE OBLIGO A COMER AUTOMATICAMENTE LA FICHA EN "<<i+1<<"-"<<j-1<<endl;
                                          tablero[i][j]=' ';
                                          tablero[i+1][j-1]= ' ';
                                          tablero[i+2][j-2]='D' ;
                                          system ("pause");
                                          fichao=fichao-1;
                                          turno=0;
                                    }      
                                    else if (tablero[i][j]=='D' && tablero[i-2][j+2]==' ' && (tablero[i-1][j+1]=='O'||tablero[i-1][j+1]=='C')  && j!= 6)
                                    {
                                          cout<<"TU OPONENTE TE OBLIGO A COMER AUTOMATICAMENTE LA FICHA EN "<<i-1<<"-"<<j+1<<endl;
                                          tablero[i][j]=' ';
                                          tablero[i-1][j+1]= ' ';
                                          tablero[i-2][j+2]='D' ;
                                          system ("pause");
                                          fichao=fichao-1;
                                          turno=0;
                                    }      
                                    else if(tablero[i][j]=='D'&& tablero[i-2][j-2]==' ' && (tablero[i-1][j-1]=='O'||tablero[i-1][j-1]=='C') && j!= 1 )
                                    {
                                          cout<<"TU OPONENTE TE OBLIGO A COMER AUTOMATICAMENTE LA FICHA EN "<<i-1<<"-"<<j-1<<endl;
                                          tablero[i][j]=' ';
                                          tablero[i-1][j-1]= ' ';
                                          tablero[i-2][j-2]='D' ;
                                          system ("pause");
                                          fichao=fichao-1;
                                          turno=0;
                                    }        
                                   else if(tablero[i][j]=='X'&& tablero[i-2][j-2]==' ' && (tablero[i-1][j-1]=='O'||tablero[i-1][j-1]=='C') && j!= 1  )
                                    {
                                      cout<<"TU OPONENTE TE OBLIGO A COMER AUTOMATICAMENTE LA FICHA EN "<<i-1<<"-"<<j-1<<endl;
                                      tablero[i][j]=' ';
                                      tablero[i-1][j-1]= ' ';
                                      tablero[i-2][j-2]='X' ;
                                      system ("pause");
                                      fichao=fichao-1;
                                      turno=0;
                                    }
                                   else if (tablero[i][j]=='X' && tablero[i-2][j+2]==' ' && (tablero[i-1][j+1]=='O'||tablero[i-1][j+1]=='C') && j!= 6 )
                                  {
                                      cout<<"TU OPONENTE TE OBLIGO A COMER AUTOMATICAMENTE LA FICHA EN "<<i-1<<"-"<<j+1<<endl;
                                      tablero[i][j]=' ';
                                      tablero[i-1][j+1]= ' ';
                                      tablero[i-2][j+2]='X' ;
                                      system ("pause");
                                      fichao=fichao-1;
                                      turno=0;}
                            }
                        }
                        if(turno==1)
                        {    
                          mover2();
                        }
                        for (x=0;x<T;x++)// PARA IDENTIFICAR UNA DAMA
                        {
                            if(tablero[0][x]== 'X' )
                            {
                                tablero[0][x]='D';
                                cout<<"TU FICHA SE A CONVERTIDO EN DAMA SE USARA LA LETRA -D- PARA REPRESENTARLA "<<endl ;
                                system ("pause");
                            }
                        }// FIN DE DAMAS
                                        system("CLS");
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
                                        system ("pause");
                                        fichax=fichax-1;
                                        turno=1;}
                                        if (tablero[i][j]=='C' && tablero[i-2 ][j-2]==' ' && ( tablero[i-1][j-1]=='X'||tablero[i-1][j-1]=='D') && j!=1)
                                        {
                                        cout<<"SE COMIO AUTOMATICAMENTE LA FICHA EN "<<i-1<<"-"<<j-1<<endl;
                                        tablero[i][j]=' ';
                                        tablero[i-1][j-1]= ' ';
                                        tablero[i-2][j-2]='C' ;
                                        system ("pause");
                                        fichax=fichax-1;
                                        turno=1;}
                                        else if (tablero[i][j]=='C' && tablero[i-2][j+2]==' ' && (tablero[i-1][j+1]=='X'||tablero[i-1][j+1]=='D') && j!=6  )
                                        {
                                        cout<<"SE COMIO AUTOMATICAMENTE LA FICHA EN "<<i-1<<"-"<<j+1<<endl;
                                        tablero[i][j]=' ';
                                        tablero[i-1][j+1]= ' ';
                                        tablero[i-2][j+2]='C' ;
                                        system ("pause");
                                        fichax=fichao-1;
                                        turno=1;}
                                        else if (tablero[i][j]=='C' && tablero[i+2][j-2]==' ' && (tablero[i+1][j-1]=='X'||tablero[i+1][j-1]=='D') && j!=6)
                                        {
                                        cout<<"SE COMIO AUTOMATICAMENTE LA FICHA EN "<<i+1<<"-"<<j-1<<endl;
                                        tablero[i][j]=' ';
                                        tablero[i+1][j-1]= ' ';
                                        tablero[i+2][j-2]='C' ;
                                        system ("pause");
                                        fichax=fichax-1;
                                        turno=1;}
                                        else if(tablero[i][j]=='O'&& tablero[i+2][j+2]==' ' &&( tablero[i+1][j+1]=='X'||tablero[i+1][j+1]=='D') && j!=6)
                                        {
                                        cout<<"SE COMIO AUTOMATICAMENTE LA FICHA EN "<<i+1<<"-"<<j+1<<endl;
                                        tablero[i][j]=' ';
                                        tablero[i+1][j+1]= ' ';
                                        tablero[i+2][j+2]='O' ;
                                        system ("pause");
                                        fichax=fichax-1;
                                        turno=1;}
                                        else if (tablero[i][j]=='O' && tablero[i+2 ][j-2 ]==' ' && (tablero[i+1][j-1]=='X' ||tablero[i+1][j-1]=='D' ) && j!=1)
                                        {            
                                        cout<<"SE COMIO AUTOMATICAMENTE LA FICHA EN "<<i+1<<"-"<<j-1<<endl;
                                        tablero[i][j]=' ';
                                        tablero[i+1][j-1]= ' ';
                                        tablero[i+2][j-2]='O' ;
                                        system ("pause");
                                        fichax=fichax-1;
                                        turno=1;}
                                        }
                                        }
                                        if(turno==0)
                                        {
                                        mover1();}
                                         for (x=0;x<T;x++)// PARA IDENTIFICAR UNA DAMA
                                        {
                                        if(tablero[7][x]== 'O' )
                                        {
                                        tablero[7][x]='C';
                                        cout<<"TU FICHA SE A CONVERTIDO EN DAMA SE USARA LA LETRA -C- PARA REPRESENTARLA "<<endl ;
                                        system ("pause");
                                        }
                                        }// FIN DE DAMAS
                                        system("CLS");
                                        cout<<"\t\t         ";
                                         for (x=0;x<T;x++)// PARA IDENTIFICAR UNA DAMA
                                        {
                                        if(tablero[7][x]== 'O' )
                                        {
                                        tablero[7][x]='C';
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
                                        }//COMENZAR JUEGO**************************************************************************************************************************
                case 2 :
                                        {
                                               cout<<"\t\t         ";
                                          system("color F") ;
                                        rellenar();
                                        imprimir() ;
                                        do
                                        {
                                        if (turno==1)
                                        {        
                                        mover2();}
                                        contador_fichas_x= contador_fichas_x-1;
                                        cout<<"JUGADOR 1 LE QUEDAN "<<contador_fichas_x<<" TURNOS "<<endl;
                                        system ("pause");
                                         for (x=0;x<T;x++)// PARA IDENTIFICAR UNA DAMA
                                        {
                                        if(tablero[0][x]== 'X' )
                                        {
                                        tablero[0][x]='D';
                                        cout<<"TU FICHA SE A CONVERTIDO EN DAMA SE USARA LA LETRA -D- PARA REPRESENTARLA "<<endl ;
                                        system ("pause");
                                        }
                                        }// FIN DE DAMAS
                                        system("CLS");
                                        cout<<"\t\t         ";
                                        imprimir() ;
                                        if (fichao==0)
                                            {
                                            cout<<"JUEGO TERMINADO JUGADOR UNO A GANADO ESTA PARTIDA  " <<endl;
                                            terminar=1;
                                            break;
                                        }
                                        else if (contador_fichas_x==0)
                                            {
                                            cout<<"JUEGO TERMINADO JUGADOR UNO A GANADO ESTA PARTIDA  " <<endl;
                                            terminar=1;
                                            break;
                                        }
                                        if(turno==0)
                                        {
                                        mover1();}
                                        contador_fichas_o = contador_fichas_o - 1;
                                        cout<<"JUGADOR DOS LE QUEDAN "<<contador_fichas_o<<" TURNOS "<<endl;
                                        system ("pause");
                                         for (x=0;x<T;x++)// PARA IDENTIFICAR UNA DAMA
                                        {
                                        if(tablero[7][x]== 'O' )
                                        {
                                        tablero[7][x]='C';
                                        cout<<"TU FICHA SE A CONVERTIDO EN DAMA SE USARA LA LETRA -C- PARA REPRESENTARLA "<<endl ;
                                        system ("pause");
                                        }
                                        }// FIN DE DAMAS
                                        system("CLS");
                                        cout<<"\t\t         ";
                                        imprimir() ;
                                         if(fichax==0){
                                             cout<<"JUEGO TERMINADO JUGADOR DOS A GANADO ESTA PARTIDA "<<endl;
                                             terminar=1;
                                             break;
                                             }
                                        else if (contador_fichas_o==0)
                                            {
                                            cout<<"JUEGO TERMINADO JUGADOR DOS A GANADO ESTA PARTIDA  " <<endl;
                                            terminar=1;
                                            break;
                                        }
                                        }while(terminar=2);
                                         }//OPCIONES DEL JUEGO *************************************************************************************************************
                                        break;
                case 3:
                {
                    cout<<"\t\t         ";
                    system("color 0A") ;
                    rellenar();
                    imprimir() ;
                    do{
                        for(i=0;i<T;i++)
                        {
                         for(j=0;j<T;j++)
                          {
                            if (tablero[i][j]=='D' && tablero[i+2][j+2]==' ' && (tablero[i+1][j+1]=='O'||tablero[i+1][j+1]=='C') && j!= 6)
                                 {
                                    cout<<"LA COMPUTADORA TE OBLIGO A COMER SU FICHA EN "<<i+1<<"-"<<j+1<<endl;
                                    tablero[i][j]=' ';
                                    tablero[i+1][j+1]= ' ';
                                    tablero[i+2][j+2]='D' ;
                                    system ("pause");
                                    fichao=fichao-1;
                                    turno=0;
                                 }
                                 else if (tablero[i][j]=='D' && tablero[i+2][j-2]==' ' && (tablero[i+1][j-1]=='O'||tablero[i+1][j-1]=='C') && j!= 1)
                                  {
                                    cout<<"LA COMPUTADORA TE OBLIGO A COMER SU FICHA EN "<<i+1<<"-"<<j-1<<endl;
                                    tablero[i][j]=' ';
                                    tablero[i+1][j-1]= ' ';
                                    tablero[i+2][j-2]='D' ;
                                    system ("pause");
                                    fichao=fichao-1;
                                    turno=0;
                                 }      
                                 else if (tablero[i][j]=='D' && tablero[i-2][j+2]==' ' && (tablero[i-1][j+1]=='O'||tablero[i-1][j+1]=='C')  && j!= 6)
                                 {
                                    cout<<"LA COMPUTADORA TE OBLIGO A COMER SU FICHA EN "<<i-1<<"-"<<j+1<<endl;
                                    tablero[i][j]=' ';
                                    tablero[i-1][j+1]= ' ';
                                    tablero[i-2][j+2]='D' ;
                                    system ("pause");
                                    fichao=fichao-1;
                                    turno=0;
                                 }      
                                 else if(tablero[i][j]=='D'&& tablero[i-2][j-2]==' ' && (tablero[i-1][j-1]=='O'||tablero[i-1][j-1]=='C') && j!= 1 )
                                 {
                                    cout<<"LA COMPUTADORA TE OBLIGO A COMER SU FICHA EN "<<i-1<<"-"<<j-1<<endl;
                                    tablero[i][j]=' ';
                                    tablero[i-1][j-1]= ' ';
                                    tablero[i-2][j-2]='D' ;
                                    system ("pause");
                                    fichao=fichao-1;
                                    turno=0;
                                 }        
                                 else if(tablero[i][j]=='X'&& tablero[i-2][j-2]==' ' && (tablero[i-1][j-1]=='O'||tablero[i-1][j-1]=='C') && j!= 1  )
                                 {
                                    cout<<"LA COMPUTADORA TE OBLIGO A COMER SU FICHA EN "<<i-1<<"-"<<j-1<<endl;
                                    tablero[i][j]=' ';
                                    tablero[i-1][j-1]= ' ';
                                    tablero[i-2][j-2]='X' ;
                                    system ("pause");
                                    fichao=fichao-1;
                                    turno=0;
                                 }
                                 else if (tablero[i][j]=='X' && tablero[i-2][j+2]==' ' && (tablero[i-1][j+1]=='O'||tablero[i-1][j+1]=='C') && j!= 6 )
                                 {
                                    cout<<"LA COMPUTADORA TE OBLIGO A COMER SU FICHA EN "<<i-1<<"-"<<j+1<<endl;
                                    tablero[i][j]=' ';
                                    tablero[i-1][j+1]= ' ';
                                    tablero[i-2][j+2]='X' ;
                                    system ("pause");
                                    fichao=fichao-1;
                                    turno=0;
                                 }
                          }
                        }
                        if(turno==1)
                        {    
                         mover2();
                        }
                           for (x=0;x<T;x++)// PARA IDENTIFICAR UNA DAMA
                           {
                                if(tablero[0][x]== 'X' )
                                {
                                 tablero[0][x]='D';
                                 cout<<"TU FICHA SE A CONVERTIDO EN DAMA SE USARA LA LETRA -D- PARA REPRESENTARLA "<<endl ;
                                 system ("pause");
                                }
                           }// FIN DE DAMAS
                           system("CLS");
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
                                            cout<<"LA COMPUTADORA COMIO TU FICHA EN"<<i+1<<"-"<<j+1<<endl;
                                            tablero[i][j]=' ';
                                            tablero[i+1][j+1]= ' ';
                                            tablero["pause");
                                            fichax=fichax-1;
                                            turno=1;
                                        }
                                        if (tablero[i][j]=='C' && tablero[i-2 ][j-2]==' ' && ( tablero[i-1][j-1]=='X'||tablero[i-1][j-1]=='D') && j!=1)
                                        {
                                            cout<<"LA COMPUTADORA COMIO TU FICHA EN "<<i-1<<"-"<<j-1<<endl;
                                            tablero[i][j]=' ';
                                            tablero[i-1][j-1]= ' ';
                                            tablero[i-2][j-2]='C' ;
                                            system ("pause");
                                            fichax=fichax-1;
                                            turno=1;
                                        }
                                        else if (tablero[i][j]=='C' && tablero[i-2][j+2]==' ' && (tablero[i-1][j+1]=='X'||tablero[i-1][j+1]=='D') && j!=6  )
                                        {
                                            cout<<"LA COMPUTADORA COMIO TU FICHA EN "<<i-1<<"-"<<j+1<<endl;
                                            tablero[i][j]=' ';
                                            tablero[i-1][j+1]= ' ';
                                            tablero[i-2][j+2]='C' ;
                                            system ("pause");
                                            fichax=fichax-1;
                                            turno=1;
                                        }
                                        else if (tablero[i][j]=='C' && tablero[i+2][j-2]==' ' && (tablero[i+1][j-1]=='X'||tablero[i+1][j-1]=='D') && j!=6)
                                        {
                                            cout<<"LA COMPUTADORA COMIO TU FICHA EN "<<i+1<<"-"<<j-1<<endl;
                                            tablero[i][j]=' ';
                                            tablero[i+1][j-1]= ' ';
                                            tablero[i+2][j-2]='C' ;
                                            system ("pause");
                                            fichax=fichax-1;
                                            turno=1;
                                        }
                                        else if(tablero[i][j]=='O'&& tablero[i+2][j+2]==' ' &&( tablero[i+1][j+1]=='X'||tablero[i+1][j+1]=='D') && j!=6)
                                        {
                                            cout<<"LA COMPUTADORA COMIO TU FICHA EN "<<i+1<<"-"<<j+1<<endl;
                                            tablero[i][j]=' ';
                                            tablero[i+1][j+1]= ' ';
                                            tablero[i+2][j+2]='O' ;
                                            system ("pause");
                                            fichax=fichax-1;
                                            turno=1;
                                        }
                                        else if (tablero[i][j]=='O' && tablero[i+2 ][j-2 ]==' ' && (tablero[i+1][j-1]=='X' ||tablero[i+1][j-1]=='D' ) && j!=1)
                                        {            
                                            cout<<"LA COMPUTADORA COMIO TU FICHA EN "<<i+1<<"-"<<j-1<<endl;
                                            tablero[i][j]=' ';
                                            tablero[i+1][j-1]= ' ';
                                            tablero[i+2][j-2]='O' ;
                                           system ("pause");
                                            fichax=fichax-1;
                                            turno=1;
                                        }
                                     }
                                 }
                                 if(turno==0)
                                   {
                                    cpu();
                                   }
                                   for (x=0;x<T;x++)// PARA IDENTIFICAR UNA DAMA
                                     {
                                       if(tablero[7][x]== 'O' )
                                        {
                                            tablero[7][x]='C';
                                            cout<<"LA COMPUTADORA SE A CORONADO -C- PARA REPRESENTARLA "<<endl ;
                                            system ("pause");
                                        }
                                     }// FIN DE DAMAS
                                     system("CLS");
                                     cout<<"\t\t         ";
                                     for (x=0;x<T;x++)// PARA IDENTIFICAR UNA DAMA
                                       {
                                            if(tablero[7][x]== 'O' )
                                             {
                                              tablero[7][x]='C';
                                             }
                                        }// FIN DE DAMAS
                                        imprimir() ;
                                        if(fichax==0)
                                        {
                                             cout<<"JUEGO TERMINADO COMPUTADORA A  GANADO ESTA PARTIDA "<<endl;
                                             terminar=2;
                                             break;
                                        }
                                        }while(terminar==1);
                                         break ; 
                 }//FIN CASE MODO CONTRA LA COMPUTADORA
                case 4:
                {
                    cout<<"\t********************MODO DE JUEGO NORMAL********************** "<<endl;
                    cout<<"\n";
                    cout<<"INSTRUCCIONES PARA JUGAR A DAMAS EN C++ LA PARTIDA COMENZARA CON LAS FICHAS 'X'"<<endl;
                    cout<<"PARA HACER UN MOVIMIENTO DEBE SELECCIONAR PRIMERO LA COORDENADA VERTICAL, Y "<<endl;
                    cout<<"DESPUES LA COORDENADA HORIZONTAL, CASO DE NO HABER FICHA SE TE VOLVERA A PEDIR"<<endl;
                    cout<<"QUE VUELVAS A TIRAR PARA SELECCIONAR EL MOVIMIENTO DE LA FICHA PERSIONA [1]"<<endl;
                    cout<<"PARA MOVERLA DIAGONALMENTE IZQUIERDA O [2] PARA DIAGONAL DERECHA"<<endl;
                    cout<<"EL JUEGO TERMINA CUANDO YA NO HAIGA FICHAS CONTRARIAS QUE COMER."<<endl;
                    cout<<"\n";
                    cout<<"\t********************MODO DE JUEGO ESPECIAL******************** "<<endl;
                    cout<<"\n";
                    cout<<"TE HAS ABURRIDO DEL MODO NORMAL PRUEBA EL MODO ESPECIAL DONDE LOS JUGADORES "<<endl;
                    cout<<"EMPIEZAN CON 7 TURNOS DE JUEGO, ADEMAS NO HAY REGLAS AQUI, CUANDO LOS JUGADORES"<<endl;
                    cout<<"TERMINAR UN MOVIMIENTO ESTOS SE REDUCEN EN UNO SI LOS TURNOS DE UN JUGADOR"<<endl;
                    cout<<"LLEGAN A 0 LA PARTIDA FINALIZA AUTOMATICAMENTE O SI YA NO HAY FICHAS QUE COMER "<<endl;
                    cout<<"DANDO POR GANADOR AL JUGADOR QUE AUN TENGA CONTADORES , PERO NO TE PREOCUPES"<<endl;
                    cout<<"PORQUE SI LLEGAS A COMER UNA FICHA CONTRARIA AUMENTARAS TUS CONTADORES EN DOS  "<<endl;
                    cout<<"POR CADA FICHA CONTRARIA COMIDA ,ASI QUE PREPARA TUS MEJORES JUGADAS Y "<<endl;
                    cout<<"ESTRATEGIAS Y NO DEJES QUE EL JUGADOR CONTRARIO GANE ESTA PARTIDA. "<<endl;
                    cout<<"\n"<<endl;
                    cout<<"CONSEJOS: SI ESTAS CANSADO DE QUE LOS CONTADORES PARA EL MODO ESPECIAL"<<endl;
                    cout<<"SIEMPRE SEAN LOS MISMOS NO TE PREOCUPES EN EL MENU EN LA PARTE DE OPCIONES  "<<endl;
                    cout<<"PUEDES MODIFICAR LOS CONTADORES DE INICIO PARA CADA JUGADOR."<<endl;
                    cout<<"\n";
                    cout<<"\t********************MODO VS COMPUTADORA ******************** "<<endl;
                    cout<<"\n";
                    cout<<"SI NO TIENES CON QUIEN JUGAR EN ESTE MODO PODRAS SIMULAR UN JUEGO "<<endl;
                    cout<<"CONTRA LA COMPUTADORA PARA PRACTICAR TUS JUGADAS "<<endl ;
                    system ("pause");
                    system("CLS");
                }
                break;
                case 5 :
                {
                 do{
                        cout<<"SELECCIONA LA CANTIDAD DE TURNOSPARA AMBOS JUGADORES "<<endl;
                        cout<<"TURNOS PARA JUGADOR 1 "<<endl;
                        cin>>contador_fichas_x;
                    if(contador_fichas_x<1)
                    {
                        cout<<"ERROR INTRODUCE UN NUMERO VALIDO MAYOR A 0 "<<endl;
                        system ("pause");
                        system("CLS");
                    }
                    }while(contador_fichas_x<1);
                    do
                    {
                        cout<<"TURNOS PARA JUGADOR 2 "<<endl;
                        cin>>contador_fichas_o;
                    if(contador_fichas_o<1)
                    {
                        cout<<"ERROR INTRODUCE UN NUMERO VALIDO MAYOR A 0 "<<endl;
                        system ("pause");
                        system("CLS");
                    }
                    }while(contador_fichas_o<1);
                        system("CLS");
                    }
                    break ;
                 }//FIN DE SWITCH
        }while (seleccion<=5&&seleccion>=1);
    system("pause");
}