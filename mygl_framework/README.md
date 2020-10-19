# Atividade Prática 2 | Triângulos gerados por meio do uso de algoritmos de rasterização do Algoritmo do Ponto Médio.
**GDSCO0051 - Introdução à Computação Gráfica** - Turmas 03/04 - 2020.1

**Alunos:**
 - Lucas de Lima Martins de Souza.
 - Allef Brenno Gomes de Lima.
___
<h2 align="center">Triângulos gerados por meio de algoritmos da rasterização do Algorítmo do ponto</h2>

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

A atividade consiste em implementar algoritmos de rasterização de linhas, nesse caso em específico baseado no Algoritmo do ponto médio para a criação de triângulos a partir de pares de coordenadas (x, y) passadas. 

Além disso, realizar as alterações necessárias para que seja possível rasterizar retas em qualquer direção/octante, já que no Algoritmo do Ponto Médio seria focado somente no 1º Octante.

___
## :interrobang: Estratégias
Uma vez compilado, ao ser executado, o programa deverá apresentar uma janela contendo um triângulo com base nos números dos vértices do triângulo da função:
  ```c
   MyGlDraw(void)
   ```

Além disso, as cores RGBA são definidas em um struct, assim como usamos uma struct Point para auxiliar na passagem dos pontos nas funções:

```c
struct RGBA{
	int red;
	int green;
	int blue;
	int alpha;
};

struct Point{
	float x;
	float y;
};
```

As funções requeridas no trabalho também são implementas:
```c
PutPixel(int x, int y, struct RGBA color);
```
A função PutPixel rasteriza um ponto na memória de vídeo recebendo como parâmetros as coordenadas (x,y) do pixel na tela e sua cor (RGBA).
Utilizamos um Struct para passar a cor RGBA.
___
```c
DrawLine(struct Point pontoA,struct Point pontoB, struct RGBA color);
```
Responsável por rasterizar uma linha na tela, recebendo como parâmetros as coordenadas dos seus vértices inicial e final e as cores (no formato RGBA) de cada vértice. 

O algoritmo utilizado é baseado no Algoritmo do Ponto Médio, porém esse algoritmo só consegue desenhar retas no 1º Octante do plano cartesiano. Assim algumas modificações devem ser realizadas para que seja possível a rasterização de retas em qualquer posição do plano cartesiano.
As tuplas de vértices iniciais e finais e cor RGBA são passados como structs.

**Restrições dos 8 Octantes**

A Imagem abaixo demonstra o plano cartesiano com todos os Octantes.
Em cada Octante há suas regras/limitantes que devem ser seguidas para conseguir modificar o algoritmo do Ponto Médio de modo que seja possível rasterizar retas em todo plano cartesiano.

<img src="https://media.discordapp.net/attachments/748604533827174534/767530137641287690/49b4a-octantes.png" width="800">

A função CheckLine:
```c
CheckLine(struct Point pontoA,struct Point pontoB);
```
É responsável por detectar em qual Octante a reta se localiza para rasterizar de forma correta.
Para isso, a função utiliza todas restrições da imagem acima que demonstra todos os Octantes.

Exemplo:

Pela imagem acima, temos que no 7º Octante o coeficiente angular(m) pode variar entre -1 e -∞(-1 > m > -∞) e outra restrição é que a coordenada y do ponto final é sempre menor que a coordenada y do ponto inicial(Y2 < Y1) 

Com o Octante determinado, é necessário realizar operações específicas com a reta para que ela seja  de modo que independente do Octante em que ela esteja, ela seja rasterizada a partir do conceito do Algoritmo do Ponto Médio.

No Algoritmo do Ponto Médio as coordenadas de Y estão em função de X. Dessa forma:

**Exemplo: 2º Octante**

No 2º Octante é necessário trocar as coordenadas em X com as coordenadas em Y. Assim o Algoritmo do Ponto Médio ficará em função do Y.

Dado que a reta de entrada seja a seguinte:

<img src="https://i.imgur.com/KZ4M2OT.png" width="600">
Reta 1

