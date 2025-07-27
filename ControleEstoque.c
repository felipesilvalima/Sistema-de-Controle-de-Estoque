#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Produto
{
    int codigo[50];
    char nome[50][30];
    char descricao[50][80];
    char categoria[50][30];
    char fabricante[50][30];
    char fornecedor[50][30];
    char unidade_medida[50][30];
    float preco_venda[50];
    float preco_custo[50];
    int estoque_atual[50];
    int estoque_minimo[50];
    int codigo_barras[50];
    int data_cadastro[50];
    char status[50][10];
};

struct Usuarios
{
    char usuario[50][30];
    char senha[50][30];
};


int main()
{
    // Declaração das funções usadas no programa
    int CadastrarProdutos(int totalProduto,int produto_encontrado, int fornecedorEncontrado, int receber_total_fornecedores, char escolha_fornecedor[30], int sair,struct Produto *pd);
    void entradaEstoque(int opcao, int receber_total_produtos, int buscarProduto, int produto_encontrado, int receberQuantidade, struct Produto *pd);
    void saidaEstoque(int opcao, int receber_total_produtos, int produto_encontrado, int buscarProduto, int receberQuantidade, struct Produto *pd);
    void relatorios(int fornecedorEncontrado, int sair, int receber_total_produtos, int totalFornecedor, char escolha_fornecedor[30], int buscarProduto, int produto_encontrado, struct Produto *pd );
    int cadastrarFornecedores(int c, int sair, int receber_novo_total_fornecedores, int produto_encontrado, int totalFornecedor, int opcao, struct Produto *pd);
    void gerenciamentoUsuario(int sair, char admin[50], char senha_admin[50], int opcao, int total_cadastro_usuarios, int encontrar_usuario, int editar, char ultimo_usuario[40], int receberInicio, struct Usuarios *user);
    void alertaEstoque(int sair, int produto_encontrado, int receber_total_produtos, struct Produto *pd);

    // Credenciais de administrador definidas via macro
    #define ADMIN "admin"
    #define SENHA_ADMIN "admin"

    // Definição do máximo total de produtos e fornecedores
    #define MAX_TOTAL 49

    // Declaração das variáveis usadas no programa
    char usuario[50];
    char senha_usuario[50];
    char admin[50];
    char senha_admin[50];
    int sair = 0;   // Controle do loop principal de login e menu
    int escolher, i, c = 0;
    int totalProduto = 0;
    int totalFornecedor = 0;
    int buscarProduto;
    int opcao;
    int receberQuantidade;
    int produto_encontrado = 0;
    char escolha_fornecedor[30];
    int fornecedorEncontrado = 0;
    int total_cadastro_usuarios = 1; // Começa com 1 porque já existe usuário inicial
    int encontrar_usuario = 0;
    int editar = 0;
    int receberInicio = 1;
    char ultimo_usuario[40];
    int receber_total_produtos = 0;
    int receber_total_fornecedores = 0;
    int receber_novo_total_fornecedores = 0;
    // Declaração das estruturas para produtos e usuários
    struct Produto pd;
    struct Usuarios user;

    // Inicialização do primeiro usuário padrão
    strcpy(user.usuario[0], "user");
    strcpy(user.senha[0], "12345");

    // Loop principal do programa que exibe o login e menu
    while (sair != 1)
    {
        encontrar_usuario = 0; // Reset flag para encontrar usuário no login

        // Solicita usuário e senha para login
        printf("Digite seu usuário:\n");
        scanf("%49s", usuario);
        while(getchar() != '\n'); // Limpa buffer de entrada

        printf("Digite sua senha:\n");
        scanf("%49s", senha_usuario);
        while(getchar() != '\n'); // Limpa buffer de entrada

        // Loop para verificar se as credenciais informadas correspondem a algum usuário cadastrado
        for(i = 0; i < total_cadastro_usuarios; i++)
        {
            if(strcmp(usuario, user.usuario[i]) == 0 && strcmp(senha_usuario, user.senha[i]) == 0)
            {
                encontrar_usuario = 1; // Usuário encontrado

                printf("Usuário logado com sucesso!\n");

                // Loop do menu principal após login
                while(sair != 2)
                {
                    // Exibe opções do menu
                    printf("------------MENU------------------\n");
                    printf("1. CADASTRAR PRODUTO\n");
                    printf("2. ENTRADA DE ESTOQUE\n");
                    printf("3. SAIDA DE ESTOQUE\n");
                    printf("4. RELATÓRIOS\n");
                    printf("5. CADASTRO DE FORNECEDORES\n");
                    printf("6. GERENCIAR USUÁRIOS\n");
                    printf("7. ALERTA DE ESTOQUE MINIMO\n");
                    printf("8. SAIR\n");
                    scanf("%d", &escolher);

                    // Chamada das funções conforme a opção escolhida,
                    // mesmo que as funções executem ações somente se o parâmetro "escolher" corresponder
                if(escolher == 1)
                {
                    receber_total_produtos =  CadastrarProdutos(totalProduto,produto_encontrado,fornecedorEncontrado, receber_total_fornecedores, escolha_fornecedor, sair, &pd);
                }

                if(escolher == 2)
                {
                    entradaEstoque(opcao, receber_total_produtos,  buscarProduto, produto_encontrado,receberQuantidade, &pd);
                }

                if(escolher == 3)
                {
                    saidaEstoque(opcao, receber_total_produtos,  produto_encontrado,  buscarProduto,  receberQuantidade, &pd);
                }

                if(escolher == 4)
                {
                    relatorios(fornecedorEncontrado,  sair,  receber_total_produtos, receber_total_fornecedores,  escolha_fornecedor,  buscarProduto,  produto_encontrado, &pd );
                }

                if(escolher == 5)
                {
                    receber_total_fornecedores =  cadastrarFornecedores( c , sair,receber_novo_total_fornecedores,  produto_encontrado,  totalFornecedor,  opcao, &pd);
                    receber_novo_total_fornecedores += receber_total_fornecedores;
                }

                if(escolher == 6)
                {
                    gerenciamentoUsuario(sair,  admin,  senha_admin,  opcao,  total_cadastro_usuarios,  encontrar_usuario,  editar,  ultimo_usuario,  receberInicio,  &user);
                }

                if(escolher == 7)
                {
                    alertaEstoque(sair,  produto_encontrado,  receber_total_produtos, &pd);
                }

                    // Se opção for 8, sai do menu e programa
                    if(escolher == 8)
                    {
                        break;
                    }

                    // Validação para opções inválidas
                    if(escolher != 1 && escolher != 2 &&  escolher != 3 && escolher != 4 && escolher != 5 && escolher != 6 && escolher != 7 && escolher != 8 )
                    {
                        printf("Opção inválida\n");
                    }
                }
            }
        }

        // Caso o usuário não seja encontrado, exibe mensagem
        if(encontrar_usuario == 0)
        {
            printf("Usuário inválido\n");
        }
    }

    return 0;
}



