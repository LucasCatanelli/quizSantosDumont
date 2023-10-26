#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pergunta {
    char desc[500], opcaoA[100], opcaoB[100], opcaoC[100], opcaoD[100], resposta_final;
};

struct Resultado_Questao {
    int pontuacao;
    char nome[100], sobrenome[100];
};

int main() {
    struct Pergunta perguntas[4];

    struct Pergunta pergunta1 = 
	{
        "1. Santos Dumont e o relogio de pulso, Dumont em uma conversa com Louis Cartier acabou reclamando da dificuldade de consultar horas nos seus voos, ja que usava relogio de bolso (comum na epoca), entao a Cartier lancou o primeiro relogio de pulso chamado Cartier Santos. Especialmente para Santos Dumont\n\nPergunta: Qual tipo de relogio Santos Dumont usava na epoca?",
        "A) celular",
        "B) relogio de parede",
        "C) relogio de bolso",
        "D) relogio de pulso",
        'C'
    };
    perguntas[0] = pergunta1;

    struct Pergunta pergunta2 = 
	{
        "2. Uma das ideias de Santos Dumont foi o hangar, ele construiu o primeiro hangar em Paris, para guardar seus avioes de experimentos com seguranca e nas melhores condicoes, ele foi construido em 1900 e possuia 30 metros de comprimento, 7 de largura e 11 metros de altura.\n\nPergunta: Qual o motivo de Santos Dumont construir o hangar?",
        "A) Guardar os chuveiro",
        "B) Guardar suas chaves",
        "C) Morar",
        "D) Abrigar seus avioes e dirigiveis em seguranca.",
        'D'
    };
    perguntas[1] = pergunta2;

    struct Pergunta pergunta3 = 
	{
        "3. Uma invensao confortavel para os dias frios, Santos Dumont em 1918 projetou um chuveiro com agua quente para sua casa, o objeto funcionava com um balde dividido ao meio, com entrada de agua quente e gelada.\n\nPergunta: Onde ele projetou o chuveiro de agua quente?",
        "A) No aviao",
        "B) No hangar",
        "C) Na sua casa no Brasil",
        "D) Em Paris",
        'C'
    };
    perguntas[2] = pergunta3;

    struct Pergunta pergunta4 = 
	{
        "4. O primeiro aviao a ser demonstrado publicamente foi feito pelo brasileiro Santos Dumont, no dia 12 de novembro de 1906, em Paris, ele levantou voo com seu aviao chamado 14-bis.\n\nPergunta: Qual cidade ele voou primeiro com seu aviao?",
        "A) Rio de Janeiro",
        "B) Petropolis",
        "C) Paris",
        "D) Sao Paulo",
        'C'
    };
    perguntas[3] = pergunta4;

    int numPerguntas = 4;

    printf("Seja Bem-vindo ao Quiz do Santos Dumont!\n");

    int numeroParticipantes;
    printf("Quantos participantes vao responder o quiz? : ");
    scanf("%d", &numeroParticipantes);

    FILE *arquivoResultado_Questao = fopen("resultados3.csv", "a");

    if (arquivoResultado_Questao == NULL) {
        printf("Nao foi possivel abrir o arquivo que contem os resultados.\n");
        return 1;
    }

    for (int x = 0; x < numeroParticipantes; x++) {
        printf("\nDados do Participante %d:\n", x + 1);

        struct Resultado_Questao resultadoAtual;
        	printf("Nome do participante: ");
        	scanf("%s", resultadoAtual.nome);

        printf("Sobrenome do participante: ");
        scanf("%s", resultadoAtual.sobrenome);

        resultadoAtual.pontuacao = 0;

        for (int i = 0; i < numPerguntas; i++) {
            printf("\n%s\n", perguntas[i].desc);
            printf("%s\n%s\n%s\n%s\n", perguntas[i].opcaoA, perguntas[i].opcaoB, perguntas[i].opcaoC, perguntas[i].opcaoD);

            char resposta;
            printf("Responda utilizando em MAIUSCULO (A/B/C/D): ");
            scanf(" %c", &resposta);

            if (resposta == perguntas[i].resposta_final) {
                resultadoAtual.pontuacao++;
                printf("Parabens!! Sua resposta esta correta!\n");
            } else {
                printf("Infelizmente sua resposta esta incorreta. A resposta correta e: %c\n", perguntas[i].resposta_final);
            }
        }

        fprintf(arquivoResultado_Questao, "Nome do Participante: %s %s, Pontuacao do Participante: %d\n", resultadoAtual.nome, resultadoAtual.sobrenome, resultadoAtual.pontuacao);
    }

    fclose(arquivoResultado_Questao);

    return 0;
}
