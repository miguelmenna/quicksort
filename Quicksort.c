#include <stdio.h>

void troca(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int particiona(int *vetor, int inicio, int fim) {
  int pivo = vetor[fim - 1];
  int i = inicio - 1;

  for (int j = inicio; j < fim - 1; j++) {
    if (vetor[j] <= pivo) {
      i++;
      troca(&vetor[i], &vetor[j]);
    }
  }

  troca(&vetor[i + 1], &vetor[fim - 1]);
  return i + 1;
}

void quicksort(int *vetor, int inicio, int fim) {
  if (inicio < fim) {
    int posicaoPivo = particiona(vetor, inicio, fim);
    quicksort(vetor, inicio, posicaoPivo - 1);
    quicksort(vetor, posicaoPivo + 1, fim);
  }
}

int main() {
  int vetor[] = {1, 5, 3, 2, 4};
  int tamanhoVetor = sizeof(vetor) / sizeof(int);

  quicksort(vetor, 0, tamanhoVetor - 1);

  for (int i = 0; i < tamanhoVetor; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  return 0;
}