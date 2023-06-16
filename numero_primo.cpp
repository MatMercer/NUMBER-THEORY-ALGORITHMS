//VAMOS CRIAR UM PROGRAMA QUE EXIBE NA TELA UMA LISTA DE NÚMEROS PRIMOS ATÉ UM LIMITE DETERMINADO PELO USUÁRIO

/*CABEÇAHO*/
#include<iostream>
#include<cmath>
using namespace std;

//FUNÇÃO QUE CHECA SE UM NÚMERO É PRIMO
bool eprimo(int n){
//DEFINIÇÃO DE VARIÁVEIS AUXILIARES
int i, resultado;
int status=0;
bool id;
//PROCEDIMENTOS EXECUTÁVEIS
if (n>2){
 //Caso trivial pares exceto 2 não são primos
 if(n%2==0)
  return false;

 for(i=3; i<(int)sqrt(n); i+=2){
  resultado=(n%i);
  if(resultado!=0)
  {continue;}
  if(resultado==0)
{status++; break;};
};
            };

if(status==0)
id=true;
if(status>0)
id=false;
return(id);}


//FUNÇÃO PRINCIPAL
int main(){
//DEFINIÇÃO DE VARIÁVEIS
int limite, i;
cout<<"Digite um limitante superior para sua sequência de números primos:\n";
cin>>limite;
//CRIANDO A LISTA DE NÚMEROS PRIMOS
cout<<"Eis a sua lista de números primos.\n";
cout<<"2, ";
for(i=3; i<=limite; i++){
if(eprimo(i))
cout<<i<<", ";
else if(!eprimo(i))
               continue;};
cout<<" ...\n";
return 0;
}

