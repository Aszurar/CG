# Atividade Pratica 1 | Compilando e Executando um Programa OpenGL Moderno
**GDSCO0051 - Introdução à Computação Gráfica** - Turmas 03/04 - 2020.1
___
<h2 align="center">Atividade Pratica 1: Triangulo Colorido(OpenGL Moderno)</h2>

___




<h3 align="center">
  <a href="#information_source-sobre">Sobre</a>&nbsp;|&nbsp;
  <a href="#interrobang-motivo">Motivo</a>&nbsp;|&nbsp;
  <a href="#seedling-requisitos-mínimos---instalação-das-bibliotecas-do-openGL-e-configurações">Requisitos</a>&nbsp;|&nbsp;
  <a href="#rocket-compilando-e-executando">Execução</a>&nbsp;|&nbsp;
  <a href="#package-como-baixar-o-projeto">Baixar</a>&nbsp;
</h3>

___

<div align="center" ><img src="" width="600"></div>

___

## :information_source: Sobre

A atividade consiste em compilar e executar o programa fornecido, 01_hello_world_gl -modern_opengl Durante a compilação alguns warnings poderão aparecer na tela. Uma vez compilado, ao ser executado, o programa deverá apresentar uma janela contendo um triângulo colorido.
com sucesso, o programa
___
## :interrobang: Motivo
 - Verificar se o ambiente de desenvolvimento em OpenGL 3.3 está corretamente configurado nos computadores dos alunos;
 - Familizarizar os alunos com a estrutura de um programa OpenGL moderno.

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
## :rocket: Compilando e Executando:
- Compilação(utulizando o terminal na mesma pasta que o programa) pode ser e 2 maneiras:
   ```bash
    gcc main.c -lglut -lGLU -lGL -I. -o cgprog
   ```
  ou pode ser compilado também como:
  ```bash
    gcc -Wall -Wextra -Wpedantic -std=c99 -O0 -g3 main.c -lglut -lGLU -lGL -o cgprog
  ```
 - Execução(Na pasta do projeto, digite no terminal):
   ```bash
   ./cgprog
    ```
  - :warning:  **No entanto, nós queremos um triângulo colorido, mas caso faça somente os comandos acima, resultará em um triângulo branco**, como a sequência abaixo:
  --Compilação:
    <img src="https://i.imgur.com/eHO5pAR.png">
  --Execução
     <img src="https://i.imgur.com/BJfyQ3R.png">
  
  - Para resolver isso, por meio de um pouco de pesquisa, foi necessário **exportar a versão mais recente do MESA_GL_VERSION_OVERRIDE**, que é o drive de dispositivos e de implementação do OPENGL, Vulkan... mencionado acima, na parte de instalação.
    
  - Assim, é necessário que antes do processo de compilação e execução seja feita essa exportação assim no terminal:
    ```bash
      export MESA_GL_VERSION_OVERRIDE=3.3
    ```
  - Após isso, basta utilizar um dos métodos de compilar acima e executar normalmente como a sequência abaixo:
    
   --Exportação e Compilação:
      <img src="https://i.imgur.com/56inU1Q.png">
   --Execução:
      <img src="https://i.imgur.com/zXXZHGP.png">
___ 
## :package: Como baixar e executar o projeto:

  - Clonar o projeto:
```bash
  $ git clone https://github.com/Aszurar/CG.git
```
  - Realize todas instalações acima, da aba de Requisitos.
  
  - Entre na pasta modern_opengl e siga os passos da aba de Compilação e Execução

___
Desenvolvido por :star2: Lucas de Lima Martins de Souza.
