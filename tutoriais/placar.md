**PLACAR**

A partir da versão 1.11.1 passam a existir dois modos de operação do FrescoGO: celular e PC. 

O modo celular funciona exatamente como nas versões anteriores, enquanto o modo PC requer que o aparelho seja conectado a um computador, onde rodará uma aplicação específica, para que todos os dados do jogo sejam apresentados em tela, em forma de um placar, permitindo melhor visualização por parte da arbitragem, e no caso de utilização de outro(s) monitor(es), permitindo também total transparência para jogadores e público.


**INSTALAÇÃO**

O primeiro passo para utilizar o modo PC e usufruir do PLACAR é atualizar o firmware do seu FrescoGO (caso seja inferior ao 1.11.1), o que pode ser feito seguindo o tutorial existente [aqui]( https://github.com/eltonrios/FrescoGO_Up/blob/master/tutoriais/atualizacao.md). Após a atualização, antes de conectá-lo ao PC, é interessante já passá-lo para o modo PC, bastando digitar o comando **modo pc** e enviar.

Depois disso será necessário preparar o PC para receber o FrescoGO, e para isso é necessário o download do Processing, que é um ambiente de desenvolvimento integrado, no qual vai rodar os códigos do PLACAR, que vão receber todas as informações do FrescoGO e apresenta-las em tela. O download deve ser feito [aqui]( https://processing.org/download/).

Selecione a versão compatível com o sistema operacional do PC e baixe a mesma;

![Download](https://github.com/eltonrios/FrescoGO_Up/blob/master/images/download_Processing.PNG "download")

Depois extraia os arquivos... isso pode levar um tempinho... e pronto, agora vamos carregar o placar;

Baixe a aplicação PLACAR clicando [aqui](https://github.com/frescogo/placar/archive/master.zip "placar")

Extraia os arquivos e depois entre na pasta **placar-master** que foi criada, em seguida na sub pasta [placar].

Clique  agora em **placar.pde**

![Icone](https://github.com/eltonrios/FrescoGO_Up/blob/master/images/icone_processing.PNG "icone")

O ambiente Processing será carregado, já com a aplicação PLACAR, e agora vamos ajustar umas pequenas coisas.

Primeiramente precisamos ajustar a porta de comunicação e caso você tenha feito a atualização do firmware, então já viu isso, então vá na linha 1 (vide figura abaixo) e insira "//" no início da linha, e na linha 3 retir o "//" e ajuste o número da porta (não apague nada, não insira espaços... apenas troque o número, se necessário).

![Porta](https://github.com/eltonrios/FrescoGO_Up/blob/master/images/porta.png "porta")


Procure a linha 77, onde está escrito "size(1024, 768);", nela você pode  ajustar o tamanho da janela do placar, adequando à tela de seu computador, ou ainda optar por usar a opção de full screen, bastando habilitar a linha 78 (retirando o “//” no início da linha) e desabilitando a linha 74 (inserindo o “//”).

![Definição](https://github.com/eltonrios/FrescoGO_Up/blob/master/images/definicao_tela.png "definição")

Agora clique no botão indicado na imagem abaixo:

![Executa](https://github.com/eltonrios/FrescoGO_Up/blob/master/images/executa.png "executa")

A configuração do FrescoGO vc pode fazer usando um celular ou, como já está com o Arduino IDE aberto, através do Monitor Serial. Após concluída, digite **modo pc** e envie... pronto, a partir de agora o celular e o Monitor Serial só te servirão para envio de comandos... nada mais.

Agora é só começar o jogo, marcando normalmente, e quando acabar (pelo tempo ou limite de bolas) o programa fará um print automático da tela e irá gerar o relatório, também automaticamente, ficando ambos salvos na pasta indicada abaixo (esse processo leva uns 30 segundos).

![Relatorios](https://github.com/eltonrios/FrescoGO_Up/blob/master/images/relatorios.PNG "relatorios")

**ATENÇÃO:**
1. Não há necessidade de trocar de aparelho (FrescoGO) entre um jogo e outro, a menos que você precise fazer alterações nas configurações;
2. A mudança dos nomes dos jogadores pode ser feita a partir do teclado do computador, usando **CTRL+E** para digitar o nome do jogador da esquerda, seguido de ENTER, depois use **CTRL+D** e entre com o nome da direita, teclando ENTER para confirmar;
3. O nome do árbitro pode ser mudado teclando **CTRL+A**, depois ENTER para confirmar;
4. Pressionando as teclas **1**, **2** ou **3** você pode mudar a distância para sete, sete e meio ou oito metros, respectivamente;
5. Teclando **CTRL+I** você pode inverter a posição dos nomes no placar, para ficar ajustado ao público e atletas (nada muda para o árbitro no que diz respeito aos botões);
6. Em cima do total da dupla aparece o set de configurações que está em uso;
7. Abaixo do total da dupla, à esquerda, aparecerá o valor máximo de pontuação obtida naquele aparelho desde o momento em que o placar foi ligado;
8. As configurações de revés e tempo tem que ser feitas conectando o aparelho no celular (e passando para o modo cel) ou no Monitor Serial do Arduino IDE (nesse caso não precisa passar para modo cel).
9. O decréscimo do tempo no placar é atualizado de 5 em 5 segundos aproximadamente, mas a contagem transcorre normalmente, com precisão;

 


