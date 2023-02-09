!UM PROGRAMA PARA CALCULAR OS NÚMEROS CATALÃES

PROGRAM numeroscatalaes
IMPLICIT NONE

!DEFINIÇÃO DE VARIÁVEIS
INTEGER, PARAMETER::IKIND=SELECTED_INT_KIND(25)
INTEGER(KIND=IKIND)::CATALAN_NUMBER
INTEGER:: FATOR, I, N

!************************************************************************************************************************
!!
!!
!!
!!NÚMEROS CATALÃES SÃO UMA IMPORTANTE SEQUÊNCIA DE NÚMEROS INTEIROS EM ANÁLISE COMBINATÓRIA. APARECENDO EM PROBLEMAS COMO A CONTAGEM DE EXEPRESSÕES ENVOLVENDO N+1 TERMOS COM N PARENTÊSES, O NÚMEROS DE CAMINHOS ENTRE VERTÍCES OPOSTOS EM UMA MALHA QUADRADA ABAIXO DA DIAGONAL PRINCIPAL, ENTRE OUTRAS APLICAÇÕES. O N-ÉSIMO TERMO DESTA SEQUÊNCIA É CALCULADO POR: C(N)=(1/(N+1))*(2N!/(N!)²=2N!/(N!)*(N+1)!).ELES PODEM SER CALCULADOS USANDO A SEGUINTE RELAÇÃO DE RECURSÃO: C(0)=1, C(N+1)=(2*(2*I+1)/(I+2))*C(N). ELES AINDA POSSUEM REPRESENTAÇÕES EM FORMA INTEGRAL E POSSUEM UMA FÓRMULA ASSINTÓTICA PARA N SUFICIENTEMENTE GRANDE C(N)~4^(N)/((N^(3/2))*(π^(1/2)))


!ENTRADA DE DADOS
WRITE(*,*)"DIGITE UM NÚMERO INTEIRO:"
READ(*,*)N
WRITE(*,*)"EIS A SEQUÊNCIA DE NÚMEROS CATALÃES ATÉ O ", N,"º TERMO:"

!AJUSTES DAS VARIÁVEIS
CATALAN_NUMBER=1
I=0
WRITE(*,*)CATALAN_NUMBER

!CÁLCULO  DOS NÚMEROS CATALÃES RECURSIVO

DO WHILE(I<N)
CATALAN_NUMBER=CATALAN_NUMBER*2
CATALAN_NUMBER=CATALAN_NUMBER*(2*I+1)
CATALAN_NUMBER=CATALAN_NUMBER/(I+2)
WRITE(*,*)CATALAN_NUMBER
I=I+1 !ATUALIZANDO A VARIÁVEL DE CONTAGEM
END DO

END PROGRAM numeroscatalaes


