-- phpMyAdmin SQL Dump
-- version 4.2.13.3
-- http://www.phpmyadmin.net
--
-- Client :  localhost
-- Généré le :  Mar 10 Novembre 2020 à 10:59
-- Version du serveur :  10.0.22-MariaDB
-- Version de PHP :  5.6.15

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de données :  `localisationmateriel`
--

-- --------------------------------------------------------

--
-- Structure de la table `attribution`
--

CREATE TABLE IF NOT EXISTS `attribution` (
`id` int(11) NOT NULL,
  `idBatiment` int(11) NOT NULL,
  `idSalle` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `attribution`
--

INSERT INTO `attribution` (`id`, `idBatiment`, `idSalle`) VALUES
(1, 10, 10),
(2, 10, 11),
(3, 10, 12),
(4, 10, 13);

-- --------------------------------------------------------

--
-- Structure de la table `batiment`
--

CREATE TABLE IF NOT EXISTS `batiment` (
`id` int(11) NOT NULL,
  `nomBatiment` varchar(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `plan` varchar(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `batiment`
--

INSERT INTO `batiment` (`id`, `nomBatiment`, `plan`) VALUES
(10, 'Batiment 4', '/home/saturne/S2Coba/Hutinet/Mini_Projets2020_21/Metrologie/src/AppLocalisation/AppLocalisation/image/batiment 4.jpg');

-- --------------------------------------------------------

--
-- Structure de la table `lecteur`
--

CREATE TABLE IF NOT EXISTS `lecteur` (
`id` int(11) NOT NULL,
  `ip` varchar(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `modele` varchar(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `etatOn` tinyint(1) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `lecteur`
--

INSERT INTO `lecteur` (`id`, `ip`, `modele`, `etatOn`) VALUES
(1, '172.16.79.100', 'simu', 0),
(2, '172.16.79.101', 'simu', 0),
(3, '172.16.79.102', 'simu', 0),
(4, '172.16.79.103', 'simu', 0),
(5, '172.16.79.104', 'simu', 0);

-- --------------------------------------------------------

--
-- Structure de la table `localisation`
--

CREATE TABLE IF NOT EXISTS `localisation` (
`id` int(11) NOT NULL,
  `idMateriel` int(11) NOT NULL,
  `idSalle` int(11) NOT NULL,
  `sortie` tinyint(1) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `localisation`
--

INSERT INTO `localisation` (`id`, `idMateriel`, `idSalle`, `sortie`) VALUES
(1, 1, 13, 0),
(2, 2, 13, 0),
(3, 3, 13, 0);

-- --------------------------------------------------------

--
-- Structure de la table `materiel`
--

CREATE TABLE IF NOT EXISTS `materiel` (
`id` int(11) NOT NULL,
  `idBadge` varchar(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `dateControle` date NOT NULL,
  `newDateControle` date NOT NULL,
  `nomMateriel` varchar(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `idType` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `materiel`
--

INSERT INTO `materiel` (`id`, `idBadge`, `dateControle`, `newDateControle`, `nomMateriel`, `idType`) VALUES
(1, 'AD813077', '2015-04-07', '2016-04-07', 'osilloscope 2', 1),
(2, '2B823077', '2003-02-18', '2004-02-18', 'voltemetre 1', 3),
(3, '0415DB52', '2003-02-18', '2003-03-18', 'ampermetre 1', 2);

-- --------------------------------------------------------

--
-- Structure de la table `metrologue`
--

CREATE TABLE IF NOT EXISTS `metrologue` (
`id` int(11) NOT NULL,
  `login` varchar(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `password` varchar(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `metrologue`
--

INSERT INTO `metrologue` (`id`, `login`, `password`) VALUES
(1, 'admin', '21232f297a57a5a743894a0e4a801fc3');

-- --------------------------------------------------------

--
-- Structure de la table `portique`
--

CREATE TABLE IF NOT EXISTS `portique` (
`id` int(11) NOT NULL,
  `x` float NOT NULL,
  `y` float NOT NULL,
  `idSalle1` int(11) NOT NULL,
  `idSalle2` int(11) DEFAULT NULL,
  `idLecteur` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `portique`
--

INSERT INTO `portique` (`id`, `x`, `y`, `idSalle1`, `idSalle2`, `idLecteur`) VALUES
(1, 17.1975, 78.1086, 11, 10, 1),
(2, 16.9427, 58.3187, 10, NULL, 2),
(3, 48.2803, 44.3082, 12, NULL, 3),
(5, 36.4331, 36.2522, 13, NULL, 4),
(6, 47.8981, 32.3993, 13, NULL, 5);

-- --------------------------------------------------------

--
-- Structure de la table `salle`
--

CREATE TABLE IF NOT EXISTS `salle` (
`id` int(11) NOT NULL,
  `x_ini` float NOT NULL,
  `y_ini` float NOT NULL,
  `x_fin` float NOT NULL,
  `y_fin` float NOT NULL,
  `numSalle` int(11) NOT NULL,
  `nomSalle` varchar(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `nomAtelier` varchar(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `salle`
--

INSERT INTO `salle` (`id`, `x_ini`, `y_ini`, `x_fin`, `y_fin`, `numSalle`, `nomSalle`, `nomAtelier`) VALUES
(10, 3.69427, 58.669, 20.5096, 77.4081, 459, 'Salle SNIR eval', 'SNIR'),
(11, 3.56688, 78.2837, 27.3885, 94.7461, 458, 'Salle SNIR cours', 'SNIR'),
(12, 29.4268, 45.359, 51.9745, 94.2207, 452, 'Salle SNEC', 'SNEC'),
(13, 34.0127, 17.8634, 50.4459, 36.7776, 400, 'Magasin', 'MMagasin');

-- --------------------------------------------------------

--
-- Structure de la table `type`
--

CREATE TABLE IF NOT EXISTS `type` (
`id` int(11) NOT NULL,
  `nomType` varchar(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `nomImage` varchar(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `type`
--

INSERT INTO `type` (`id`, `nomType`, `nomImage`) VALUES
(1, 'oscilloscope', '/home/saturne/S2Coba/Hutinet/Mini_Projets2020_21/Metrologie/src/AppLocalisation/AppLocalisation/image/oscillo.jpg'),
(2, 'amperemetre', '/home/saturne/S2Coba/Hutinet/Mini_Projets2020_21/Metrologie/src/AppLocalisation/AppLocalisation/image/amper.jpg'),
(3, 'voltmetre', '/home/saturne/S2Coba/Hutinet/Mini_Projets2020_21/Metrologie/src/AppLocalisation/AppLocalisation/image/volt.jpg');

--
-- Index pour les tables exportées
--

--
-- Index pour la table `attribution`
--
ALTER TABLE `attribution`
 ADD PRIMARY KEY (`id`), ADD UNIQUE KEY `idSalle` (`idSalle`), ADD KEY `idBatiment` (`idBatiment`);

--
-- Index pour la table `batiment`
--
ALTER TABLE `batiment`
 ADD PRIMARY KEY (`id`), ADD UNIQUE KEY `nomBatiment` (`nomBatiment`), ADD UNIQUE KEY `plan` (`plan`);

--
-- Index pour la table `lecteur`
--
ALTER TABLE `lecteur`
 ADD PRIMARY KEY (`id`), ADD UNIQUE KEY `ip` (`ip`), ADD KEY `modele` (`modele`), ADD KEY `etatOn` (`etatOn`);

--
-- Index pour la table `localisation`
--
ALTER TABLE `localisation`
 ADD PRIMARY KEY (`id`), ADD UNIQUE KEY `idMateriel` (`idMateriel`), ADD KEY `idSalle` (`idSalle`), ADD KEY `sortie` (`sortie`);

--
-- Index pour la table `materiel`
--
ALTER TABLE `materiel`
 ADD PRIMARY KEY (`id`), ADD UNIQUE KEY `idBadge` (`idBadge`), ADD KEY `dateControle` (`dateControle`), ADD KEY `nomMateriel` (`nomMateriel`), ADD KEY `idType` (`idType`), ADD KEY `newDateControle` (`newDateControle`);

--
-- Index pour la table `metrologue`
--
ALTER TABLE `metrologue`
 ADD PRIMARY KEY (`id`), ADD UNIQUE KEY `login` (`login`), ADD KEY `password` (`password`);

--
-- Index pour la table `portique`
--
ALTER TABLE `portique`
 ADD PRIMARY KEY (`id`), ADD UNIQUE KEY `idLecteur` (`idLecteur`), ADD KEY `idSalle1` (`idSalle1`), ADD KEY `idSalle2` (`idSalle2`), ADD KEY `x` (`x`,`y`);

--
-- Index pour la table `salle`
--
ALTER TABLE `salle`
 ADD PRIMARY KEY (`id`), ADD UNIQUE KEY `numSalle` (`numSalle`), ADD KEY `x_ini` (`x_ini`), ADD KEY `y_ini` (`y_ini`), ADD KEY `x_fin` (`x_fin`), ADD KEY `y_fin` (`y_fin`), ADD KEY `nomSalle` (`nomSalle`), ADD KEY `nomAtelier` (`nomAtelier`);

--
-- Index pour la table `type`
--
ALTER TABLE `type`
 ADD PRIMARY KEY (`id`), ADD UNIQUE KEY `nomType` (`nomType`), ADD KEY `nomImage` (`nomImage`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `attribution`
--
ALTER TABLE `attribution`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT pour la table `batiment`
--
ALTER TABLE `batiment`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=12;
--
-- AUTO_INCREMENT pour la table `lecteur`
--
ALTER TABLE `lecteur`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT pour la table `localisation`
--
ALTER TABLE `localisation`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT pour la table `materiel`
--
ALTER TABLE `materiel`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT pour la table `metrologue`
--
ALTER TABLE `metrologue`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT pour la table `portique`
--
ALTER TABLE `portique`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=7;
--
-- AUTO_INCREMENT pour la table `salle`
--
ALTER TABLE `salle`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=14;
--
-- AUTO_INCREMENT pour la table `type`
--
ALTER TABLE `type`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=4;
--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `attribution`
--
ALTER TABLE `attribution`
ADD CONSTRAINT `fk_attribution_batiment` FOREIGN KEY (`idBatiment`) REFERENCES `batiment` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
ADD CONSTRAINT `fk_attribution_salle1` FOREIGN KEY (`idSalle`) REFERENCES `salle` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Contraintes pour la table `localisation`
--
ALTER TABLE `localisation`
ADD CONSTRAINT `fk_localisation_materiel1` FOREIGN KEY (`idMateriel`) REFERENCES `materiel` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
ADD CONSTRAINT `fk_localisation_salle1` FOREIGN KEY (`idSalle`) REFERENCES `salle` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Contraintes pour la table `materiel`
--
ALTER TABLE `materiel`
ADD CONSTRAINT `fk_materiel_type1` FOREIGN KEY (`idType`) REFERENCES `type` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Contraintes pour la table `portique`
--
ALTER TABLE `portique`
ADD CONSTRAINT `fk_portique_lecteur1` FOREIGN KEY (`idLecteur`) REFERENCES `lecteur` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
ADD CONSTRAINT `fk_portique_salle1` FOREIGN KEY (`idSalle1`) REFERENCES `salle` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
ADD CONSTRAINT `fk_portique_salle2` FOREIGN KEY (`idSalle2`) REFERENCES `salle` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
