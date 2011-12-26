/* 
 * File:   ERROR_CODES.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on December 10, 2011, 6:13 PM
 */

#ifndef ERROR_CODES_H
#define	ERROR_CODES_H

#define ERROR_TYPE_MYSQL "MYSQL_ERROR"

#define ERROR_MYSQL_CONNECT 1
#define ERROR_MYSQL_CHANGE_DB 2
#define ERROR_MYSQL_QUERY 3

enum MYSQL_QUERY_TYPE { SELECT, INSERT, UPDATE, DELETE, OTHER };

#endif	/* ERROR_CODES_H */

