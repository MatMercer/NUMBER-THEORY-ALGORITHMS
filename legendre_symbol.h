// VAMOS CRIAR UM PROGRAM QUE CALCULA OS SÍMBOLOS DE LEGENDRE USANDO O LEMA DE
// GAUSS

/*
O SÍMBOLO DE LEGENDRE (a/b) É DEFINIDO COMO:
       { 0 SE a = 0 mod(b)
(a/b)= { +1 SE a ≠ 0 mod(b) E PARA ALGUM x SE VERIFICA A RELAÇÃO a = x² mod(b)
       { -1 SE a ≠ 0 mod(b) E PARA NENHUM x SE VERIFICA A RELAÇÃO a = x² mod(b)

O LEMA DE GAUSS FORNECE UM ALGORITMO RELATIVAMENTE SIMPLES PARA SE COMPUTAR OS
SÍMBOLOS DE LEGENDRE SENDO a E b COPRIMOS. AS CONGRUÊNCIAS MÓDULO b SÃO
DETERMINADAS PARA TODOS OS NÚMEROS NA SEQUÊNCIA: a, 2a, ..., a((p-1)/2). SENDO
u O NÚMERO DE VALORES SUPERIORES A p/2, O LEMA DE GAUSS AFIRMA QUE O SÍMBOLO DE
LEGENDRE (a/b) É IGUAL A (-1)^u.

PARA MAIORES INFORMAÇÕES:
https://crypto.stanford.edu/pbc/notes/numbertheory/book.pdf
                          https://en.wikipedia.org/wiki/Legendre_symbol

*/

//****************************************************************************************************************************
// CABEÇALHO
#ifndef LEGENDRE_SYMBOL_H
#define LEGENDRE_SYMBOL_H
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

//****************************************************************************************************************************
// DECLARAÇÃO DE FUNÇÕES
uint64_t euclides_algorithm (uint64_t, uint64_t);
int legendre (uint64_t, uint64_t);

//****************************************************************************************************************************
// FUNÇÕES
// Função que implementa o algoritmo de Euclides
uint64_t
euclides_algorithm (uint64_t a, uint64_t b)
{
  if (b == 0)
    return a;
  else
    return euclides_algorithm (b, a % b);
};

// Função que calcula o símbolo de Legendre usando o lema de Gauss
int
legendre (uint64_t n, uint64_t prime)
{
  // Variáveis locais
  uint64_t i, maximum = ((prime - 1) / 2);
  uint64_t upper_half_terms = 0, tester;
  int result = 1;

  // Procedimentos
  // Caso trivial
  if (euclides_algorithm (n, prime) != 1)
    return 0;

  // Caso base: n=2
  if (n == 2)
    {
      uint64_t base = floor ((prime + 1) / 4);
      if (base % 2 == 0)
        return result;
      else
        return (-1) * result;
    };

  // Caso geral: n e prime são ímpares
  // Calculando congruências modulo p na sequância a, 2a, ..., a((p-1)/2)
  for (i = 1; i <= maximum; ++i)
    {
      tester = (i * n) % prime;
      if (tester > (prime / 2))
        upper_half_terms++;
    };
  // Resultado
  if (upper_half_terms % 2 == 0)
    return result;
  else
    return (-1) * result;
};

//****************************************************************************************************************************
// FIM DO HEADER
#endif
