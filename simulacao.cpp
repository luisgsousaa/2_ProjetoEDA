#include "simulacao.h"
#include "iostream"
#include "estruturas.h"
#include "funcoes.h"
#include "ficheiros.h"
#include "fstream"


using namespace std;

/** Luis
 * Esta função imprime todas as informações do aeroportoEDA, usando um iterador para percorrer e imprimir as informações contidas nas listas ligadas do tipo Fila, para a Aproximação, Pista e Descolados.
 * Também usa um iterador dentro de cada avião que percorre a lista de passageiros e imprime o segundo nome e a nacionalidade de cada passageiro no avião.
 * @param ll_aproximacao Lista Ligada onde estão os aviões em aproximação
 * @param ll_pista Lista Ligada onde estão os aviões na pista
 * @param ll_descolados Lista Ligada onde estão os aviões a descolar
 */
void aeroportoEDA(LL_avioes &ll_aproximacao, LL_avioes &ll_pista, LL_avioes &ll_descolados){

    cout << "-----------------" << endl;
    cout << " Em aproximacao" << endl;
    cout << "-----------------" << endl;
    cout << endl;

    LL_avioes::Item * iterator1 = ll_aproximacao.topo;
    while(iterator1 != NULL){
        cout << " - Voo: " << iterator1->dados.nome_voo << endl;
        cout << " - Modelo: " << iterator1->dados.modelo_aviao << endl;
        cout << " - Ocupacao: " << iterator1->dados.capacidade << endl;
        cout << " - Origem: " << iterator1->dados.origem << endl;
        cout << " - Destino: " << iterator1->dados.destino << endl;

        aviao aviao_atual1 = iterator1->dados;
        aviao::Item * iterator_passageiro1 = aviao_atual1.topo;
        cout << " - Passageiros: ";

        while(iterator_passageiro1 != NULL){
            cout << iterator_passageiro1->LL_passageiros.segundo_nome << ", " << iterator_passageiro1->LL_passageiros.nacionalidade  <<  " | ";
            iterator_passageiro1=iterator_passageiro1->seguinte;
        }

        cout << endl << "------------------------------------------------------------------------------------------------------" << endl;
        iterator1=iterator1->seguinte;

    }
    delete iterator1;

    cout << "**********************************************************************************************************" << endl;
    cout << "**********************************************************************************************************" << endl;

    cout << "-----------------" << endl;
    cout << "   Na pista" << endl;
    cout << "-----------------" << endl;
    cout << endl;
    LL_avioes::Item * iterator2 = ll_pista.topo;
    while(iterator2 != NULL){
        cout << " - Voo: " << iterator2->dados.nome_voo << endl;
        cout << " - Modelo: " << iterator2->dados.modelo_aviao << endl;
        cout << " - Ocupacao: " << iterator2->dados.capacidade << endl;
        cout << " - Origem: " << iterator2->dados.origem << endl;
        cout << " - Destino: " << iterator2->dados.destino << endl;

        aviao aviao_atual2 = iterator2->dados;
        aviao::Item * iterator_passageiro2 = aviao_atual2.topo;
        cout << " - Passageiros: ";
        while(iterator_passageiro2 != NULL){
            cout << iterator_passageiro2->LL_passageiros.segundo_nome << ", " << iterator_passageiro2->LL_passageiros.nacionalidade <<  " | ";
            iterator_passageiro2=iterator_passageiro2->seguinte;
        }
        cout << endl <<"------------------------------------------------------------------------------------------------------" << endl;
        iterator2=iterator2->seguinte;
    }
    delete iterator2;

    cout << "**********************************************************************************************************" << endl;
    cout << "**********************************************************************************************************" << endl;

    cout << "-----------------" << endl;
    cout << "  A descolar" << endl;
    cout << "-----------------" << endl;
    cout << endl;

    LL_avioes::Item * iterator3 = ll_descolados.topo;
    while(iterator3 != NULL){
        cout << " - Voo: " << iterator3->dados.nome_voo << endl;
        cout << " - Modelo: " << iterator3->dados.modelo_aviao << endl;
        cout << " - Ocupacao: " << iterator3->dados.capacidade << endl;
        cout << " - Origem: " << iterator3->dados.origem << endl;
        cout << " - Destino: " << iterator3->dados.destino << endl;

        aviao aviao_atual3 = iterator3->dados;
        aviao::Item * iterator_passageiro3 = aviao_atual3.topo;
        cout << " - Passageiros: ";
        while(iterator_passageiro3 != NULL){
            cout << iterator_passageiro3->LL_passageiros.segundo_nome << ", " << iterator_passageiro3->LL_passageiros.nacionalidade <<  " | ";
            iterator_passageiro3=iterator_passageiro3->seguinte;
        }

        cout << endl << "------------------------------------------------------------------------------------------------------" << endl;
        iterator3=iterator3->seguinte;
    }
    delete iterator3;
}


/** Luis
 * Esta função aprsenta as opções disponíveis na gestão do aeroporto e pede ao utilizador para escolher uma, caso escolha uma inválida irá aparecer uma mensagem de erro a pedir
 * para o utilizador introduzir novamente. Caso escolha uma opção válida a função respetiva irá ser chamada.
 * @param ll_pista Lista ligada de aviões na pista
 * @param ll_aproximacao Lista ligadad de aviões em aproximação
 * @param ll_descolados Lista ligadad de aviões descolados
 * @param ll_nacionalidades Lista ligada de nacionalidades
 * @param conta_array_passageiros Tamanho de um array de passageiros
 * @param fechado booleano que guarda se o aeroporto está fechado ou não
 * @param ciclos_fechado número de ciclos que faltam para o aeroporto abrir
 */
