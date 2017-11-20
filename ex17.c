#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address 
{
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};

struct Database
{
	struct Address rows[MAX_ROWS];
};

struct Connection
{
	FILE *file;
	struct Database *db;
};

void die(const char *message);
void Address_print(struct Address *addr);
void Database_load(struct Connection *conn);
struct Connection *Database_open(const char *filename, char mode);
void Database_close(struct Connection *conn);
void Database_write(struct Connection *conn);
void Database_create(struct Connection *conn);
void Database_set(struct Connection *conn, int id, const char *name, const char *email);
void Database_get(struct Connection *conn, int id);
void Database_delete(struct Connection *conn, int id);
void Database_list(struct Connection *conn);	

int main(int argc, char *argv[])
{
	char *filename;
	char action;
	struct Connection *conn;
	int id = 0;

	if (argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]");
	filename = argv[1];
	action = argv[2][0];
	conn = Database_open(filename, action);
	if (argc > 3) id = atoi(argv[3]);
	if (id >= MAX_ROWS) die("There's not that many records");
	switch (action)
	{
		case 'c': 
			Database_create(conn);
			Database_write(conn);
			break;
		case 'g':
			if (argc != 4) die("Need an id to get");
			Database_get(conn,id);
			break;
		case 's':
			if (argc != 6) die("Need id, name, email to set");
			Database_set(conn, argv[4], argv[5]);
			Database_write(conn);
			break;
		case 'd':
			if (argc != 4) die("Need an id to delete");
			Database_delete(conn, id);
			Database_write(conn);
			break;
		case 'l':
			Database_list(conn);
			break;
		default:
			die("Invalid action: c=create, g=get, s=set, d=del, l=list");
	}
	Database_close(conn);
	return 0;
}
			
