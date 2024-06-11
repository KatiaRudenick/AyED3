// control_casa.c
#include "control_casa.h"
#include <stdio.h>

void armar_total() {
    printf("Sistema armado totalmente.\n");
}

void armar_parcial() {
    printf("Sistema armado parcialmente.\n");
}

void desactivar() {
    printf("Sistema desactivado.\n");
}

void anular_zona(int zona) {
    printf("Zona %d anulada.\n", zona);
}

void panico() {
    printf("Alarma de pánico activada.\n");
}

void emergencia_medica() {
    printf("Alarma de emergencia médica activada.\n");
}