void menu_opcoes(LL_avioes &ll_pista,LL_avioes &ll_aproximacao,LL_avioes &ll_descolados,LL_nacionalidades &ll_nacionalidades,int &conta_array_passageiros, bool &fechado, int &ciclos_fechado){
    cout << "Opcoes: " << endl;

    cout << "1 - Inverter Prioridade da Pista." << endl
         << "2 - Fechar Aeroporto." << endl
         << "3 - Mostrar os passageiros em pista." << endl
         << "4 - Pesquisa de passageiros." << endl
         << "5 - Editar nacionalidade de passageiro nas chegadas." << endl
         << "0 - Voltar ao aeroporto." << endl;
    cout << "Escolha uma opcao: " << endl;

    bool sair_opcoes = false;
    char opcao;
    do{
        cin >> opcao;
        switch(opcao){
            case '1':
                inverte_LL_avioes(ll_pista);
                cout << "A prioridade da Pista foi invertida com sucesso" << endl;
                voltar_ao_menu();
                sair_opcoes = true;
                break;
            case '2':
                fechar_aeroporto(fechado,ciclos_fechado);
                voltar_ao_menu();
                sair_opcoes = true;
                break;
            case '3':
                menu_imprime_passageiros(ll_nacionalidades, conta_array_passageiros);
                sair_opcoes = true;
                break;
            case '4':
                pesquisa_passageiros(ll_aproximacao,ll_descolados);
                sair_opcoes = true;
                break;
            case '5':
                muda_nacionalidade_passageiro(ll_aproximacao);
                voltar_ao_menu();
                sair_opcoes = true;
                break;
            case '0':
                sair_opcoes = true;
                break;
            default:
                cout << "Escolha uma opcao valida! " << endl;
                break;

        }
    }while(!sair_opcoes);
}

/** Luis
 * Esta funcção chama a função que imprime todas as informações do aeroportoEDA, incluindo se está fechado ou não, e apresenta as opções que o utilizador pode escolher.
 * Quando o utilizador introduz o caracter correspondente à opção que pretende, a função correspondente irá ser chamada.
 * Caso seja introduzido um caracter inválido o utilizador deverá introduzir um novo.
 * Quando é introduzido uma opção válida o booleano sair passa a ser verdadeiro o que faz o ciclo do while acabar e por fim chama novamente esta função para o utilizador
 * poder continuar a passar os ciclos ou escolher uma das outras opções.
 * @param ll_aproximacao Lista Ligada onde estão os aviões em aproximação
 * @param ll_pista Lista Ligada onde estão os aviões na pista
 * @param ll_descolados Lista Ligada onde estão os aviões a descolar
 * @param numero_bilhete_novo Número do proximo bilhete a ser criado
 * @param indice_lista_numeros_de_voo Índice usado para a atribuição de novos números de voo
 * @param ciclos Contagem dos ciclos da simulação
 * @param ll_nacionalidades Lista Ligada de nacionalidades
 * @param conta_array_passageiros Número de passageiros que tem dentro das árvores de pesquisa binária
 * @param fechado booleano que guarda se o aeroporto está fechado ou não
 * @param ciclos_fechado número de ciclos que faltam para o aeroporto abrir
 *
 */
void menu(LL_avioes &ll_aproximacao, LL_avioes &ll_pista, LL_avioes &ll_descolados,int &numero_bilhete_novo,int &indice_lista_numeros_de_voo, int &ciclos,LL_nacionalidades &ll_nacionalidades,int &conta_array_passageiros,bool &fechado, int &ciclos_fechado){
    aeroportoEDA(ll_aproximacao,ll_pista,ll_descolados);
    if(fechado){
        cout << endl << "|||| O aeroportoEDA encontra-se fechado durante " << ciclos_fechado << " ciclos. ||||" << endl << endl;
    }
    cout << "Ciclo " << ciclos << endl;
    cout << "Escolha uma opcao: (e)mergencias | (o)pcoes | (g)uardar | Ciclo (s)eguinte" << endl;
    bool sair = false;
    char opcao;
    do{
        cin >> opcao;

        switch(opcao){
            case 'e':
                emergencia(ll_aproximacao,ll_pista,ll_descolados,ll_nacionalidades,numero_bilhete_novo,indice_lista_numeros_de_voo,ciclos,fechado,ciclos_fechado);
                voltar_ao_menu();
                sair = true;
                break;

            case 'o':
                menu_opcoes(ll_pista,ll_aproximacao,ll_descolados,ll_nacionalidades,conta_array_passageiros,fechado,ciclos_fechado);
                sair = true;
                break;

            case 'g':
                guardar_aeroportoEDA(ll_aproximacao,ll_pista,ll_descolados,ll_nacionalidades,numero_bilhete_novo,indice_lista_numeros_de_voo,ciclos,conta_array_passageiros,fechado,ciclos_fechado);
                voltar_ao_menu();
                sair = true;
                break;
            case 's':
                ciclo_seguinte(ll_aproximacao,ll_pista,ll_descolados,numero_bilhete_novo,indice_lista_numeros_de_voo,ciclos,ll_nacionalidades,fechado,ciclos_fechado);
                sair = true;
                break;

            default:
                cout << "Escolha uma opcao valida!" << endl;
                break;

        }

    }while(!sair);
    menu(ll_aproximacao,ll_pista,ll_descolados,numero_bilhete_novo,indice_lista_numeros_de_voo,ciclos,ll_nacionalidades,conta_array_passageiros,fechado,ciclos_fechado);
}

/** Luis
 * Função para simular a passagem de ciclos, desencadeada pelo utilizador
 * Começa por remover um avião ao conjunto de aviões a descolar, de seguida move um avião em pista para os descolados.
 * Move um avião do conjunto de aviões em aproximação para o conjunto de aviões em pista.
 * Adiciona um avião ao conjunto de aviões em aproximação.
 * Incrementa o número de ciclos.
 *
 * Caso esteja fechado o aeroporto apenas é adicionado um avião na aproximação, incrementado o ciclo e decrementado os ciclos restantes do aeroporto fechado.
 * Quando estes forem == 0 fechado recebe o valor false e o aeroporto é reaberto.
 * Caso a lista de aproximação tenha mais de 10 aviões são despachados dois para aterrar e levantar voo e adicionado um avião na aproximação a cada ciclo.
 * @param ll_aproximacao lista ligada de aviões em aproximção
 * @param ll_pista lista ligada de aviões em pista
 * @param ll_descolados lista ligada de aviões descolados
 * @param numero_bilhete_novo Número do proximo bilhete a ser criado
 * @param indice_lista_numeros_de_voo Índice usado para a atribuição de novos números de voo
 * @param ciclos Contagem dos ciclos da simulação
 * @param ll_nacionalidades Lista Ligada de nacionalidades
 * @param fechado booleano que guarda se o aeroporto está fechado ou não
 * @param ciclos_fechado número de ciclos que faltam para o aeroporto abrir
 *
 */