int CadastrarProdutos(int totalProduto, int produto_encontrado, 
                      int fornecedorEncontrado, int receber_total_fornecedores, 
                      char escolha_fornecedor[30], int sair, struct Produto *pd)
{
    int escolher = 0;
    // Verifica se a opção escolhida foi 1 (cadastrar produto)
   
        printf("--------------CADASTRAR PRODUTO-------------------------\n\n");

        // Loop para cadastrar até MAX_TOTAL produtos
        for (int i = 0; i < MAX_TOTAL; i++)
        {
            produto_encontrado = 0;      // Reseta a flag para indicar se existe fornecedor
            fornecedorEncontrado = 0;    // Reseta a flag para indicar se o fornecedor foi encontrado

            // Entrada do código do produto
            printf(" Digite codigo do produto\n");
            scanf("%d", &pd->codigo[i]);

            // Entrada do nome do produto
            printf(" Digite nome do produto\n");
            while (getchar() != '\n'); // Limpa buffer
            fgets(pd->nome[i], 30, stdin);

            // Entrada da categoria
            printf(" Digite categoria do produto\n");
            scanf("%29s", pd->categoria[i]);
            while (getchar() != '\n');

            // Entrada do preço de custo
            printf(" Digite preço de custo do produto\n");
            scanf("%f", &pd->preco_custo[i]);

            // Entrada do preço de venda
            printf(" Digite preço de venda do produto\n");
            scanf("%f", &pd->preco_venda[i]);

            // Entrada do estoque atual
            printf(" Digite o estoque atual do produto\n");
            scanf("%d", &pd->estoque_atual[i]);

            // Entrada do estoque mínimo
            printf(" Digite estoque minimo do produto\n");
            scanf("%d", &pd->estoque_minimo[i]);

            // Entrada da unidade de medida
            printf(" Digite a unidade de medida do produto\n");
            scanf("%19s", pd->unidade_medida[i]);
            while (getchar() != '\n');

            // Entrada do código de barras
            printf(" Digite codigo de barras do produto\n");
            scanf("%d", &pd->codigo_barras[i]);

            // Entrada da descrição
            printf(" Digite a descrição do produto\n");
            while (getchar() != '\n');
            fgets(pd->descricao[i], 80, stdin);

            // Entrada do status do produto
            printf(" Digite o status do produto (ativo) ou (negativo)\n");
            scanf("%9s", pd->status[i]);
            while (getchar() != '\n');

            // Validação do status (somente "ativo" ou "negativo")
            while (strcmp(pd->status[i], "ativo") != 0 && strcmp(pd->status[i], "negativo") != 0)
            {
                printf(" Digite o status do produto (ativo) ou (negativo)\n");
                scanf("%9s", pd->status[i]);
                while (getchar() != '\n');
            }

            // Entrada da data de cadastro
            printf(" Digite a data de cadastro do produto\n");
            scanf("%d", &pd->data_cadastro[i]);
            while (getchar() != '\n');

            // Lista todos os fornecedores cadastrados
            for (i = 0; i < receber_total_fornecedores; i++)
            {
                produto_encontrado = 1;
                printf("FORNECEDOR: %d:\n", i + 1);
                printf("FORNERCEDORES: %s\n\n", pd->fornecedor[i]);
            }

            // Se não existir fornecedor, força o usuário a ir para aba de fornecedores
            if (produto_encontrado == 0)
            {
                printf("Está sem fornecedores vá para a aba de fornecedores digitando 5");
                scanf("%d", &escolher);
                while (getchar() != '\n');

                while (escolher != 5)
                {
                    printf("Você está sem fornecedores vá para a aba de fornecedores digitando 5");
                    scanf("%d", &escolher);
                    while (getchar() != '\n');
                }

                if (escolher == 5) { break; }
            }

            // Escolhe o fornecedor pelo nome
            while (fornecedorEncontrado != 1)
            {
                printf("Escolha o fornecedor pelo nome\n\n");
                fgets(escolha_fornecedor, 30, stdin);
                escolha_fornecedor[strcspn(escolha_fornecedor, "\n")] = 0; // Remove \n

                for (int c = 0; c < receber_total_fornecedores; c++)
                {
                    if (strcmp(escolha_fornecedor, pd->fornecedor[c]) == 0)
                    {
                        fornecedorEncontrado = 1;
                        break;
                    }
                }
            }

            // Incrementa total de produtos
            totalProduto += 1;

            // Verifica se atingiu o máximo de produtos
            if (totalProduto > MAX_TOTAL)
            {
                printf("Atingiu o Máximo total de produtos\n");
            }
            else
            {
                printf("Produto cadastrado com sucesso\n\n");
                printf("1- para continuar\n");
                printf("0- para sair\n");
                scanf("%d", &sair);

                // Validação da escolha do usuário
                while (sair != 0 && sair != 1)
                {
                    printf("1- para continuar\n");
                    printf("0- para sair\n");
                    scanf("%d", &sair);
                }

                if (sair == 0) { return totalProduto; break; }
                return totalProduto;
            }
        }
    
}



