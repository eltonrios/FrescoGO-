**PLACAR**

A partir da versão 1.11.1 passam a existir dois modos de operação do FrescoGO: celular e PC. 

O modo celular funciona exatamente como nas versões anteriores, enquanto o modo PC requer que o aparelho seja conectado a um computador, onde rodará uma aplicação específica, para que todos os dados do jogo sejam apresentados em tela, em forma de um placar, permitindo melhor visualização por parte da arbitragem, e no caso de utilização de outro(s) monitor(es), permitindo também total transparência para jogadores e público.


**INSTALAÇÃO**

O primeiro passo para utilizar o modo PC e usufruir do PLACAR é atualizar o firmware do seu FrescoGO, o que pode ser feito seguindo o tutorial existente [aqui]( https://github.com/eltonrios/FrescoGO_Up/blob/master/tutoriais/tutorial_fvm.md). Após a atualização, antes de conectá-lo ao PC, é interessante já passá-lo para o modo PC, bastando digitar o comando **modo pc** e enviar.

Depois disso será necessário preparar o PC para receber o FrescoGO, e para isso é necessário o download do Processing, que é um ambiente de desenvolvimento integrado, no qual vai rodar os códigos do PLACAR, que vão receber todas as informações do FrescoGO e apresenta-las em tela. O download deve ser feito [aqui]( https://processing.org/download/).

Selecione a versão compatível com o sistema operacional do PC e baixe a mesma;

![Download](https://github.com/eltonrios/FrescoGO_Up/blob/master/images/download_Processing.PNG "download")

Depois extraia os arquivos... isso pode levar um tempinho... e pronto, agora vamos carregar o placar;

Volte na pasta FrescoGO_Up-master que foi criada durante a atualização do firmware, dê 2 cliques sobre ela e entre na pasta [placar].

Clique  agora em **placar.pde**

![Icone](https://github.com/eltonrios/FrescoGO_Up/blob/master/images/icone_processing.PNG "icone")

O ambiente Processing será carregado, já com a aplicação PLACAR, e agora vamos ajustar umas pequenas coisas.

Primeiramente precisamos ajustar a porta de comunicação (você já viu isso durante a atualização do firmware), e para isso, vá na linha 2 (vide figura abaixo) e ajuste o número da porta (não apague nada, não insira espaços... apenas troque o número, se necessário).

![Porta](https://github.com/eltonrios/FrescoGO_Up/blob/master/images/porta.png "porta")

Na linha 33 estará escrito "size(640, 480);" e aí você pode ajustar você pode ajustar o tamanho da janela do placar, adequando à tela de seu computador, mas ainda existe a opção de **full screen**,  bastando habilitar a linha 34 (retirando o “//” no início da linha) e desabilitando a linha 33 (inserindo o “//”).

![Definição](https://github.com/eltonrios/FrescoGO_Up/blob/master/images/definicao_tela.PNG "definição")

Agora clique no botão indicado na imagem abaixo:

![Executa](https://github.com/eltonrios/FrescoGO_Up/blob/master/images/definicao_tela.PNG "executa")

A configuração do FrescoGO vc pode fazer usando um celular ou, como já está com o Arduino IDE aberto, através do Monitor Serial. Após concluída, digite **modo pc** e envie... pronto, a partir de agora o celular e o Monitor Serial só te servirão para envio de comandos... nada mais.

Agora é só começar o jogo, marcando normalmente, e quando acabar (pelo tempo ou limite de bolas) o programa fará um print automático da tela e irá gerar o relatório, também automaticamente, ficando ambos salvos na pasta indicada abaixo (esse processo leva uns 30 segundos).

![Relatorios](https://github.com/eltonrios/FrescoGO_Up/blob/master/images/relatorios.PNG "relatorios")

**ATENÇÃO:**
1. Não há necessidade de trocar de aparelho (FrescoGO) entre um jogo e outro, a menos que você precise fazer alterações nas configurações;
2. A mudança dos nomes dos jogadores pode ser feita a partir do teclado do computador, usando **CTRL+E** para digitar o nome do jogador da esquerda, seguido de ENTER, depois use **CTRL+D** e entre com o nome da direita, teclando ENTER para confirmar;
3. O descréscimo do tempo no placar é atualizado de 5 em 5 segundos aproximadamente, mas a contagem transcorre normalmente, com precisão;