void ciclo_seguinte(LL_avioes &ll_aproximacao, LL_avioes &ll_pista, LL_avioes &ll_descolados,int &numero_bilhete_novo,int &indice_lista_numeros_de_voo, int &ciclos,LL_nacionalidades &ll_nacionalidades,bool &fechado, int &ciclos_fechado){
    if(fechado){
        adiciona_aproximacao(ll_aproximacao,numero_bilhete_novo,indice_lista_numeros_de_voo);
        ciclos++;
        ciclos_fechado--;
        if(ciclos_fechado==0){
            fechado = false;
        }
        return;
    }
    //adiciona nas descolagens, adiciona na pista, repete(para não acontecer da pista ficar com a capacidade errada), adiciona um na aproximação
    if(comprimento(ll_aproximacao) > 10){
        adiciona_descolados(ll_pista,ll_descolados);
        adiciona_pista(ll_aproximacao,ll_pista,indice_lista_numeros_de_voo, numero_bilhete_novo,ll_nacionalidades);
        adiciona_descolados(ll_pista,ll_descolados);
        adiciona_pista(ll_aproximacao,ll_pista,indice_lista_numeros_de_voo, numero_bilhete_novo,ll_nacionalidades);
        adiciona_aproximacao(ll_aproximacao,numero_bilhete_novo,indice_lista_numeros_de_voo); //
        ciclos++;
        return;
    }

    // caso a aproximação tenha um comprimento normal e não esteja fechado
    adiciona_descolados(ll_pista,ll_descolados);
    adiciona_pista(ll_aproximacao,ll_pista,indice_lista_numeros_de_voo, numero_bilhete_novo,ll_nacionalidades);
    adiciona_aproximacao(ll_aproximacao,numero_bilhete_novo,indice_lista_numeros_de_voo);
    ciclos++;
}


/** Luis
 * Pede que o utilizador pressione enter para poder voltar ao menu após usar uma função do aeroporto, de modo a facilitar a leitura dos dados
 */
void voltar_ao_menu(){
    cout << endl
         << "Pressione Enter para voltar ao menu. ";
    cin.ignore();
    cin.get();
}
/** Luis
 * Esta função guarda todos os dados do aeroporto em ficheiros.txt de modo a poder guardar o estado atual e carregar este estado noutro momento.
 * No ficheiro caracteristicas são guardados os comprimentos das listas ligadas aproximação, pista e descolados usando a função comprimento(), o número de ciclos, o número do proximo bilhete a ser criado e o índice do array de numeros de voo.
 * Nota: Os números de voo poderão ser repetidos se após guardar for usado um ficheiro de números de voo diferente do inicial(de dentro da pasta "ficheiros") na próxima execução do programa.
 * No ficheiro avioes são guardadas as características de cada avião seguido dos seus passageiros.
 * No ficheiro passageiros são guardadas as características de cada passageiro.
 *
 * @param ll_aproximacao Lista Ligada onde estão os aviões em aproximação
 * @param ll_pista Lista Ligada onde estão os aviões na pista
 * @param ll_descolados Lista Ligada onde estão os aviões a descolar
 * @param ll_nacionalidades Lista Ligada de nacionalidades
 * @param numero_bilhete_novo Variável que guarda o número do próximo bilhete a ser criado
 * @param indice_lista_numeros_de_voo Variavél que guarda o índice atual do array que é usado para atribuição de números de voo
 * @param ciclos Contagem dos ciclos da simulação
 * @param conta_array_passageiros Número de passageiros que tem dentro das árvores de pesquisa binária
 * @param fechado booleano que guarda se o aeroporto está fechado ou não
 * @param ciclos_fechado número de ciclos que faltam para o aeroporto abrir
 */
void guardar_aeroportoEDA(LL_avioes &ll_aproximacao, LL_avioes &ll_pista, LL_avioes &ll_descolados,LL_nacionalidades &ll_nacionalidades ,int &numero_bilhete_novo,int &indice_lista_numeros_de_voo, int &ciclos, int &conta_array_passageiros,bool &fechado, int &ciclos_fechado){
    ofstream caracteristicas("caracteristicas.txt");
    if (caracteristicas.is_open()) {
        caracteristicas << comprimento(ll_aproximacao) << endl;
        caracteristicas << comprimento(ll_pista) << endl;
        caracteristicas << comprimento(ll_descolados) << endl;
        caracteristicas << ciclos << endl;
        caracteristicas << numero_bilhete_novo << endl;
        caracteristicas << indice_lista_numeros_de_voo << endl;
        caracteristicas << fechado << endl;
        caracteristicas << ciclos_fechado << endl;
        caracteristicas.close();
    } else{
        cerr << "Erro a editar o ficheiro caracteristicas.txt";
    }

    ofstream avioes("avioes.txt");
    if(avioes.is_open()){
        LL_avioes::Item * iterator1 = ll_aproximacao.topo;
        while(iterator1 != NULL){
            avioes << iterator1->dados.nome_voo
                   << "|" << iterator1->dados.modelo_aviao
                   << "|" << iterator1->dados.capacidade
                   << "|" << iterator1->dados.origem
                   << "|" << iterator1->dados.destino << endl;

            aviao aviao_atual1 = iterator1->dados;
            aviao::Item * iterator_passageiro1 = aviao_atual1.topo;
            while(iterator_passageiro1 != NULL) {
                avioes << iterator_passageiro1->LL_passageiros.numero_bilhete
                       << "|" << iterator_passageiro1->LL_passageiros.primeiro_nome
                       << "|" << iterator_passageiro1->LL_passageiros.segundo_nome
                       << "|" << iterator_passageiro1->LL_passageiros.nacionalidade << endl;
                iterator_passageiro1 = iterator_passageiro1->seguinte;
            }
            iterator1=iterator1->seguinte;
        }
        delete iterator1;

        LL_avioes::Item * iterator2 = ll_pista.topo;
        while(iterator2 != NULL) {
            avioes << iterator2->dados.nome_voo
                   << "|" << iterator2->dados.modelo_aviao
                   << "|" << iterator2->dados.capacidade
                   << "|" << iterator2->dados.origem
                   << "|" << iterator2->dados.destino << endl;
            aviao aviao_atual2 = iterator2->dados;
            aviao::Item * iterator_passageiro2 = aviao_atual2.topo;
            while(iterator_passageiro2 != NULL) {
                avioes << iterator_passageiro2->LL_passageiros.numero_bilhete
                       << "|" << iterator_passageiro2->LL_passageiros.primeiro_nome
                       << "|" << iterator_passageiro2->LL_passageiros.segundo_nome
                       << "|" << iterator_passageiro2->LL_passageiros.nacionalidade << endl;
                iterator_passageiro2 = iterator_passageiro2->seguinte;
            }
            iterator2 = iterator2->seguinte;
        }
        delete iterator2;

        LL_avioes::Item * iterator3 = ll_descolados.topo;

        while(iterator3 != NULL) {
            avioes << iterator3->dados.nome_voo
                   << "|" << iterator3->dados.modelo_aviao
                   << "|" << iterator3->dados.capacidade
                   << "|" << iterator3->dados.origem
                   << "|" << iterator3->dados.destino << endl;
            aviao aviao_atual3 = iterator3->dados;
            aviao::Item * iterator_passageiro3 = aviao_atual3.topo;
            while(iterator_passageiro3 != NULL) {
                avioes << iterator_passageiro3->LL_passageiros.numero_bilhete
                       << "|" << iterator_passageiro3->LL_passageiros.primeiro_nome
                       << "|" << iterator_passageiro3->LL_passageiros.segundo_nome
                       << "|" << iterator_passageiro3->LL_passageiros.nacionalidade << endl;
                iterator_passageiro3 = iterator_passageiro3->seguinte;
            }
            iterator3 = iterator3->seguinte;
        }
        delete iterator3;

        avioes.close();
    }
    else{
        cerr << "Erro a editar o ficheiro avioes.txt";
    }

    ofstream passageiros("passageiros.txt");
    if (passageiros.is_open()) {
        passageiro * array_passageiros = passa_array(ll_nacionalidades,conta_array_passageiros);

        for (int i = 0;i<conta_array_passageiros;i++){
            passageiros << array_passageiros[i].numero_bilhete << "|"
                        << array_passageiros[i].primeiro_nome <<  "|"
                        << array_passageiros[i].segundo_nome <<   "|"
                    << array_passageiros[i].nacionalidade <<  "|" << endl;
        }
        delete[] array_passageiros;
    } else{
        cerr << "Erro a editar o ficheiro passageiros.txt";
    }

    cout << "O Aeroporto foi gravado com sucesso!" << endl;
}


