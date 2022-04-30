## Zadanie 2

Napisz wizualizator kolizji koła (statycznie położonego na środku ekranu) i obracającego się prostokąta (obrót poprzez naciśnięcie odpowiednich klawiszy np. q, e albo strzałki). Kolizja powinna być zasygnalizowana np. poprzez komunikat lub zmianę koloru obiektów.

### Rozwiązanie 

W celu sprawdzenia kolizji obiektów, najpierw sprawdzam czy środek koła znajduje się w prostokącie, gdy ten warunek nie zachodzi, sprawdzam czy któryś z wierzchołków prostokąta nie znajduje się kole, gdy obydwa przypadkie nie zachodzą, sprawdzam czy któryś z boków prostokąta nie przecina koła. Jeżeli te warunki nie zostaną spełnione - obiekty nie kolidują ze sobą. 

### Uruchomienie

```
git clone https://github.com/M4yfl0w3r/recruitment-task.git

cd recruitment-task

cd Ex2

mkdir build 

cd build

cmake ..

make
```

Aby uruchomić program
```
./sol_run
```

Obracać prostokątem można zarówno klawiszami q i e oraz strzałkami. <br/>
Kolizja obiektów sygnalizowana jest poprzez zmianę koloru. <br/>
W programie została użyta biblioteka SFML, którą CMake automatycznie załącza do programu.
