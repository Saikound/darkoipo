#include <stdbool.h>
#include <stdio.h>
#define ROWS 6
#define COLS 7

void marca_jugador(char casillas[] ){
    printf("    |    |    |    |    |    |\n");
    printf(" %c  | %c  | %c  | %c  | %c  | %c  \n", 
           (casillas[0] != ' ' ? casillas[0] : '1'),
           (casillas[1] != ' ' ? casillas[1] : '2'),
           (casillas[2] != ' ' ? casillas[2] : '3'),
           (casillas[3] != ' ' ? casillas[3] : '4'),
           (casillas[4] != ' ' ? casillas[4] : '5'),
           (casillas[5] != ' ' ? casillas[5] : '6'));
    printf("____|____|____|____|____|____|\n");
    printf("    |    |    |    |    |    |\n");
    printf(" %c  | %c  | %c  | %c  | %c  | %c  \n", 
           (casillas[6] != ' ' ? casillas[6] : '7'),
           (casillas[7] != ' ' ? casillas[7] : '8'),
           (casillas[8] != ' ' ? casillas[8] : '9'),
           (casillas[9] != ' ' ? casillas[9] : '10'),
           (casillas[10] != ' ' ? casillas[10] : '11'),
           (casillas[11] != ' ' ? casillas[11] : '12'));
    printf("____|____|____|____|____|____|\n");
    printf("    |    |    |    |    |    |\n");
    printf(" %c  | %c  | %c  | %c  | %c  | %c  \n", 
           (casillas[12] != ' ' ? casillas[12] : '13'),
           (casillas[13] != ' ' ? casillas[13] : '14'),
           (casillas[14] != ' ' ? casillas[14] : '15'),
           (casillas[15] != ' ' ? casillas[15] : '16'),
           (casillas[16] != ' ' ? casillas[16] : '17'),
           (casillas[17] != ' ' ? casillas[17] : '18'));
    printf("____|____|____|____|____|____|\n");
    printf("    |    |    |    |    |    |\n");
    printf(" %c  | %c  | %c  | %c  | %c  | %c  \n", 
           (casillas[18] != ' ' ? casillas[18] : '19'),
           (casillas[19] != ' ' ? casillas[19] : '20'),
           (casillas[20] != ' ' ? casillas[20] : '21'),
           (casillas[21] != ' ' ? casillas[21] : '22'),
           (casillas[22] != ' ' ? casillas[22] : '23'),
           (casillas[23] != ' ' ? casillas[23] : '24'));
    printf("____|____|____|____|____|____|\n");
    printf("    |    |    |    |    |    |\n");
    printf(" %c  | %c  | %c  | %c  | %c  | %c  \n", 
           (casillas[24] != ' ' ? casillas[24] : '25'),
           (casillas[25] != ' ' ? casillas[25] : '26'),
           (casillas[26] != ' ' ? casillas[26] : '27'),
           (casillas[27] != ' ' ? casillas[27] : '28'),
           (casillas[28] != ' ' ? casillas[28] : '29'),
           (casillas[29] != ' ' ? casillas[29] : '30'));
    printf("    |    |    |    |    |    |\n");
}

// Función para verificar si hay un ganador en el juego Cuatro en Rayas
// Retorna el número del jugador ganador (1 o 2), o 0 si no hay ganador
int verificarGanador(int casillas[ROWS][COLS]) {
    // Verificar horizontalmente
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS - 3; col++) {
            int jugador = casillas[row][col];
            if (jugador != 0 && jugador == casillas[row][col+1] && jugador == casillas[row][col+2] && jugador == casillas[row][col+3]) {
                return jugador;
            }
        }
    }
    
    // Verificar verticalmente
    for (int row = 0; row < ROWS - 3; row++) {
        for (int col = 0; col < COLS; col++) {
            int jugador = casillas[row][col];
            if (jugador != 0 && jugador == casillas[row+1][col] && jugador == casillas[row+2][col] && jugador == casillas[row+3][col]) {
                return jugador;
            }
        }
    }
    
    // Verificar en diagonal (ascendente)
    for (int row = 3; row < ROWS; row++) {
        for (int col = 0; col < COLS - 3; col++) {
            int jugador = casillas[row][col];
            if (jugador != 0 && jugador == casillas[row-1][col+1] && jugador == casillas[row-2][col+2] && jugador == casillas[row-3][col+3]) {
                return jugador;
            }
        }
    }
    
    // Verificar en diagonal (descendente)
    for (int row = 0; row < ROWS - 3; row++) {
        for (int col = 0; col < COLS - 3; col++) {
            int jugador = casillas[row][col];
            if (jugador != 0 && jugador == casillas[row+1][col+1] && jugador == casillas[row+2][col+2] && jugador == casillas[row+3][col+3]) {
                return jugador;
            }
        }
    }
    
    // No hay ganador
    return 0;
}