/** Luis
 * Esta função permite que o utilizador mude a nacionalidade de qualquer passageiro dentro de um dos aviões da lista de aproximação.
 * A função apresenta numa lista todos os voos e a sua origem e pede ao utilizador para escolher um destes, caso a sua escolha não seja válida uma mensagem de erro irá ser exibida, podendo apenas continuar depois de introduzir um número válido.
 * Tendo em conta o número que o utilizador escolheu o iterador percorre a lista ligada até chegar ao voo escolhido, nesse voo um novo iterador é criado desta vez para percorrer a lista ligada de passageiros.
 * De seguida acontece o mesmo, são apresentadas as opções e o utilizador escolhe e o apontador para o passageiro pretendido é guardado.
 * A nacionalidade atual do passageiro é guardada na variável temp.
 * A função escolhe_nacionalidades() que tem um funcionamento semelhante a esta e que retorna a nacionalidade que o utilizador escolher, é chamada e atribui a nova nacionalidade do passageiro.
 * Por fim é apresentada uma mensagem de confirmação a mostrar o nome do passageiro e a nacionalidade antiga e a nova.
 *
 * @param ll_aproximacao Lista ligada de aproximação
 */
void muda_nacionalidade_passageiro(LL_avioes &ll_aproximacao){
    int lista = 1;
    LL_avioes::Item * iterator_voos = ll_aproximacao.topo;
    cout << "     Voo             Origem" << endl;
    while(iterator_voos != NULL) {
        cout << lista << " - " << iterator_voos->dados.nome_voo << " | " << iterator_voos->dados.origem << endl;
        iterator_voos = iterator_voos->seguinte;
        lista++;
    }
    lista--;
    cout << "Escolha o voo onde se encontra o passageiro que pretende editar: ";
    int opcao;
    bool sair = false;
    do{
        cin >> opcao;
        if (opcao > lista or opcao < 1){
            cout << "Escolha uma opcao valida!" << endl;
        }
        else{
            sair = true;
        }
    }while(!sair);

    iterator_voos = ll_aproximacao.topo;

    int i = 1;
    while(i<opcao){
        iterator_voos=iterator_voos->seguinte;
        i++;
    }

    aviao aviao_passageiro = iterator_voos->dados;
    aviao::Item * iterator_passageiros = aviao_passageiro.topo;
    lista = 1;
    cout << endl << "Passageiros a bordo do voo " << iterator_voos->dados.nome_voo << ":" << endl;
    while(iterator_passageiros != NULL){
        cout << lista << " - "
             << iterator_passageiros->LL_passageiros.primeiro_nome
             << " " << iterator_passageiros->LL_passageiros.segundo_nome
             << " | " << iterator_passageiros->LL_passageiros.nacionalidade << endl;
        iterator_passageiros=iterator_passageiros->seguinte;
        lista++;
    }
    lista--;
    cout << "Escolha um dos passageiros para editar a nacionalidade: ";
    sair = false;
    do{
        cin >> opcao;
        if (opcao > lista or opcao < 1){
            cout << "Escolha uma opcao valida!" << endl;
        }
        else{
            sair = true;
        }
    }while(!sair);

    i = 1;
    iterator_passageiros = aviao_passageiro.topo;
    while(i<opcao){
        iterator_passageiros=iterator_passageiros->seguinte;
        i++;
    }
    string temp = iterator_passageiros->LL_passageiros.nacionalidade;
    iterator_passageiros->LL_passageiros.nacionalidade = escolhe_nacionalidades();

    cout << endl << "A nacionalidade do passageiro "
         << iterator_passageiros->LL_passageiros.primeiro_nome << " "
         << iterator_passageiros->LL_passageiros.segundo_nome
         << " foi alterada com sucesso de " << temp << " para "
         << iterator_passageiros->LL_passageiros.nacionalidade << ".";
}
/** Luis
 * Esta função permite ao utilizador declarar emergência num voo em aproximação, para isto a função pede ao utilizador para escolher um voo, e caso seja necessário, um avião em pista irá levantar voo de modo a arranjar espaço.
 * Caso haja espaço na pista o segundo avião não será pedido ao utilizador e caso haja espaço na lista de descoladods não será removido um avião desta lista.
 * Ao chegar à pista o avião em emergência muda de número de voo, destino, origem e passageiros. (O número de voo novo é apresentado para facilitar o acompanhamento após a aterragem do avião em emergência).
 * Dependendo da posição dos voos escolhidos nas filas a função irá usar uma estratégia adequada para os movimentar.
 * (por exemplo quando um dos aviões está no topo da sua lista vs quando está no meio, pois é usado um iterador auxiliar para guardar a referência do avião anterior no segundo caso)
 * O ciclo é incrementado no fim da função.
 *
 * Caso o aeroporto esteja fechado uma mensagem é apresentada a informar que não é possivél aterrar nenhum avião pelo número de ciclos que é apresentado.
 *
 * @param ll_aproximacao Ligada onde estão os aviões em aproximação
 * @param ll_pista Ligada onde estão os aviões na pista
 * @param ll_descolados Lista Ligada onde estão os aviões a descolar
 * @param ll_nacionalidades Lista Ligada de nacionalidades
 * @param numero_bilhete_novo Variável que guarda o número do próximo bilhete a ser criado
 * @param indice_lista_numeros_de_voo Variavél que guarda o índice atual do array que é usado para atribuição de números de voo
 * @param ciclos Contagem dos ciclos da simulação
 * @param fechado booleano que guarda se o aeroporto está fechado ou não
 * @param ciclos_fechado número de ciclos que faltam para o aeroporto abrir
 *
 */
