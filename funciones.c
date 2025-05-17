#include <stdio.h>
#include <math.h>
#include <string.h>

void ingresarTiempoDisponible(int *tiempoDisponible) {
    int val;
    do {
        printf("Ingrese el tiempo disponible de produccion (en semanas): ");
        fflush(stdin);
        val = scanf("%d", tiempoDisponible);
        if (*tiempoDisponible < 0 || val != 1) {
            printf("Valor no valido.\n");
        }
    } while (*tiempoDisponible < 0 || val != 1);
}
void ingresarRecursosDisponibles(int *recursosDisponibles) {
    int val;
    do {
        printf("Ingrese la cantidad de recursos disponibles (kilos de metal): ");
        fflush(stdin);
        val = scanf("%d", recursosDisponibles);
        if (*recursosDisponibles <= 0 || val != 1) {
            printf("Valor no valido.\n");
        }
    } while (*recursosDisponibles <= 0 || val != 1);
}

void ingresarProductos(char nombres[][30], int tiempos[], int recursos[], int cantidades[], int *numProductos) // CASO 1
{ // INGRESAR PRODUCTO
    
    int i, j, k, val = 0;
    char nombreTemporal[30];

    for (i = 0; i < 5; i++)
    {
        int nombreValido = 0;
        while (nombreValido == 0) 
        {
            printf("Producto %d:\n", i + 1);
            printf("Nombre: ");
            fflush(stdin); 
            scanf("%s", nombreTemporal);

            // Verificar duplicados
            nombreValido = 1;
            for (j = 0; j < i; j++) {
                for (k = 0; nombreTemporal[k] != '\0' || nombres[j][k] != '\0'; k++) {
                    if (nombreTemporal[k] != nombres[j][k]) {
                        break;
                    }
                }
                if (nombreTemporal[k] == '\0' && nombres[j][k] == '\0') {
                    printf("El nombre '%s' ya existe. Ingrese un nombre diferente.\n", nombreTemporal);
                    nombreValido = 0;
                    break;
                }
            }
            if (nombreValido == 1) {
                for (k = 0; nombreTemporal[k] != '\0'; k++) {
                    nombres[i][k] = nombreTemporal[k];
                }
                nombres[i][k] = '\0';
            }
        }
        do // CANTIDAD A FABRICAR DE CADA  PRODUCTO 
        {
            printf("Cantidad a fabricar de %s: ", nombres[i]);
            fflush(stdin);
            val = scanf("%d", &cantidades[i]);
            if (val != 1 || cantidades[i] < 0)
                printf("Valor fuera del rango permitido o entrada no numerica.\n");
        } while (val != 1 || cantidades[i] < 0);
        do // TIEMPO DE FABRICACIÓN DE CADA PRODUCTO
        {
            printf("Tiempo de fabricacion (en semanas) de %d %s: ", cantidades[i], nombres[i]);
            fflush(stdin);
            val = scanf("%d", &tiempos[i]);
            if (val != 1 || tiempos[i] < 0)
                printf("Valor fuera del rango permitido o entrada no numerica.\n");
        } while (val != 1 || tiempos[i] < 0);
        do // RECURSOS REQUERIDOS EN CADA PRODUCTO
        {
            printf("Cantidad de kg de metal (recursos) necesarios para %d %s: ", cantidades[i], nombres[i]);
            fflush(stdin);
            val = scanf("%d", &recursos[i]);
            if (val != 1 || recursos[i] < 0)
                printf("Valor fuera del rango permitido o entrada no numerica.\n");
        } while (val != 1 || recursos[i] < 0);
    }
}
void editarProducto(char nombres[][30], int tiempos[], int recursos[], int cantidades[], int numProductos) // CASO 2
{  
    int i; 
    if (cantidades[i] == 0) {
        printf("No hay productos ingresados.\n");
        return;
    } 
    // EDITAR TODOS LOS DATOS DE UN PRODUCTO
    char nombreBuscar[30];
    int val = 0, encontrado = 0;
    printf("Ingrese el nombre del producto a editar: ");
    scanf("%s", nombreBuscar);
    for (i = 0; i < numProductos; i++) {  // CUENTA CARACTER POR CARACTER PARA BUSCAR EL PRODUCTO
        int iguales = 1;
        for (int j = 0; j < 30; j++) {
            if (nombres[i][j] != nombreBuscar[j]) {
                iguales = 0;
                break;
            }
            if (nombres[i][j] == '\0' && nombreBuscar[j] == '\0') {
                break;
            }
        }
        if (iguales != 0) { // ENCUENTRA EL PRODUCTO SEGUN EL NOMBRE
            printf("Producto encontrado.\n");
            printf("Ingrese nuevos datos:\n");
            printf("Nuevo nombre: ");
            scanf("%s", nombres[i]);
            do
            { 
                printf("Cantidad a fabricar %s: ", nombres[i]); // NUEVA CANTIDAD
                fflush(stdin);
                val = scanf("%d", &cantidades[i]);
                if (val != 1 || cantidades[i] < 0)
                {
                    printf("Valor fuera del rango permitido o entrada no numerica.\n");
                }
            } while (val != 1 || cantidades[i] < 0);
            do
            {
                printf("Tiempo de fabricacion (en semanas) de %d %s: ", cantidades[i], nombres[i]); // NUEVO TIEMPO
                fflush(stdin);
                val = scanf("%d", &tiempos[i]);
                if (val != 1 || tiempos[i] < 0)
                    printf("Valor fuera del rango permitido o entrada no numerica.\n");
            } while (val != 1 || tiempos[i] < 0);

            do
            {
                printf("Cantidad de kg de metal (recursos) necesarios para %d %s: ", cantidades[i], nombres[i]); // NUEVOS RECURSOS
                fflush(stdin);
                val = scanf("%d", &recursos[i]);
                if (val != 1 || recursos[i] < 0){
                    printf("Valor fuera del rango permitido o entrada no numerica.\n");
                }
            } while (val != 1 || recursos[i] < 0);
            encontrado = 1;
            break;
        }
    }
    if (encontrado == 0) {
        printf("Producto no encontrado.\n");
    }
}
void eliminarProducto(char nombres[][30], int tiempos[], int recursos[], int cantidades[], int *numProductos) // CASO 3
{ 
    int i; 
    if (cantidades[i] == 0) {
        printf("No hay productos ingresados.\n");
        return;
    }
    // ELIMINAR PRODUCTO
    char nombreBuscar[30];
    int j, encontrado = 0;
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", nombreBuscar);
    for (i = 0; i < *numProductos; i++) { // BUSCA CARACTER POR CARACTER EL PRODUCTO
        int iguales = 1;
        for (int k = 0; k < 30; k++) {
            if (nombres[i][k] != nombreBuscar[k]) {
                iguales = 0;
                break;
            }
            if (nombres[i][k] == '\0' && nombreBuscar[k] == '\0') {
                break;
            }
        }
        if (iguales != 0) {
            for (j = i; j < *numProductos - 1; j++) {
                for (int k = 0; k < 30; k++) {
                    nombres[j][k] = nombres[j + 1][k];
                }
                tiempos[j] = tiempos[j + 1];
                recursos[j] = recursos[j + 1];
                cantidades[j] = cantidades[j + 1];
            }
            *numProductos -= 1;
            printf("Producto eliminado.\n");
            encontrado = 1;
            break;
        }
    }
    if (encontrado == 0) {
        printf("Producto no encontrado.\n");
    }
}
void calcularProduccion(int tiempos[], int recursos[], int cantidades[], int numProductos, int *tiempoTotal, int *recursosTotales) { // CASO 4
    
    // SUMA LOS TOTALES DE TODO 
    *tiempoTotal = 0;
    *recursosTotales = 0;
    for (int i = 0; i < numProductos; i++) {
        *tiempoTotal += tiempos[i];
        *recursosTotales += recursos[i];
    }
}
void verificarCapacidad(int tiempoTotal, int recursosTotales, int cantidades[], int tiempoDisponible, int recursosDisponibles, int numProductos) // CASO 4
{
    int i;
    // VERIFICA QUE LO DISPONIBLE SEA MENOR O IGUAL A LO REQUERIDO
    printf("\n--- Verificacion de Capacidad ---\n");
    printf("Tiempo total requerido: %d semanas\n", tiempoTotal);
    printf("Recursos totales requeridos: %d kg de metal\n", recursosTotales);
    printf("Tiempo disponible: %d semanas\n", tiempoDisponible);
    printf("Recursos disponibles: %d de metal\n", recursosDisponibles);
    if (tiempoTotal <= tiempoDisponible && recursosTotales <= recursosDisponibles)
    {
        printf("La fabrica SI puede cumplir con la demanda.\n");
    }
    else
    {
        printf("La fabrica NO puede cumplir con la demanda.\n");
        if (tiempoTotal > tiempoDisponible && recursosTotales < recursosDisponibles)
        {
            printf("Se cumplen los recursos pero no se cumplen los tiempos.\n "); 
        }
        else if (tiempoTotal < tiempoDisponible && recursosTotales > recursosDisponibles)
        {
            printf("Se cumplen los tiempos pero no se cumplen los recursos.\n "); 
        }
    }
}
void mostrarProductos(char nombres[][30], int tiempos[], int recursos[], int cantidades[], int numProductos) { // CASO 5
    // MUESTRA UNA LISTA  DE PRODUCTOS
    int i;
    if (cantidades[i] == 0) {
        printf("No hay productos registrados.\n");
        return;
    }
    printf("\n\t\t--- Lista de productos ---\n");
    printf("#\tNombres\t\tSemanas\t\tRecursos\tCantidades\n");
    for (i = 0; i < numProductos; i++) { 
        printf("%d\t%s\t   %d\t\t  %d\t\t   %d\n", i + 1, nombres[i], tiempos[i], recursos[i], cantidades[i]);
    }
}