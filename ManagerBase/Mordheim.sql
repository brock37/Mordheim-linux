-- phpMyAdmin SQL Dump
-- version 4.2.12deb2+deb8u1
-- http://www.phpmyadmin.net
--
-- Client :  localhost
-- Généré le :  Sam 14 Mai 2016 à 11:26
-- Version du serveur :  5.5.46-0+deb8u1
-- Version de PHP :  5.6.14-0+deb8u1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de données :  `Mordheim`
--

-- --------------------------------------------------------

--
-- Structure de la table `equipement`
--

CREATE TABLE IF NOT EXISTS `equipement` (
`ID` int(11) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `Type` varchar(255) NOT NULL,
  `prix` int(11) NOT NULL,
  `description` text NOT NULL,
  `regles` text NOT NULL,
  `Force` int(11) DEFAULT NULL,
  `Protee` int(11) DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `equipement`
--

INSERT INTO `equipement` (`ID`, `nom`, `Type`, `prix`, `description`, `regles`, `Force`, `Protee`) VALUES
(1, 'Dague', 'CAC', 2, '', '', NULL, NULL),
(2, 'Masse', 'CAC', 3, '', 'Contondant', NULL, NULL),
(3, 'Marteau', 'CAC', 3, '', 'Contondant', NULL, NULL);

-- --------------------------------------------------------

--
-- Structure de la table `listemembre_glop`
--

CREATE TABLE IF NOT EXISTS `listemembre_glop` (
`id` smallint(5) unsigned NOT NULL,
  `id_ref_profil` smallint(5) unsigned NOT NULL,
  `nom` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `listemembre_nains d'erebor`
--

CREATE TABLE IF NOT EXISTS `listemembre_nains d'erebor` (
`id` int(11) NOT NULL,
  `id_ref_profil` int(11) NOT NULL,
  `nom` varchar(255) DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `listemembre_nains d'erebor`
--

INSERT INTO `listemembre_nains d'erebor` (`id`, `id_ref_profil`, `nom`) VALUES
(1, 1, 'Ecu de chene'),
(2, 2, 'Balin'),
(3, 4, 'Morgul'),
(4, 4, NULL);

-- --------------------------------------------------------

--
-- Structure de la table `listemembre_nains de lamoria`
--

CREATE TABLE IF NOT EXISTS `listemembre_nains de lamoria` (
`id` smallint(5) unsigned NOT NULL,
  `id_ref_profil` smallint(5) unsigned NOT NULL,
  `nom` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `listemembre_ouza`
--

CREATE TABLE IF NOT EXISTS `listemembre_ouza` (
`id` smallint(5) unsigned NOT NULL,
  `id_ref_profil` smallint(5) unsigned NOT NULL,
  `nom` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `listemembre_piis'arlk`
--

CREATE TABLE IF NOT EXISTS `listemembre_piis'arlk` (
`id` smallint(5) unsigned NOT NULL,
  `id_ref_profil` smallint(5) unsigned NOT NULL,
  `nom` varchar(30) DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `listemembre_piis'arlk`
--

INSERT INTO `listemembre_piis'arlk` (`id`, `id_ref_profil`, `nom`) VALUES
(1, 1, 'hoho'),
(2, 1, NULL),
(3, 1, NULL),
(4, 3, NULL);

-- --------------------------------------------------------

--
-- Structure de la table `listemembre_piis'ar lk`
--

CREATE TABLE IF NOT EXISTS `listemembre_piis'ar lk` (
`id` smallint(5) unsigned NOT NULL,
  `id_ref_profil` smallint(5) unsigned NOT NULL,
  `nom` varchar(30) DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `listemembre_piis'ar lk`
--

INSERT INTO `listemembre_piis'ar lk` (`id`, `id_ref_profil`, `nom`) VALUES
(1, 3, 'orkul'),
(2, 3, 'jo'),
(3, 4, 'bollop'),
(4, 1, NULL);

-- --------------------------------------------------------

--
-- Structure de la table `listemembre_plo blop`
--

CREATE TABLE IF NOT EXISTS `listemembre_plo blop` (
`id` smallint(5) unsigned NOT NULL,
  `id_ref_profil` smallint(5) unsigned NOT NULL,
  `nom` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `listemembre_pougou`
--

CREATE TABLE IF NOT EXISTS `listemembre_pougou` (
`id` smallint(5) unsigned NOT NULL,
  `id_ref_profil` smallint(5) unsigned NOT NULL,
  `nom` varchar(30) DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `listemembre_pougou`
--

INSERT INTO `listemembre_pougou` (`id`, `id_ref_profil`, `nom`) VALUES
(1, 1, NULL);

-- --------------------------------------------------------

--
-- Structure de la table `listemembre_ptit gars`
--

CREATE TABLE IF NOT EXISTS `listemembre_ptit gars` (
`id` smallint(5) unsigned NOT NULL,
  `id_ref_profil` smallint(5) unsigned NOT NULL,
  `nom` varchar(30) DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `listemembre_ptit gars`
--

INSERT INTO `listemembre_ptit gars` (`id`, `id_ref_profil`, `nom`) VALUES
(1, 1, NULL);

-- --------------------------------------------------------

--
-- Structure de la table `listemembre_rat dagaste`
--

CREATE TABLE IF NOT EXISTS `listemembre_rat dagaste` (
`id` smallint(5) unsigned NOT NULL,
  `id_ref_profil` smallint(5) unsigned NOT NULL,
  `nom` varchar(30) DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `listemembre_rat dagaste`
--

INSERT INTO `listemembre_rat dagaste` (`id`, `id_ref_profil`, `nom`) VALUES
(1, 2, NULL);

-- --------------------------------------------------------

--
-- Structure de la table `listemembre_retr' a`
--

CREATE TABLE IF NOT EXISTS `listemembre_retr' a` (
`id` smallint(5) unsigned NOT NULL,
  `id_ref_profil` smallint(5) unsigned NOT NULL,
  `nom` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `listerang`
--

CREATE TABLE IF NOT EXISTS `listerang` (
`id` int(10) unsigned NOT NULL,
  `nom` varchar(255) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `listerang`
--

INSERT INTO `listerang` (`id`, `nom`) VALUES
(1, 'Héros'),
(2, 'Hommes de main');

-- --------------------------------------------------------

--
-- Structure de la table `liste_bandes`
--

CREATE TABLE IF NOT EXISTS `liste_bandes` (
`ID` int(10) unsigned NOT NULL,
  `nom` varchar(255) NOT NULL,
  `id_race` int(11) NOT NULL,
  `ValeurDeBase` int(11) NOT NULL,
  `ValeurActuelle` int(11) NOT NULL DEFAULT '0',
  `nomTableListeMembre` varchar(255) NOT NULL,
  `nomTableListeEquipement` varchar(255) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=25 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `liste_bandes`
--

INSERT INTO `liste_bandes` (`ID`, `nom`, `id_race`, `ValeurDeBase`, `ValeurActuelle`, `nomTableListeMembre`, `nomTableListeEquipement`) VALUES
(1, 'nains d''Erebor', 1, 500, 0, 'listeMembre_nainsd''Erebor', 'listeEquipement_nainsdErebor'),
(2, 'Nains de la moria', 1, 500, 0, 'listeMembre_Nains de la moria', 'listeEquipement_Nainsdelamoria'),
(3, 'Nains de Monts de fer', 1, 500, 0, 'listeMembre_NainsdeMontsdefer', 'listeEquipement_NainsdeMontsdefer'),
(4, 'Orques de la moria', 2, 500, 0, 'listeMembre_Orquesdelamoria', 'listeEquipement_Orquesdelamoria'),
(13, 'ouza', 1, 500, 0, 'listeMembre_ouza', 'listeEquipement_ouza'),
(16, 'piis''ar lk', 1, 500, 0, 'listeMembre_piis''arlk', 'listeEquipement_piis''arlk'),
(17, 'ptit gars', 2, 500, 0, 'listeMembre_ptitgars', 'listeEquipement_ptitgars'),
(18, 'pougou', 1, 500, 0, 'listeMembre_pougou', 'listeEquipement_pougou'),
(19, 'rat dagaste', 1, 500, 0, 'listeMembre_ratdagaste', 'listeEquipement_ratdagaste'),
(20, 'plo blop', 2, 500, 0, 'listeMembre_ploblop', 'listeEquipement_ploblop'),
(21, 'glop', 1, 500, 0, 'listeMembre_glop', 'listeEquipement_glop'),
(23, 'Nains de lamoria', 1, 500, 0, 'listeMembre_Nainsdelamoria', 'listeEquipement_Nainsdelamoria'),
(24, 'piis''arlk', 1, 500, 0, 'listeMembre_piis''arlk', 'listeEquipement_piis''arlk');

-- --------------------------------------------------------

--
-- Structure de la table `race`
--

CREATE TABLE IF NOT EXISTS `race` (
`ID` int(11) NOT NULL,
  `nom_race` varchar(255) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `race`
--

INSERT INTO `race` (`ID`, `nom_race`) VALUES
(1, 'Nains'),
(2, 'Orques'),
(3, 'Hommes-bêtes'),
(4, 'Skavens');

-- --------------------------------------------------------

--
-- Structure de la table `rang`
--

CREATE TABLE IF NOT EXISTS `rang` (
`id` int(10) unsigned NOT NULL,
  `nom_rang` varchar(255) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `rang`
--

INSERT INTO `rang` (`id`, `nom_rang`) VALUES
(0, 'Héros'),
(1, 'Hommes de Main');

-- --------------------------------------------------------

--
-- Structure de la table `ref_profil`
--

CREATE TABLE IF NOT EXISTS `ref_profil` (
`ID` int(11) NOT NULL,
  `id_rang` int(11) NOT NULL,
  `id_race` int(11) NOT NULL,
  `Nom` varchar(255) NOT NULL,
  `Prix` int(11) NOT NULL,
  `M` int(11) NOT NULL,
  `CC` int(11) NOT NULL,
  `CT` int(11) NOT NULL,
  `F` int(11) NOT NULL,
  `E` int(11) NOT NULL,
  `PV` int(11) NOT NULL,
  `I` int(11) NOT NULL,
  `A` int(11) NOT NULL,
  `Cd` int(11) NOT NULL,
  `Arme_Armure` text NOT NULL,
  `Regle` int(11) DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `ref_profil`
--

INSERT INTO `ref_profil` (`ID`, `id_rang`, `id_race`, `Nom`, `Prix`, `M`, `CC`, `CT`, `F`, `E`, `PV`, `I`, `A`, `Cd`, `Arme_Armure`, `Regle`) VALUES
(1, 0, 1, 'Noble Nain', 85, 3, 5, 4, 3, 4, 1, 2, 1, 9, 'Guerriers Nains', 1),
(2, 0, 1, 'Ingenieur Nain', 50, 3, 4, 3, 3, 4, 1, 2, 1, 9, '', 0),
(3, 0, 1, 'Tueurs de Trolls Nain', 50, 3, 4, 3, 3, 4, 1, 2, 1, 9, '', 0),
(4, 1, 1, 'Guerriers nains', 40, 3, 4, 3, 3, 4, 1, 2, 1, 9, '', 0),
(5, 1, 1, 'Tireurs nains', 40, 3, 4, 3, 3, 4, 1, 2, 1, 9, '', 0),
(6, 1, 1, 'Poil-au-menton', 25, 3, 3, 2, 3, 4, 1, 2, 1, 8, '', 0),
(7, 0, 2, 'Chef Orque', 80, 4, 4, 4, 4, 4, 1, 3, 1, 8, '', 0),
(8, 0, 2, 'Chaman Orque', 40, 4, 3, 3, 3, 4, 1, 3, 1, 7, '', 0),
(9, 0, 3, 'chef homme-bête', 65, 5, 4, 3, 4, 4, 1, 4, 1, 7, '', 0),
(10, 0, 3, 'Shaman homme-bête', 45, 5, 4, 3, 3, 4, 1, 3, 1, 6, '', 0),
(11, 0, 3, 'Bestigor', 45, 5, 4, 3, 4, 4, 1, 3, 1, 7, '', 0),
(12, 0, 3, 'Centigor', 80, 8, 4, 3, 4, 4, 1, 2, 1, 7, '', 0),
(13, 1, 3, 'Ungor', 25, 5, 3, 3, 3, 3, 1, 3, 1, 6, '', NULL),
(14, 1, 3, 'Gor', 35, 5, 4, 3, 3, 3, 1, 3, 1, 6, '', NULL),
(15, 1, 3, 'Chien du chaos', 15, 7, 4, 0, 4, 3, 1, 3, 1, 5, '', NULL),
(16, 1, 3, 'Minotaure', 200, 6, 4, 3, 4, 4, 3, 4, 3, 8, '', NULL);

-- --------------------------------------------------------

--
-- Structure de la table `regles_speciales`
--

CREATE TABLE IF NOT EXISTS `regles_speciales` (
`ID` int(11) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `description` text NOT NULL,
  `resume` varchar(255) NOT NULL,
  `id_personnage` int(11) DEFAULT NULL,
  `id_race` int(11) DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `regles_speciales`
--

INSERT INTO `regles_speciales` (`ID`, `nom`, `description`, `resume`, `id_personnage`, `id_race`) VALUES
(1, 'Difficile a tuer', 'Les nains sont très coriaces et résilients, ils ne peuvent donc être mis hors combat que sur un jet de 6 au lieu de 5-6 sur le tableau des degats.', 'hors combat que sur un jet de 6 au lieu de 5-6 sur le tableau des degats', NULL, 1),
(2, 'Tête dure', 'Les nains ignorent les règles spéciales des masses, marteaux,etc. Ils ne sont pas faciles a assommer!', 'Les nains ignorent les règles spéciales des masses, marteaux,etc.', NULL, 1),
(3, 'Armure', 'Les nains ne subissent aucune pénalité de mouvement pour le port d''une armure.', 'Les nains ne subissent aucune pénalité de mouvement pour le port d''une armure.', NULL, 1),
(4, 'Haine des orques et des gobelins', 'Tous les nains haïssent les orques et les gobelins. Voir la section psychologie des règles de Mordheim pour les détails sur les effets de la haine.', 'Tous les nains haïssent les orques et les gobelins.', NULL, 1),
(5, 'Rancuniers', 'Les nains gardent une vieille rancœur contre les elfes qui date du temps où les deux races se disputaient\r\nla suprématie sur le Vieux Monde. Une bande nains ne peut jamais inclure de ranc-tireur elfe, quel qu’il soit.', 'Une bande nains ne peut jamais inclure de franc-tireur elfe, quel qu’il soit.', NULL, 1),
(6, 'Mineurs Sans Egaux', 'Les nains passent leur vie sous terre a\r\nla recherche de minerais précieux et sont les meilleurs mineurs du Vieux Monde. Dans la cité de Mordheim, ils mettent leur talent a pro?t pour chercher de la Pierre Magique. Ajoutez + 1 au nombre de fragments trouvés lors du jet pour déterminer la quantité de Pierre Magique a la ?n de la partie.', 'Ajoutez + 1 au nombre de fragments trouvés lors du jet pour déterminer\r\nla quantité de Pierre Magique a la ?n de la partie.', NULL, 1),
(7, 'Chef', 'Tout membre de la bande situé a moins de 6ps du noble nain peut utiliser le Commandement de ce dernier a la place du sien pour effectuer ses tests.', 'Tout membre de la bande situé a moins de 6ps du noble nain peut utiliser le Commandement de ce dernier', 1, NULL),
(8, 'Maître Armurier', 'Les ingénieurs nains sont des experts en mécanique. Grâce a l’utilisation de meilleurs matériaux et de techniques secrètes, un ingénieur nain peut accroître la portée des armes de tir de la bande. Toutes les armes de tir de la bande voient leur portée accrue de 6ps tant que l’ingénieur fait partie de la bande (Les modi?cations nécessitent l’entretien constant et méticuleux d’un expert).', 'Toutes les armes de tir de la bande voient leur portée accrue de 6ps tant que l’ingénieur fait partie de la bande.', 2, NULL),
(9, 'Voeu de Mort', 'Les Tueurs de Trolls cherchent une mort honorable au combat. Ils sont immunisés a la psychologie et ne font jamais de test lorsqu’ils se battent seuls.', 'Ils sont immunisés a la psychologie et ne font jamais de test lorsqu’ils se battent seuls.', 3, NULL),
(10, 'Compétences de Tueur', 'Les Tueurs de Trolls peuvent choisir une compétence dans le tableau des compétences de Tueur au lieu des tableaux de compétences classiques lorsqu’ils gagnent une nouvelle compétence.', 'Les Tueurs de Trolls peuvent choisir une compétence dans le tableau des compétences de Tueur', 3, NULL),
(11, 'Des gens peu recommandables', 'De nombreux Francs-Tireurs refuseraient de travailler pour des orques car ils savent que ces derniers peuvents à tout moment se retourner contre eux. Une bande d''orques ne peut donc louer les services que des francs-Tireurs suivants : Gladiateurs, Ogres ou Mages.', 'les orques peuventlouer les services que des francs-Tireurs suivants : Gladiateurs, Ogres ou Mages.', NULL, 2),
(12, 'Sorcier', 'Un Chaman homme-bête est un sorcier, il peut utiliser les rituels du chaos décrits dans la section magie du livre de règles de Mordheim (p.59).', '', 9, NULL),
(13, 'Ivre', 'Avant un combat, le Centigor a pour habitude d''ingurgiter de grandes quantités de bière et de vin, fruits de ses précédentes rapines. Cette pratique les plonge dans une ivresse frénétique aux effets variables.\r\n\r\nAu début de chaque tour, jetez 1D6. Sur un résultat de 1, effectuez un test de stupidité (en cas d’échec, l''effet dure jusqu''à la fin du tour).\r\nSi vous obtenez un résultat compris entre 2 et 5, rien de particulier. Un résultat de 6 indique qu''il devient frénétique pour la durée du tour.\r\n\r\nLorsqu''il est stupide ou frénétique, le Centigor est immunisé à la psychologie.', '1D6 1->stupidité/2-5->R.A.S/6->frénétique', 12, NULL);

--
-- Index pour les tables exportées
--

--
-- Index pour la table `equipement`
--
ALTER TABLE `equipement`
 ADD PRIMARY KEY (`ID`);

--
-- Index pour la table `listemembre_glop`
--
ALTER TABLE `listemembre_glop`
 ADD PRIMARY KEY (`id`);

--
-- Index pour la table `listemembre_nains d'erebor`
--
ALTER TABLE `listemembre_nains d'erebor`
 ADD PRIMARY KEY (`id`);

--
-- Index pour la table `listemembre_nains de lamoria`
--
ALTER TABLE `listemembre_nains de lamoria`
 ADD PRIMARY KEY (`id`);

--
-- Index pour la table `listemembre_ouza`
--
ALTER TABLE `listemembre_ouza`
 ADD PRIMARY KEY (`id`);

--
-- Index pour la table `listemembre_piis'arlk`
--
ALTER TABLE `listemembre_piis'arlk`
 ADD PRIMARY KEY (`id`);

--
-- Index pour la table `listemembre_piis'ar lk`
--
ALTER TABLE `listemembre_piis'ar lk`
 ADD PRIMARY KEY (`id`);

--
-- Index pour la table `listemembre_plo blop`
--
ALTER TABLE `listemembre_plo blop`
 ADD PRIMARY KEY (`id`);

--
-- Index pour la table `listemembre_pougou`
--
ALTER TABLE `listemembre_pougou`
 ADD PRIMARY KEY (`id`);

--
-- Index pour la table `listemembre_ptit gars`
--
ALTER TABLE `listemembre_ptit gars`
 ADD PRIMARY KEY (`id`);

--
-- Index pour la table `listemembre_rat dagaste`
--
ALTER TABLE `listemembre_rat dagaste`
 ADD PRIMARY KEY (`id`);

--
-- Index pour la table `listemembre_retr' a`
--
ALTER TABLE `listemembre_retr' a`
 ADD PRIMARY KEY (`id`);

--
-- Index pour la table `listerang`
--
ALTER TABLE `listerang`
 ADD PRIMARY KEY (`id`);

--
-- Index pour la table `liste_bandes`
--
ALTER TABLE `liste_bandes`
 ADD PRIMARY KEY (`ID`);

--
-- Index pour la table `race`
--
ALTER TABLE `race`
 ADD PRIMARY KEY (`ID`);

--
-- Index pour la table `rang`
--
ALTER TABLE `rang`
 ADD PRIMARY KEY (`id`);

--
-- Index pour la table `ref_profil`
--
ALTER TABLE `ref_profil`
 ADD PRIMARY KEY (`ID`);

--
-- Index pour la table `regles_speciales`
--
ALTER TABLE `regles_speciales`
 ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `equipement`
--
ALTER TABLE `equipement`
MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT pour la table `listemembre_glop`
--
ALTER TABLE `listemembre_glop`
MODIFY `id` smallint(5) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `listemembre_nains d'erebor`
--
ALTER TABLE `listemembre_nains d'erebor`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT pour la table `listemembre_nains de lamoria`
--
ALTER TABLE `listemembre_nains de lamoria`
MODIFY `id` smallint(5) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `listemembre_ouza`
--
ALTER TABLE `listemembre_ouza`
MODIFY `id` smallint(5) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `listemembre_piis'arlk`
--
ALTER TABLE `listemembre_piis'arlk`
MODIFY `id` smallint(5) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT pour la table `listemembre_piis'ar lk`
--
ALTER TABLE `listemembre_piis'ar lk`
MODIFY `id` smallint(5) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT pour la table `listemembre_plo blop`
--
ALTER TABLE `listemembre_plo blop`
MODIFY `id` smallint(5) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `listemembre_pougou`
--
ALTER TABLE `listemembre_pougou`
MODIFY `id` smallint(5) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT pour la table `listemembre_ptit gars`
--
ALTER TABLE `listemembre_ptit gars`
MODIFY `id` smallint(5) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT pour la table `listemembre_rat dagaste`
--
ALTER TABLE `listemembre_rat dagaste`
MODIFY `id` smallint(5) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT pour la table `listemembre_retr' a`
--
ALTER TABLE `listemembre_retr' a`
MODIFY `id` smallint(5) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `listerang`
--
ALTER TABLE `listerang`
MODIFY `id` int(10) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT pour la table `liste_bandes`
--
ALTER TABLE `liste_bandes`
MODIFY `ID` int(10) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=25;
--
-- AUTO_INCREMENT pour la table `race`
--
ALTER TABLE `race`
MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT pour la table `rang`
--
ALTER TABLE `rang`
MODIFY `id` int(10) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT pour la table `ref_profil`
--
ALTER TABLE `ref_profil`
MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=17;
--
-- AUTO_INCREMENT pour la table `regles_speciales`
--
ALTER TABLE `regles_speciales`
MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=14;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
