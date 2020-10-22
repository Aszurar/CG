# Atividade Prática 2 | Triângulos gerados por meio do uso do Algoritmo do Ponto Médio.
**GDSCO0051 - Introdução à Computação Gráfica** - Turmas 03/04 - 2020.1

**Alunos:**
 - **Lucas de Lima Martins de Souza - 20170061294**
 - **Allef Brenno Gomes de Lima - 20160121380**
___
<h2 align="center">Triângulos gerados por meio de algoritmo de rasterização do Ponto Médio</h2>

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

A atividade consiste em implementar algoritmos de rasterização de linhas, nesse caso em específico baseado no Algoritmo do Ponto Médio para a criação de triângulos a partir dos vértices(x, y) dos trigângulos passados. 

Além disso, realizar as alterações necessárias para que seja possível rasterizar retas em qualquer direção/octante, já que no Algoritmo do Ponto Médio seria focado somente no 1º Octante.

Lucas de Lima foi responsável pelas funções Putpixel(), pela Interpolação de Cores e também  ajudou um pouco na DrawnLine(). Allef foi responsável pela maior parte da DrawnLine() e pela DrawTriangle(). Apesar dessa separação entre o dever de cada um, todo trabalho foi feito em conjunto, não hcegou a ter alguma parte em que um não tentasse ajudar o outro, principalmente com toda dificuldade de sair do campo abstrato e ir para o código, foi necessário o trabalho em conjunto!.

O principal esforço em dupla realizado foi  a construção da DrawnLine(), as estratégias dos Octantes, essa foi uma das partes mais difícies do trabalho, assim como apesar de não ter funcionado completamente, a estratégia de Interpolação de Cores também foi pensada em dupla.
___
## :interrobang: Estratégias
É utilizado structs para definição das cores RGBA e dos pontos.

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

**Funções implementadas:**
```c
PutPixel(int x, int y, struct RGBA color);
```
A função PutPixel rasteriza um ponto na memória de vídeo recebendo como parâmetros as coordenadas (x,y) do pixel na tela e sua cor (RGBA).
___
```c
DrawLine(struct Point pontoA,struct Point pontoB, struct RGBA color);
```
Responsável por rasterizar uma linha na tela, recebendo como parâmetros as coordenadas dos seus vértices inicial e final e as cores (no formato RGBA) de cada vértice. 

O algoritmo utilizado é baseado no Algoritmo do Ponto Médio, porém esse algoritmo só consegue desenhar retas no 1º Octante do plano cartesiano. A partir disso, modificações devem ser realizadas para que seja possível a rasterização de retas em qualquer posição do plano cartesiano.

**Restrições dos 8 Octantes**

A Imagem abaixo demonstra o plano cartesiano com todos os Octantes.
Em cada Octante há suas regras/limitantes que devem ser seguidas para conseguir modificar o algoritmo do Ponto Médio de modo que seja possível rasterizar retas em todo plano cartesiano.

<img src="https://media.discordapp.net/attachments/748604533827174534/767530137641287690/49b4a-octantes.png" width="800">

**A função CheckLine:**
```c
CheckLine(struct Point pontoA,struct Point pontoB);
```
É responsável por detectar em qual Octante a reta se localiza para rasterizar de forma correta.
Para isso, a função utiliza todas restrições da imagem acima que demonstra todos os Octantes.

Exemplo:

Pela imagem acima, temos que no 7º Octante o coeficiente angular(m) pode variar entre -1 e -∞(-1 > m > -∞) e outra restrição é que a coordenada y do ponto final é sempre menor que a coordenada y do ponto inicial(Y2 < Y1) 

Com o Octante determinado, é necessário realizar operações específicas com a reta para  que independente do Octante em que ela esteja, seja rasterizada a partir do conceito do Algoritmo do Ponto Médio.

No Algoritmo do Ponto Médio as coordenadas de Y estão em função de X. Assim, as alterações que devem ser feitas:

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

  - á que o 4º Octante é um espelhamento do 1º Octante, para manter a regra acima, é necessário que X final seja trocado pelo X inicial.

  - Após a 1º Alteração, essa será a Reta resultante:
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

Portanto, para construir o Algoritmo, foi necessário implementar as modificações do 1º ao 4º octantes,e com isso, resolver por meio da simetria entre os demais octantes. 

**A Interpolação Linear de Cores**

Não foi possível realizar a interpolação Linear das cores totalmente efetiva. Na lógica utilizada, há o funcionamento somente com a entrada de vértices de triângulos que não possuam coordenadas tão distantes umas das outras. 

**Falha**: 
 - Caso a entrada na entrada dos 3 vértices do Triângulo, algum deles possua alguma coordenada muito distante das coordenadas dos demais vértices, as linhas rasterizadas ligadas à esse vértice não serão coloridas, ficaram por padrão pretas. 
 - Esse problema ocorre somente no uso da Interpolação Linear de Cores,  o projeto gera os triângulos normalmente.
 - Quando não se usa a interpolação e configura a cor das linhas, qualquer triângulo será rasterizado colorido na cor configurada normalmente.