Trocando as Coordenadas de Y em função de X para X em função de Y.
```c
aux = Xi
Xi = Yi
Yi = aux

aux = Xf
Xf = Yf
Yf = aux
```
Reta resultante após a alteração:

<img src="https://i.imgur.com/Rc4znyo.png" width="600">
Reta 2

Após essa transformação, a reta está moldada para ser calculada no Algoritmo do Ponto Médio. Porém, no momento da plotagem dos pixels na tela, outra alteração deve ser feita, os valores das coordenadas em X dos pontos devem ser trocados pelos  valores das coordenadas em Y. Por fim, na plotagem a reta original(Reta 1) deverá ser rasterizada na tela.

**Exemplo: 4º Octante**

No 4º Octante os valores das coordenadas estariam espelhando os do modelo do Algoritmo do Ponto Médio, pois este está no 1º Octante, um é o espelho do outro. Portante, 2 alterações serão feitas:

  Dado que essa seja a Reta inicial:
  <img src="https://i.imgur.com/g5Q0BL4.png" width="600">

- 1º Alteração:
  - No Algoritmo do Ponto Médio(que é no 1º Octante) as coordenadas do X final sempre serão maiores que as coordenadas do X inicial.

    Já que o 4º Octante é um espelhamento do 1º Octante, para manter a regra acima, é necessário que X final seja trocado pelo X inicial.
    

    Após a 1º Alteração, essa será a Reta resultante:
   <img src="https://i.imgur.com/uPHW3MD.png" width="600">
- 2º Alteração:
  
   - No Algoritmo do Ponto Médio o Y inicial sempre é menor que o Y final, e o y inicial sempre é incrementado de em uma unidade até chegar ao valor do Y final. 
  
   - Porém, já que no 4º Octante os valores são espelhados em relação ao 1º Octante, o Y inicial do Loop terá que ser igual ao Y do ponto final da reta de entrada. Dessa forma, durante o Loop ao contrário de incrementar o Y inicial, ele será decrementado.
  

**Conclusão:**

 A partir disso, com os primeiros 4 Octantes descobertos, o restante será um espelhamento deles, e com isso basta trocar os pontos iniciais pelos pontos finais:
  
  Exemplo:
    
  - O 2º e o 6º Octantes são semelhantes, a única diferença será a inversão dos pontos finais com os iniciais no 6º Octante.
    O mesmo vale para:

    - 1º com o 5º octante
    - 3º com o 7º octante
    - 4º com o 8º octante

Portanto, para construir o Algoritmo, foi necessário implementar as modificações do 1º ao 4º quadrante, resolvendo assim por meio da simetria entre os demais quadrantes. 
___


```c
DrawTriangle(struct Point pontoA,struct Point pontoB, struct RGBA color);
```
Basta chamar o DrawnLine 3 vezes, e relacionar os 3 pontos(vértices do triãngulo).
 - 1º Ponto é o A
 - 2º Ponto é o B
 - 3º Ponto é o C
  <img src="https://media.discordapp.net/attachments/748604533827174534/767519565844054046/Sem_titulo.png" width=600>

## :seedling: Resultados:
- Triângulo Escaleno:
  <img src="https://i.imgur.com/0FEKgOy.png">

- Triângulo Equiátero:
  <img src="https://i.imgur.com/bWWOAtn.png">

- Os 8 Octantes:
 - Teste rasterizando somente retas com a função **DrawnLine()**
    <img src="https://i.imgur.com/8HmpqG3.png">

**Dificultades**
    
- A abstração para sair do campo da lógica da algebra vetorial para a lógica da programação foi muito dificil.
- Os documentos passados não ajudaram em colaborar com a lógica do trabalho. Com isso, o mal entendimento dos materiais passados, a construção da lógica do trabalho tornou-se muito complexa.
- Essa complexidade aumentou mais pelo fato de que os sites buscados sobre o assunto também ou eram escassos ou difícies de se entender.

**Melhorias**
- Acredita-se que os documentos de referências passados poderiam ser mais didáticos. 

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
