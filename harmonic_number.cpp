//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO harmonic_number.hpp
//COMPILAR ESTE PROGRAMA: g++ -o harmonic_number harmonic_number.cpp

//Cabeçalho
#include<iostream>
#include<stdint.h>
#include"complex_numbers.hpp"
#include"harmonic_number.hpp"
using namespace std;

//Função principal
int main(){
//Função variável
complex<double> z;
double x;
int n;

//Procedimento
//Recebendo input do usuário
cout<<"Digite um número inteiro: ";
cin>>n;
cout<<"Digite um número real: ";
cin>>x;
z.set();
//Calculando o número harmônico para argumentos inteiros, reais e complexos
cout<<"H("<<n<<") = "<<harmonic_number(n)<<"\n";
cout<<"H("<<x<<") = "<<harmonic_number(x)<<"\n";
cout<<"H("<<z.algebraic()<<") = "<<harmonic_number(z).algebraic()<<"\n";

//Calculando a função  para argumentos inteiros, reais e complexos
cout<<"Ψ("<<n<<") = "<<digamma(n)<<"\n";
cout<<"Ψ("<<x<<") = "<<digamma(x)<<"\n";
cout<<"Ψ("<<z.algebraic()<<") = "<<digamma(z).algebraic()<<"\n";

//Finalizando a aplicação
return 0;
          }
