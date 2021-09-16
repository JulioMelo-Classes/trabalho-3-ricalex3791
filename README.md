# LP1 Projeto 3

## Para compilar com CMake no Windows PowerShell

O arquivo CMakeList.txt já está configurado, então pode seguir os seguintes passos para compilar o projeto pelo powershell.
Após abrir o PowerShell e ir para o diretório onde os arquivos estão, execute os comandos

```console
mkdir build
cd build
cmake ..
cmake --build .
```

Isso irá criar uma pasta **Debug** e criar um executavel **"snaze.exe"** dentro dela.

## Executando o programa e utilizando os testes

Ainda no PowerShell, execute um "cd .." para voltar para o diretório padrão do projeto. Daqui você pode executar os seguintes comandos para rodar o sistema e ler o mapa.
```console
./build/Debug/snaze.exe ./data/[nome do mapa]
```
... substituindo o [nome do mapa] pelo nome de alguns dos arquivos na pasta /data. O mapa numero 3 é particularmente mais propenso a entrar em situações onde não há um caminho válido até a comida.

## Limitações
O programa ainda apenas possui o modo de cobra sem corpo. A classe de niveis ainda não foi implementada e a cobra continua jogando no mesmo nivel até encontrar todas as comidas, ou então até suas vidas acabarem.

# Avaliação CP2

## FindSolution.pacman

O método find soluiton ou similar deve ser capaz de encontrar o conjunto de comandos que levam da posição atual da cobrinha até a posição da comida no modo pacman.

**Avaiação**

80% acho que o método find solution está implementado de forma equivocada, uma vez que ele desmarca posições visitadas quando não encontra uma solução, o que pode causar um loop infinito.

## FindSolution.snake

O método find soluiton ou similar deve ser capaz de encontrar o conjunto de comandos que levam da posição atual da cobrinha até a posição da comida no modo snake.

**Avaliação**

não implementado

## Random start

Deveria ser implementado na execução do programa um comando que permita que a posição inicial seja sorteada aleatoriamente. A posição inicial precisa ser válida e não deve causar a cobrinha/pacman iniciar em uma posição encurralada.

**Avaliação**

não implementado

## Level Loop

Deveria se implementado na execução do programa um comando que permite que os níveis fiquem se repetindo infinitamente, com a transição de mapas indo do primeiro nível até o último nível e voltando para o primeiro, de forma que seja mantida a contagem de pontos bem como a contagem de nível.

**Avaliação**

não implementado

## Organização / Compilação automatizada / Casos de Teste

Para a entrega final a organização do código em scr/data/include e compilação automatizada de alguma forma deve ser feita.

**Avaliação**

70% não foram feitos casos de teste

## Documentação do código / Readme / Documentação de Casos de Teste

**Avaliação**

70% não foram documentados casos de teste

