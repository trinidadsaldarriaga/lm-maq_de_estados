//ejercicio 1 fsm escalera
#include <stdio.h>
#include <stdint.h>
enum{
    ESTADO_NO_PRESIONADO,
    ESTADO_CONTANDO,
    ESTADO_ESPERO_LIBERACION,
};
//tengo el estado donde no presiono el botón (botón=0), donde espero 20ms para 
//ver si es con rebote, y el estado al que se pasa si no hay rebote (botón=1)

void Inicializar (void);
uint8_t estado;
uint8_t boton;
uint8_t contador;//ms

int main()
{
   
   estado = ESTADO_NO_PRESIONADO; //inicializo
   boton = 0;
}

int FSM_antirrebote(){
    switch (estado){
    case ESTADO_NO_PRESIONADO:
        if (boton == 1)
            estado = ESTADO_CONTANDO;
        else
            estado = ESTADO_NO_PRESIONADO;
    break;

    case ESTADO_CONTANDO:
        if (contador == 20){
            if(boton == 1){
                estado = ESTADO_ESPERO_LIBERACION;
        }
            else{
                estado = ESTADO_NO_PRESIONADO; //rebote
            }
        }
        else if (contador<20){
            contador = contador + 1;
            estado = ESTADO_CONTANDO;
        }
    break;
    

    case ESTADO_ESPERO_LIBERACION:
        if (boton == 0){
            estado = ESTADO_NO_PRESIONADO;
        }
        else {
            estado = ESTADO_ESPERO_LIBERACION;
        }
    break;
    
    default:
        Inicializar();
    }
}
