#include<stdio.h> 
#include <SQLAPI.h> 
int main(int argc, char* argv[])
{
	SAConnection con; 
	SACommandcmd;   
	try
	{
		
		con.Connect("test", "tester", "tester", SA_Oracle_Client);

		 
		
		cmd.setConnection(&con);

		
		cmd.setCommandText("create table tbl(id number, name varchar(20));");
		cmd.Execute();

		 
		cmd.setCommandText("Insert into tbl(id, name) values (1,”Vinay”)");
		cmd.setCommandText("Insert into tbl(id, name) values (2,”Kushal”)");
		cmd.setCommandText("Insert into tbl(id, name) values (3,”Saransh”)");
		cmd.Execute();

		 
		con.Commit();
		printf("Table created, row inserted!\n");
	}

	catch (SAException &x)
	{
		
		try
		{
		
			con.Rollback();
		}
		catch (SAException &)
		{
		}
		 

		printf("%s\n", (const char*)x.ErrText());
	}
	return 0;
}










