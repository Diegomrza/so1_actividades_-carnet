# Actividad 4 - Systemd Unit

## Servicio de Saludo en Linux

Este README explica cómo crear un servicio en Linux que ejecuta un script de Bash en un bucle infinito, imprime un saludo y la fecha actual cada segundo, y cómo configurar el servicio para que inicie automáticamente al arrancar el sistema usando `systemd`.

### Script `saludo.sh`

Este script es un simple bucle que imprime un saludo junto con la fecha y la hora actuales y luego hace una pausa de un segundo antes de repetir.

#### Código del Script

```bash
#!/bin/bash

# Script que imprime un saludo y la fecha actual infinitamente
# con una pausa de un segundo entre iteraciones.

# Bucle infinito
while true; do
  # Imprimir el saludo y la fecha actual
  echo "¡Hola! La fecha y hora actuales son: $(date)"
  # Esperar 1 segundo antes de repetir
  sleep 1
done
```

### Crear el servicio con systemd

- Paso 1: Crear el archivo de servicio y agregarle el contenido

```bash
  sudo nano /etc/systemd/system/saludo.service
```

- Paso 2: Agregar el contenido al archivo

```bash
  # Contenido
  [Unit]
  Description=Servicio de saludo que imprime la fecha y hora cada segundo

  [Service]
  ExecStart=/usr/local/bin/saludo.sh
  Restart=always

  [Install]
  WantedBy=multi-user.target
```

- Paso 3: Habilitar e iniciar el servicio

```bash
# Recargar los archivos de servicio de systemd
sudo systemctl daemon-reload

# Habilitar el servicio para que se inicie al arrancar el sistema
sudo systemctl enable saludo.service

# Iniciar el servicio manualmente
sudo systemctl start saludo.service

```

Paso 4: Verificar el estado del servicio

```bash
  sudo systemctl status saludo.service
```
