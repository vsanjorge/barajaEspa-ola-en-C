#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void srand(unsigned int seed); // IMPORTANTE inicializar para poder generar la semilla
int seedMod = 0;

void clean_stdin(void) // UTILIZAR ESTE MÉTODO SI fflush(stdin) DIESE PROBLEMAS! source: https://stackoverflow.com/questions/17318886/fflush-is-not-working-in-linux
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

char* sacarNumero(void) {
  srand(getpid()+seedMod); // IMPORTANTE para generar una nueva semilla en cada iteración del bucle!
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
  seedMod++;
  return n;
}

char* sacarPalo(void) {
  srand(getpid()+seedMod); // IMPORTANTE para generar una nueva semilla en cada iteración del bucle!
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
  seedMod++;
  return n;
}

void sacarCarta(void) {
  printf("%s%s",sacarNumero(),sacarPalo());
  seedMod++;
}

int main(void) {
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