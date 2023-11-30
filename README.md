# Tarifeitor
Herramienta para automatizar procesos de creacion de tarifas en GVisualREC

[Parametros]
-h: Muestra el manual

-T: Cambia el tamaño de las columnas a las apropiadas para el programa

-F: Cambia la fuente y el tamaño de la fuente a Arial 10

-P: Cambia las propiedades de las columnas de precio y codigo de barras

-M: Aplica mayusculas a todas las descripciones

-R: Borra los caracteres especiales de los numeros de referencia, dejando solo los numeros
    y reemplaza las vocales con tilde, la Ñ, los espacios antes y despues de los caracteres especiales
    en las descripciones


-E Cambia la extension del archivo a la que indiques
[Funcionamiento]
Ejemplo: python Tarifeitor.py ejemplo.xlsx -TPF -e xls
En este ejemplo se ejecutaria el cambio de tamaño de columnas(T), cambio de propiedades de las columnas de precio(P)
y cambio de fuentes, ademas se exportaria en formato xls(F)

El primer parametro debe ser el libro con el que trabajaremos, tiene que estar ya ordenado en este orden:

Codigo | Indice | Codigo de Fabricante | Descripcion | Subfamilia | PV1 | PV2 | Precio Neto | Codigo de Barras

El segundo parametro puedes dejarlo en blanco y ejecutara automaticamente todas las funciones, en caso de que quieras
ejecutar funciones concretas, debes especificarlas como en el ejemplo

Puedes añadir separado el parametro -E para especificar la extension de archivo a utilizar, por defecto se usara la extension original
