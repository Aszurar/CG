# Atividade Prática 3 | Implementação do pipeline gráfico.
**GDSCO0051 - Introdução à Computação Gráfica** - Turmas 03/04 - 2020.1

**Alunos:**
 - **Lucas de Lima Martins de Souza - 20170061294**
 - **Allef Brenno Gomes de Lima - 20160121380**
___
<h2 align="center">Implementação do Pipeline Gráfico</h2>

___



<h3 align="center">
  <a href="#information_source-sobre">Sobre</a>&nbsp;|&nbsp;
  <a href="#interrobang-soluções">Soluções</a>&nbsp;|&nbsp;
  <a href="#seedling-requisitos-mínimos">Requisitos</a>&nbsp;|&nbsp;
  <a href="#package-como-baixar-o-projeto">Baixar</a> |&nbsp;
  <a href="#rocket-compilando-e-executando">Execução</a>&nbsp;|&nbsp;

</h3>

___

<div align="center" ><img src="https://i.imgur.com/yBG9noP.gif" width="650"></div>

___

## :information_source: Sobre

- A atividade consiste realizar 4 exercícios com objetivo de praticar a teoria das Matrizes Model, View e e Projection por meio da alteração do conteúdo dessas matrizes em cada exercício. Além disso, há mais um exercício com uma transformações livres, escolhidas pelos alunos para gerar uma cena diferente dos demais. 
- O Exercício 1 foi feito por Lucas de Lima, o Exercício 2 por Allef, já os Exercícios 3 e 4 foram feitos em conjunto.

 * **Exercício 1:**
Modificar a matriz Model de forma que a imagem gerada pelo programa fique igual ao a Figura 5(da especificação) que é essa abaixo:

  <img src="https://i.imgur.com/8g0id3K.png" width="400px">

___
 * **Exercício 2:**
Modificar a matriz Model de forma que a imagem gerada pelo programa fique como a da Figura 6(da especificação) que é essa figura abaixo:

  <img src="https://i.imgur.com/vNQDegl.png" width="400px"> 

___
  * **Exercício 3:**
Modificar a matriz MP projection de forma que a imagem gerada pelo programa fique como a da Figura 7(da especificação):

<img src="https://i.imgur.com/20yXvNr.png" width="400px">

A matriz de projeção MP projection a ser utilizada é a que estudamos em aula e que considera a câmera na origem do seu sistema de coordenadas:

  <img src="https://i.imgur.com/QV52lKH.png" width="200px">
  
  onde **d** é a distância do centro de projeção até a origem do sistema de coordenadas da câmera.
___   
* **Exercício 4:**
 Neste exercício os alunos deverão modificar a matriz MView de forma que a imagem gerada pelo
programa fique como o da Figura 8:

  <img src="https://i.imgur.com/gvNVKY5.png">
___
## :interrobang: Soluções:
* **Exercício 1:**
  - No caso, os valores alterados foram somente 2 na matriz Model, foram trocados valores Sx e Sy da formula abaixo:
   
    <img src="https://i.imgur.com/pjEZKNB.png" width="250px">

  - Como temos que os Fatores de escala em (x, y, z) = (1/3, 3/2, 1). 
  - Então trocamos Sx que era 1.0f por 0.33f e Sy que era 1.0f para 1.5f na matriz Model.
  - Assim, a matriz model no código ficará igual a abaixo para gerar uma imagem igual a da Figura 5.
    ```c
    // Matriz Model 
    float model_array[16] = {0.33f, 0.0f, 0.0f, 0.0f, 
                             0.0f, 1.5f, 0.0f, 0.0f, 
                             0.0f, 0.0f, 1.0f, 0.0f, 
                             0.0f, 0.0f, 0.0f, 1.0f};
    ```
  - Resultado:
  - 
    <img src="https://i.imgur.com/1e0lMHN.png" width="800px">
___

* **Exercício 2:** 
  - A modificação feita foi a partir da formula abaixo:
   
    <img src="https://i.imgur.com/e7orOR4.png" width="250px">
  - Como temos que os Fatores de escala em (x, y, z) = (1, 0, 0). 
  - Então trocamos o valor dx para 1.0f 
  - A matriz utilizada para conseguir gerar uma imagem igual a Figura 6, foi a abaixo: 
    ```c
    // Matriz Model 
    float model_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                             0.0f, 1.0f, 0.0f, 0.0f, 
                             0.0f, 0.0f, 1.0f, 0.0f, 
                             1.0f, 0.0f, 0.0f, 1.0f};
    ``` 
  - Resultado:
   
      <img src="https://i.imgur.com/M3aVISq.png" width="800px">
___
* **Exercícios 3:**
- Utilizamos a matriz mencionada no exercício, que é a matriz abaixo:
  <img src="https://i.imgur.com/QV52lKH.png" width="200px"> 
- A partir disso, substituimos d por 1/8 que é o parâmetro informado. Assim, a matriz Projection no código se torna assim:
  ```c
    float proj_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                            0.0f, 1.0f, 0.0f, 0.0f, 
                            0.0f, 0.0f, 1.0f, -8.0f, 
                            0.0f, 0.0f, 0.125, 0.0f};
  ```
- Resultado:
 
  <img src="https://i.imgur.com/71gBz7A.png" width="800px">
  ___
