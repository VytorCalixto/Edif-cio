# Edifício
### Trabalho 2 de Oficina de Programação (2014/2)
###### Trabalho feito por Vytor Calixto

## Sobre o trabalho
A especificação do trabalho pode ser encontrada no arquivo trabalho2_v2.pdf.

O arquivo principal é o main.c. Algumas estruturas de dados foram separadas em outros arquivos para ajudar na legibilidade.

## Como executar
Após baixar o projeto com `git clone git@gitlab.c3sl.ufpr.br:vsbc14/edificio.git` você pode executá-lo digitando o comando `make` no terminal e `./fogo < mapa/in_XXX_xx.in`

Uma variedade de mapas para testes estão disponíveis na pasta mapa. Para testar todos de uma vez utilize o script testarMapas executando `./testarMapas` no terminal.

## Testes
Caso queira realizar mais testes, siga as seguintes expecificações:
* Crie um arquivo com o nome in_XXX_xx.in, que conterá o mapa (veja exemplos na pasta mapa/).
* Crie um arquio de mesmo nome, mas com a extensão .out que contém o tempo correto (ou -1 caso não haja saída). Por exemplo, se você criou o arquivo in_100_42.in crie o arquivo in_100_42.out.
* Coloque ambos os arquivos na pasta mapa/ para que o teste possa ser automatizado.

Caso encontre algum bug, sinta-se livre para abrir tentar resolvê-lo ou abrir uma issue (seja detalhado e tenha certeza de que está dando erro).
