***************************************************************
---------------------------------------------------------------
Projet d'acquisition des données des field tests d'Atlantic Industrie
---------------------------------------------------------------
***************************************************************

Réalisateurs :
- SEALEY Floyd

--------------------------------
Objectif Général : 

Le Groupe Atlantic développe et commercialise des solutions de confort thermique tant bien
individuelles que collectives pour le chauffage de l’eau et de l’air, la climatisation et la ventilation
depuis 40 ans. Après la phase d’innovation où le produit est conçu, une phase
d’opportunité puis de faisabilité permettent de vérifier qu’un tel produit soit viable pour la
commercialisation.
Sur chaque chauffe-eau est monté un boitier appelé le LOG, permettant par exemple de vérifier la quantité d’eau chaude débitée par le
ballon. Ainsi, le LOG est un boitier qui, à la fois enregistre des données thermodynamiques du chauffe-eau via des capteurs incorporés dans le ballon, 
et qui régule par la suite les caractéristiques comme le débit pour assurer le bon fonctionnement du produit.
L’enjeu est de pouvoir dans un premier temps, faire l'acquisition de ces données à l'aide d'un dispositif arduino et dans un deuxième, 
transmettre des informations (températures, débit et puissance directement prises du ballon d’eau) et (prises du LOG) à distance à l’équipe R&D
sur un site web. C'est ce dernier volet qui est développé ici.

--------------------------------
Objectif des programmes: 

La plaque Arduino dispose des capteurs et est programmée pour enregistrer les données sur une carte SD incluse. Il est donc
possible d’obtenir directement un fichier .txt depuis cette carte SD afin d’envoyer le tout via le shield GSM/GPRS. C'est l'objectif
des codes envoieGSM.ino et envoiGPRS.ino


Le code de l'acuqisition préalable est log.ino

