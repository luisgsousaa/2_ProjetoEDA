#ifndef INC_2_PROJETOEDA_FUNCOES_H
#define INC_2_PROJETOEDA_FUNCOES_H
#include <string>
#include "estruturas.h"
using namespace std;

int capacidade_aviao();


void nova_lista_avioes(LL_avioes &lista);
bool vazia_lista_avioes (LL_avioes &lista);
void inserir_aviao(LL_avioes &lista, aviao &novo);
void retirar_avioes (LL_avioes &lista);
int comprimento(LL_avioes &lista);
LL_avioes inicializar_aproximacao(LL_avioes &ll_aproximacao,int &numero_bilhete_novo,int &indice_lista_numeros_de_voo);
LL_avioes adiciona_aproximacao(LL_avioes &ll_aproximacao,int &numero_bilhete_novo,int &indice_lista_numeros_de_voo);
LL_avioes adiciona_pista (LL_avioes &ll_aproximacao,LL_avioes &ll_pista,int &indice_lista_numeros_de_voo, int &numero_bilhete_novo,LL_nacionalidades &ll_nacionalidades);
LL_avioes adiciona_descolados (LL_avioes &ll_pista, LL_avioes &ll_descolados);
void inserir_passageiro(aviao &lista, passageiro &novo);
passageiro * procura_passageiro_random (passageiro * raiz);

void travessia_prefixa_arvore_passageiros_para_array(passageiro * no,passageiro *array);
int conta_nos_arvore(passageiro * no);
passageiro * passa_array(LL_nacionalidades &ll_nacionalidades, int &conta_array_passageiros);
passageiro * passa_array_nacionalidade(LL_nacionalidades ll_nacionalidades, int &conta_array_passageiros, string nacionalidade);

void carrega_aeroportoEDA(char* argv[],LL_avioes &ll_aproximacao,LL_avioes &ll_pista,LL_avioes &ll_descolados,LL_nacionalidades &ll_nacionalidades,int &numero_bilhete_novo, int &indice_lista_numeros_de_voo, int &ciclos,bool &fechado, int &ciclos_fechado);

//Inverter LL_avioes
void inverte_LL_avioes(LL_avioes& p);
void adiciona_nodo_LL_avioes(LL_avioes& p, aviao dados);
void retira_nodo_LL_avioes(LL_avioes& p);

//Inverter LL_passageiros
void inverte_LL_passageiros(aviao &p);
void adiciona_nodo_LL_passageiros(aviao& p, passageiro dados);
void retira_nodo_LL_passageiros(aviao& p);

void adiciona_passageiros_estrangeiros(passageiro *&retirados,int tamanho_array,LL_nacionalidades &ll_nacionalidades);

passageiro* novo_nodo_arvore(passageiro novo_passageiro);
passageiro * inserir_passageiros_arvore(passageiro  *&pass, passageiro novo_passageiro);
void imprime_arvore(passageiro* pass, int nivel);

passageiro * remover_copia(passageiro *&raiz, string nome);
passageiro* remover_copia(passageiro* raiz, passageiro* no, passageiro* ant);

#endif //INC_2_PROJETOEDA_FUNCOES_H