void entradaEstoque(int opcao, int receber_total_produtos, 
                    int buscarProduto, int produto_encontrado, int receberQuantidade,  
                    struct Produto *pd)
{
    // Verifica se a opção escolhida foi 2 (entrada de estoque)
        printf("--------------ENTRADA DE ESTOQUE-------------------------\n\n");

        opcao = 0;

        // Mantém o usuário dentro do menu até ele escolher sair (opção 3)
        while (opcao != 3)
        {
            // Lista todos os produtos cadastrados (menos o último?)
            for (int i = 0; i < receber_total_produtos - 1; i++)
            {
                printf("Código do produto: %d\n", pd->codigo[i]);
                printf("Nome do produto: %s", pd->nome[i]);
                printf("status do produto: %s\n\n", pd->status[i]);
            }

            // Permite buscar um produto pelo código
            for (int i = 0; i < receber_total_produtos; i++)
            {
                printf("Digite o código do produto\n");
                scanf("%d", &buscarProduto);

                // Percorre a lista de produtos para encontrar o código digitado
                for (i = 0; i < receber_total_produtos; i++)
                {
                    if (buscarProduto == pd->codigo[i])
                    {
                        produto_encontrado = 1;

                        // Exibe informações do produto encontrado
                        printf("Estoque atual do produto: %d\n", pd->estoque_atual[i]);
                        printf("1- para Inserir a quantidade do produto\n");
                        printf("2- para voltar\n");
                        printf("3- para voltar ao Menu\n");
                        scanf("%d", &opcao);

                        // Gerencia a escolha do usuário
                        switch (opcao)
                        {
                            case 1:
                                // Entrada da quantidade para adicionar ao estoque
                                printf("Digite  a quantidade do produto:\n");
                                scanf("%d", &receberQuantidade);

                                // Atualiza o estoque
                                pd->estoque_atual[i] += receberQuantidade;
                                printf("O estoque atual do produto é %d\n", pd->estoque_atual[i]);

                                // Pergunta novamente se quer voltar ou sair
                                printf("2- para voltar\n");
                                printf("3- para voltar ao Menu\n");
                                scanf("%d", &opcao);

                                // Validação para aceitar apenas 2 ou 3
                                while (opcao != 2 && opcao != 3)
                                {
                                    printf("2- para voltar\n");
                                    printf("3- para voltar ao Menu\n");
                                    scanf("%d", &opcao);
                                }
                                if (opcao == 3) { opcao = 3; }
                                break;

                            case 2:
                                // Volta para o loop principal (sem sair do menu)
                                break;

                            case 3:
                                // Sai do menu
                                if (opcao == 3) { opcao = 3; }
                                break;

                            default:
                                printf("Opção inválida!");
                                break;
                        }
                    }
                }
            }

            // Caso o produto não seja encontrado
            if (produto_encontrado == 0)
            {
                printf("Produto não encontrado:\n\n");

                printf("2- para voltar\n");
                printf("3- para voltar ao Menu\n");
                scanf("%d", &opcao);

                // Valida a entrada do usuário
                while (opcao != 2 && opcao != 3)
                {
                    printf("2- para voltar\n");
                    printf("3- para voltar ao Menu\n");
                    scanf("%d", &opcao);
                }
            }

            produto_encontrado = 0; // Reseta a flag para próxima busca
        }
}


