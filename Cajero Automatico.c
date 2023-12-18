#include <stdio.h>

// Estructura para la cuenta del usuario
struct Cuenta {
    float saldo;
    float inversion;
};

// Prototipos de funciones
void consultarSaldo(struct Cuenta *cuenta);
void retirarDinero(struct Cuenta *cuenta);
void depositarDinero(struct Cuenta *cuenta);
void solicitarPrestamo(struct Cuenta *cuenta);
void realizarInversion(struct Cuenta *cuenta);

int main() {
    struct Cuenta cuenta = {1000.0, 0.0};  // Saldo inicial y ninguna inversión

    int opcion;

    do {
        printf("\n--- Simulador de Cajero Automático ---\n");
        printf("1. Consultar Saldo\n");
        printf("2. Retirar Dinero\n");
        printf("3. Depositar Dinero\n");
        printf("4. Solicitar Préstamo\n");
        printf("5. Realizar Inversión\n");
        printf("0. Salir\n");

        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                consultarSaldo(&cuenta);
                break;
            case 2:
                retirarDinero(&cuenta);
                break;
            case 3:
                depositarDinero(&cuenta);
                break;
            case 4:
                solicitarPrestamo(&cuenta);
                break;
            case 5:
                realizarInversion(&cuenta);
                break;
            case 0:
                printf("Saliendo del simulador de cajero automático. ¡Hasta luego!\n");
                break;
            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
        }

    } while (opcion != 0);

    return 0;
}

void consultarSaldo(struct Cuenta *cuenta) {
    printf("Saldo actual: $%.2f\n", cuenta->saldo);
}

void retirarDinero(struct Cuenta *cuenta) {
    float cantidad;

    printf("Ingrese la cantidad a retirar: $");
    scanf("%f", &cantidad);

    if (cantidad > 0 && cantidad <= cuenta->saldo) {
        cuenta->saldo -= cantidad;
        printf("Retiro exitoso. Nuevo saldo: $%.2f\n", cuenta->saldo);
    } else {
        printf("Error: Cantidad no válida o saldo insuficiente.\n");
    }
}

void depositarDinero(struct Cuenta *cuenta) {
    float cantidad;

    printf("Ingrese la cantidad a depositar: $");
    scanf("%f", &cantidad);

    if (cantidad > 0) {
        cuenta->saldo += cantidad;
        printf("Depósito exitoso. Nuevo saldo: $%.2f\n", cuenta->saldo);
    } else {
        printf("Error: Cantidad no válida.\n");
    }
}

void solicitarPrestamo(struct Cuenta *cuenta) {
    float cantidad;

    printf("Ingrese la cantidad del préstamo solicitado: $");
    scanf("%f", &cantidad);

    if (cantidad > 0) {
        cuenta->saldo += cantidad;
        printf("Préstamo aprobado. Nuevo saldo: $%.2f\n", cuenta->saldo);
    } else {
        printf("Error: Cantidad no válida.\n");
    }
}

void realizarInversion(struct Cuenta *cuenta) {
    float cantidad;

    printf("Ingrese la cantidad a invertir: $");
    scanf("%f", &cantidad);

    if (cantidad > 0 && cantidad <= cuenta->saldo) {
        cuenta->saldo -= cantidad;
        cuenta->inversion += cantidad;
        printf("Inversión exitosa. Nuevo saldo: $%.2f, Inversión total: $%.2f\n", cuenta->saldo, cuenta->inversion);
    } else {
        printf("Error: Cantidad no válida o saldo insuficiente.\n");
    }
}