void emergencia(LL_avioes &ll_aproximacao,LL_avioes &ll_pista, LL_avioes &ll_descolados,LL_nacionalidades &ll_nacionalidades,int &numero_bilhete_novo, int &indice_lista_numeros_de_voo,int &ciclos,bool &fechado, int &ciclos_fechado){
    if(fechado){
        cout << "O aeroporto encontra-se fechado nao e possivel aterrar nenhum aviao durante " << ciclos_fechado << " ciclos." << endl;
        return;
    }
    if(comprimento(ll_pista)<7){ // se a pista não está cheia não é nessario nenhum avião descolar
        LL_avioes::Item * iterator_emergencia = ll_aproximacao.topo;
        LL_avioes::Item * iterator_emergencia_aux = ll_aproximacao.topo;
        int lista = 1;
        cout << "     Voo             Origem" << endl;
        while(iterator_emergencia!=NULL){
            cout << lista << " - " << iterator_emergencia->dados.nome_voo
                 << " | "
                 << iterator_emergencia->dados.origem << endl;
            iterator_emergencia = iterator_emergencia->seguinte;
            lista++;
        }
        iterator_emergencia = ll_aproximacao.topo;
        cout << "Escolha o voo que precisa de aterrar de emergencia: ";
        int opcao;
        bool sair = false;
        do{
            cin >> opcao;
            if(opcao<1 or opcao >lista-1)
                cout << "Opcao invalida, introduza um numero entre 1 e " << lista-1 << ": ";
            else
                sair = true;

        } while (!sair);

        for (int i = 0; i<opcao-1 ; i++){
            iterator_emergencia = iterator_emergencia->seguinte;
            if(i!=opcao-2)
                iterator_emergencia_aux = iterator_emergencia_aux->seguinte;
        }
        if(iterator_emergencia == ll_aproximacao.topo){ //caso o aviao em emergencia seja o topo da lista de chegada
            ll_aproximacao.topo = iterator_emergencia->seguinte;
            iterator_emergencia->seguinte = ll_pista.topo;
            ll_pista.topo = iterator_emergencia;
        }
        else{ //caso o aviao em emergência não seja o topo da lista de chegada
            iterator_emergencia_aux->seguinte=iterator_emergencia->seguinte;
            iterator_emergencia->seguinte=ll_pista.topo;
            ll_pista.topo = iterator_emergencia;
        }
        // mudança de informações e passageiros do avião em emergência
        adiciona_aproximacao(ll_aproximacao,numero_bilhete_novo,indice_lista_numeros_de_voo);
        string num_voo_antigo = iterator_emergencia->dados.nome_voo;
        iterator_emergencia->dados.nome_voo= numero_de_voo(indice_lista_numeros_de_voo);
        iterator_emergencia->dados.origem = "AeroportoEDA - Madeira, Portugal";
        iterator_emergencia->dados.destino = destino_aleatorio();

        //mudar passageiros---------------------------------------------------------------------------------------------
        aviao::Item * iterator_passageiros = iterator_emergencia->dados.topo;
        passageiro * retirados = new passageiro[iterator_emergencia->dados.capacidade];

        int i = 0;
        passageiro novo;
        while(iterator_passageiros != NULL) {
            novo = criar_passageiro(numero_bilhete_novo);
            retirados[i] = iterator_passageiros->LL_passageiros;
            i++;
            iterator_passageiros->LL_passageiros = novo;
            iterator_passageiros = iterator_passageiros->seguinte;
        }
        adiciona_passageiros_estrangeiros(retirados,iterator_emergencia->dados.capacidade,ll_nacionalidades);

        LL_nacionalidades::Item * procura;
        passageiro array_estr[3];
        passageiro * estrangeiro;
        int j = 0;

        while (j < 3) {

            procura = ll_nacionalidades.topo;
            string nacionalidade = nacionalidade_aleatoria();

            while (nacionalidade == "Portuguese")
                nacionalidade = nacionalidade_aleatoria();

            while (procura->nacionalidade != nacionalidade)
                procura = procura->seguinte;


            estrangeiro = procura_passageiro_random(procura->raiz);
            if(estrangeiro==NULL) {
                continue;
            }
            array_estr[j].primeiro_nome = estrangeiro->primeiro_nome;
            array_estr[j].segundo_nome = estrangeiro->segundo_nome;
            array_estr[j].nacionalidade = estrangeiro->nacionalidade;
            array_estr[j].numero_bilhete = estrangeiro->numero_bilhete;
            remover_copia(procura->raiz, estrangeiro->segundo_nome);

            j++;
        }


        int k = 0;
        iterator_passageiros = ll_pista.topo->dados.topo;
        passageiro escala;
        while (k < 3) {
            escala = array_estr[k];
            iterator_passageiros->LL_passageiros = escala;
            iterator_passageiros = iterator_passageiros->seguinte;
            k++;
        }

        cout << "O voo " << num_voo_antigo << " aterrou com sucesso, e foi alterado para o numero " << iterator_emergencia->dados.nome_voo << endl;
        delete[] retirados;
    }

    else{   //Caso a pista esteja cheia é necessario escolher um avião para levantar voo de modo a arranjar espaço
        LL_avioes::Item * iterator_emergencia = ll_aproximacao.topo;
        LL_avioes::Item * iterator_emergencia_aux = ll_aproximacao.topo;
        int lista = 1;
        cout << "     Voo             Origem" << endl;
        while(iterator_emergencia!=NULL){
            cout << lista << " - " << iterator_emergencia->dados.nome_voo
                 << " | "
                 << iterator_emergencia->dados.origem << endl;
            iterator_emergencia = iterator_emergencia->seguinte;
            lista++;
        }
        iterator_emergencia = ll_aproximacao.topo;
        cout << "Escolha o voo que precisa de aterrar de emergencia: ";
        int opcao;
        bool sair = false;
        do{
            cin >> opcao;
            if(opcao<1 or opcao >lista-1)
                cout << "Opcao invalida, introduza um numero entre 1 e " << lista-1 << ": ";
            else
                sair = true;

        } while (!sair);

        for (int i = 0; i<opcao-1 ; i++){
            iterator_emergencia = iterator_emergencia->seguinte;
            if(i!=opcao-2)
                iterator_emergencia_aux = iterator_emergencia_aux->seguinte;
        }

        //iterator_emergencia avião que está em emergência
        cout << endl;

        LL_avioes::Item * iterator_retirado = ll_pista.topo;
        LL_avioes::Item * iterator_retirado_aux = ll_pista.topo;
        lista = 1;
        cout << "     Voo             Destino" << endl;
        while(iterator_retirado!=NULL){
            cout << lista << " - " << iterator_retirado->dados.nome_voo
                 << " | "
                 << iterator_retirado->dados.destino << endl;
            iterator_retirado = iterator_retirado->seguinte;
            lista++;
        }
        iterator_retirado = ll_pista.topo;
        cout << "Escolha o voo que precisa de descolar para o voo " << iterator_emergencia->dados.nome_voo
             << " poder aterrar: ";

        sair = false;
        do{
            cin >> opcao;
            if(opcao<1 or opcao >lista-1)
                cout << "Opcao invalida, introduza um numero entre 1 e " << lista-1 << ": ";
            else
                sair = true;

        } while (!sair);

        for (int i = 0; i<opcao-1 ; i++){
            iterator_retirado = iterator_retirado->seguinte;
            if(i!=opcao-2)
                iterator_retirado_aux=iterator_retirado_aux->seguinte;
        }

        // iterator_retirado é o avião a ser retirado
        if (comprimento(ll_descolados)<5) { //caso as descolagens não estejam cheias não é necessário remover um avião
            if (iterator_emergencia == ll_aproximacao.topo){ // caso o avião em emergência seja o topo da lista de aproximação
                if(iterator_retirado==ll_pista.topo){ // caso o avião a ser retirado seja o topo da lista da pista
                    ll_aproximacao.topo = iterator_emergencia->seguinte;
                    iterator_emergencia->seguinte=iterator_retirado->seguinte;
                    ll_pista.topo = iterator_emergencia;
                    iterator_retirado->seguinte=ll_descolados.topo;
                    ll_descolados.topo=iterator_retirado;
                    adiciona_aproximacao(ll_aproximacao,numero_bilhete_novo,indice_lista_numeros_de_voo);
                }
                else{ // caso o avião a ser retirado não seja o topo da lista da pista
                    ll_aproximacao.topo = iterator_emergencia->seguinte;
                    iterator_emergencia->seguinte=iterator_retirado->seguinte;
                    iterator_retirado_aux->seguinte=iterator_emergencia;
                    iterator_retirado->seguinte=ll_descolados.topo;
                    ll_descolados.topo=iterator_retirado;
                    adiciona_aproximacao(ll_aproximacao,numero_bilhete_novo,indice_lista_numeros_de_voo);
                }

            }
            else{ // caso o avião em emergência não seja o topo da lista de aproximação
                if(iterator_retirado==ll_pista.topo){ /// caso o avião a ser retirado seja o topo da lista da pista
                    iterator_emergencia_aux->seguinte=iterator_emergencia->seguinte;
                    iterator_emergencia->seguinte=iterator_retirado->seguinte;
                    ll_pista.topo=iterator_emergencia;
                    iterator_retirado->seguinte=ll_descolados.topo;
                    ll_descolados.topo=iterator_retirado;
                    adiciona_aproximacao(ll_aproximacao,numero_bilhete_novo,indice_lista_numeros_de_voo);
                }
                else{ // caso o avião a ser retirado não seja o topo da lista da pista
                    iterator_emergencia_aux->seguinte=iterator_emergencia->seguinte;
                    iterator_retirado_aux->seguinte=iterator_emergencia;
                    iterator_emergencia->seguinte=iterator_retirado->seguinte;
                    iterator_retirado->seguinte=ll_descolados.topo;
                    ll_descolados.topo=iterator_retirado;
                    adiciona_aproximacao(ll_aproximacao,numero_bilhete_novo,indice_lista_numeros_de_voo);
                }
            }
        }
        else{ // as descolagens está cheia por isso é preciso remover um avião do fim.
            retirar_avioes(ll_descolados); // retira o ultimo aviao dos descolados
            if (iterator_emergencia == ll_aproximacao.topo){ // caso o avião em emergência seja o topo da lista de aproximação
                if(iterator_retirado==ll_pista.topo){ // caso o avião a ser retirado seja o topo da lista da pista
                    ll_aproximacao.topo = iterator_emergencia->seguinte;
                    iterator_emergencia->seguinte=iterator_retirado->seguinte;
                    ll_pista.topo=iterator_emergencia;
                    iterator_retirado->seguinte=ll_descolados.topo;
                    ll_descolados.topo=iterator_retirado;
                    adiciona_aproximacao(ll_aproximacao,numero_bilhete_novo,indice_lista_numeros_de_voo);
                }
                else{ // caso o avião a ser retirado não seja o topo da lista da pista
                    ll_aproximacao.topo = iterator_emergencia->seguinte;
                    iterator_emergencia->seguinte=iterator_retirado->seguinte;
                    iterator_retirado_aux->seguinte=iterator_emergencia;
                    iterator_retirado->seguinte=ll_descolados.topo;
                    ll_descolados.topo=iterator_retirado;
                    adiciona_aproximacao(ll_aproximacao,numero_bilhete_novo,indice_lista_numeros_de_voo);
                }

            }
            else{ // caso o avião em emergência não seja o topo da lista de aproximação
                if(iterator_retirado==ll_pista.topo){ // caso o avião a ser retirado seja o topo da lista da pista
                    iterator_emergencia_aux->seguinte=iterator_emergencia->seguinte;
                    iterator_emergencia->seguinte=iterator_retirado->seguinte;
                    ll_pista.topo=iterator_emergencia;
                    iterator_retirado->seguinte=ll_descolados.topo;
                    ll_descolados.topo = iterator_retirado;
                    adiciona_aproximacao(ll_aproximacao,numero_bilhete_novo,indice_lista_numeros_de_voo);
                }
                else{ // caso o avião a ser retirado não seja o topo da lista da pista
                    iterator_emergencia_aux->seguinte=iterator_emergencia->seguinte;
                    iterator_retirado_aux->seguinte=iterator_emergencia;
                    iterator_emergencia->seguinte=iterator_retirado->seguinte;
                    iterator_retirado->seguinte=ll_descolados.topo;
                    ll_descolados.topo = iterator_retirado;
                    adiciona_aproximacao(ll_aproximacao,numero_bilhete_novo,indice_lista_numeros_de_voo);
                }
            }

        }


        //mudar numero de voo, origem e destino
        string num_voo_antigo = iterator_emergencia->dados.nome_voo;
        iterator_emergencia->dados.nome_voo= numero_de_voo(indice_lista_numeros_de_voo);
        iterator_emergencia->dados.origem = "AeroportoEDA - Madeira, Portugal";
        iterator_emergencia->dados.destino = destino_aleatorio();

        //mudar passageiros ------------------------------------------------------------------------------------------------
        aviao::Item * iterator_passageiros = iterator_emergencia->dados.topo;
        passageiro * retirados = new passageiro[iterator_emergencia->dados.capacidade];

        int i = 0;
        passageiro novo;
        while(iterator_passageiros != NULL) {
            novo = criar_passageiro(numero_bilhete_novo);
            retirados[i] = iterator_passageiros->LL_passageiros;
            i++;
            iterator_passageiros->LL_passageiros = novo;
            iterator_passageiros = iterator_passageiros->seguinte;
        }
        adiciona_passageiros_estrangeiros(retirados,iterator_emergencia->dados.capacidade,ll_nacionalidades);

        LL_nacionalidades::Item * procura;
        passageiro array_estr[3];
        passageiro * estrangeiro;
        int j = 0;

        while (j < 3) {

            procura = ll_nacionalidades.topo;
            string nacionalidade = nacionalidade_aleatoria();

            while (nacionalidade == "Portuguese")
                nacionalidade = nacionalidade_aleatoria();

            while (procura->nacionalidade != nacionalidade)
                procura = procura->seguinte;


            estrangeiro = procura_passageiro_random(procura->raiz);
            if(estrangeiro==NULL) {
                continue;
            }

            array_estr[j].primeiro_nome = estrangeiro->primeiro_nome;
            array_estr[j].segundo_nome = estrangeiro->segundo_nome;
            array_estr[j].nacionalidade = estrangeiro->nacionalidade;
            array_estr[j].numero_bilhete = estrangeiro->numero_bilhete;
            remover_copia(procura->raiz, estrangeiro->segundo_nome);

            j++;
        }

        int k = 0;
        iterator_passageiros = ll_pista.topo->dados.topo;
        passageiro escala;
        while (k < 3) {
            escala = array_estr[k];
            iterator_passageiros->LL_passageiros = escala;
            iterator_passageiros = iterator_passageiros->seguinte;
            k++;
        }

        delete[] retirados;
        cout << "O voo " << num_voo_antigo << " aterrou com sucesso, e foi alterado para o numero " << iterator_emergencia->dados.nome_voo << endl;
    }
    ciclos++;
}

