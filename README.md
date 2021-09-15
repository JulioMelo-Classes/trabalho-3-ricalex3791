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