void saidaEstoque( int opcao, int receber_total_produtos, int produto_encontrado, int buscarProduto, int receberQuantidade, struct Produto *pd)
{
    // Verifica se a opção escolhida é 3 (Saída de estoque)
   
        printf("--------------SAÍDA DE ESTOQUE-------------------------\n\n");

        opcao = 0;

        // Loop principal até o usuário escolher voltar ao menu (opção 3)
        while (opcao != 3)
        {
            // Exibe a lista de produtos cadastrados (menos os dois últimos?)
            for (int i = 0; i < receber_total_produtos - 2; i++)
            {
                printf("Código do produto: %d\n", pd->codigo[i]);
                printf("Nome do produto: %s\n", pd->nome[i]);
                printf("Status do produto: %s\n\n", pd->status[i]);
            }

            // Permite buscar um produto pelo código
            for (int i = 0; i < receber_total_produtos - 2; i++)
            {
                printf("Digite o código do produto\n");
                scanf("%d", &buscarProduto);

                // Busca pelo produto
                for (i = 0; i < receber_total_produtos - 2; i++)
                {
                    if (buscarProduto == pd->codigo[i])
                    {
                        produto_encontrado = 1;

                        // Exibe o estoque mínimo do produto
                        printf("Estoque mínimo do produto: %d\n", pd->estoque_minimo[i]);
                        printf("1- para inserir o estoque mínimo\n");
                        printf("2- para voltar\n");
                        printf("3- para voltar ao Menu\n");
                        scanf("%d", &opcao);

                        // Validação da opção
                        while (opcao != 1 && opcao != 2 && opcao != 3)
                        {
                            printf("1- para inserir o estoque mínimo\n");
                            printf("2- para voltar\n");
                            printf("3- para voltar ao Menu\n");
                            scanf("%d", &opcao);
                        }

                        // Se escolher inserir estoque mínimo
                        if (opcao == 1)
                        {
                            printf("Digite a quantidade do produto:\n");
                            scanf("%d", &receberQuantidade);

                            // Atualiza o estoque mínimo
                            pd->estoque_minimo[i] += receberQuantidade;

                            printf("O estoque mínimo do produto é %d\n", pd->estoque_minimo[i]);
                            printf("2- para voltar\n");
                            printf("3- para voltar ao Menu\n");
                            scanf("%d", &opcao);

                            // Valida a escolha
                            while (opcao != 2 && opcao != 3)
                            {
                                printf("2- para voltar\n");
                                printf("3- para voltar ao Menu\n");
                                scanf("%d", &opcao);
                            }

                            if (opcao == 3) { break; }
                        }

                        if (opcao == 3) { break; }

                        // Alerta se o estoque atual estiver abaixo do mínimo
                        if (pd->estoque_atual[i] < pd->estoque_minimo[i])
                        {
                            printf("----------Alerta de Estoque---------------\n");
                            printf("O estoque atual está abaixo do estoque mínimo\n");
                        }
                    }
                }
            }

            // Caso não encontre o produto
            if (produto_encontrado == 0)
            {
                printf("Produto não encontrado:\n");

                printf("2- para voltar\n");
                printf("3- para voltar ao Menu\n");
                scanf("%d", &opcao);

                // Valida a opção
                while (opcao != 2 && opcao != 3)
                {
                    printf("2- para voltar\n");
                    printf("3- para voltar ao Menu\n");
                    scanf("%d", &opcao);
                }

                if (opcao == 3) { break; }
            }

            produto_encontrado = 0; // Reseta flag para próxima busca
        }

}


       void relatorios(int fornecedorEncontrado, int sair, int receber_total_produtos, int totalFornecedor, char escolha_fornecedor[30], int buscarProduto, int produto_encontrado, struct Produto *pd)
{
    // Função responsável por exibir relatórios de produtos e fornecedores
    // Recebe diversos parâmetros de controle e um ponteiro para a estrutura de produtos

   
        printf("--------------RELATÓRIOS-------------------------\n\n");

        sair = 1;  // Variável de controle do loop principal (1 = continuar, 0 = sair)
        fornecedorEncontrado = 0; // Flag para indicar se um fornecedor foi encontrado para um produto

        while (sair != 0) // Loop principal do relatório: continua até o usuário digitar 0 para sair
        {
            // Primeiro, lista todos os produtos cadastrados
            for (int i = 0; i < receber_total_produtos - 1; i++)
            {
                // Exibe informações gerais do produto
                printf("Informações do Produto:\n");
                printf("Código do produto: %d\n", pd->codigo[i]);
                printf("Nome do produto: %s", pd->nome[i]);
                printf("Descrição do produto: %s", pd->descricao[i]);
                printf("Data de cadastro do produto: %d\n", pd->data_cadastro[i]);
                printf("Codigo de barras do produto: %d\n", pd->codigo_barras[i]);
                printf("Categoria do produto: %s\n", pd->categoria[i]);
                printf("Unidade de medida do produto: %s\n\n", pd->unidade_medida[i]);
                printf("Status do produto: %s\n\n", pd->status[i]);

                // Exibe dados financeiros do produto
                printf("Dados financeiros do Produto:\n");
                printf("Preço de custo: %.2f\n", pd->preco_custo[i]);
                printf("Preço de venda: %.2f\n\n", pd->preco_venda[i]);

                // Exibe dados de estoque do produto
                printf("Quantidade do Produto:\n");
                printf("Estoque atual: %d\n", pd->estoque_atual[i]);
                printf("Estoque mínimo: %d\n\n", pd->estoque_minimo[i]);

                // Agora tenta exibir informações do fornecedor associado
                // Observação: a lógica atual é falha, pois percorre todos os fornecedores e compara com "escolha_fornecedor"
                // que não é alterado pelo usuário nesta função. Ou seja, provavelmente não encontra nada.
                for (i = 0; i < totalFornecedor; i++)
                {
                    // Se o fornecedor do produto for igual ao escolhido pelo usuário, mostra os dados
                    if (strcmp(pd->fornecedor[i], escolha_fornecedor) == 0)
                    {
                        fornecedorEncontrado = 1;
                        printf("Fornecedor do Produto:\n");
                        printf("Fornecedor: %s\n", pd->fornecedor[i]);
                    }
                }

                // Caso nenhum fornecedor tenha sido encontrado, exibe 0 (lógica confusa)
                if (fornecedorEncontrado == 0)
                {
                    printf("Fornecedor do Produto:\n");
                    printf("Fornecedor: 0\n");
                }
            }

            // Após listar todos os produtos, pergunta ao usuário se deseja buscar um produto específico
            printf("Digite o código do produto para buscar ou digite 0 para sair\n");
            scanf("%d", &buscarProduto);

            if (buscarProduto == 0) { break; } // Se o usuário digitou 0, sai do loop principal

            // Busca o produto pelo código digitado
            for (int i = 0; i < receber_total_produtos - 1; i++)
            {
                if (buscarProduto == pd->codigo[i]) // Produto encontrado
                {
                    produto_encontrado = 1;

                    // Exibe novamente todas as informações do produto específico
                    printf("Informações do Produto:\n");
                    printf("Código do produto: %d\n", pd->codigo[i]);
                    printf("Nome do produto: %s", pd->nome[i]);
                    printf("Descrição do produto: %s", pd->descricao[i]);
                    printf("Data de cadastro: %d\n", pd->data_cadastro[i]);
                    printf("Codigo de barras: %d\n", pd->codigo_barras[i]);
                    printf("Categoria: %s\n", pd->categoria[i]);
                    printf("Unidade de medida: %s\n\n", pd->unidade_medida[i]);
                    printf("Status: %s\n\n", pd->status[i]);

                    printf("Dados financeiros:\n");
                    printf("Preço de custo: %.2f\n", pd->preco_custo[i]);
                    printf("Preço de venda: %.2f\n\n", pd->preco_venda[i]);

                    printf("Estoque:\n");
                    printf("Estoque atual: %d\n", pd->estoque_atual[i]);
                    printf("Estoque mínimo: %d\n\n", pd->estoque_minimo[i]);

                    // Novamente tenta mostrar fornecedor (mesma lógica problemática anterior)
                    for (i = 0; i < totalFornecedor; i++)
                    {
                        if (strcmp(pd->fornecedor[i], escolha_fornecedor) == 0)
                        {
                            fornecedorEncontrado = 1;
                            printf("Fornecedor do Produto:\n");
                            printf("Fornecedor: %s\n", pd->fornecedor[i]);
                        }
                    }

                    if (fornecedorEncontrado == 0)
                    {
                        printf("Fornecedor do Produto:\n");
                        printf("Fornecedor: 0\n");
                    }
                }
            }

            // Caso não encontre o produto
            if (produto_encontrado == 0)
            {
                printf("Produto não encontrado.\n");
            }

            // Reseta flag para próxima busca
            produto_encontrado = 0;

            // Pergunta se o usuário quer sair ou continuar no relatório
            printf("0 - para sair\n");
            printf("2 - para continuar\n");
            scanf("%d", &sair);

            // Validação para garantir que só aceita 0 ou 2
            while (sair != 0 && sair != 2)
            {
                printf("Opção inválida. Digite novamente:\n");
                printf("0 - para sair\n");
                printf("2 - para continuar\n");
                scanf("%d", &sair);
            }
        }
    
}



