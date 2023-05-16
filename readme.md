# Mini-Projet C++

Ce repo git contient notre version du miniprojet du cours de C++ de l'ISEN.
Ce mini projet a pour but de créer une carte sur QT et d'afficher le chemin le plus court entre 2 villes de Bretagne.

## Compilation & utilisation

Afin de compiler le projet il est nécessaire d'avoir `make` ainsi que `qmake` sur votre ordinateur.  
Dans un premier temps il faudra compiler la libraire qui se trouve dans le dossier `lib/libBDD`.  

```bash
cd lib/libBDD && make
cd ../..
qmake
make
```

  
Puis il faudra ajouter la base de donnée à votre mysql.  
```bash 
sudo mysql
```
Puis dans mysql:  
```mysql
source assets/sql/adduser.sql
```  
  
Normalement si tout se passe bien vous devriez avoir une bdd au nom de miniprojet et qui contient les tables contour, route, ville, waypoint.
Et enfin pour lancer le programme:  

```bash  
./MiniProjetCPP
``` 

Un fichier de test est disponible afin de tester le bon fonctionnement de la librairie.  
```bash
make -f Makefile_test
./testBDD
```

## Utilisation

Il faudra vous connecter à votre BDD pour utiliser l'application. Une fois connecté vous pourrez choisir une ville de départ et une ville d'arrivée et le programme calculera le plus court chemin entre ces deux villes.

## License

Ce projet est sous la license [GPL v3](https://www.gnu.org/licenses/gpl-3.0.fr.html).

## Contribution

Ce projet est un projet scolaire et n'est donc pas ouvert aux contributions extérieures.