/**
 * Apresenta um menu para escolher como o utilizador quer visualizar os passageiros.
 * @param ll_nacionalidades Lista ligada de nacionalidades
 * @param conta_array_passageiros tamanho de um array de passageiros
 */
void menu_imprime_passageiros(LL_nacionalidades &ll_nacionalidades,int &conta_array_passageiros){
    cout << endl
         << "Opcoes:" << endl
         << "1 - Todos os passageiros em pista" << endl
         << "2 - Passageiros por Nacionalidade ordenados por ordem alfabetica" << endl
         << "3 - Passageiros por Nacionalidade em formato de Arvore de Pesquisa Binaria" << endl
         << "0 - Voltar ao menu" << endl;

    cout << "Escolha uma opcao: ";
    bool sair = false;
    char opcao;
    while(!sair){
        cin >> opcao;
        switch(opcao){
            case '1':
                imprime_todos_os_passageiros(ll_nacionalidades, conta_array_passageiros);
                voltar_ao_menu();
                sair = true;
                break;

            case '2':
                imprime_por_nacionalidade(ll_nacionalidades,conta_array_passageiros);
                voltar_ao_menu();
                sair = true;
                break;

            case '3':
                imprime_arvore_por_nacionalidade(ll_nacionalidades);
                voltar_ao_menu();
                sair=true;
                break;

            case '0':
                sair = true;

            default:
                cout << "Escolha uma opcao valida!" << endl;
        }
    }
}


