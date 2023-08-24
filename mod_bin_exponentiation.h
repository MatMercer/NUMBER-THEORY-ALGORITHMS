//VAMOS ESCREVER UM PROGRAMA QUEM IMPLMENTA AS ROTINAS DE EXPONENCIAÇÃO BINÁRIA MODULAR E EXPONENCIAL MODULAR

/*
A EXPONENCIAÇÃO BINÁRIA É UM MECANISMO PARA PERMITIR UMA EXPONENCIAÇÃO MAIS RÁPIDA ENVOLVENDO NÚMEROS INTEIROS.
A IDEIA BÁSICA CONSISTE EM EXPRESSAR UM EXPOENTE EM NOTAÇÃO BINÁRIA E USAR POTÊNCIAS DE MÚLTIPLOS DE 2 PARA COMPUTAR A EXPONENCIAL.
POR EXEMPLO:
13 = 8+4+1 = 1.2³+1.2²+0.2¹+1.2⁰ --> 1101
a¹³= a⁸a⁴a¹= ((a²)²)².(a²)².a =(a⁴)².(a²)².a 

PORTANTO AS POTÊNCIA REQUERIDAS NO CÁLCULO SÃO COMPUTADAS POR MEIO DE MULTIPLICAÇÕES SIMPLES RECURSIVAMENTE.

A EXPONENCIAÇÃO MODULAR É USADA  PARA COMPUTAR EXPRESSÕES DO TIPO a^(b) mod(c).
ESTA OPERAÇÃO FAZ USO DAS SEGUINTES PROPRIEDADES DA ARITMÉTICA MODULAR:
SEJAM a = b mod(n) E c = d mod(n).
ENTÃO:
(a.b) = (c.d) mod(n)
(a+b) = (c+d) mod(n)
EXEMPLO:
25=4 mod(7)
16=2 mod(7)
(25x16) = 400 = 8 mod(7) = 1 mod(7) [ POIS 8 = 1 mod(7) ]
(25+16) = 41 = 6 mod(7)

AS DUAS TÉCNICAS PODEM SEM COMBINADAS PARA O CÁLCULO DE EXPONENCIAIS MAIS RAPIDAMENTE.
*/


//***********************************************************************************************************************
//CABEÇALHO (usaremos apenas headers básicos de C para maior compatibilidade com C++)
#ifndef MOD_BIN_EXPONENTIATION_H
#define MOD_BIN_EXPONENTIATION_H
#include<stdint.h>
#include<inttypes.h>
#include<stdlib.h>


//***********************************************************************************************************************
//PROTÓTIPOS DE FUNÇÕES
uint64_t mod_pow(uint64_t, uint64_t, uint64_t);
uint64_t bin_pow(uint64_t, uint64_t);
uint64_t mod_bin_pow(uint64_t, uint64_t, uint64_t);

//***********************************************************************************************************************
//EXPONENCIAÇÃO MODULAR

//Função que calcula a exponencial modular a^b mod(n)
uint64_t mod_pow(uint64_t a, uint64_t b, uint64_t n){
//Variáveis locais
uint64_t result=1;
uint64_t i;//Variável de iteração

//Procedimento
for(i=0; i<b; ++i)
result= (result*a)%n;

return result;
                                                    };

//***********************************************************************************************************************
//EXPONENCIAÇÃO BINÁRIA

/*OBSERVAÇÃO:
NO PRESENTE ALGORITMO USAMOS OS OPERADORES BITWISE & E >>.
O OPERADOR >> REALIZA UMA TRANSLAÇÃO DOS BITS DE UM NÚMERO INTEIRO PARA A DIREITA PREENCHENDO OS BITS RESTANTES COM 0'S.
ÚTIL PARA FAZER DIVISÃO POR POTÊNCIAS DE 2.
EXEMPLO:
24=16+8 EM BINÁRIO É 11000 (16+8+0+0+0)
24/4 = 24>>2, POIS:
1º SHIFT: 01100 QUE É 12 (0+8+4+0+0) EM BINÁRIO
2º SHIFT: 00110 QUE É 12 (0+0+4+2+0) EM BINÁRIO

A PARIDADE DO MENOR BIT É TESTADA COM O OPERADOR and '&', QUE SATIFAZ AS RELAÇÕES:
0 & 0 = 0
1 & 0 = 0
0 & 1 = 0
1 & 1 = 1

O NÚMERO 1 EM BINÁRIO É ...0001, DE FORMA QUE AO FAZER n & 1, TODOS OS BITS DE n SÃO ZERADOS EXCETO POSSIVELMENTE O ÚLTIMO
*/
uint64_t bin_pow(uint64_t a, uint64_t b) {
//Variáveis locais
uint64_t result = 1;
//Procedimentos
while (b > 0) {
if (b & 1) {
result *= a;
           };

a = a*a;
b >>= 1;
              };

//Resultado
return result;
                                         };

//***********************************************************************************************************************
//TÉCNICA MISTA DE EXPONENCIAÇÃO: EXPONENCIAÇÃO BINÁRIA COMBINADA COM EXPONENCIAÇÃO MODULAR
uint64_t mod_bin_pow(uint64_t a, uint64_t b, uint64_t n){
//Variáveis locais
uint64_t result = 1;
//Procedimentos
while (b > 0) {
if (b & 1) {
result = (result*a)%n;
           };

a = a*a;
b >>= 1;
              };

//Resultado
return result;
                                                        };

//***********************************************************************************************************************
//FIM DO HEADER
#endif
