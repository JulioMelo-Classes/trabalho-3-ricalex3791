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
... substituindo o [nome do mapa] pelo nome de alguns dos arquivos na pasta /data.

## Limitações
O programa ainda apenas possui o modo de cobra sem corpo. A cobra também não utiliza as vidas, e um game over ocorre assim que ela colidir com a parede.
A função find_solution ainda não foi implementada, então a cobra apenas se move aleatoriamente pelo mapa, evitando apenas colidir com paredes, a menos que não haja outra alternativa.

## Avaliação CP1

### Snake/Pacman
O jogo deveria conter o modo snake/pacman. Em ambos os modos não é possível andar pra trás. No modo snake deve ser desenhado o corpo.

**Avaliação**

50% apenas o modo pacman foi feito

### Render.ui
O jogo deveria desenhar a UI corretamente, mostrando ao menos as vidas, o nível e o score.

**Avaliação**

não implementado

### Render.mapa
O jogo deveria desenhar o mapa corretamente, com base no arquivo passado como argumento. Ok

**Avaliação**

ok

### Render.snake
O jogo deveria desenhar a snake corretamente.

**Avaliação**
Neste caso vou considerar Ok, pois estou mais preocupado com o posicionamento e movimentação da snake no mapa.

### Logic.colisão e Logic.comida
O jogo deve se comportar corretamente quando ocorre uma colisão com comida e com paredes.

**Avaliação**

ok

### Transição de mapas
O jogo deve ter transição de mapa uma vez que um mapa é terminado.

**Avaliação**

Não implementado.

### Interação com o usuário
O jogo deve perguntar ao usuário se quer continuar/reiniciar o nível/reiniciar o jogo a cada transição de mapa

**Avaliação**

Não implementado

### Classe Level ou similar
O software deve encapsular as funcionalidades do nível em uma classe.

**Avaliação**

Ok

### Classe Player ou similar
O software deve encapsular as decisões do jogo em uma classe.

**Avaliação**

Ok

### Classe Snake ou similar
O software deve encapsular as funcionalidades relacionadas à snake em uma classe. 

**Avaliação**

OK

## Comentários gerais CP1
- Como conversamos, com seu estado atual de implementação acho que vale a pena tentar implementar o CP2 sem entregar as demais funcionalidades do CP1. A unica coisa que talvez precisasse fazer era a implementação da snake com calda, no entanto você também podem implementar o CP2 com o pacman valendo um pouco menos pontos.