/** Luis
 * Recebe o array criado em passa_array() que contém todos os passageiros que estão dentro das árvores de pesquisa binária e imprime as informações na consola.
 * Por fim a memória do array é desalocada.
 * @param ll_nacionalidades Lista ligada de nacionalidades
 * @param conta_array_passageiros tamanho do array recebido da função passa_array
 */
void imprime_todos_os_passageiros(LL_nacionalidades &ll_nacionalidades,int &conta_array_passageiros){

    cout << "Passageiros em pista: " << endl;

    passageiro * array = passa_array(ll_nacionalidades,conta_array_passageiros);
    for(int i = 0; i < conta_array_passageiros ; i++){
        cout << array[i].numero_bilhete << " | "
             << array[i].primeiro_nome << " "
             << array[i].segundo_nome << " | "
             << array[i].nacionalidade << endl;
    }
    delete[] array;
}
/** Luis
 * Função para auxiliar o algoritmo bubble sort, troca dois valores que são passados como parâmetros
 */
void troca(passageiro& a, passageiro& b) {
    passageiro temp = a;
    a = b;
    b = temp;
}

/** Luis
 * Esta função pede ao utilizador para escolher uma nacionalidade e de seguida apresenta todos os passageiros contidos na
 * árvore de pesquisa binária dessa nacionalidade, organizados pela ordemm alfabetica do seu primeiro nome. A organização é feita pelo algoritmo BubbleSort
 * @param ll_nacionalidades Lista ligada de nacionalidades
 * @param conta_array_passageiros tamanho do array usado
 */
