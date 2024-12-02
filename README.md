# Simulation d'un Écosystème : Proies et Prédateurs

## Description du Projet
Ce projet est une simulation d'un écosystème simplifié dans lequel des proies et des prédateurs interagissent. L'écosystème est modélisé à l'aide de listes chaînées et utilise un espace représenté sous forme d'un tableau bidimensionnel (un "tore") pour simuler le mouvement des entités. Chaque entité (proie ou prédateur) se déplace dans l'espace et peut interagir avec d'autres entités présentes dans la même case.

### Objectif
L'objectif principal de ce projet est de créer une simulation interactive permettant de comprendre les concepts d'équilibre écologique et la dynamique des populations de proies et de prédateurs. Les entités doivent interagir de manière réaliste pour montrer des comportements tels que la chasse, la fuite et la reproduction.

## Fonctionnalités
- **Simulation d'un espace écologique** : Un monde représenté par un tableau bidimensionnel où les entités se déplacent.
- **Proies et Prédateurs** : Les proies se déplacent aléatoirement et les prédateurs les chassent. Chaque entité a des comportements définis (par exemple, les prédateurs chassent les proies et les proies fuient).
- **Interactivité** : Les entités peuvent se déplacer d'une case à l'autre et interagir avec celles présentes sur la même case.
- **Liste chaînée** : Les proies et les prédateurs sont stockés dans des listes chaînées séparées, permettant une gestion flexible et efficace des entités.

## Technologies Utilisées
- **Langage de programmation** : C
- **Structures de données** : Listes chaînées, tableau bidimensionnel pour l'espace
- **Concepts** : Programmation orientée vers les structures de données, simulation de processus, algorithmique

## Installation et Exécution
### Prérequis
- Un compilateur C (par exemple, GCC)
- Un éditeur de code (Visual Studio Code, Sublime Text, etc.)

### Instructions d'installation
1. Clonez le dépôt ou téléchargez le code source.
2. Compilez le programme avec la commande suivante :
   ```bash
   gcc -o simulation simulation.c
