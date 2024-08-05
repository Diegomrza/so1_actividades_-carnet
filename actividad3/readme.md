# Actividad 3 - Control de Accesos

## Parte 1

#### 1.1 Creacion de usuarios

```bash
sudo useradd -m usuario1
sudo useradd -m usuario2
sudo useradd -m usuario3
```

#### 1.2 Asignacion de contraseñas

```bash
sudo passwd usuario1
# Ingresar contraseña: sopes1
# Confirmar contraseña: sopes1

sudo passwd usuario2
# Ingresar contraseña: sopes1
# Confirmar contraseña: sopes1

sudo passwd usuario3
# Ingresar contraseña: sopes1
# Confirmar contraseña: sopes1
```

#### 1.3 Informacion de usuario1

```bash
id usuario1
# uid=1001(usuario1) gid=1001(usuario1) grupos=1001(usuario1)
```

#### 1.4 Eliminacion de usuario3, conservando su directorio

```bash
sudo userdel usuario3
sudo mv /home/usuario3 /home/backups/usuario3
```

## Parte 2

#### 2.1 Creacion de grupos

```bash
sudo groupadd grupo1
sudo groupadd grupo2
```

#### 2.2 Agregar usuarios a los grupos

```bash
sudo usermod -aG grupo1 usuario1
sudo usermod -aG grupo2 usuario2
```

#### 2.3 Verificacion de grupos

```bash
groups usuario1
# usuario1 : usuario1 grupo1
groups usuario2
# usuario2 : usuario2 grupo2
```

#### 2.4 Eliminacion de grupo2

```bash
sudo groupdel grupo2
```

## Parte 3

#### 3.1 Crear de archivos y directorios

```bash
sudo -u usuario1 bash -c 'echo "Contenido de archivo #1" > /home/usuario1/archivo1.txt'
```

#### Crear un directorio llamado directorio1

```bash
sudo -u usuario1 bash -c 'mkdir /home/usuario1/directorio1 && echo "Contenido de archivo #2" > /home/usuario1/directorio1/archivo2.txt'
```

#### 3.2 Verificacion de permisos

```bash
ls -l /home/usuario1/archivo1.txt
# -rw-r--r-- 1 usuario1 usuario1 24 Aug  4 20:30 /home/usuario1/archivo1.txt

ls -ld /home/usuario2/directorio1
# drwxr-xr-x 2 usuario1 usuario1 4096 Aug  4 20:30 /home/usuario1/directorio1
```

#### 3.3 Modificacion de permisos modo numerico

#### Cambia los permisos del archivo1.txt para que sólo usuario1 pueda leer y escribir (permisos rw-), el grupo pueda leer (permisos r--) y nadie más pueda hacer nada.

```bash
chmod 640 /home/usuario1/archivo1.txt
# -rw-r----- 1 usuario1 usuario1 24 Aug  4 20:30 /home/usuario1/archivo1.txt
```

#### 3.4 Modificacion de permisos modo simbolico

```bash
chmod u+x /home/usuario1/directorio1/archivo2.txt
# -rwxr-xr-x 1 usuario1 usuario1 24 Aug  4 20:30 /home/usuario1/directorio1/archivo2.txt
```

#### 3.5 Cambia el grupo propietario de archivo2.txt a grupo1.

```bash
sudo chgrp grupo1 /home/usuario1/directorio1/archivo2.txt
# -rwxr-xr-x 1 usuario1 grupo1 24 Aug  4 20:30 /home/usuario1/directorio1/archivo2.txt
```

#### 3.6 Cambia los permisos del directorio1 para que sólo el propietario pueda entrar (permisos rwx), el grupo pueda listar contenidos pero no entrar (permisos r--), y otros no puedan hacer nada.

```bash
chmod 740 /home/usuario1/directorio1
# drwxr----- 2 usuario1 usuario1 4096 Aug  4 20:30 /home/usuario1/directorio1
```

#### 3.7 Comprobacion de acceso

```bash
sudo -u usuario2 cat /home/usuario1/archivo1.txt
# Contenido de archivo # 1

sudo -u usuario2 ls /home/usuario1/directorio1
# ls: cannot open directory '/home/usuario1/directorio1': Permission denied

sudo -u usuario2 cat /home/usuario1/directorio1/archivo2.txt
# cat: /home/usuario1/directorio1/archivo2.txt: Permission denied
```

#### 3.8 Verificacion final: Verificar los permisos y propietario de los archivos y directorio nuevamente con ls y derivados

```bash
ls -l /home/usuario1/archivo1.txt
# -rw-r----- 1 usuario1 usuario1 24 Aug  4 20:30 /home/usuario1/archivo1.txt

ls -ld /home/usuario1/directorio1
# drwxr----- 2 usuario1 usuario1 4096 Aug  4 20:30 /home/usuario1/directorio1

ls -l /home/usuario1/directorio1/archivo2.txt
# -rwxr-xr-x 1 usuario1 grupo1 24 Aug  4 20:30 /home/usuario1/directorio1/archivo2.txt
```
