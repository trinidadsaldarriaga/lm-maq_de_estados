
//ejercicio 1 fsm escalera
#include <stdio.h>
#include <stdint.h>
#define OK "TRUE"
#define ERROR "FALSE"
enum{
    ESTADO_INICIALIZACION = 0,
    ESTADO_HOLA,
    ESTADO_IDENTIFICA,
    ESTADO_PASS,
};

void Inicializar (void);
char recibir_msj (void);
char recibo_id (void);
char recibo_pass (void);
char recibo_error (void);
void enviar_msj (bool);
char recibo_hola (void);
uint8_t estado;

int main()
{
   
   estado = ESTADO_INICIALIZACION; //inicializo
}

int FSM_B(){
    switch(estado){
       case ESTADO_INICIALIZACION:
       if(recibir_msj() == recibo_hola()){
           estado = ESTADO_HOLA;
           enviar_msj (OK);
       }
       
        case ESTADO_HOLA:
        if (recibir_msj() == recibo_id()){
            estado = ESTADO_IDENTIFICA;
            enviar_msj(OK); //conozco
        }
        else if (recibir_msj() == recibo_error()){
            enviar_msj(ERROR); //no conozco
        }
        break;
        
        case ESTADO_IDENTIFICA:
        if (recibir_msj() == recibo_pass()){
            estado = ESTADO_PASS;
            enviar_msj(OK);
        }
        else if (recibir_msj() == recibo_error()){
            enviar_msj(ERROR);
        }
        break;
        
        case ESTADO_PASS:
        break;
        
        default:
        Inicializar();
    }
}
