#### Shebang para que se intreprete con bash

```bash
#!/bin/bash
```

#### Leer el archivo settings.json

```bash
SETTINGS_FILE="settings.json"
```

#### Validando que el archivo existe

```bash
if [ ! -f "$SETTINGS_FILE" ]; then
echo "Error: El archivo $SETTINGS_FILE no existe."
exit 1
fi
```

#### Intentando obtener el valor de las variables

```bash
GITHUB_USER=$(jq -r '.GITHUB_USER' $SETTINGS_FILE)
URL_SCRIPT=$(jq -r '.URL_SCRIPT' $SETTINGS_FILE)
```

#### Validar si las variables están definidas

```bash
if [ -z "$GITHUB_USER" ] || [ -z "$URL_SCRIPT" ]; then
echo "Error: Las variables GITHUB_USER o URL_SCRIPT no están definidas en $SETTINGS_FILE."
exit 1
fi
```

#### Consultar la URL concatenando el valor de la variable GITHUB_USER

```bash
URL="https://api.github.com/users/$GITHUB_USER"
RESPONSE=$(curl -s $URL)
```

#### Extraer los datos del JSON respuesta

```bash
USER_ID=$(echo $RESPONSE | jq -r '.id')
CREATED_AT=$(echo $RESPONSE | jq -r '.created_at')
```

#### Construir el mensaje de salida

```bash
MESSAGE="Hola $GITHUB_USER. User ID: $USER_ID. Cuenta fue creada el: $CREATED_AT."
```

#### Crear el log file en /tmp/<fecha>/saludos.log

```bash
DATE=$(date +%Y-%m-%d)
LOG_DIR="/tmp/$DATE"
mkdir -p $LOG_DIR
```

#### Crear el cronjob para que el script se ejecute cada 5 minutos

```bash
(crontab -l 2>/dev/null; echo "_/5 _ \* \* \* $URL_SCRIPT") | crontab -
```

#### Instalar jq para trabajar con JSON con facilidad

```bash
sudo apt-get install jq
```

### Dar permisos de ejecución al script

```bash
chmod +x /ruta/al/script.sh
```
