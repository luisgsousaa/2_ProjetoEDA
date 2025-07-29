#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"
#include "estruturas.h"
#include "ficheiros.h"
#include "simulacao.h"


/*
 * Grupo 16
 * Luís Sousa 2133323
 * André Figueira 2112623
 * Melissa Freitas 2048518
 */

/**
 * Todas as variáveis e listas são inicializadas e a leitura de ficheiros é feita. Caso não tenham sido passados argumentos suficientes para carregar um estado anterior do aeroporto,
 * as variáveis inteiras são inicializadas com os valores iniciais, caso contrário a função carrega_aeroportoEDA() é chamada e aí são dados os valores respetivos às variáveis
 * @param argc numéro de argumentos passados na execução do programa
 * @param argv argumentos passados na execução do programa
 * @return 0
 */
int main(int argc, char* argv[]) {
    srand(time(NULL));
    if(argc==4){
        int numero_bilhete_novo;
        int indice_lista_numeros_de_voo;
        int ciclos;
        int conta_array_passageiros = 0;
        int ciclos_fechado;
        bool fechado;

        //Leitura de ficheiros
        leitura_dos_ficheiros();

        //Inicialização das Listas Ligadas
        LL_avioes ll_aproximacao;
        nova_lista_avioes(ll_aproximacao);

        LL_avioes ll_pista;
        nova_lista_avioes(ll_pista);

        LL_avioes ll_descolados;
        nova_lista_avioes(ll_descolados);

        LL_nacionalidades ll_nacionalidades;
        cria_e_preenche_LL_nacionalidades(ll_nacionalidades);

        carrega_aeroportoEDA(argv,ll_aproximacao,ll_pista,ll_descolados,ll_nacionalidades,numero_bilhete_novo,indice_lista_numeros_de_voo,ciclos,fechado,ciclos_fechado);


        menu(ll_aproximacao,ll_pista,ll_descolados,numero_bilhete_novo,indice_lista_numeros_de_voo,ciclos,ll_nacionalidades,conta_array_passageiros,fechado,ciclos_fechado);
    }
    else{
        int numero_bilhete_novo = 1000000000;
        int indice_lista_numeros_de_voo = 0;
        int ciclos = 0;
        int conta_array_passageiros = 0;
        int ciclos_fechado = 0;
        bool fechado = false;

        leitura_dos_ficheiros();

        //inicialização lista de aproximação
        LL_avioes ll_aproximacao;
        nova_lista_avioes(ll_aproximacao);
        inicializar_aproximacao(ll_aproximacao,numero_bilhete_novo,indice_lista_numeros_de_voo);

        //inicialização lista na pista
        LL_avioes ll_pista;
        nova_lista_avioes(ll_pista);


        //inicialização lista descolados
        LL_avioes ll_descolados;
        nova_lista_avioes(ll_descolados);

        //Inicialização lista de nacionalidades
        LL_nacionalidades ll_nacionalidades;
        cria_e_preenche_LL_nacionalidades(ll_nacionalidades);




        menu(ll_aproximacao,ll_pista,ll_descolados,numero_bilhete_novo,indice_lista_numeros_de_voo,ciclos,ll_nacionalidades,conta_array_passageiros,fechado,ciclos_fechado);
    }


    return 0;
}