**Lógica Utilizada:**
 - Calcula-se a variação(deltas) entre das coordenadas x e y dos pontos
 - Caso o delta em x seja maior que 0, é realizado a diferença entre as 2 cores red, green e blue.
 - Cada diferença dessas é divididada pelo delta em x.
 - O valor final de cada divisão é guardado.
 - Caso o delta em X não seja maior que zero, então é feito o mesmo procedimento mas com o delta em y.
	
```c
	if(dx>0){
		rP = (color2.red - color1.red)/dx;
		gP = (color2.green - color1.green)/dx;
		bP = (color2.blue - color1.blue)/dx;
	}else if(dy>0){
		rP = (color2.red - color1.red)/dy;
		gP = (color2.green - color1.green)/dy;
		bP = (color2.blue - color1.blue)/dy;
	}
```
 - Por fim esses valores são somados as cores RGBA:
 ```c
	colorF.red = colorF.red + rP;
	colorF.green = colorF.green + gP;
	colorF.blue = colorF.blue + bP;
 ```
 
 **Motivo da falha**
  - As cores por padrão são definidas com o valor 0.
  - O problema ocorre quando a distância entre algum vértice é grande. Pois assim, o delta(dx) do trecho do código acima assume um valor alto, enquanto que a diferença realizada no Numerador da divisões do trecho do código acima se torna um valor baixo, e essa divisão resulta em um valor entre 0 e 1.
  - O Resultado dessas divisões é guardado em varíaveis que são float.
  - No entando, as cores são valores inteiros, e quando ocorre a soma entre as cores e as variáveis que guardam o resultado da divisão(que são float), essas divisiões que são valores entre 0 e 1 tornam-se 0 nessa soma final.
  - Por fim, a conversão da variável float em 0 e como as cores são declaradas com o valor 0, então a soma final será 0 = 0 + 0 configurando assim a cor preta.
___

```c
DrawTriangle(struct Point pontoA,struct Point pontoB, struct RGBA color);
```
Basta chamar o DrawnLine 3 vezes, e relacionar os 3 pontos(vértices do triãngulo).
 - 1º Ponto é o A(Vértice esquerdo)
 - 2º Ponto é o B(Vértice do meio)
 - 3º Ponto é o C(Vértice da direita)
  <img src="https://media.discordapp.net/attachments/748604533827174534/767519565844054046/Sem_titulo.png" width=600>

___
## :seedling: Resultados:
- Triângulo com a Interpolação Linear de Cores realizada com sucesso:
- Vértices escolhidos:
 	- A(100, 100)
 	- B(200, 300)
 	- C(300, 100)
<img src="https://i.imgur.com/0gv2KUx.png">

___

- Triângulo com a falha da Interpolação Linear de Cores citada acima:
- As linhas ligadas ao ponto C não são coloridas e ficam pretas.
- Vértices escolhidos:
 	- A(100, 100)
 	- B(200, 300)
 	- C(457, 465)
<img src="https://i.imgur.com/gpHhUfs.png">

___

- O mesmo triângulo acima sem a Interpolação Linear de Cores:
- Vértices escolhidos:
 	- A(100, 100)
 	- B(200, 300)
 	- C(457, 465)
<img src="https://i.imgur.com/LC74mJs.png">

___

**Segue exemplos com a Interpolação Linear de Cores realizada com sucesso:**

- Vértices escolhidos:
 	- A(100, 200)
 	- B(200, 400)
 	- C(350, 350)
<img src="https://i.imgur.com/d9u1nRm.png">

___

- Vértices escolhidos:
	- A(200, 100)
 	- B(200, 300)
 	- C(100, 300)
<img src="https://i.imgur.com/1oRDZz4.png">

___

**Segue outros exemplos sem a Interpolação Linear de Cores:**
- Triângulo Escaleno:
  <img src="https://i.imgur.com/0FEKgOy.png">

- Triângulo Equiátero:
  <img src="https://i.imgur.com/bWWOAtn.png">

- Os 8 Octantes:
 - Teste rasterizando somente retas com a função **DrawnLine()**
    <img src="https://i.imgur.com/8HmpqG3.png">

**Dificultades**
    
- A abstração para sair do campo da lógica da algebra vetorial para a lógica da programação foi muito dificil.
- Os documentos passados não ajudaram em colaborar com a lógica do trabalho, na verdade, geraram mais dúvidas sobre o assunto. Com isso, o mal entendimento dos materiais passados, a construção da lógica do trabalho tornou-se muito complexa.
- Essa complexidade aumentou mais pelo fato de que os sites buscados sobre o assunto também ou eram escassos ou difícies de se entender.

**Melhorias**
- Acredita-se que os documentos de referências passados poderiam ser mais didáticos. 
- Mais exemplos práticos na aula, mais praticidade no geral em conjunto com os alunos. Pois é muito difícil encaixar toda teoria passada em uma aula somente de slides aprensentando conceitos em um projeto prático com a lógica de programação.

___

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
