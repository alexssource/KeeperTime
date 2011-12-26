-- MySQL Administrator dump 1.4
--
-- ------------------------------------------------------
-- Server version	5.1.58-1ubuntu1


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


--
-- Create schema KeeperTime
--

CREATE DATABASE IF NOT EXISTS KeeperTime;
USE KeeperTime;

--
-- Definition of table `KeeperTime`.`Group`
--

DROP TABLE IF EXISTS `KeeperTime`.`Group`;
CREATE TABLE  `KeeperTime`.`Group` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL COMMENT 'Name of group',
  `is_manager` tinyint(1) NOT NULL DEFAULT '0',
  `is_admin` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `KeeperTime`.`Group`
--

/*!40000 ALTER TABLE `Group` DISABLE KEYS */;
LOCK TABLES `Group` WRITE;
INSERT INTO `KeeperTime`.`Group` VALUES  (1,'user',0,0),
 (2,'manager',1,0),
 (3,'admin',1,1);
UNLOCK TABLES;
/*!40000 ALTER TABLE `Group` ENABLE KEYS */;


--
-- Definition of table `KeeperTime`.`Project`
--

DROP TABLE IF EXISTS `KeeperTime`.`Project`;
CREATE TABLE  `KeeperTime`.`Project` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) CHARACTER SET utf8 NOT NULL,
  `description` text CHARACTER SET utf8 NOT NULL,
  `team` int(10) unsigned NOT NULL,
  `timming_plan` float unsigned NOT NULL DEFAULT '3',
  `status` int(10) unsigned NOT NULL,
  `created_at` bigint(20) unsigned NOT NULL,
  `expired_at` bigint(20) unsigned NOT NULL,
  `deadline` bigint(20) unsigned NOT NULL,
  `priority` tinyint(3) unsigned NOT NULL DEFAULT '3',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `KeeperTime`.`Project`
--

/*!40000 ALTER TABLE `Project` DISABLE KEYS */;
LOCK TABLES `Project` WRITE;
INSERT INTO `KeeperTime`.`Project` VALUES  (1,'Модуль','Сделать модуль для Joomla! 1.7',3,5.7,2,1324842551,1324842551,1326656951,5);
UNLOCK TABLES;
/*!40000 ALTER TABLE `Project` ENABLE KEYS */;


--
-- Definition of table `KeeperTime`.`Report`
--

DROP TABLE IF EXISTS `KeeperTime`.`Report`;
CREATE TABLE  `KeeperTime`.`Report` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `task` int(10) unsigned NOT NULL,
  `project` int(10) unsigned NOT NULL,
  `report` text CHARACTER SET utf8 NOT NULL,
  `hours` float unsigned NOT NULL,
  `created_at` bigint(20) unsigned NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `KeeperTime`.`Report`
--

/*!40000 ALTER TABLE `Report` DISABLE KEYS */;
LOCK TABLES `Report` WRITE;
INSERT INTO `KeeperTime`.`Report` VALUES  (1,1,1,'{$project}\n{$task}\nCreated: {$created}\nЗатрачено времени на выполнение: {$hours}\n\n{$report}',2.5,1324854444);
UNLOCK TABLES;
/*!40000 ALTER TABLE `Report` ENABLE KEYS */;


--
-- Definition of table `KeeperTime`.`Status`
--

DROP TABLE IF EXISTS `KeeperTime`.`Status`;
CREATE TABLE  `KeeperTime`.`Status` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(64) CHARACTER SET utf8 NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `KeeperTime`.`Status`
--

/*!40000 ALTER TABLE `Status` DISABLE KEYS */;
LOCK TABLES `Status` WRITE;
INSERT INTO `KeeperTime`.`Status` VALUES  (2,'Сделать');
UNLOCK TABLES;
/*!40000 ALTER TABLE `Status` ENABLE KEYS */;


--
-- Definition of table `KeeperTime`.`Task`
--

