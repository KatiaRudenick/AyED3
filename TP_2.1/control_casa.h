// control_casa.h
#ifndef CONTROL_CASA_H
#define CONTROL_CASA_H

#ifdef __cplusplus
extern "C" {
#endif

void armar_total();
void armar_parcial();
void desactivar();
void anular_zona(int zona);
void panico();
void emergencia_medica();

#ifdef __cplusplus
}
#endif

#endif // CONTROL_CASA_H
