## Zadanie 1

Zaimplementuj funkcję `isColliding` zwracającą `true` jeśli dwa trójkąty w przestrzeni 2D kolidują ze sobą.

### Rozwiązanie 

W celu sprawdzenia kolizji między trójkątami, sprawdzam czy któryś z wierzchołków danego trójkąta zawiera się w tym drugim i na odwrót. Gdy żaden z wierzchołków obu trójkątów nie spełnia tego wymagania sprawdzam czy któryś z boków przecina bok drugiego trójkąta. Jeśli oba warunki nie zostaną spełnione - trójkąty nie kolidują ze sobą.

### Uruchomienie

```
git clone https://github.com/M4yfl0w3r/recruitment-task.git

cd recruitment-task

mkdir build 

cd build

cmake ..

make
```

Aby uruchomić program
```
./sol_run
```

Aby uruchomić testy 
```
./sol_tst
```

Testy zostały napisane przy użyciu Google Test. CMake automatycznie załącza bibliotekę do programu.

