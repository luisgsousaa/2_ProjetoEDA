#ifndef INC_2_PROJETOEDA_SIMULACAO_H
#define INC_2_PROJETOEDA_SIMULACAO_H
#include "estruturas.h"

void aeroportoEDA(LL_avioes &ll_aproximacao, LL_avioes &ll_pista, LL_avioes &ll_descolados);
void menu_opcoes(LL_avioes &ll_pista,LL_avioes &ll_aproximacao,LL_avioes &ll_descolados,LL_nacionalidades &ll_nacionalidades,int &conta_array_passageiros,bool &fechado, int &ciclos_fechado);
void menu(LL_avioes &ll_aproximacao, LL_avioes &ll_pista, LL_avioes &ll_descolados,int &numero_bilhete_novo,int &indice_lista_numeros_de_voo,int &ciclos,LL_nacionalidades &ll_nacionalidades,int &conta_array_passageiros,bool &fechado, int &ciclos_fechado);
void ciclo_seguinte(LL_avioes &ll_aproximacao, LL_avioes &ll_pista, LL_avioes &ll_descolados,int &numero_bilhete_novo,int &indice_lista_numeros_de_voo, int &ciclos,LL_nacionalidades &ll_nacionalidades,bool &fechado, int &ciclos_fechado);
void voltar_ao_menu();
void guardar_aeroportoEDA(LL_avioes &ll_aproximacao, LL_avioes &ll_pista, LL_avioes &ll_descolados,LL_nacionalidades &ll_nacionalidades,int &numero_bilhete_novo,int &indice_lista_numeros_de_voo,int &ciclos, int &conta_array_passageiros,bool &fechado, int &ciclos_fechado);
void muda_nacionalidade_passageiro(LL_avioes &ll_aproximacao);
void emergencia(LL_avioes &ll_aproximacao,LL_avioes &ll_pista,LL_avioes &ll_descolados,LL_nacionalidades &ll_nacionalidades,int &numero_bilhete_novo, int &indice_lista_numeros_de_voo,int &ciclos,bool &fechado, int &ciclos_fechado);
void menu_imprime_passageiros(LL_nacionalidades &ll_nacionalidades,int &conta_array_passageiros);
void imprime_todos_os_passageiros(LL_nacionalidades &ll_nacionalidades,int &conta_array_passageiros);
void troca(passageiro& a, passageiro& b);
void imprime_por_nacionalidade(LL_nacionalidades &ll_nacionalidades,int &conta_array_passageiros);
void imprime_arvore_por_nacionalidade(LL_nacionalidades &ll_nacionalidades);
void pesquisa_passageiros(LL_avioes &ll_aproximacao, LL_avioes &ll_descolados);
void fechar_aeroporto(bool &fechado, int &ciclos_fechado);



#endif //INC_2_PROJETOEDA_SIMULACAO_H
