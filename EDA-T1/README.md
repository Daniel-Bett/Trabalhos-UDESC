Trabalho realizado para a disciplina de Estrutura de Dados na Universidade do Estado de Santa Catarina.

O objetivo deste trabalho é implementar o algoritmo de preenchimento baseado
em semente (seed fill). O algoritmo processa uma matriz MxN representando uma
figura, em que cada coordenada contém um valor que representa a cor do pixel.
O algoritmo recebe como entrada as coordenadas (x,y) do pixel semente e a nova
cor. O algoritmo deve preencher toda a área adjacente ao pixel semente, percorrendo os
pixels vizinhos (acima, abaixo, à direita e à esquerda), trocando todos os pixels
adjacentes (e que tenham a mesma cor original) pela nova cor.
A aplicação não utilizará nenhum procedimento recursivo para a solução do
problema proposto. O objetivo é utilizar uma pilha para armazenar os pixels adjacentes
à medida que ocorre o percurso.

Implementação:
O programa deve ter como entrada um arquivo contendo uma como uma matriz
de inteiros: suas dimensões e seu conteúdo. Cada célula da matriz representa um pixel e
o seu valor representa a sua cor. Uma vez carregada a figura, o programa deve solicitar
as coordenadas (x,y) do pixel semente e qual a nova cor.