DROP TABLE IF EXISTS `KeeperTime`.`Task`;
CREATE TABLE  `KeeperTime`.`Task` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) CHARACTER SET utf8 NOT NULL,
  `title` varchar(255) CHARACTER SET utf8 NOT NULL,
  `description` text CHARACTER SET utf8 NOT NULL,
  `timming_plan` float unsigned NOT NULL DEFAULT '3',
  `project` int(10) unsigned NOT NULL,
  `user` int(10) unsigned NOT NULL,
  `status` int(10) unsigned NOT NULL,
  `created_at` bigint(20) unsigned NOT NULL,
  `priority` tinyint(3) unsigned NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `KeeperTime`.`Task`
--

/*!40000 ALTER TABLE `Task` DISABLE KEYS */;
LOCK TABLES `Task` WRITE;
INSERT INTO `KeeperTime`.`Task` VALUES  (1,'Написать код для модулья','Новая задача','Очень сделать',3.45,1,2,2,1324845577,7);
UNLOCK TABLES;
/*!40000 ALTER TABLE `Task` ENABLE KEYS */;


--
-- Definition of table `KeeperTime`.`Team`
--

DROP TABLE IF EXISTS `KeeperTime`.`Team`;
CREATE TABLE  `KeeperTime`.`Team` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(128) CHARACTER SET utf8 NOT NULL,
  `created_at` bigint(20) unsigned NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `KeeperTime`.`Team`
--

/*!40000 ALTER TABLE `Team` DISABLE KEYS */;
LOCK TABLES `Team` WRITE;
INSERT INTO `KeeperTime`.`Team` VALUES  (2,'DevTeam',0),
 (3,'DevTeam',1324831766);
UNLOCK TABLES;
/*!40000 ALTER TABLE `Team` ENABLE KEYS */;


--
-- Definition of table `KeeperTime`.`Templates`
--

DROP TABLE IF EXISTS `KeeperTime`.`Templates`;
CREATE TABLE  `KeeperTime`.`Templates` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `module` varchar(255) NOT NULL,
  `template` text CHARACTER SET utf8 NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `KeeperTime`.`Templates`
--

/*!40000 ALTER TABLE `Templates` DISABLE KEYS */;
LOCK TABLES `Templates` WRITE;
INSERT INTO `KeeperTime`.`Templates` VALUES  (1,'Report','{$project}\n{$task}\nCreated: {$created}\nЗатрачено времени на выполнение: {$hours}\n\n{$report}');
UNLOCK TABLES;
/*!40000 ALTER TABLE `Templates` ENABLE KEYS */;


--
-- Definition of table `KeeperTime`.`User`
--

DROP TABLE IF EXISTS `KeeperTime`.`User`;
CREATE TABLE  `KeeperTime`.`User` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) CHARACTER SET utf8 NOT NULL,
  `surname` varchar(32) CHARACTER SET utf8 NOT NULL,
  `login` varchar(32) NOT NULL,
  `password` varchar(32) NOT NULL,
  `email` varchar(32) NOT NULL,
  `group` int(10) unsigned NOT NULL,
  `team` int(10) unsigned NOT NULL,
  `created_at` bigint(20) unsigned NOT NULL,
  `wage` float unsigned NOT NULL COMMENT 'Часовая тарифная ставка',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `KeeperTime`.`User`
--

/*!40000 ALTER TABLE `User` DISABLE KEYS */;
LOCK TABLES `User` WRITE;
INSERT INTO `KeeperTime`.`User` VALUES  (1,'Alex','Kozlov','alexssource','1','alexssource@mail.by',1,3,1324832337,5),
 (2,'Sasha','Kozlov','gaizjad','3','gaizjad@mail.by',2,2,1324835463,5);
UNLOCK TABLES;
/*!40000 ALTER TABLE `User` ENABLE KEYS */;


--
-- Definition of table `KeeperTime`.`WorkTime`
--

DROP TABLE IF EXISTS `KeeperTime`.`WorkTime`;
CREATE TABLE  `KeeperTime`.`WorkTime` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `day` bigint(20) unsigned NOT NULL,
  `hours` float unsigned NOT NULL,
  `user` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `KeeperTime`.`WorkTime`
--

/*!40000 ALTER TABLE `WorkTime` DISABLE KEYS */;
LOCK TABLES `WorkTime` WRITE;
INSERT INTO `KeeperTime`.`WorkTime` VALUES  (1,1324848050,13,1);
UNLOCK TABLES;
/*!40000 ALTER TABLE `WorkTime` ENABLE KEYS */;




/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
