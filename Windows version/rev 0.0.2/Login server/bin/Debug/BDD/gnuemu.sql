/*
MySQL Data Transfer
Source Host: localhost
Source Database: gnuemu
Target Host: localhost
Target Database: gnuemu
Date: 03/01/2014 01:38:12
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for gnu_accounts
-- ----------------------------
CREATE TABLE `gnu_accounts` (
  `id` int(11) DEFAULT NULL,
  `user` text,
  `password` text,
  `email` text,
  `name` text,
  `character` text,
  `is_connected` int(11) DEFAULT NULL,
  `ban` int(11) DEFAULT NULL,
  `gm_level` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for gnu_servers_list
-- ----------------------------
CREATE TABLE `gnu_servers_list` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `ip` varchar(255) NOT NULL,
  `port` int(11) NOT NULL,
  `system_port` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=23 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `gnu_accounts` VALUES ('1', 'hamza', 'hamza', 'grifrose@gmail.com', 'hamza', null, null, null, '10');
INSERT INTO `gnu_servers_list` VALUES ('1', '127.0.0.1', '5555', '4040');
