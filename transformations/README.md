# Atividade Prática 3 | Implementação do pipeline gráfico.
**GDSCO0051 - Introdução à Computação Gráfica** - Turmas 03/04 - 2020.1

**Alunos:**
 - **Lucas de Lima Martins de Souza - 20170061294**
 - **Allef Brenno Gomes de Lima - 20160121380**
___
<h2 align="center">Implementação do Pipeline Gráfico</h2>

___



<h3 align="center">
  <a href="#information_source-objetivo">Objetivo</a>&nbsp;|&nbsp;
  <a href="#interrobang-estratégias">Estratégias</a>&nbsp;|&nbsp;
  <a href="#seedling-resultados">Resultadoss</a>&nbsp;|&nbsp;
  <a href="#package-como-baixar-o-projeto">Baixar</a> |&nbsp;
  <a href="#rocket-compilando-e-executando">Execução</a>&nbsp;|&nbsp;

</h3>

___

<div align="center" ><img src="https://media.giphy.com/media/RiqD20doJPMd1PLBvE/giphy.gif" width="650"></div>

___

## :information_source: Sobre

A atividade consiste realizar 4 exercícios com objetivo de praticar a teoria das Matrizes Model, View e e Projection por meio da alteração do conteúdo dessas matrizes em cada exercício. Além disso, há mais um exercício com uma transformações livres, escolhidas pelos alunos para gerar uma cena diferente dos demais.


 * **Exercício 1:**
Modificar a matriz Model de forma que a imagem gerada pelo programa fique igual ao a Figura 5(da especificação) que é essa abaixo:
  <img src="https://i.imgur.com/8g0id3K.png" width="400px">


 * **Exercício 2:**
Modificar a matriz Model de forma que a imagem gerada pelo programa fique como a da Figura 6(da especificação) que é essa figura abaixo:.
  <img src="https://i.imgur.com/vNQDegl.png" width="400px"> 
  

___
## :interrobang: Estratégias
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
  

## :seedling: Requisitos Mínimos - Instalação das bibliotecas do OpenGL e Configurações:
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