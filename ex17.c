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

	if (argc < 3) 
		die("USAGE: ex17 <dbfile> <action> [action params]");
	filename = argv[1];
	action = argv[2][0];
	conn = Database_open(filename, action);
	if (argc > 3) 
		id = atoi(argv[3]);
	if (id >= MAX_ROWS) 
		die("There's not that many records");
	switch (action)
	{
		case 'c': 
			Database_create(conn);
			Database_write(conn);
			break;
		case 'g':
			if (argc != 4) 
				die("Need an id to get");
			Database_get(conn,id);
			break;
		case 's':
			if (argc != 6) 
				die("Need id, name, email to set");
			Database_set(conn, atoi(argv[3]), argv[4], argv[5]);
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

void die(const char *message)
{
	if (error) 
		perror(message);
	else 
		printf("%s\n", message);
	exit(1);
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
	int rc;

	rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	if (rc != 1) 
		die("Failed to load database");
}

struct Connection *Database_open(const char *filename, char mode)
{
	struct Connection *conn;

	conn = malloc(sizeof(struct Connection));
	if (!conn) 
		die("Memory error");
	conn->db = malloc(sizeof(Database));
	if (!(conn->db)) 
		die("Memory error");
	if (mode == 'c')
		conn->file = fopen(filename, "w");
	else
	{		
		conn->file = fopen(filename, "r+");
		if (conn->file)
			Database_load(conn);
	}
	if (!(conn-file))
		die("Failed to open the file");
	return conn;
}

void Database_close(struct Connection *conn)
{
	if (conn)
	{
		if (conn->file)
			fclose(conn->file);
		if (conn->db)
			free(conn->db);
		free(conn);
	}
}

void Database_write(struct Connection *conn)
{
	int rc;	
	
	rewind(conn->file);
	rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	if (rc != 1)
		die("Failed to write database.");
	rc = fflush(conn->file);
	if (rc == EOF)
		die("Cannot flush database");
} 	

void Database_create(struct Connection *conn)
{
	int i;
	struct Address addr;

	for (i = 0; i < MAX_ROWS; i++)
	{
		addr = {.id = i, .set = 0};
		conn->db->rows[i] = addr;
	}
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr;
	char *res;

	addr = &(conn->db->rows[i]);
	if (addr->set)
		die("Already set, delete it first");
	addr->set = 1;
	res = strncpy(addr->name, name, MAX_DATA);
	if(!res)
		die("Name copy failed.");
	res = strncpy(addr->email, email, MAX_DATA);
	if (!res)
		die("Email copy failed");
}

void Database_get(struct Connection *conn, int id)
{
	struct Address *addr;

	addr = &(conn->db->rows[id]);
	
	if (addr->set)
		Address_print(addr);
	else
		die("ID is not set");
}	

void Database_delete(struct Connection *conn, int id)
{
	struct Address addr;

	addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
	int i;
	struct Database *db;
	struct Address *cur;

	db = conn->db;	
	for (i = 0; i < MAX_ROWS; i++)
	{
		cur = &(conn->db->rows[i]);
		if (cur->set)
			Address_print(cur);
	}
}
