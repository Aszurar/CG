# Atividade Pratica 1 | Compilando e Executando um Programa OpenGL Moderno
**GDSCO0051 - Introdução à Computação Gráfica** - Turmas 03/04 - 2020.1
___
<h2 align="center">Atividade Pratica 1: Triangulo Colorido(OpenGL Moderno)</h2>

___




<h3 align="center">
  <a href="#information_source-sobre">Sobre</a>&nbsp;|&nbsp;
  <a href="#interrobang-motivo">Motivo</a>&nbsp;|&nbsp;
  <a href="#seedling-requisitos-mínimos">Requisitos</a>&nbsp;|&nbsp;
  <a href="#rocket-tecnologias-utilizadas">Tecnologias</a>&nbsp;|&nbsp;
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
- Instalação da biblioteca GLEW como ferramenta de desenvolvedor, que é uma biblioteca de carregamento de extensões C/C++. O GLEW fornece mecanismos eficientes de tempo de execução para determinar quais extensões OpenGL são suportadas na plataforma de destino:
```c
sudo apt-get install libglew-dev; 
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

- Compilação:
```bash
gcc lucas.c -lglut -lGLU -lGL -I. -o cgprog
```

- [HTML](https://developer.mozilla.org/pt-BR/docs/Web/HTML)
- [CSS](https://developer.mozilla.org/pt-BR/docs/Web/CSS)

___
## :package: Como baixar o projeto

  - Clonar o projeto:
```bash
  $ git clone https://github.com/Aszurar/SitePessoal.git
  
```
  - Baixar a extensão Live Server do vscode:
  <img src="" width="600">
  
  - Abrir a pasta do projeto no vscode e abrir o arquivo **index.html** e clicar em Go Live(opção localizada no canto inferior direito):
  <img src="" width="600">
  
  - Com isso, seu navegador padrão abrirá a página automaticamente:
  <img src="" width="600">
  

___
Desenvolvido por :star2: Lucas de Lima Martins de Souza.