* **Exercícios 4:** 
  - Para realização desse exercício, é seguido os passos das fórmulas abaixo para descobrir as coordeadas x, y e z do espaço da Câmera:
   
    <img src="https://i.imgur.com/NTlUJz6.png" width="500px"> 
  - Com isso, temos que a Matriz Bt(ou de Rotação) é igual a:
   
    <img src="https://i.imgur.com/bjJAOaQ.png" width="200px">

  - E a matriz de translação T é igual a:
   
    <img src="https://i.imgur.com/iCnpWiu.png" width="200px"> 
  
  - Resultado:
   
    <img src="https://i.imgur.com/d7u8uF5.png" width="800px">
  
  - Para encontrar a matriz Bt, ou seja, achar as coordenadas do espaço da Câmera, a realização dos calculos entre os vetores e matrizes, foi utilizado a função **create_matrix_bt** da biblioteca **MatrixLibrary**.
  Nessa função, possui 3 métodos:
      - **vetorial**: Realiza o cálculo do produto vetorial
      - **calculate_zc**: Realiza o cálculo para achar as coordenadas Z da Câmera.
      - **calculate_xc**: Realiza o cálculo para achar as coordenadas X e Y da Câmera, por isso é chamada 2 vezes. 
  - Além disso, nas funções **calculate_zc**  e **calculate_xc** é utilizado outra função chamada **module** para calcular o módulo dos vetores.
  - Já a matriz de Translação T, é encontrada a partir do do vetor p(px, py e pz) que é dado na questão e utilizando a fórmula mencionada acima.
___ 
* **Exercícios 5:** 
  * A 1º transformação realizada foi na Matriz Model, em que negativamos o y para deixar os triângulos invertidos. Após isso, transladamos os triângulos em 1 unidade no eixo y e no eixo x. 
     ```c
      float model_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                               0.0f, -1.0f, 0.0f, 0.0f, 
                               0.0f, 0.0f, 1.0f, 0.0f, 
                               1.0f, 1.0f, 0.0f, 1.0f};
     ```
  * A partir disso, alteramos a posição da câmera com a finalidade de centralizar os triângulos e vê-los de frente(vetor p) com uma leve alteração no y.
     ```c
      float vector_p[3] = {1.0f, 0.1f, 2.5f};
     ``` 
  * Assim recalculamos o view direction(vetor d).
    ```c
      float vector_d[3] = {0.0f, 0.9f, -2.5f};
    ``` 
  * Permanecemos com o vetor up no y igual a 1.
    ```c
      float vector_up[3] = {0.0f, 1.0f, 0.0f};
    ``` 
  * Além disso, alteramos a Matriz Projection para que a imagem ficasse maior na tela:
    ```c
       float proj_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                               0.0f, 1.0f, 0.0f, 0.0f, 
                               0.0f, 0.0f, 1.0f, -0.5f, 
                               0.0f, 0.0f, 2.0f, 0.0f};
    ```
  * Por fim, a Matriz View resultará em uma nova matriz, já que ela depende dos valores anteriores citados acima( Matriz View = Matriz de Rotação * Matriz de Translação).
  * Resultado:

    <img src="https://i.imgur.com/Qquldok.png" width="800px">


## :seedling: Requisitos Mínimos:
### Instalação das bibliotecas do OpenGL e Configurações:
 
- Atualização das listas de pacotes dos repositórios para obter informações sobre as versões mais recentes dos pacotes e suas dependencias
 ```c
 sudo apt-get update;
 ```
- Instação da biblioteca GLUT, que é uma biblioteca de funcionalidades para OpenGL como criação/controle de janelas e tratamento de eventos de dispositivos de entrada e saída, o segundo comando(_freeglut3-dev_), instala a biblioteca com ferramentas para desenvolvedor: 
```c
sudo apt-get install freeglut3; 
```
```c
sudo apt-get install freeglut3-dev; 
```
- Instalação do CMake, que é uma ferramenta que permite a geração automática de scripts de construção de aplicação em diferentes plataformas
```c
sudo apt-get install g++ cmake; 
```
- Instalação da biblioteca GLEW como ferramenta de desenvolvedor, que é uma biblioteca de carregamento de extensões C/C++. O GLEW fornece mecanismos eficientes de tempo de execução para determinar quais extensões OpenGL são suportadas na plataforma de destino(O 2º comando, ta instalando sua versão 1.5):
```c
sudo apt-get install libglew-dev; 
```
```c
sudo apt-get install libglew1.5-dev libglm-dev
```
- Intalação do G++, o compilador de C++:
```c
sudo apt-get install g++;  
```
- Instalação do Mesa, que é um driver de dispositivo e implementação de software do OpenGL, Vulkan e de outras especificações.
```c
sudo apt-get install mesa-common-dev;
```
 - (opcional) Instalação do Gold, que é um vinculador(linker) de arquivos especial para arquivos grandes em C++
```c 
sudo apt-get install binutils-gold; 
```
___

## :package: Baixar:

  - Clonar o projeto:
```bash
  $ git clone https://github.com/Aszurar/CG.git
```
  - Realize todas instalações acima, da aba de Requisitos.
  
  - Entre na pasta mygl_framework e siga os passos da aba de Compilação e Execução
___ 

## :rocket: Compilando e Executando:
- Compilação(utulizando o terminal na mesma pasta que o programa) pode ser e 2 maneiras:
  ```bash
    -Wall -Wextra -Wpedantic -std=c99 -O0 mygl.c main.c -lglut -lGLU -lGL -o mygl
  ```
 - Execução(Na pasta do projeto, digite no terminal):
   ```bash
   ./mygl
    ```
___

Desenvolvido por :star2: Lucas de Lima Martins de Souza e :crown: Allef Brenno Gomes de Lima.
