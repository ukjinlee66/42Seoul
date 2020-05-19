<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpressdb' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', '' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'j_aA3iVs[kr`db.$-ORoE$9vn0;lq`f_3*+Icb/gtvkHj6)#[41tj<Dl0rDL]Pw2');
define('SECURE_AUTH_KEY',  'tu;#M=K<>uGi4ItnEg0,@n-kIQ]8q{Geo>rPB{9/B1vv=]-!D7K5,y?,xTK-f&Y#');
define('LOGGED_IN_KEY',    '.w-Kd]U$G-yl)ORjRFVP,CSv2eXnvf%}E=LCz;@11x5-?B_Rn]&h>CNF&[Ivt[3L');
define('NONCE_KEY',        'jv;Qx#y_6k-!q.M2iyeU-+ |9KfTfLJfs7$^pHq^aOMk7!<mwS165#}Kjqd-CK|V');
define('AUTH_SALT',        '[DBb35]<tYGmt&vu{>5QF5!+n_ PwQNeU{f-^|?G0NG*kC>B0R/!Rm!ZM`3qM_8=');
define('SECURE_AUTH_SALT', 'R4dZ.b [;)>9lBXIg9Am*q&9:WH`,~rn]b|b|1V$j<%Sn!<P+Bp,4%TQ{c(U+-2_');
define('LOGGED_IN_SALT',   '#|m+*@y%uZeNcXhqt4]i1T]l*%Y=Q|<xo d7g_9k^t_f3cCvVj;fqX 2@g.,=Lm^');
define('NONCE_SALT',       'EN3Vha+H=+2%&pmL#Ib|gp+,.!mYlw<8lLLHEqw! 7w 8`()SLSB9?dAOSwRx-Fb');
/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );
define('FS_METHOD', 'direct');
/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