void juego_maquina() {
    char casillas[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};			//funcion de la maquina, esta funcion correra si el usuario decide escribir "S" en int_main
    char jugador, jugador_maquina;
    int juego_perdido = 0;
    int turno_maquina = 0;

    printf("Ingrese su letra (X/O): ");					//El usuario escoge su letra y sus respectivas condicionales
    scanf(" %c", &jugador);

    if (jugador == 'O') {
        jugador_maquina = 'X';
    } else {
        jugador_maquina = 'O';
    }

    while (!juego_perdido) {
        marca_jugador(casillas);
        printf("Es el turno del jugador %c\n", jugador);

        int movimiento;
        printf("Ingresa un numero del 1 al 9 para colocar tu ficha: ");   //Varible movimiento que permite almacenar la figura escogida en la posicion deseada
        scanf("%d", &movimiento);

        while (movimiento >  30|| movimiento < 1) {
            printf("Ingresa un numero valido del 1 al 9: ");			
            scanf("%d", &movimiento);
        }

        if (casillas[movimiento - 1] == ' ') {
            casillas[movimiento - 1] = jugador;								//Condicionales si el usuario cumple con confirmar_ganador
            if (verificarGanador(casillas, jugador)) {
                marca_jugador(casillas);
                printf("¡Felicidades, ganaste!\n");
                juego_perdido = 1;
                break;
            }
            turno_maquina++;

            if (turno_maquina == 9) {
                marca_jugador(casillas);
                printf("¡Empate!\n");
                juego_perdido = 1;
                break;
            }

            while (1) {
                int movimiento_maquina = rand() % 9;			//rand permite escoger una posicion aleatoria dentro del rango 0 - 8, el % limita el rango 	
                if (casillas[movimiento_maquina] == ' ') {
                	printf("Escogiendo posicion...\n");
                	sleep(2);											//sleep de la biblioteca <unistd.h>, que permite antes de mostrar la casilla generar una pausa, que en este caso es de 2 segundos
                    casillas[movimiento_maquina] = jugador_maquina;     //recreando una accion de "pensar" en la maquina
                    ///printf("La maquina escogio %i \n", casillas);
                    break;
                }
            }

            if (verificarGanador(casillas, jugador_maquina)) {				//Condicion maquina cumple con los requisitos de confirmar_ganadar
                marca_jugador(casillas);
                printf("Lo siento, la IA gano.\n");
                juego_perdido = 1;
                break;
            }
            turno_maquina++;
        }
    }
}

void importante() {
    char casillas[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};			//Funcion que se ejecuta cuando el usuario ingresa != "S"
    char jugador;
    int juego_perdido = 0;
    

    printf("Ingrese su letra (X/O): ");
    scanf(" %c", &jugador);

    while (!juego_perdido) {
        marca_jugador(casillas);
        printf("Es el turno del jugador %c\n", jugador);

        int movimiento;
        printf("Ingresa un numero del 1 al 9 para colocar tu ficha: ");
        scanf("%d", &movimiento);

        while (movimiento > 9 || movimiento < 1) {
            printf("Ingresa un numero valido del 1 al 9: ");
            scanf("%d", &movimiento);
        }

        if (casillas[movimiento - 1] == ' ') {
            casillas[movimiento - 1] = jugador;
            if (verificarGanador(casillas, jugador)) {
                marca_jugador(casillas);
                printf("¡Felicidades, jugador %c, has ganado!\n", jugador);		//Condicionales de victoria, empate
                juego_perdido = 1;
            } else if (!strchr(casillas, ' ')) {								//strchr perteneciente de la biblioteca <string.h> se utiliza para buscar caracteres especificos 
                marca_jugador(casillas);										//en este caso ' ' = espacio en blanco
                printf("¡Empate!\n");
                juego_perdido = 1;
               
            } else {
                jugador = (jugador == 'X' ? 'O' : 'X');							
            }
        } else {
            printf("Esa casilla ya está ocupada. Por favor, selecciona otra.\n");
        }
    }
}

int main() {
    srand(time(NULL));						//srand inicia el generador de numeros aleatorios, y time(null) para obtener numero diferentes en cada inicializacion del codigo
    char mientras = 'S';

    while (mientras == 'S') {				//Ciclo while que vuelve a ejecutarse el codigo si el usuario responde con "S"
        char Maquina;

        printf("¿Desea jugar contra la IA? /Presione S para confirmar: ");		//Si el usuario coloca "S" correra la funcion de la maquina (void juego_maquina) 
        scanf(" %c", &Maquina);

        if (Maquina == 'S') {									//Condicionales de maquina
            juego_maquina();
        } else {
            importante();
        }

        printf("¿Deseas seguir jugando?/Presiones S para confirmar: ");		//mientras que esta vinculado con while, "S" -->> se corre nuevamente el codigo
        scanf(" %c", &mientras);
    }

    printf("¡Gracias por jugar!\n");

    return 0;
}

