#include "estruturas.h"
#include "ficheiros.h"
#include "funcoes.h"
using namespace std;
#include <iostream>




/** Sara
 * Esta função cria um novo avião usando dados aleatórios exceto o destino que é sempre AeroportoEDA pois estes aviões são postos na aproximação.
 * @param indice_lista_numeros_de_voo Variavél que guarda o índice atual do array que é usado para atribuição de números de voo
 * @return avião que foi criado
 */
aviao criar_aviao(int &indice_lista_numeros_de_voo) {
    aviao novo;
    novo.modelo_aviao = modelo_aleatorio();
    novo.nome_voo = numero_de_voo(indice_lista_numeros_de_voo);
    novo.origem = origem_aleatoria();
    novo.destino = "AeroportoEDA - Madeira, Portugal";
    novo.capacidade = capacidade_aviao();
    novo.topo = NULL;
    return novo;
}

/** Sara
 * Função que cria o número único de bilhete.
 * Caso o número passe o máximo um erro irá ser apresentado e o programa irá terminar.
 * Caso contrário é retornado o valor da variável numero_bilhete novo e depois é incrementada a variável.
 * @param numero_bilhete_novo número de bilhete a ser incrementado
 * @return número de bilhete que foi criado
 */
int bilhete_novo(int &numero_bilhete_novo){
    if (numero_bilhete_novo > 9999999999){
        cout << "O numero de bilhetes excedeu o maximo";
        exit(1);
    }
    else{
        return numero_bilhete_novo++;
    }
}

/** Sara
 * Função para criar um passageiro com dados aleatórios
 * @param numero_bilhete_novo Número do proximo bilhete a ser criado
 * @return passageiro que foi criado
 */
passageiro criar_passageiro(int &numero_bilhete_novo) {
    passageiro novo;
    novo.primeiro_nome = primeiro_nome_aleatorio();
    novo.segundo_nome = segundo_nome_aleatorio();
    novo.nacionalidade = nacionalidade_aleatoria();
    novo.numero_bilhete = "TK"+ to_string(bilhete_novo(numero_bilhete_novo));
    novo.dir = NULL;
    novo.esq = NULL;
    return novo;
}