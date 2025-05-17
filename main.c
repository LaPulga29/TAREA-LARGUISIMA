#include <stdio.h>
#include "funciones.h"

int main()
{
    char nombres[5][30];
    int tiempos[5], recursos[5], cantidades[5];
    int numProductos = 5;
    int tiempoDisponible, recursosDisponibles;
    int tiempoTotal, recursosTotales;
    int opcion, val = 0, i;
    ingresarTiempoDisponible(&tiempoDisponible);
    ingresarRecursosDisponibles(&recursosDisponibles);
    do{
        printf("\n\t---- Menu ----\n");
        printf("1. Ingresar productos\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Mostrar productos\n");
        printf("5. Calcular produccion y verificar capacidad\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion){
        case 1:
            ingresarProductos(nombres, tiempos, recursos, cantidades, &numProductos);
            break;
        case 2:
            editarProducto(nombres, tiempos, recursos, cantidades, numProductos);
            break;
        case 3:
            eliminarProducto(nombres, tiempos, recursos, cantidades, &numProductos);
            break;
        case 4:
            mostrarProductos(nombres, tiempos, recursos, cantidades, numProductos);
            break;
        case 5:
            if (cantidades[i] == 0)
            {
                printf("No hay productos registrados.\n"); 
            }
            else 
            {
            calcularProduccion(tiempos, recursos, cantidades, numProductos, &tiempoTotal, &recursosTotales);
            verificarCapacidad(tiempoTotal, recursosTotales, cantidades, tiempoDisponible, recursosDisponibles, numProductos);
            }
            break;
        case 6:
            printf("Adiossss :3\n");
            break;
        default:
            printf("Opcion no valida.\n");
            break;
        }
    } while (opcion != 6);
    return 0;
}