Proyecto de Ingenier ́ıa de Software
Juego de Damas
06 de Abril de 2015



                  Damas Chilenas
1.1 Objetivos
     Dejar sin movimiento al rival, por medio de:
     • Inmovilizar al contrincante, sin que pueda mover ninguna de sus piezas.
     • Capturar todas las piezas enemigas.

1.2 Tablero y Piezas
    El tablero es de 10x10 casillas colocando en la esquina inferior derecha la casilla
    de color blanco. Se utilizan 15 fichas por jugador (blancas y negras, respec-
    tivamente) las cuales se situaran sobre las casillas negras de las tres primeras
    filas de cada jugador. El juego se desarrolla, por lo tanto, s ́olo sobre las casillas
    negras. Comienza el juego quien ocupe las piezas blancas.

1.3 Reglas
    Las fichas avanzan en forma diagonal por el tablero s ́olo hacia adelante, no
    pueden capturar hacia atras. Se corona cuando se llega a la linea final, en
    donde la dama tiene la particularidad de que “vuela” (se mueve libremente
    sobre las diagonales de las casillas que se deseen, la dama puede retroceder).
    Para capturar una pieza contraria debe estar justo delante o atr ́as (s ́olo para la
    dama) de una  de las fichas. Se realiza en diagonal saltando sobre la pieza que se
    quiere capturar, cayendo en la casilla inmediatamente detr ́as de ella siguiendo
    la direccion del movimiento de nuestra pieza. Este movimiento se puede realizar
siempre y cuando la casilla final est ́e libre. Las capturas se pueden encadenar.
Esto es, si saltamos una pieza y desde esa posici ́on podemos saltar una y otra,
lo hacemos. Es obligaci ́
on capturar, siendo inv ́alido aquel movimiento que no
captura piezas enemigas teniendo posibilidades para hacerlo. En su turno si un
jugador dispone de dos o m ́
as opciones de captura, deber ́a optar por aquella
que capture mayor n ́
umero de piezas contrarias.
Se debe utilizar la regla ”Preferencia dama”, la cual estipula que ante dos o m ́as
posibilidades de captura, es obligaci ́on hacerlo con la dama aunque con el pe ́on
se puedan capturar m ́
as fichas enemigas.
Otra regla es la “sopladita” (obligaci ́on de captura), si no se cumple el oponente
1tiene el derecho a su elecci ́
on de pedir que se capture o se retire del juego la
ficha que no captur 




Proyecto
El proyecto consiste en dos partes:
Por un lado deben entregar el c ́
odigo fuente de un programa ejecutable. Y
por otro lado deben entregar un informe de dise ̃
no de la soluci ́on.
• El lenguaje de programaci ́on debe ser C o C++. El compilador en que se
revisar ́
a ser ́
a gcc (aconsejo usar MinGW en Windows).
• El trabajo debe ser realizado por los grupos de 3 personas definidos.
• La fecha de entrega es hasta el 03 de Julio de 2015 a las 23:55 (hora con-
tinental de Chile), deben enviarme un correo electr ́onico con la direcci ́on
de su repositorio GitHub.
• Cualquier duda, la pueden expresar en el grupo de Facebook o a mi correo.
