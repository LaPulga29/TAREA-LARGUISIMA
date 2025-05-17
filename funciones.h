void ingresarTiempoDisponible(int *tiempoDisponible);
void ingresarRecursosDisponibles(int *recursosDisponibles);
void ingresarProductos(char nombres[][30], int tiempos[], int recursos[], int cantidades[], int *numProductos);
void editarProducto(char nombres[][30], int tiempos[], int recursos[], int cantidades[], int numProductos);
void eliminarProducto(char nombres[][30], int tiempos[], int recursos[], int cantidades[], int *numProductos);
void calcularProduccion(int tiempos[], int recursos[], int cantidades[], int numProductos, int *tiempoTotal, int *recursosTotales);
void verificarCapacidad(int tiempoTotal, int recursosTotales, int cantidades[], int tiempoDisponible, int recursosDisponibles, int numProductos);
void mostrarProductos(char nombres[][30], int tiempos[], int recursos[], int cantidades[], int numProductos); 