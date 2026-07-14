#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#define BOARD_SIZE 9

bool load_board(sudoku *board, const char *filename){
    //1. Abro el archivo.
    FILE *archivo = fopen(filename, "r");
    //2. Compruebo que el archivo se abrio sin ningun error.
    if (archivo == NULL){
        printf("Error: no se pudo leer el archivo- \n");
        return false;
    }
    //3. Aca controlamos la integridad de las columnas y filas
    int columnas = 0;
    int filas = 0;
    int caracter;
    while ((caracter = fgetc(archivo)) != EOF){
        if((caracter < '0' || caracter > '9') && caracter != '\n' && caracter != '\r'){
            printf("Error: Caracteres no validos.\n");
            fclose(archivo);
            return false;
        }
        //3.1 Si caracter es (\n) o (\r) es lo que le dice a fgetc que salte de linea, no cuenta como columna
        if(caracter != '\n' && caracter != '\r'){
        columnas ++;
        }
        //3.2 Mientras caracter sea \n puedo ver si la cnatidad de columnas es 9 o no
        if(caracter == '\n'){
            if(columnas!=BOARD_SIZE){
            printf("Error: Cantidad de columnas invalidas. \n");
            fclose(archivo);
            return false;
            }
            columnas = 0;
            filas ++;
        }
        if(columnas>BOARD_SIZE){
            printf("Error: Cantidad de columnas invalidas. \n");
            fclose(archivo);
            return false;
        }
        if(filas>BOARD_SIZE){
            printf("Error: Cantidad de filas invalidas. \n");
            fclose(archivo);
            return false;
        }
    }
    //4. Le sumo la ultima fila si existe.
        if(columnas == BOARD_SIZE){
            filas ++;
        }
    //5. Una vez terminado el bucle while puedo verificar que la cantidad de filas es 9
    if(filas !=BOARD_SIZE){
        printf("Error: Cantidad de filas invalidas. \n");
        fclose(archivo);
        return false;
    }
    //6. Segunda pasada: copiamos el tablero ya validado a la estructura del sudoku
    rewind(archivo);
    columnas = 0;
    filas = 0;
    while((caracter = fgetc(archivo)) != EOF){
        if(caracter != '\n' && caracter != '\r'){
        board -> cells[filas][columnas] = caracter - '0';
        columnas ++;
        }
        if(columnas == BOARD_SIZE){
            filas ++;
            columnas = 0;
        }
    } 
    fclose(archivo);
    return true;
}
void print_board(const sudoku *board){
    for (int f = 0; f < BOARD_SIZE; f++ ){
        if(f % 3 == 0 && f != 0){
            printf("---+---+---\n");
        }   
        for(int c = 0; c < BOARD_SIZE; c++){
            if(c != 0){
              if(c % 3 == 0){
                printf("|");
            }}
            if(board -> cells[f][c] == 0){
                printf(".");
            }else{
            printf("%d", board -> cells[f][c]);}
        } printf("\n");
    } 
}