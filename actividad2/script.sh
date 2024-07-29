#!/bin/bash

# Leer el archivo settings.json
SETTINGS_FILE="settings.json"

# Validando que el archivo existe
if [ ! -f "$SETTINGS_FILE" ]; then
  echo "Error: El archivo $SETTINGS_FILE no existe."
  exit 1
fi

#Intentando obtener el valor de las variables
GITHUB_USER=$(jq -r '.GITHUB_USER' $SETTINGS_FILE)
URL_SCRIPT=$(jq -r '.URL_SCRIPT' $SETTINGS_FILE)

# Validar si las variables están definidas
if [ -z "$GITHUB_USER" ] || [ -z "$URL_SCRIPT" ]; then
  echo "Error: Las variables GITHUB_USER o URL_SCRIPT no están definidas en $SETTINGS_FILE."
  exit 1
fi

# Consultar la URL concatenando el valor de la variable GITHUB_USER
URL="https://api.github.com/users/$GITHUB_USER"
RESPONSE=$(curl -s $URL)

# Extraer los datos del JSON respuesta
USER_ID=$(echo $RESPONSE | jq -r '.id')
CREATED_AT=$(echo $RESPONSE | jq -r '.created_at')

# Construir el mensaje de salida
MESSAGE="Hola $GITHUB_USER. User ID: $USER_ID. Cuenta fue creada el: $CREATED_AT."

# Crear el log file en /tmp/<fecha>/saludos.log
DATE=$(date +%Y-%m-%d)
LOG_DIR="/tmp/$DATE"
mkdir -p $LOG_DIR

echo $MESSAGE >> "$LOG_DIR/saludos.log"

# Crear el cronjob para que el script se ejecute cada 5 minutos
(crontab -l 2>/dev/null; echo "*/5 * * * * $URL_SCRIPT") | crontab -
