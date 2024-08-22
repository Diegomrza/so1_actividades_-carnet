#!/bin/bash

# Script que imprime un saludo y la fecha actual infinitamente
# con una pausa de un segundo entre iteraciones.

while true; do
  echo "¡Hola! La fecha y hora actuales son: $(date)"
  sleep 1
done
