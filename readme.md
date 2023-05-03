# Mini-Projet C++

Ce repo git contient notre version du miniprojet du cours de C++ de l'ISEN.
Ce mini projet a pour but de créer une carte sur QT et d'afficher le chemin le plus court entre 2 villes de Bretagne.

## Compilation & utilisation

Afin de compiler le projet il est nécessaire d'avoir make sur votre ordinateur.  
Puis executer la commande suivante:  
  
`make`  
  
Puis il faudra ajouter la base de donnée à votre mysql.

`sudo mysql`
`source assets/sql/adduser.sql`

Normalement si tout se passe bien vous devriez avoir une bdd au nom de miniprojet et qui contient les tables contour, route, ville, waypoint.
Et enfin pour lancer le programme:  
  
`./MiniProjetCPP`  

## TODO:
- Connexion BDD (fenêtre pour se connecter / pas de connexion en durs)
