	Trabalho 3 - L�gica e Algor�timos
	Luigi Perotti Souza - 201910462
	
Descri��o: 
	
	O seguinte algor�timo tem por finalidade ler, utilizar da API "Canvas 2D - Vers�o C" de 
	autoria de Cesar Tadeu Pozzer na implementa��o de fun��es b�sicas de desenho 2D na tela
	para utiliza��o em casos mais complexos. 
	Nesse trabalho, o programa implementado foi uma vers�o do jogo Candy Crush por�m reformulado
	nas capacidades da linguagem C/C++.
	
Objetivos e apresenta��o:

	O jogo se baseia na apresenta��o de um tabuleiro de dimens�es 9x9 como uma figura dentro de
	cada "casa" deste tabuleiro (81 pe�as) divididas entre sete figuras geom�tricas com cores
	e/ou figuras diferentes entre si, sendo seis delas capazes de se obter a qualquer momento a partir
	da renderiza��o natural do jogo.
	Todo o jogo � manipulado a partir da solicita��o do jogador e controlado utilizando somente as fun��es
	de movimentar e pressionar o bot�o esquerdo do mouse.	

	O objetivo do jogo � alterar as posi��es das pe�as com o mouse para formar combina��es de pe�as iguas
	na horizontal, vertival ou ambos (casos de combina��es cruzadas) com tr�s ou mais doces iguais. A troca 
	dessas pe�as e feita a partir de dois cliques do mouse, sendo um deles para a primeira posi��o e o 
	segundo para a pe�a adjacente no qual se deseja realizar a troca. Ser� poss�vel identificar as pe�as 
 	escolhidas uma vez que a mesma estar� destacada ap�s a sele��o.
	Como regra fundamental, uma troca de pe�as s� � v�lida quando ap�s acontecer a altera��o, uma ou mais 
	combina��es de pe�as forem poss�veis se fazer. Caso a troca se mostrar irrelevante para o andamento do 
	jogo, nenhum doce mudar� de lugar Baseado no n�mero de doces combinados em uma mesma troca, uma pontua��o 
	ser� apresentada no canto superior direito do tabuleiro, juntamente com uma mensagem de parabeniza��o no 
	canto superior esquerdo da tela. � importante salientar que para as seis pe�as padr�es do jogo, nenhum
	fator al�m do n�mero de pe�as combinadas influencia na contagem de pontos, ou seja, suas cores n�o s�o
	relevante nesse quesito.

	Ap�s a troca ter sido v�lidada, a primeira pe�a selecionada toma o lugar da segunda e vice versa, assim,
	todas as pe�as da mesma cor dentro da combina��o formada ser�o "explodidas"  exibindo uma pequena anima��o de 
	explos�o e logo ser�o substitu�das por espa�os em branco, onde as pe�as das fileiras de cima ir�o por si s� 
	ca�rem conforme o tempo passa e subituindo os locais vazios. No topo onde restar� sobrando espa�o vazio, 
	novas pe�as ser�o sorteadas de maneira aleat�ria. Enquanto o programa estiver ou quebrando pe�as ou realizando
	o ShiftDown (queda das pe�as superiores) nenhum clique ou sele��o de doces ser� habilitado para evitar bugs.

Pe�as Especiais:

	Como dito anteriormente, al�m das seis pe�as padr�o do jogo h� a implementa��o de uma pe�a especial onde
	carinhosamente foi chamada de "biscoit�o". O biscoit�o � obtido ao juntar-se cinco ou mais pe�as iguais,
	a partir da�, uma pe�a diferente das demais aparecer� na fileira destru�da com as habilidades do biscoit�o.
	Esse doce em especial tem a capacidade de destruir qualquer pe�a que por ele seja trocada, ou seja, se o
	biscoit�o for trocado de posi��o com uma pe�a circular azul, todos c�rculos azuis no tabuleiro ser�o apagados 
	e seus pontos ser�o registrados.
	Caso haja a troca de um biscoit�o por outro, ent�o todas as pe�as do tabuleiro ser�o "explodidas" e sorteadas 
	novamente com seus pontos contabilizados.

Contagem de Pontos:
	
	Tricas:                                                          	+40 
	Quadras ou Mais:                                                 	+80 (por pe�as al�m da trinca)
	Cruz Comum:                                                      	+30
	Cruzamento Vertical de Trica(em uma linha horizontal):           	+60
	Cruzamento Vertical de Quadras ou mais(em uma linha horizontal): 	+80 (por pe�as al�m da trinca)
	Biscoit�o:                                                       	+15 (por pe�a explodida) 

