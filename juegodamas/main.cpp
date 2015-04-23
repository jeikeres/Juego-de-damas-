/* 
 * File:   main.cpp
 * Author: Jonathan Sepulveda Nuñez
 *         17563886-5
 *         Roberto Esparza
 *         17754205-9
 *         Joaquin Astudillo
 *  
 * Created on 23 de abril de 2015, 12:32
 */

#include <iostream>
//#include <conio.h>
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
void presntacion()
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

} //FIN VOID PRESENTACION

void rellernar()
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
} //fin del void llenar o imprimir 

void mover1()
{
    do{
      do{
          do{
              do
              {
                  cout<<"turno jugador 2 fichas 0"<<endl;
                  cout<<"ingrese cordenada vertical"<<endl;
                  cin>>x;
                  cout<<"ingrese cordenada hotizontal"<<endl;
                  cin>>y;
                  if (tablero[x][y]!='0'&&tablero[x][y]!='c');
                  {
                      cout<<"error vuelva a tirar no hay ficha en la casilla"<<x<<"-"<<y<<endl;
                  }while (tablero[x][y]!='0'&&tablero[x][y]!='c');//validacion para el tiro de movimiento
                  
                  do{
                      if(tablero[x][y]!='0')
                      {
                       cout<<"";
                         
                      }
                  }
                      
              }  
           }
        }  
      }
} 