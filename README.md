# Sistemas en Tiempo Real
## Universidad Nacional de Colombia - Sede Medellín
## Semestre 2019-2

Integrantes:
- Nicolás Villegas Echavarría
- Juan Camilo Ruiz Escobar


### Instrucciones

En primer lugar deben compilarse los diferentes archivos que componen el programa en archivos objeto, de la siguiente forma:

```shell
gcc -c <lista de archivos .c separados por espacio>
```

Lo cual produce una series de archivos con la extensión `.o` uno por cada archivo `.c` que fue compilado. Cabe anotar que no es necesario incluir los archivos de cabecera (`.h`) en esta instrucción, ya que los mismos son llamados indirectamente por los archivos `.c` que hace uso de ellos. Luego, los archivos `.o` archivos deben de ser enlazados, mediante la siguiente instrucción:

```
gcc <lista de archivos .o separados por espacio> -o <ejecutable>
```

en donde `<ejecutable>` es el nombre deseado para el archivo ejecutable de salida. Finalmente, para ejecutar el programa, basta con escribir en la línea de comandos:

```
./<ejecutable>
```
