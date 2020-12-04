#include <stdio.h> // para los printf()
#include <stdlib.h> // para usar rand() y srand()
#include <unistd.h> // para usar getpid()

void clean_stdin(void) // UTILIZAR ESTE MÉTODO SI fflush(stdin) DIESE PROBLEMAS! source: https://stackoverflow.com/questions/17318886/fflush-is-not-working-in-linux
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

char* sacarNumero(void) { // este método genera el número o figura de la carta
  int r = ((rand()%12)+1);
  char* n = "";
  if (r == 1) {
    n = "As";
  } else if (r == 2) {
    n = "2";
  } else if (r == 3) {
    n = "3";
  } else if (r == 4) {
    n = "4";
  } else if (r == 5) {
    n = "5";
  } else if (r == 6) {
    n = "6";
  } else if (r == 7) {
    n = "7";
  } else if (r == 8) {
    n = "8";
  } else if (r == 9) {
    n = "9";
  } else if (r == 10) {
    n = "Sota";
  } else if (r == 11) {
    n = "Caballo";
  } else if (r == 12) {
    n = "Rey";
  }
  return n;
}

char* sacarPalo(void) { // este método determina el palo de la carta
  int r = ((rand()%4)+1);
  char* n = "";
  if (r == 1) {
    n = " de Oros";
  } else if (r == 2) {
    n = " de Copas";
  } else if (r == 3) {
    n = " de Espadas";
  } else if (r == 4) {
    n = " de Bastos";
  }
  return n;
}

void sacarCarta(void) { // imprime una carta aleatoria
  printf("%s%s",sacarNumero(),sacarPalo());
}

int main(void) {
  void srand(unsigned int seed); // IMPORTANTE inicializar para poder generar la semilla
  srand(getpid()); // generamos la semilla para nuestro random con el ID de proceso
  for(;;) {
    printf("¿Robar carta? <s/n>: ");
    char res = getchar();
    if (res == 's' || res == 'S') {
      sacarCarta();
      printf("\n\n");
      clean_stdin();
    } else if (res == 'n' || res == 'N') {
      printf("\nSaliendo del programa...");
      break;
    } else {
      printf("\nPor favor introduce un parámetro válido <s/n>\n\n");
      clean_stdin();
    }
  }
  return 0;
}