int cadastrarFornecedores( int c, int sair,int receber_novo_total_fornecedores, int produto_encontrado, int totalFornecedor, int opcao, struct Produto *pd)
{
    
    char fornecedores_recebidos[50][30];
    // Função responsável por cadastrar novos fornecedores no sistema.
    // Retorna a quantidade atualizada de fornecedores cadastrados.

        printf("--------------CADASTRO DE FORNECEDORES-------------------------\n\n");
        
        sair = 1; // Controle do loop principal (1 = continuar, 0 = sair)
        produto_encontrado = 0; // Flag para verificar se existe algum fornecedor cadastrado

        while (sair != 0) // Loop principal para exibir lista e cadastrar fornecedores
        {
            // Exibe a lista atual de fornecedores cadastrados
            for (int i = 0; i < receber_novo_total_fornecedores; i++)
            {
                produto_encontrado = 1; // Indica que existe pelo menos um fornecedor

                printf("TOTAL DE FORNECEDORES: %d\n", i + 1);
                printf("FORNECEDOR: %s\n\n", pd->fornecedor[i]);
            }

            // Se não existir nenhum fornecedor cadastrado, exibe mensagem
            if (produto_encontrado == 0) { printf("Nenhum fornecedor encontrado\n"); }

            // Laço para cadastrar novos fornecedores enquanto não atingir o limite
            for (receber_novo_total_fornecedores; receber_novo_total_fornecedores < MAX_TOTAL;)
            {
                // Exibe as opções para o usuário
                printf("1 - Cadastrar um fornecedor\n");
                printf("2 - Voltar ao menu\n");
                scanf("%d", &opcao);

                // Valida a entrada do usuário (aceita apenas 1, 2 ou 3)
                while (opcao != 1 && opcao != 2)
                {
                    printf("Opção inválida. Digite novamente:\n");
                    printf("1 - Cadastrar um fornecedor\n");
                    printf("2 - Voltar ao menu\n");
                    scanf("%d", &opcao);
                }

                // Se a opção for cadastrar fornecedor
                if (opcao == 1)
                {
                    printf("Digite o nome do fornecedor:\n");
                    
                    while (getchar() != '\n'); // Limpa o buffer do teclado
                    fgets(pd->fornecedor[receber_novo_total_fornecedores], 30, stdin); // Lê o nome do fornecedor

                    // Remove o caractere '\n' adicionado pelo fgets
                     pd->fornecedor[receber_novo_total_fornecedores][strcspn(pd->fornecedor[receber_novo_total_fornecedores], "\n")] = '\0';
                    
                    for(int i = 0; i < c; i++)
                    {
                        if(strcmp(fornecedores_recebidos[i], pd->fornecedor[receber_novo_total_fornecedores]) == 0)
                        {
                            printf("Esse fornecedor já foi cadastrado!\n");
                            
                            while(strcmp(fornecedores_recebidos[i], pd->fornecedor[receber_novo_total_fornecedores]) == 0)
                            {
                                printf("Digite outro fornecedor:\n");
                                fgets(pd->fornecedor[receber_novo_total_fornecedores], 30, stdin); // Lê o nome do fornecedor

                                // Remove o caractere '\n' adicionado pelo fgets
                                pd->fornecedor[receber_novo_total_fornecedores][strcspn(pd->fornecedor[receber_novo_total_fornecedores], "\n")] = '\0';
                            }
                        }
                    }
                    
                    strcpy(fornecedores_recebidos[c], (*pd->fornecedor));// adicionando fornecedor na lista de fornecedores
                    
                    totalFornecedor++; // Incrementa o número total de fornecedores

                    receber_novo_total_fornecedores = totalFornecedor;//recebendo totalFornecedores
                }
                   
                // Se a opção for voltar ao menu principal
                if (opcao == 2)
                {
                    sair = 0; // Define para sair do loop principal
                    return receber_novo_total_fornecedores; // Retorna a nova quantidade de fornecedores
                }
                
                // Se o fornecedor foi cadastrado corretamente, exibe mensagem de sucesso
                if (strcmp(pd->fornecedor[totalFornecedor], "") != 0)
                {
                    c++;
                    printf("Fornecedor cadastrado com sucesso!\n");
                }
            }

            // Se atingiu o limite máximo de fornecedores, exibe mensagem
            if (totalFornecedor >= MAX_TOTAL)
            {
                printf("Atingiu o máximo de fornecedores permitidos.\n");
            }
        }
}

              void gerenciamentoUsuario(int sair, char admin[50], char senha_admin[50], int opcao, int total_cadastro_usuarios, int encontrar_usuario, int editar, char ultimo_usuario[40], int receberInicio, struct Usuarios *user)
{
    // Função responsável por gerenciar usuários no sistema (cadastrar, editar, remover, visualizar).
    // Exige login do administrador para liberar as operações.

        printf("----------GERENCIADOR DE USUARIOS---------------\n\n");
        
        while (sair != 1) // Loop principal enquanto não sair do gerenciamento
        {
            // Solicita login do administrador
            printf("Digite o usuario do ADM\n");
            while (getchar() != '\n'); // Limpa buffer
            scanf("%29s", admin);

            printf("Digite o senha do ADM\n");
            while (getchar() != '\n'); // Limpa buffer
            scanf("%29s", senha_admin);

            // Valida credenciais do administrador
            if (strcmp(admin, ADMIN) == 0 && strcmp(senha_admin, SENHA_ADMIN) == 0)
            {
                printf("ADMIN logado com sucesso!\n");
                
                // Menu interno do gerenciador de usuários
                while (sair != 2)
                {
                    printf("1- Cadastrar um novo usuario\n");
                    printf("2- Editar um usuario\n");
                    printf("3- Remover um usuario\n");
                    printf("4- Visualizar Usuarios\n");
                    printf("5- Sair\n");
                    scanf("%d", &opcao);

                    // Valida entrada
                    while (opcao < 1 || opcao > 5)
                    {
                        printf("Opção inválida! Digite novamente:\n");
                        printf("1- Cadastrar um novo usuario\n");
                        printf("2- Editar um usuario\n");
                        printf("3- Remover um usuario\n");
                        printf("4- Visualizar Usuarios\n");
                        printf("5- Sair\n");
                        scanf("%d", &opcao);
                    }

                    /* ========================================
                       OPÇÃO 1: CADASTRAR UM NOVO USUÁRIO
                    ======================================== */
                    if (opcao == 1)
                    {
                        for (int i = 1; i < MAX_TOTAL; i++) // Inicia a partir do índice 1 (usuário 0 é reservado)
                        {
                            while (getchar() != '\n'); // Limpa buffer
                            printf("Digite seu nome:\n");
                            fgets(user->usuario[i], 30, stdin); // Lê nome do usuário
                            user->usuario[i][strcspn(user->usuario[i], "\n")] = 0; // Remove \n

                            printf("Digite uma senha:\n");
                            scanf("%29s", user->senha[i]);
                            while (getchar() != '\n');

                            total_cadastro_usuarios++; // Incrementa total de usuários
                            strcpy(ultimo_usuario, user->usuario[i]); // Guarda último usuário cadastrado

                            // Verifica se atingiu limite máximo de usuários
                            if (total_cadastro_usuarios > MAX_TOTAL)
                            {
                                printf("Atingiu máximo total de usuários cadastrados\n");
                                printf("0 - para sair\n");
                                scanf("%d", &sair);

                                while (sair != 0)
                                {
                                    printf("1 - para sair\n");
                                    scanf("%d", &sair);
                                }
                            }
                            else
                            {
                                printf("Usuário cadastrado com sucesso!\n");

                                // Pergunta se deseja continuar cadastrando
                                printf("0 - Cadastrar mais usuários\n");
                                printf("1 - Sair\n");
                                scanf("%d", &sair);

                                while (sair != 0 && sair != 1)
                                {
                                    printf("Opção inválida! Digite novamente:\n");
                                    printf("0 - Cadastrar mais usuários\n");
                                    printf("1 - Sair\n");
                                    scanf("%d", &sair);
                                }
                            }

                            if (sair == 1) { break; }
                        }
                    }

                    /* ========================================
                       OPÇÃO 2: EDITAR UM USUÁRIO EXISTENTE
                    ======================================== */
                    if (opcao == 2)
                    {
                        while (sair != 2)
                        {
                            encontrar_usuario = 0;
                            int editado = 0;
                            int opcao_editar = 0;

                            // Lista todos os usuários
                            for (int i = 0; i < total_cadastro_usuarios; i++)
                            {
                                printf("ID: %d\n", i);
                                printf("Usuario: %s\n", user->usuario[i]);
                                printf("Senha: %s\n\n", user->senha[i]);
                            }

                            printf("1- Continuar\n");
                            printf("2- Sair\n");
                            scanf("%d", &opcao_editar);

                            if (opcao_editar == 2) { break; }

                            // Pede ID do usuário para editar
                            printf("Digite o ID do usuário que deseja editar:\n");
                            scanf("%d", &editar);

                            for (int i = 0; i < total_cadastro_usuarios; i++)
                            {
                                if (editar == 0)
                                {
                                    encontrar_usuario = 1;
                                    printf("Esse usuário não pode ser alterado\n");
                                    break;
                                }
                                else if (editar == i)
                                {
                                    encontrar_usuario = 1;

                                    printf("Usuario: %s\n", user->usuario[i]);
                                    printf("Senha: %s\n\n", user->senha[i]);

                                    printf("Digite 1 para editar usuário:\n");
                                    printf("Digite 2 para editar senha:\n");
                                    scanf("%d", &editar);

                                    if (editar == 1)
                                    {
                                        editado = 1;
                                        char New_user[50];
                                        while (getchar() != '\n');
                                        printf("Digite o novo usuário:\n");
                                        fgets(New_user, 50, stdin);
                                        New_user[strcspn(New_user, "\n")] = 0;
                                        strcpy(user->usuario[i], New_user);
                                        break;
                                    }
                                    else if (editar == 2)
                                    {
                                        editado = 2;
                                        char New_senha[50];
                                        printf("Digite a nova senha:\n");
                                        while (getchar() != '\n');
                                        scanf("%s", New_senha);
                                        strcpy(user->senha[i], New_senha);
                                        break;
                                    }
                                }
                            }

                            if (encontrar_usuario == 0)
                            {
                                printf("Usuário não existe\n");
                            }

                            if (editado == 1 || editado == 2)
                            {
                                printf("Usuário editado com sucesso!\n");
                            }
                        }
                    }

                    /* ========================================
                       OPÇÃO 3: REMOVER UM USUÁRIO
                    ======================================== */
                    if (opcao == 3)
                    {
                        encontrar_usuario = 0;

                        // Lista todos os usuários
                        printf("ID: 0:\n");
                        printf("Usuario: %s\n", user->usuario[0]);
                        printf("Senha: %s\n\n", user->senha[0]);

                        for (int i = receberInicio; i < total_cadastro_usuarios; i++)
                        {
                            printf("ID: %d\n", i);
                            printf("Usuario: %s\n", user->usuario[i]);
                            printf("Senha: %s\n\n", user->senha[i]);
                        }

                        int remover;
                        printf("Digite o ID do usuário que deseja remover:\n");
                        scanf("%d", &remover);

                        for (int i = 0; i < total_cadastro_usuarios; i++)
                        {
                            if (remover == i)
                            {
                                encontrar_usuario = 1;

                                if (remover == 0)
                                {
                                    printf("Esse usuário não pode ser removido\n");
                                }
                                else
                                {
                                    if (strcmp(ultimo_usuario, user->usuario[i]) == 0)
                                    {
                                        total_cadastro_usuarios--;
                                        printf("Usuário removido com sucesso!\n");
                                    }
                                    else
                                    {
                                        receberInicio++;
                                        printf("Usuário removido com sucesso!\n");
                                    }
                                }
                            }
                        }

                        if (encontrar_usuario == 0)
                        {
                            printf("Usuário não existe\n");
                        }
                    }

                    /* ========================================
                       OPÇÃO 4: VISUALIZAR TODOS OS USUÁRIOS
                    ======================================== */
                    if (opcao == 4)
                    {
                        while (opcao == 4)
                        {
                            for (int i = 0; i < total_cadastro_usuarios; i++)
                            {
                                printf("ID: %d\n", i);
                                printf("Usuario: %s\n", user->usuario[i]);
                                printf("Senha: %s\n\n", user->senha[i]);
                            }

                            printf("Digite 0 para sair: ");
                            scanf("%d", &sair);

                            while (sair != 0)
                            {
                                printf("Digite 0 para sair: ");
                                scanf("%d", &sair);
                            }

                            if (sair == 0) { break; }
                        }
                    }

                    /* ========================================
                       OPÇÃO 5: SAIR DO GERENCIADOR
                    ======================================== */
                    if (opcao == 5)
                    {
                        sair = 1; // Sai do gerenciador
                        break;
                    }
                }
            }
            else
            {
                printf("Login inválido\n");
            }
        }

        sair = 0; // Reseta variável
    
}



