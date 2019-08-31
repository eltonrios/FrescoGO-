###### _TUTORIAL  (v1.1)_
# Atualize seu dispositivo - Faça você mesmo 
**_O objetivo desse breve tutorial é auxiliar aos usuários do dispositivo FrescoGO na atualização do firmware do mesmo._**

---------------------------------------------------------------------
**Se você não possui conhecimentos de instalação de aplicativos e drivers, bem como na configuração de hardware, sugiro que opte por realizar esta fase de _preparação do ambiente_ utilizando o [SUPORTE REMOTO](https://github.com/eltonrios/FrescoGO_Up/blob/master/tutoriais/atualizacao_remota.md)**

---------------------------------------------------------------------
**1.** Você vai precisar ter em mãos um computador e o dispositivo *FrescoGO* (com aquele cabo azul que acompanha o dispositivo);

**2.** Baixe o software IDE Arduino correspondente ao seu sistema operacional, clicando [aqui](https://www.arduino.cc/en/Main/Software) ;

**3.** Faça a instalação do mesmo;

**4.** Após a instalação, clique [aqui](https://drive.google.com/open?id=1VTL2lCYFa-qNSE-W7CuF0xUKozHJST1d) para baixar o driver para seu dispositivo;

=> Opção alternativa para esse driver pode ser encontrada [aqui](https://drive.google.com/open?id=1goUx56K8cNx4pufPFdrshv0VtVliTP9X);

**5.** Após baixar e clicar duas vezes irá abrir a janela abaixo:

![Instalador](images/driver341.png "Setup")

**6.** Clique na opção Install;

<!-- Obs: http://blogdarobotica.com/instalando-driver-serial-para-arduinos-com-chip-ch340/
--> 

## *Efetuando atualização:*
---------------------------------------------------------------------
**1.** Clique [aqui](https://github.com/frescogo/aparelho/archive/master.zip) para baixar a versão mais recente;

**2.** Extraia todos os arquivos e pastas do pacote baixado ("aparelho-master.zip"), depois entre na pasta "aparelho-master";

**3.** Entre na pasta "software" e em seguida dê dois cliques no arquivo "**software.ino**", isso fará com que seja aberta a aplicação **IDE Arduino** e todo o pacote carregado automaticamente;

**4.** Conecte seu dispositivo *FrescoGO* numa entrada USB do computador;

**5.** Vá no menu _Ferramentas_ e selecione a placa;

![Seleção do arduino](images/arduino_select.png "Seleção do arduino")

**5.** Selecione o processador;

![Seleção da placa](images/placa_select.png "Seleção da placa")

**6.** Selecione a porta de comunicação (é provável que seja COM3 ou maior, já que COM1 e COM2 são normalmente reservados para portas seriais nativas, e não por USB);

![Seleção da porta](images/com_select.png "Seleção da porta")

**7.** Observe se irá conectar e reconhecer o dispositivo (no rodapé da janela do aplicativo, lado direito, deverá aparecer algo como "Arduino Nano, ATmega328P (Old Bootloader) em COM12" (a porta COM, principalmente, pode variar). Se isso acontecer já estará tudo pronto para proceder a atualização, sempre que necessário.;

![Status](images/barra_status.png "Status")

**4.** Faça o envio da nova programação para seu dispositivo *FrescoGO*, clicando no icone de uma seta para a direita, que se encontra abaixo da opção "Arquivo", no menu principal;

![Carregar](images/transferir.PNG "Carregar")

**5.** Vai aparecer a palavra "Carregando..." na barra azul logo abaixo dos códigos, aguarde o processo ser concluído (normalmente dura de 15 a 30 segundos); 

**6.** Quando aparecer a palavra "Carregado." seu dispositivo já estará atualizado, podendo ser desconectado;

## *Dicas importantes:*
---------------------------------------------------------------------
**a.** Pode acontecer de, após uma atualização, virem valores estranhos nos parâmetros de configuração, observe e parametrize se necessário;

**b.** Em alguns casos pode ser necessário o *reset* (pressione os três botoões por cerca de 5 segundos).