void imprime_por_nacionalidade(LL_nacionalidades &ll_nacionalidades,int &conta_array_passageiros){

    string nacionalidade = escolhe_nacionalidades_imprimir();

    passageiro * array = passa_array_nacionalidade(ll_nacionalidades,conta_array_passageiros,nacionalidade);

    bool trocado = true; // Bubble sort para organizar por ordem alfabetica do primeiro nome
    for (int i = 0; i < conta_array_passageiros and trocado;i++) {
        trocado = false;
        for (int j = conta_array_passageiros - 1; j > i; j--)
            if (array[j].primeiro_nome < array[j - 1].primeiro_nome) {
                troca(array[j], array[j - 1]);
                trocado = true;
            }
    }
    for(int i = 0; i < conta_array_passageiros; i++){
        cout << array[i].numero_bilhete << " | "
             << array[i].primeiro_nome << " "
             << array[i].segundo_nome << " | "
             << array[i].nacionalidade << endl;
    }

    delete[] array;
}
/** Luis
 * Função que pede ao utilizador para escolher uma nacionalidade e imprime a árvore de pesquisa binária correspoondente a essa nacionalidade.
 * @param ll_nacionalidades Lista ligada de nacionalidades onde estão contidas as respetivas árvores
 */
void imprime_arvore_por_nacionalidade(LL_nacionalidades &ll_nacionalidades){
    string nacionalidade = escolhe_nacionalidades_imprimir();

    LL_nacionalidades::Item * iterator = ll_nacionalidades.topo;
    while(iterator->nacionalidade != nacionalidade){
        iterator = iterator->seguinte;
    }
    cout << endl << "Passageiros da nacionalidade " << nacionalidade << " em pista: " << endl;
    imprime_arvore(iterator->raiz,1);
};

/** Luis
 *  Função que pede ao utilizador para introduzir o primeiro nome de um passageiro e imprime as informações do(s) passageiro(s) com esse nome que estão nas chegadas ou nas partidas.
 *  É usado um iterador para percorrer a lista ligada de aviões e outro para percorrer a lista ligada de passageiros contida em cada avião, para cada passageiro o primeiro nome é
 *  comparado ao nome que o utilizador forneceu, caso seja igual as suas informações irão ser imprimidas na consola.
 *  Caso não seja encontrado nenhum passageiro com o nome fornecido o utilizador irá ser informado e poderá escolher introduzir outro nome ou voltar para o menu.
 * @param ll_aproximacao Lista ligada de aviões em aproximação
 * @param ll_descolados Lista ligada de avioes descolados
 */
void pesquisa_passageiros(LL_avioes &ll_aproximacao, LL_avioes &ll_descolados){
    string nome;
    cout << endl << "Introduza o primeiro nome do passageiro que quer pesquisar(Primeria letra maiscula): ";
    cin >> nome;
    bool encontrado_chegadas = false;

    LL_avioes::Item * iterator1 = ll_aproximacao.topo;
    while(iterator1 != NULL){
        aviao aviao_atual1 = iterator1->dados;
        aviao::Item * iterator_passageiro1 = aviao_atual1.topo;

        while(iterator_passageiro1 != NULL){
            if(nome == iterator_passageiro1->LL_passageiros.primeiro_nome ){
                if (encontrado_chegadas == false){
                    encontrado_chegadas = true;
                    cout << endl << "Resultados Chegadas:" << endl;
                }
                //Informações passageiro
                cout << "Voo: " << iterator1->dados.nome_voo
                     << " | " <<iterator_passageiro1->LL_passageiros.primeiro_nome
                     << " " << iterator_passageiro1->LL_passageiros.segundo_nome
                     << " | " << iterator_passageiro1->LL_passageiros.numero_bilhete
                     << " | " << iterator_passageiro1->LL_passageiros.nacionalidade << endl;
            }
            iterator_passageiro1 = iterator_passageiro1->seguinte;
        }
        iterator1=iterator1->seguinte;

    }

    bool encontrado_partidas = false;
    LL_avioes::Item * iterator2 = ll_descolados.topo;
    while(iterator2 != NULL){
        aviao aviao_atual2 = iterator2->dados;
        aviao::Item * iterator_passageiro2 = aviao_atual2.topo;

        while(iterator_passageiro2 != NULL){
            if(nome == iterator_passageiro2->LL_passageiros.primeiro_nome ){
                if (encontrado_partidas == false){
                    encontrado_partidas = true;
                    cout << endl
                         << endl
                         << "Resultados Partidas:" << endl;
                }
                //Informações passageiro
                cout << "Voo: " << iterator2->dados.nome_voo
                     << " | " <<iterator_passageiro2->LL_passageiros.primeiro_nome
                     << " " << iterator_passageiro2->LL_passageiros.segundo_nome
                     << " | " << iterator_passageiro2->LL_passageiros.numero_bilhete
                     << " | " << iterator_passageiro2->LL_passageiros.nacionalidade << endl;
            }
            iterator_passageiro2 = iterator_passageiro2->seguinte;
        }
        iterator2=iterator2->seguinte;

    }

    if(!encontrado_chegadas and !encontrado_partidas){
        cout << endl << "A pesquisa do nome '" << nome << "' obteve 0 resultados." << endl;
        cout << "Verifique se introduziu o nome do passageiro corretamente." << endl;

        cout << endl << "Pressione '1' para voltar a introduzir o nome, ou qualquer outra tecla para voltar ao menu: ";
        char opcao;
        cin >> opcao;

        if(opcao == '1')
            pesquisa_passageiros(ll_aproximacao,ll_descolados);
        else
            return;
    }
    voltar_ao_menu();
}
/**
 * Caso o aeroporto já esteja fechado o utilizador é informado e a função acaba.
 * Caso contrario pergunta ao utilizador quantos ciclos deve estar fechado o aeroporto e atribui esse valor à variável ciclos_fechado e atribui true à variável fechado.
 * @param fechado booleano que guarda se o aeroporto está fechado ou não
 * @param ciclos_fechado número de ciclos que faltam para o aeroporto abrir
 */
void fechar_aeroporto(bool &fechado, int &ciclos_fechado){
    if(fechado){
        cout << "O aeroporto ja se encontra fechado, faltam " << ciclos_fechado << " ciclos para voltar a abrir.";
        return;
    }
    int opcao;
    cout  << "Escolha por quantos ciclos ira fechar o aeroporto(entre 1 e 5): ";
    while(true){
        cin >> opcao;
        if (opcao < 1 or opcao > 5){
            cout << "Opcao invalida, escolha um numero entre 1 e 5." << endl;
        }
        else
            break;
    }
    ciclos_fechado = opcao;
    fechado = true;

    cout << "O aeroporto foi fechado durante " << ciclos_fechado << " ciclos com sucesso." << endl;
}