void alertaEstoque(int sair, int produto_encontrado, int receber_total_produtos, struct Produto *pd)
{
    
        sair = 1; // Controla o loop principal, iniciado como 1 para entrar no loop
        
        // Enquanto o usuário não digitar 0 para sair, o programa continua exibindo alertas
        while(sair != 0)
        {
            // Percorre todos os produtos, até receber_total_produtos - 1 (último índice é -1)
            for(int i = 0; i < receber_total_produtos; i++)
            {
                
                // Verifica se o estoque atual do produto está abaixo do estoque mínimo
                if(pd->estoque_atual[i] < pd->estoque_minimo[i])
                {
                    produto_encontrado = 1; // Marca que encontrou ao menos um produto com estoque baixo

                    // Exibe as informações do alerta de estoque para esse produto
                    printf("----------Alerta de Estoque---------------\n");
                    printf("O produto %s\n", pd->nome[i]);
                    printf("Está com estoque atual a abaixo do minimo: %d\n", pd->estoque_atual[i]);
                    printf("Estoque minimo: %d\n\n", pd->estoque_minimo[i]);
                }
            }

            // Se nenhum produto foi encontrado com estoque abaixo do mínimo, exibe essa mensagem
            if(produto_encontrado == 0)
            {
                printf("Não a Alerta de estoque minimo!\n");
            }

            produto_encontrado = 0; // Reseta a flag para a próxima verificação

            // Solicita que o usuário digite 0 para sair da tela de alerta
            printf("Digite 0 para sair\n");
            scanf("%d", &sair);

            // Caso o usuário não digite 0, entra nesse loop pedindo para digitar 0 novamente
            while(sair != 0)
            {
                printf("Digite 0 para sair\n");
                scanf("%d", &sair);
            }
        }
    
}
