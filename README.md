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