Implementa��o do Programa:

	Para a manipula��o do c�digo do jogo, como j� dito, foi utilizado das fun��es dispon�veis na API Canvas 2D
	e das fun��es padr�es do C, como math.h e string.h. Todo o programa no caso, � repetido sem interrup��es na
	fun��o "render" debtro da API que tem a capacidade de desenhar qualquer desenho na tela do computador a 
	partir de cada altera��o feita pelo usu�rio, no caso, dentro da fun��o render h� uma fun��o chamada Iniciar
	que manda e retorna uma valor para uma mesma vari�vel que por si s� controlar� o in�cio do jogo para evitar 
	a aleatoriedade do programa antes do necess�rio. 

	Para o desenho do tabuleiro do jogo foram deness�rio dos la�os de repeti��o, um para linhas horizontais e outro
	para linhas verticais que no caso, a partir de um valor inicial (margem e piso) das coordenadas do tabuleiro
	desenham somando a si mesmo um valor em X ou Y no plano cartesiano para desenhar linhas de um tabuleiro 
	quadriculado e representar setores onde entrar�o cada figura do jogo. 
	Na primeira jogada, todas pe�as do tabuleiro s�o sorteadas aleatoriamente a partir da biblioteca time.h e 
	posteriormente ser�o mantidas para serem alterada somente pelo usu�rio. Para representar cada pe�a, h� outros
	dois la�os de repeti��o que percorrer�o da mesma maneira que o desenho do tabuleiro, todo a matriz em branco 
	para desenhar cada pe�a no exato centro das "casas" da malha e ter seus limites da figura alterados manualmente
	pelo programador em cada tipo de figura. Foram representado c�rculos, tri�ngulos, hex�gonos e quadrados pelas 
	fun��es 'circle', 'rect' e 'polygon'.

	Para o contador de pontos, a pontua��o � configurada a medida das combina��es do jogador e guardados em uma vari�vel
	global. Tendo em vista que o programa s� exibe textos est�ticos, o valor da pontua��o � converitido para um vetor
	que guardar� cada ordem das unidades cimples (unidade, dezena, centena, etc.) e imprimir� cada uma na tela formando 
	um valor s� e exibindo a pontua��o real do usu�rio.

	Para a sele��o de pe�as do jogador, o programa chama uma fun��o sempre que as coordenadas do mouse estiverem dentro
	do tabuleiro e o bot�o esquerdo for pressionado. A partir da�, o programa percorrer� todo a matriz do jogo comparando	
	cada posi��o do mouse com sua coordenada reespecitiva do tabuleiro para assim, quando encontrar a posi��o correspondente,
	guardar essa informa��o em um ponteiro que receber� o endere�o da matriz na posi��o espec�fica para comparar posteriormente.
	Se durante a fun��o de desenahr as pe�as, for encontrada a pos���o onde o ponteiro possuir o mesmo endere�o do doce, um
	quadrado dourado ser� desenhado em volta para demontrar que ali a pe�a foi selecionada.
	Para segunda sele��o o funcionamento � exatamente igual, contudo, caso a segunda sele��o seja a mesma posi��o que a primeira,
	a sele��o ser� desfeita. Caso a segunda escolha esteja muito longe (qualquer posi��o que n�o seja adjacente a primeira
	sele��o de maneira horizontal ou vertical) ent�o a primeira sele��o tomar� o lugar segunda e a antiga sele��o ser� desfeita.
	
	Para a procura de combina��es, dois la�oes de repepti��o percorrer�o toda a matriz do jogo procurando primeiramente por
	linahs horizontais que tenham o mesmo valor consecutivo de tr�s ou mais pe�as iguais, para posteriormente, buscar combina��es
	verticais. Caso seja encontrada uma combina��o horizontal, outro la�o percorrer� essa linha correspondente buscando por 
	combina��es verticais, formando assim, as combina��es diferenciadas (cruzadas, forma de L ou T).
	Quando uma combina��o � formada, todas as pe�as desta s�o substitu�das por uma figuras vermelha e laranja para representar uma
	explos�o das pe�as. Posteriormente, o programa procurar� por essas figuras de explos�o e automaticamente as substituir� por
	espa�oes em branco para realizar o ShiftDown. Como j� dito, no topo novas pe�as ser�o sorteadas.
	Caso o jogador selecione duas pe�as que ap�s sua troca n�o ser� poss�vel realizar combina��es, ent�o a troca n�o ser� efetuada
	a as sele��es do jogador ser�o desfeitas.

	Durante o ShiftDown, cada pe�a v�lida ser� tranferida para baixo de cada vez, realizando um efeito visual de movimento dando a
	entender que as pe�as est�o literalmente caindo nos espa�os livres.	


	  